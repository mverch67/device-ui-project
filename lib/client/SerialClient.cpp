#include "SerialClient.h"
#include "MeshEnvelope.h"
#include "Log.h"
#include <time.h>
#include <assert.h>

#if defined(HAS_FREE_RTOS) || defined(ARCH_ESP32)
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#else
#include <thread>
#endif
#include "Arduino.h"

SerialClient* SerialClient::instance = nullptr;

SerialClient::SerialClient(void) : connected(false), shutdown(false), pb_size(0), bytes_read(0)
{
    buffer = new uint8_t[PB_BUFSIZE + MT_HEADER_SIZE];
    instance = this;
}

void SerialClient::init(void)
{
    ILOG_TRACE("SerialClient::init() creating serial task\n");
#if defined(HAS_FREE_RTOS) || defined(ARCH_ESP32)
    xTaskCreateUniversal(task_loop, "serial", 8192, NULL, 2, NULL, 0);
#elif defined(PORTDUINO)
    std::thread* tft_task = new std::thread([] { instance->task_loop(nullptr); });
#else
#error "unsupported architecture"
#endif

}

bool SerialClient::connect(void)
{
    ILOG_ERROR("SerialClient::connect() not implemented\n");
    return false;
}

bool SerialClient::disconnect(void)
{
    connected = false;
    return connected;
}

bool SerialClient::isConnected(void)
{
    return connected;
}

bool SerialClient::send(meshtastic_ToRadio &&to)
{
    static uint32_t id = 1;
    ILOG_TRACE("SerialClient::send() push packet %d to queue\n", id);
    queue.clientSend(DataPacket<meshtastic_ToRadio>(id++, to));
    return false;
}

meshtastic_FromRadio SerialClient::receive(void)
{
    if (queue.serverQueueSize() != 0) {
        ILOG_TRACE("SerialClient::receive() got a packet from queue\n");
        auto p = queue.clientReceive()->move();
        return static_cast<DataPacket<meshtastic_FromRadio> *>(p.get())->getData();
    }
    return meshtastic_FromRadio();
} 

SerialClient::~SerialClient() { 
    shutdown = true;
};


// --- protected part ---

bool SerialClient::send(const uint8_t* buf, size_t len) {
    ILOG_ERROR("SerialClient::send not implemented\n");
    return false;
}

size_t SerialClient::receive(uint8_t* buf, size_t space_left) {
    ILOG_ERROR("SerialClient::receive not implemented\n");
    return 0;
}

/**
 * @brief put received bytes into envelope and send to client queue
 * 
 */
void SerialClient::handlePacketReceived(void) {
    ILOG_TRACE("SerialClient::handlePacketReceived pb_size=%d\n", pb_size);

    MeshEnvelope envelope(buffer, pb_size);
    meshtastic_FromRadio fromRadio = envelope.decode();
    if (fromRadio.which_payload_variant != 0) {
        queue.serverSend(DataPacket<meshtastic_FromRadio>(fromRadio.id, fromRadio));
    }
}

void SerialClient::handleSendPacket(void) {
    auto p = queue.serverReceive()->move();
    meshtastic_ToRadio toRadio = static_cast<DataPacket<meshtastic_ToRadio> *>(p.get())->getData();
//    meshtastic_ToRadio toRadio{std::move(static_cast<DataPacket<meshtastic_ToRadio> *>(p.get())->getData())};
    MeshEnvelope envelope;
    const std::vector<uint8_t>& pb_buf = envelope.encode(toRadio);
    if (pb_buf.size() > 0) {
        send(&pb_buf[0], pb_buf.size());
    }
}


/**
 * @brief Sending and receiving packets to/from packet queue
 * 
 */
void SerialClient::task_loop(void*) {
    size_t space_left = PB_BUFSIZE - instance->pb_size;
    ILOG_TRACE("SerialClient::task_loop running\n");

    while (!instance->shutdown) {
        if (instance->connected) {
            size_t bytes_read = instance->receive(&instance->buffer[instance->pb_size], space_left);
            instance->pb_size += bytes_read;
            size_t payload_len;
            bool valid = MeshEnvelope::validate(instance->buffer, instance->pb_size, payload_len);

            if (valid) {
                instance->handlePacketReceived();
                MeshEnvelope::invalidate(instance->buffer, instance->pb_size, payload_len);
            }

            // send a packet if available
            if (instance->queue.clientQueueSize() != 0) {
                instance->handleSendPacket();
            }
#if defined(HAS_FREE_RTOS) || defined(ARCH_ESP32)
            vTaskDelay((TickType_t)5); // yield, do not remove
#else   
            delay(5);
#endif
        }
    }
}

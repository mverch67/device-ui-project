/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9 */

#ifndef PB_MESHTASTIC_MESHTASTIC_APPONLY_PB_H_INCLUDED
#define PB_MESHTASTIC_MESHTASTIC_APPONLY_PB_H_INCLUDED
#include "meshtastic/channel.pb.h"
#include "meshtastic/config.pb.h"
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* This is the most compact possible representation for a set of channels.
 It includes only one PRIMARY channel (which must be first) and
 any SECONDARY channels.
 No DISABLED channels are included.
 This abstraction is used only on the the 'app side' of the world (ie python, javascript and android etc) to show a group of
 Channels as a (long) URL */
typedef struct _meshtastic_ChannelSet {
    /* Channel list with settings */
    pb_size_t settings_count;
    meshtastic_ChannelSettings settings[8];
    /* LoRa config */
    bool has_lora_config;
    meshtastic_Config_LoRaConfig lora_config;
} meshtastic_ChannelSet;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define meshtastic_ChannelSet_init_default                                                                                       \
    {                                                                                                                            \
        0, {meshtastic_ChannelSettings_init_default, meshtastic_ChannelSettings_init_default,                                    \
            meshtastic_ChannelSettings_init_default, meshtastic_ChannelSettings_init_default,                                    \
            meshtastic_ChannelSettings_init_default, meshtastic_ChannelSettings_init_default,                                    \
            meshtastic_ChannelSettings_init_default, meshtastic_ChannelSettings_init_default},                                   \
            false, meshtastic_Config_LoRaConfig_init_default                                                                     \
    }
#define meshtastic_ChannelSet_init_zero                                                                                          \
    {                                                                                                                            \
        0, {meshtastic_ChannelSettings_init_zero, meshtastic_ChannelSettings_init_zero, meshtastic_ChannelSettings_init_zero,    \
            meshtastic_ChannelSettings_init_zero, meshtastic_ChannelSettings_init_zero, meshtastic_ChannelSettings_init_zero,    \
            meshtastic_ChannelSettings_init_zero, meshtastic_ChannelSettings_init_zero},                                         \
            false, meshtastic_Config_LoRaConfig_init_zero                                                                        \
    }

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_ChannelSet_settings_tag 1
#define meshtastic_ChannelSet_lora_config_tag 2

/* Struct field encoding specification for nanopb */
#define meshtastic_ChannelSet_FIELDLIST(X, a)                                                                                    \
    X(a, STATIC, REPEATED, MESSAGE, settings, 1)                                                                                 \
    X(a, STATIC, OPTIONAL, MESSAGE, lora_config, 2)
#define meshtastic_ChannelSet_CALLBACK NULL
#define meshtastic_ChannelSet_DEFAULT NULL
#define meshtastic_ChannelSet_settings_MSGTYPE meshtastic_ChannelSettings
#define meshtastic_ChannelSet_lora_config_MSGTYPE meshtastic_Config_LoRaConfig

extern const pb_msgdesc_t meshtastic_ChannelSet_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_ChannelSet_fields &meshtastic_ChannelSet_msg

/* Maximum encoded size of messages (where known) */
#define MESHTASTIC_MESHTASTIC_APPONLY_PB_H_MAX_SIZE meshtastic_ChannelSet_size
#define meshtastic_ChannelSet_size 679

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

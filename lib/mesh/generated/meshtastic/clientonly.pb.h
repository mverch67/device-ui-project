/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9.1 */

#ifndef PB_MESHTASTIC_MESHTASTIC_CLIENTONLY_PB_H_INCLUDED
#define PB_MESHTASTIC_MESHTASTIC_CLIENTONLY_PB_H_INCLUDED
#include "meshtastic/localonly.pb.h"
#include "meshtastic/mesh.pb.h"
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* This abstraction is used to contain any configuration for provisioning a node on any client.
 It is useful for importing and exporting configurations. */
typedef struct _meshtastic_DeviceProfile {
    /* Long name for the node */
    bool has_long_name;
    char long_name[40];
    /* Short name of the node */
    bool has_short_name;
    char short_name[5];
    /* The url of the channels from our node */
    pb_callback_t channel_url;
    /* The Config of the node */
    bool has_config;
    meshtastic_LocalConfig config;
    /* The ModuleConfig of the node */
    bool has_module_config;
    meshtastic_LocalModuleConfig module_config;
    /* Fixed position data */
    bool has_fixed_position;
    meshtastic_Position fixed_position;
    /* Ringtone for ExternalNotification */
    bool has_ringtone;
    char ringtone[231];
    /* Predefined messages for CannedMessage */
    bool has_canned_messages;
    char canned_messages[201];
} meshtastic_DeviceProfile;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define meshtastic_DeviceProfile_init_default                                                                                    \
    {                                                                                                                            \
        false, "", false, "", {{NULL}, NULL}, false, meshtastic_LocalConfig_init_default, false,                                 \
            meshtastic_LocalModuleConfig_init_default, false, meshtastic_Position_init_default, false, "", false, ""             \
    }
#define meshtastic_DeviceProfile_init_zero                                                                                       \
    {                                                                                                                            \
        false, "", false, "", {{NULL}, NULL}, false, meshtastic_LocalConfig_init_zero, false,                                    \
            meshtastic_LocalModuleConfig_init_zero, false, meshtastic_Position_init_zero, false, "", false, ""                   \
    }

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_DeviceProfile_long_name_tag 1
#define meshtastic_DeviceProfile_short_name_tag 2
#define meshtastic_DeviceProfile_channel_url_tag 3
#define meshtastic_DeviceProfile_config_tag 4
#define meshtastic_DeviceProfile_module_config_tag 5
#define meshtastic_DeviceProfile_fixed_position_tag 6
#define meshtastic_DeviceProfile_ringtone_tag 7
#define meshtastic_DeviceProfile_canned_messages_tag 8

/* Struct field encoding specification for nanopb */
#define meshtastic_DeviceProfile_FIELDLIST(X, a)                                                                                 \
    X(a, STATIC, OPTIONAL, STRING, long_name, 1)                                                                                 \
    X(a, STATIC, OPTIONAL, STRING, short_name, 2)                                                                                \
    X(a, CALLBACK, OPTIONAL, STRING, channel_url, 3)                                                                             \
    X(a, STATIC, OPTIONAL, MESSAGE, config, 4)                                                                                   \
    X(a, STATIC, OPTIONAL, MESSAGE, module_config, 5)                                                                            \
    X(a, STATIC, OPTIONAL, MESSAGE, fixed_position, 6)                                                                           \
    X(a, STATIC, OPTIONAL, STRING, ringtone, 7)                                                                                  \
    X(a, STATIC, OPTIONAL, STRING, canned_messages, 8)
#define meshtastic_DeviceProfile_CALLBACK pb_default_field_callback
#define meshtastic_DeviceProfile_DEFAULT NULL
#define meshtastic_DeviceProfile_config_MSGTYPE meshtastic_LocalConfig
#define meshtastic_DeviceProfile_module_config_MSGTYPE meshtastic_LocalModuleConfig
#define meshtastic_DeviceProfile_fixed_position_MSGTYPE meshtastic_Position

extern const pb_msgdesc_t meshtastic_DeviceProfile_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_DeviceProfile_fields &meshtastic_DeviceProfile_msg

/* Maximum encoded size of messages (where known) */
/* meshtastic_DeviceProfile_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

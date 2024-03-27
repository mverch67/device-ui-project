#include "mesh-pb-constants.h"

#include <pb_decode.h>
#include <pb_encode.h>
#include <vector>

bool meshtastic_DeviceState_callback(pb_istream_t *istream, pb_ostream_t *ostream, const pb_field_iter_t *field)
{
    if (ostream) {
        std::vector<meshtastic_NodeInfoLite> *vec = (std::vector<meshtastic_NodeInfoLite> *)field->pData;
        for (auto item : *vec) {
            if (!pb_encode_tag_for_field(ostream, field))
                return false;
            pb_encode_submessage(ostream, meshtastic_NodeInfoLite_fields, &item);
        }
    }
    if (istream) {
        meshtastic_NodeInfoLite node; // this gets good data
        std::vector<meshtastic_NodeInfoLite> *vec = (std::vector<meshtastic_NodeInfoLite> *)field->pData;

        if (istream->bytes_left && pb_decode(istream, meshtastic_NodeInfoLite_fields, &node))
            vec->push_back(node);
    }
    return true;
}

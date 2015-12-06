#ifndef CHANNEL_SERIALIZER_PROTOCOL_H
#define CHANNEL_SERIALIZER_PROTOCOL_H

#include "lms/serializable.h"
#include "cereal/cerealizable.h"
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"

struct ProtocolHeader : public lms::Serializable {
    std::vector<std::string> dataChannels;

    //get default interface for datamanager
    CEREAL_SERIALIZATION()

    template<class Archive>
    void serialize(Archive & archive) {
        archive( dataChannels );
    }
};

#endif /* CHANNEL_SERIALIZER_PROTOCOL_H */

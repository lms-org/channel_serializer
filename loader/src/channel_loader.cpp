#include "channel_loader.h"

bool ChannelLoader::initialize() {
    std::string filePath = config().get<std::string>("file");
    file.open(filePath);
    header.lmsDeserialize(file);

    // get write access for all channels that shall be serialized
    for(const std::string &channel : header.dataChannels) {
        channels.push_back(writeChannel<lms::Any>(channel));
    }

    return true;
}

bool ChannelLoader::deinitialize() {
    file.close();

    return true;
}

bool ChannelLoader::cycle() {
    try {
        for(auto& ch : channels) {
            if(! ch.deserialize(file)) {
                logger.error("cycle") << "Failed to deserialize " << ch.name();
            }
        }
    } catch (cereal::Exception &ex) {
        logger.error("cycle") << ex.what();

        file.seekg(0, std::ios::beg);
        header.lmsDeserialize(file);

        return false;
    }

    return true;
}

#include "channel_loader.h"

bool ChannelLoader::initialize() {
    config = getConfig();

    std::string filePath = config->get<std::string>("file");
    file.open(filePath);
    header.deserialize(file);

    // get write access for all channels that shall be serialized
    for(const std::string &channel : header.dataChannels) {
        datamanager()->getWriteAccess(this, channel);
    }

    return true;
}

bool ChannelLoader::deinitialize() {
    file.close();

    return true;
}

bool ChannelLoader::cycle() {
    try {
        for(const std::string &channel : header.dataChannels) {
            datamanager()->deserializeChannel(this, channel, file);
        }
    } catch (cereal::Exception &ex) {
        logger.error("cycle") << ex.what();
        return false;
    }

    return true;
}
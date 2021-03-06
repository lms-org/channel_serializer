#include "channel_loader.h"

bool ChannelLoader::initialize() {
    if(! isEnableLoad()) {
        logger.error() << "Command line option --enable-load was not specified";
        return false;
    }

    std::string fileName = config().get<std::string>("fileName","channels");
    file.open(loadLogFile(fileName+".cereal"));
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
            if(!ch.isSerializable()){
                logger.error("cycle")<<"channel is not deserialize "<<ch.name();
            }
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

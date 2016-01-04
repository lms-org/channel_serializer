#include "channel_logger.h"
#include "protocol.h"

bool ChannelLogger::initialize() {
    header.dataChannels = config().getArray<std::string>("dataChannels");

    // get read access for all channels that shall be serialized
    for(const std::string &channel : header.dataChannels) {
        channels.push_back(readChannel<lms::Any>(channel));
    }

    file.open(logFile("channels.cereal"));
    header.lmsSerialize(file);

    return true;
}

bool ChannelLogger::deinitialize() {
    file.close();

    return true;
}

bool ChannelLogger::cycle() {
    for(auto const& ch : channels) {
        if(! ch.serialize(file)) {
            logger.error("cycle") << "Failed to serialize " << ch.name();
        }
    }

    // write all buffered data into the physical file
    // this ensures that most of the written data is actually written
    // in case of an error/exception
    file.flush();

    return true;
}

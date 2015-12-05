#include "channel_logger.h"
#include "protocol.h"

bool ChannelLogger::initialize() {
    config = getConfig();

    std::string directory = config->get<std::string>("directory");

    header.dataChannels = config->getArray<std::string>("dataChannels");

    // get read access for all channels that shall be serialized
    for(const std::string &channel : header.dataChannels) {
        datamanager()->getReadAccess(this, channel);
    }

    file.open(directory + "/" + generateFileName() + ".cereal");
    header.lmsSerialize(file);

    return true;
}

bool ChannelLogger::deinitialize() {
    file.close();

    return true;
}

bool ChannelLogger::cycle() {
    for(const std::string &channel : header.dataChannels) {
        datamanager()->serializeChannel(this, channel, file);
    }

    // write all buffered data into the physical file
    // this ensures that most of the written data is actually written
    // in case of an error/exception
    file.flush();

    return true;
}

std::string ChannelLogger::generateFileName() {
    char dateDir[50];

    time_t rawtime;
    time (&rawtime);
    tm *t = gmtime(&rawtime);
    snprintf(dateDir, sizeof(dateDir), "%04i%02i%02i-%02i%02i%02i",
        t->tm_year+1900,
        t->tm_mon+1,
        t->tm_mday,
        t->tm_hour,
        t->tm_min,
        t->tm_sec
    );

    return dateDir;
}

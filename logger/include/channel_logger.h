#ifndef CHANNEL_LOGGER_H
#define CHANNEL_LOGGER_H

#include "lms/module.h"
#include "protocol.h"

#include <fstream>

/**
 * @brief Log a bunch of data channels into a single file using cereal.
 */
class ChannelLogger : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
private:
    std::vector<lms::ReadDataChannel<lms::Any>> channels;

    ProtocolHeader header;
    std::ofstream file;
};

#endif /* CHANNEL_LOGGER_H */

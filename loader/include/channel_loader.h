#ifndef CHANNEL_LOADER_H
#define CHANNEL_LOADER_H

#include "lms/module.h"
#include "protocol.h"

#include <fstream>

/**
 * @brief Load a bunch of data channels from a single file.
 */
class ChannelLoader : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
private:
    ProtocolHeader header;
    std::ifstream file;

    std::vector<lms::WriteDataChannel<lms::Any>> channels;
};

#endif /* CHANNEL_LOADER_H */

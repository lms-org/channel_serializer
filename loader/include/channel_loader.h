#ifndef CHANNEL_LOADER_H
#define CHANNEL_LOADER_H

#include "lms/datamanager.h"
#include "lms/module.h"
#include "lms/type/module_config.h"
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
    const lms::type::ModuleConfig *config;

    ProtocolHeader header;
    std::ifstream file;
};

#endif /* CHANNEL_LOADER_H */

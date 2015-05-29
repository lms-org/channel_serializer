#ifndef CHANNEL_LOGGER_H
#define CHANNEL_LOGGER_H

#include "lms/datamanager.h"
#include "lms/module.h"
#include "lms/type/module_config.h"
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
    std::string generateFileName();

    const lms::type::ModuleConfig *config;

    ProtocolHeader header;
    std::ofstream file;
};

#endif /* CHANNEL_LOGGER_H */

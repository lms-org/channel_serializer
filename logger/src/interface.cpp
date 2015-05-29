#include "channel_logger.h"

extern "C" {
void* getInstance() {
    return new ChannelLogger();
}
}

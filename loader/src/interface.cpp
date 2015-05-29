#include "channel_loader.h"

extern "C" {
void* getInstance() {
    return new ChannelLoader();
}
}

set ( SOURCES 
	"src/channel_loader.cpp"
	"src/interface.cpp"
)

set (HEADERS
	"include/channel_loader.h"
    "../include/protocol.h"
)

include_directories("include")

add_library (channel_loader MODULE ${SOURCES} ${HEADERS})
target_link_libraries(channel_loader PRIVATE lmscore)

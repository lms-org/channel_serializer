set ( SOURCES 
	"src/channel_logger.cpp"
	"src/interface.cpp"
)

set (HEADERS
	"include/channel_logger.h"
    "../include/protocol.h"
)

include_directories("include")

add_library (channel_logger MODULE ${SOURCES} ${HEADERS})
target_link_libraries(channel_logger PRIVATE lmscore)

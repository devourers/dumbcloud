project(dumbcloud_server)

option(WITH_DUMBCLOUD_SERVER_GO "Builds headless CLI for dumbcloud-server" OFF)


set(dumbcloud_server_H 
    include/dumbcloud_server/dumbcloud_server.h
)

set(dumbcloud_server_SRC
    src/dumbcloud_server.cpp
)

add_library(dumbcloud_server STATIC ${dumbcloud_server_H} ${dumbcloud_server_SRC})
target_include_directories(dumbcloud_server PUBLIC include PRIVATE src)
target_link_libraries(dumbcloud_server dumbcloud_utils)


if(WITH_DUMBCLOUD_SERVER_GO)
    add_subdirectory(dumbcloud_server_go)
endif()

install(DIRECTORY include/dumbcloud_server
  DESTINATION include)
install(TARGETS dumbcloud_server
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
project(dumbcloud_client)

option(WITH_DUMBCLOUD_CLIENT_GO "Builds headless CLI for dumbcloud-server" OFF)


set(dumbcloud_client_H 
    include/dumbcloud_client/dumbcloud_client.h
)

set(dumbcloud_client_SRC
    src/dumbcloud_client.cpp
)

add_library(dumbcloud_client STATIC ${dumbcloud_client_H} ${dumbcloud_client_SRC})
target_include_directories(dumbcloud_client PUBLIC include PRIVATE src)
target_link_libraries(dumbcloud_client dumbcloud_utils)


if(WITH_DUMBCLOUD_CLIENT_GO)
    add_subdirectory(dumbcloud_client_go)
endif()

install(DIRECTORY include/dumbcloud_client
  DESTINATION include)
install(TARGETS dumbcloud_client
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
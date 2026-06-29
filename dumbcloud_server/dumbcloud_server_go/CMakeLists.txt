project(dumbcloud_server_go)

set(dumbcloud_server_go_SRC 
    dumbcloud_server_go.cpp
)

add_executable(dumbcloud_server_go
  ${dumbcloud_server_go_SRC})

set_target_properties(dumbcloud_server_go PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../bin/dumbcloud_server_go"
)

target_link_libraries(dumbcloud_server_go 
  dumbcloud_server
  dumbcloud_utils)
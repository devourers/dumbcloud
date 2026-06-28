project(dumbcloud_server_go)

set(dumbcloud_server_go_SRC 
    dumbcloud_server_go.cpp
)

add_executable(dumbcloud_server_go
  ${dumbcloud_server_go_SRC})

target_link_libraries(dumbcloud_server_go 
  dumbcloud_server
  dumbcloud_utils)
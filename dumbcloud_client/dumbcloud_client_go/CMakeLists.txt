project(dumbcloud_client_go)

set(dumbcloud_client_go_SRC 
    dumbcloud_client_go.cpp
)

add_executable(dumbcloud_client_go
  ${dumbcloud_client_go_SRC})

  target_link_libraries(dumbcloud_client_go 
  dumbcloud_client
  dumbcloud_utils)
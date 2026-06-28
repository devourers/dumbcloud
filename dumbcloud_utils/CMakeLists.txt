project(dumbcloud_utils)

set(dumbcloud_utils_H 
    include/dumbcloud_utils/dumbcloud_utils.h
    include/dumbcloud_utils/journal.h
    include/dumbcloud_utils/json.hpp
)

set(dumbcloud_utils_SRC
    src/dumbcloud_utils.cpp
    src/journal.cpp
)

add_library(dumbcloud_utils STATIC ${dumbcloud_utils_H} ${dumbcloud_utils_SRC})
target_include_directories(dumbcloud_utils PUBLIC include PRIVATE src)

install(DIRECTORY include/dumbcloud_utils
  DESTINATION include)
install(TARGETS dumbcloud_utils
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
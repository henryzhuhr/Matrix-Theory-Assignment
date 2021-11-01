include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(" BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)

# add_executable(test-linkedlist test-linkedlist.cpp)
add_executable(test test-linkedlist.cpp)

# reference in CXX
add_executable(reference reference.cpp)

# copy in CXX
add_executable(memory_shallow_copy memory_shallow_copy.cpp)
add_executable(memory_deep_copy memory_deep_copy.cpp)

# Generic Programming
add_executable(generic_programming generic_programming.cpp)

# Log
include_directories(~/Programs/glog)
find_package (glog 0.5.0 REQUIRED)
add_executable(log log.cpp)
target_link_libraries (log glog::glog)

# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libstdc++-6.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libwinpthread-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
# file(COPY ${PROJECT_SOURCE_DIR}/tools/mingw64/bin/libgcc_s_seh-1.dll DESTINATION ${PROJECT_SOURCE_DIR}/bin FOLLOW_SYMLINK_CHAIN)
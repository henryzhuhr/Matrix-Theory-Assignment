include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("[INFO] BINARY DIR:" ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/bin)


add_executable(lu lu.cpp) # lu
add_executable(qr qr.cpp) # lu
add_executable(svd svd.cpp) # lu



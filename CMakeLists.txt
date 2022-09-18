cmake_minimum_required(VERSION 3.20)
project(FaceFind)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp)
add_executable(FaceFind ${SOURCE_FILES})

add_subdirectory(src/libfacefind)
target_link_libraries(FaceFind libfacefind)

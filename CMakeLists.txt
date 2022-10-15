cmake_minimum_required(VERSION 3.20)
project(FaceFind)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5Widgets REQUIRED)

include_directories(
        ${Qt5Widgets_INCLUDE_DIRS}
)

set(SOURCE_FILES src/main.cpp)
add_executable(FaceFind ${SOURCE_FILES})

add_subdirectory(src/libfacefind)
add_subdirectory(src/libproto)

target_link_libraries(${PROJECT_NAME} libfacefind libproto ${Qt5Widgets_LIBS})



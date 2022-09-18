project(libfacefind)

file(COPY cascades DESTINATION ${CMAKE_BINARY_DIR})
set(SOURCES FaceFinder.cpp)
set(HEADERS FaceFinder.h)

find_package(OpenCV REQUIRED)

add_library(libfacefind ${SOURCES} ${HEADERS})
target_include_directories(libfacefind PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
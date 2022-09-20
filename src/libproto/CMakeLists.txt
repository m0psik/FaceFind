project(libproto)

find_package(Protobuf REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(
        ${PROTOBUF_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
)

protobuf_generate_cpp(PROTO_SRC PROTO_HEADER face.proto)

set(SOURCES
        FaceInfo.cpp
        Answer.cpp
        ${PROTO_SRC})

set(HEADERS
        FaceInfo.h
        Answer.h
        ${PROTO_HEADER})

add_library(libproto ${SOURCES} ${HEADERS})
target_include_directories(libproto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBS} ${Qt5Widgets_LIBS})
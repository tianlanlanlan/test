project(proto)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS detection2d.proto)
add_library(custom_proto ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(custom_proto
    PUBLIC
    ${Protobuf_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(custom_proto
    PRIVATE
    ${Protobuf_LIBRARIES}
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB LIB_SRCS ${PROJECT_SOURCE_DIR}/*.cpp)
add_library (graph STATIC ${LIB_SRCS})
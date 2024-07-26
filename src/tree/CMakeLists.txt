set(LIB_NAME tree)
file(GLOB SOURCES *.hpp *.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
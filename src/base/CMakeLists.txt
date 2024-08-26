set(LIB_NAME base)
file(GLOB SOURCES *.hpp *.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
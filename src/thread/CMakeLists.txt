set(LIB_NAME thread)
file(GLOB SOURCES *.hpp *.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
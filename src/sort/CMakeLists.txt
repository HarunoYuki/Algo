set(LIB_NAME sort)
file(GLOB SOURCES *.hpp *.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
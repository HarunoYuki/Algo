set(LIB_NAME find)
file(GLOB SOURCES *.hpp *.cpp)
add_library(${LIB_NAME} STATIC ${SOURCES})
#设定源码列表.cpp
set(SOURCE_FILES ./main.cpp)
#添加子目录,作用相当于进入子目录里面，展开子目录的CMakeLists.txt
#同时执行，子目录中的CMakeLists.txt一般是编译成一个库，作为一个模块
#在父目录中可以直接引用子目录生成的库
add_subdirectory(base)
add_subdirectory(find)
add_subdirectory(pointer)
add_subdirectory(sort)
add_subdirectory(thread)
add_subdirectory(tree)
add_executable(algo ${SOURCE_FILES})
target_link_libraries(algo thread base sort find tree pointer)

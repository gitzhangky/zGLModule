cmake_minimum_required(VERSION 3.5)  #最低版本号

project(GLGui)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

add_library(GLGui ${ALL_SOURCE})

include_directories(${PROJECT_SOURCE_DIR}/../../openGL/include)

target_link_libraries(GLGui glad)

cmake_minimum_required(VERSION 3.5)  #最低版本号

project(Common)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

add_library(Common ${ALL_SOURCE})

target_link_libraries(Common ModelData )





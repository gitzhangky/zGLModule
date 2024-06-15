cmake_minimum_required(VERSION 3.5)  #最低版本号

project(ModelData)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

add_library(ModelData ${ALL_SOURCE})

target_link_libraries(ModelData glad glm )





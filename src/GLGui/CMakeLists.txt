cmake_minimum_required(VERSION 3.5)  #最低版本号

project(GLGui)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

file(GLOB Frag_FILES ${PROJECT_SOURCE_DIR}/../GLSL/Fragment/*.frag)  #片段着色器

file(GLOB Frag_FILES ${PROJECT_SOURCE_DIR}/../GLSL/Vetex/*.vex)  #顶点着色器

add_library(GLGui ${ALL_SOURCE} ${Frag_FILES} )

include_directories(${PROJECT_SOURCE_DIR}/../../thirdLib/glad/include)

target_link_libraries(GLGui glad)



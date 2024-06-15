cmake_minimum_required(VERSION 3.5)  #最低版本号

project(GLGui)
find_package(Qt5 COMPONENTS Widgets Gui OpenGL REQUIRED)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

file(GLOB Frag_FILES ${PROJECT_SOURCE_DIR}/../GLSL/Fragment/*.frag)  #片段着色器

file(GLOB Vetex_FILES ${PROJECT_SOURCE_DIR}/../GLSL/Vertex/*.vert)  #顶点着色器


add_library(GLGui ${ALL_SOURCE} ${Frag_FILES} ${Vetex_FILES} )

include_directories(${PROJECT_SOURCE_DIR}/../../thirdLib/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/../../thirdLib/glm-1.0.1/glm)

target_link_libraries(GLGui Qt5::Core Qt5::Widgets Qt5::Gui Qt5::OpenGL Common)



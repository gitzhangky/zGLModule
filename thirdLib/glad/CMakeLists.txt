cmake_minimum_required(VERSION 3.5)  #最低版本号

project(openGL_lib)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_library(glad STATIC ${PROJECT_SOURCE_DIR}/src/glad.c )

target_link_libraries(glad ${PROJECT_SOURCE_DIR}/lib/glfw3.lib)

set_property(TARGET glad PROPERTY FOLDER thidLib)
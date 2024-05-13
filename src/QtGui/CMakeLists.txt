cmake_minimum_required(VERSION 3.5)  #最低版本号

project(QtGui)

find_package(Qt5 COMPONENTS Widgets Gui OpenGL REQUIRED)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

add_library(QtGui ${ALL_SOURCE})

include_directories(${PROJECT_SOURCE_DIR}/../GLGui)

target_link_libraries(QtGui Qt5::Core Qt5::Widgets 
						Qt5::Gui Qt5::OpenGL GLGui)
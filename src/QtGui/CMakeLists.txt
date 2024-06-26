cmake_minimum_required(VERSION 3.5)  #最低版本号

project(QtGui)

find_package(Qt5 COMPONENTS Widgets Gui OpenGL REQUIRED)

file(GLOB ALL_SOURCE "*.c*" "*.h*")  #获取当前目录下所有源文件

file(GLOB QT_FORMS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)    #获取ui文件

QT5_WRAP_UI(QT_FORMS_H ${QT_FORMS})

qt5_add_resources(qrc_files ${CMAKE_CURRENT_SOURCE_DIR}/Resource.qrc)

add_library(QtGui ${ALL_SOURCE} ${QT_FORMS_H} ${qrc_files})
list(GET QT_FORMS_H 0 FIRST_ELEMENT)
get_filename_component(VAR ${FIRST_ELEMENT} DIRECTORY)

include_directories(${VAR})
include_directories(${PROJECT_SOURCE_DIR}/../GLGui)

target_link_libraries(QtGui Qt5::Core Qt5::Widgets 
						Qt5::Gui Qt5::OpenGL GLGui)
cmake_minimum_required(VERSION 3.5)  #最低版本号


project(zGLModule)     #创建项目名

set(openGL_Path ${PROJECT_SOURCE_DIR}/openGL)    #openGL路径
set(QtGui_Path ${PROJECT_SOURCE_DIR}/src/QtGui)    #QtGui路径
set(GLGui_Path ${PROJECT_SOURCE_DIR}/src/GLGui)    #QtGui路径
set(CommonData_Path ${PROJECT_SOURCE_DIR}/src/CommonData)    #QtGui路径

# 编译子文件夹的CMakeLists.txt
add_subdirectory(${openGL_Path})
add_subdirectory(${QtGui_Path})
add_subdirectory(${GLGui_Path})
add_subdirectory(${CommonData_Path})



# 规定.h头文件路径
include_directories(${openGL_Path}/include)           #设置包含头文件路径

# 生成可执行文件,其中WIN32用于去掉控制台
add_executable(zGLModule WIN32 main.cpp )  


# 链接操作
target_link_libraries(zGLModule 
     QtGui)
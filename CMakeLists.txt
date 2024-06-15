cmake_minimum_required(VERSION 3.5)  #最低版本号


project(zGLModule)     #创建项目名

set(openGL_Path ${PROJECT_SOURCE_DIR}/thirdLib/glad)    #glad三方库
set(glm_Path ${PROJECT_SOURCE_DIR}/thirdLib/glm-1.0.1)    #glm三方库
set(QtGui_Path ${PROJECT_SOURCE_DIR}/src/QtGui)    #QtGui路径
set(GLGui_Path ${PROJECT_SOURCE_DIR}/src/GLGui)    #GLGui路径
set(Common_Path ${PROJECT_SOURCE_DIR}/src/Common)    #Common路径
set(ModelData_Path ${PROJECT_SOURCE_DIR}/src/ModelData)    #Common路径

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 编译子文件夹的CMakeLists.txt
add_subdirectory(${openGL_Path})
add_subdirectory(${QtGui_Path})
add_subdirectory(${GLGui_Path})
add_subdirectory(${Common_Path})
add_subdirectory(${glm_Path})
add_subdirectory(${ModelData_Path})


# 规定.h头文件路径
include_directories(${openGL_Path}/include)           #设置包含头文件路径

# 生成可执行文件,其中WIN32用于去掉控制台
add_executable(zGLModule WIN32 main.cpp resourceFiles/icon.rc)  
#add_executable(zGLModule main.cpp )  

# 链接操作
target_link_libraries(zGLModule 
     QtGui)
	 
set_property(TARGET glad PROPERTY FOLDER thidLib)
set_property(TARGET glm PROPERTY FOLDER thidLib)
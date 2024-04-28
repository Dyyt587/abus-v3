cmake_minimum_required(VERSION 3.10)  # 必须
set(CMAKE_CXX_STANDARD 14)	# C++14

project(abus_v3)  #工程名

include_directories("/") # 头文件目录

#link_directories("/usr/local/lib/") # 链接库目录

aux_source_directory(. SRCS) # 源文件
# aux_source_directory(./abc SRCS)

set(CMAKE_C_FLAGS "-O1") # 设置C工程的 CFLAGS
set(CMAKE_CXX_FLAGS "-O0 -Werror") # 设置C++ 工程的 CXX_FLAGS

add_executable(${PROJECT_NAME} ${SRCS}) # 生成可执行文件，这里程序名即为功能名


# 下面使用install作为项目打包使用

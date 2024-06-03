# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.7)

# Set the project name
project (example)

 
aux_source_directory(. ALL_SRCS)			# 添加当前目录下所有的源文件

add_library(example ${ALL_SRCS})


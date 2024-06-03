cmake_minimum_required (VERSION 3.7)

project(abus_v3)
set(C_STANDARD 11)


# # 指定生成目标 
# add_executable(exampple ./example)
# # 生成链接库
# add_library (exampple ${DIR_LIB_SRCS})

add_subdirectory(src)
add_subdirectory(example)

aux_source_directory(./example ALL_SRCS)			# 添加当前目录下所有的源文件
add_executable(abus_v3 ${ALL_SRCS})	# 指定生成目标，注意这里要用${ALL_SRCS}!!!
target_link_libraries(abus_v3 example)	# 添加链接库，power是在math子目录的CMakeLists中定义的
target_link_libraries(abus_v3 abus)	# 添加链接库，power是在math子目录的CMakeLists中定义的


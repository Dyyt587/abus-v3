# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject1 "abus_v3.cpp" "abus_v3.h"  "abus_topic.c" "abus_hash.c" "abus_acc.c" "abus.h" "abus_port.h" 
"afifo.c" "cvector.c" "all_check.c" "cvector.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。


# Set the project name
cmake_minimum_required (VERSION 3.7)

aux_source_directory(. ALL_SRCS)			# 添加当前目录下所有的源文件

add_library(abus ${ALL_SRCS})


# Add support for installation
include(CMakePackageConfigHelpers)

include(GNUInstallDirs) 
# Install headers
install(DIRECTORY . DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.h")
# Install library
install(TARGETS abus
  EXPORT ${PROJECT_NAME}-targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

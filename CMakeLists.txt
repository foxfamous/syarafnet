# project
cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME "newelas")
project( ${PROJECT_NAME} )

#package
find_package( OpenCV REQUIRED )

#libraries
set(GL_S0 "/usr/lib64/libGL.so.1" "/usr/lib64/libglut.so" "/lib64/libGLU.so.1")
set(PTHREAD_SO "/lib64/libpthread.so.0")

# directories
set (SRC_DIR src)

# include directory
include_directories("${SRC_DIR}")

# use sse3 instruction set
SET(CMAKE_CXX_FLAGS "-msse3")

# sources
FILE(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# make release version
set(CMAKE_BUILD_TYPE Release)

add_executable( ${PROJECT_NAME} ${SRC_FILES} )

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${GL_S0} ${PTHREAD_SO})

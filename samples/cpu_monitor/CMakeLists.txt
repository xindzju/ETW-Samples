cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME cpu_monitor)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB CPU_MONITOR_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

include_directories(./samples/cpu_monitor/src)

add_executable(${TARGET_NAME} ${CPU_MONITOR_SRC})
cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME etw_sample)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./samples/cpu_monitor)
add_subdirectory(./samples/logman)
add_subdirectory(./samples/etw_consumer)
add_subdirectory(./samples/enumerate_provider)
add_subdirectory(./samples/retrieve_metadata)

file(GLOB ETW_SAMPLES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

include_directories(./src)
include_directories(./external/PresentMon/PresentData)

add_executable(${TARGET_NAME} ${ETW_SAMPLES_SRC})
cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME ETW_Samples)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB ETW_SAMPLES_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

include_directories(./src)
include_directories(./external/PresentMon/PresentData)

add_executable(${TARGET_NAME} ${ETW_SAMPLES_SRC})
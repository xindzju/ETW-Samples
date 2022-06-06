cmake_minimum_required(VERSION 3.10)
set(TARGET_NAME enumerate_provider)
project(${TARGET_NAME} LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB LOGMAN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

include_directories(./samples/enumerate_provider/src)

add_executable(${TARGET_NAME} ${LOGMAN_SRC})
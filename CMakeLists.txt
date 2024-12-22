cmake_minimum_required(VERSION 3.25)
project(perlin_color)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.c)
add_library(noise SHARED noise.c)
add_library(screentools SHARED screentools.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} noise)
target_link_libraries(${PROJECT_NAME} screentools)
cmake_minimum_required(VERSION 3.25)
project(perlin_color)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.c)
add_library(noise SHARED noise.c)
add_library(screentools SHARED screentools.c)
add_library(colormap SHARED colormap.c)
add_library(load_palettes SHARED load_palettes.c)

target_compile_options(${PROJECT_NAME} PRIVATE -g)
target_compile_options(noise PRIVATE -g)
target_compile_options(screentools PRIVATE -g)
target_compile_options(colormap PRIVATE -g)
target_compile_options(load_palettes PRIVATE -g)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} noise)
target_link_libraries(${PROJECT_NAME} screentools)
target_link_libraries(${PROJECT_NAME} colormap)
target_link_libraries(colormap noise)
target_link_libraries(colormap load_palettes)


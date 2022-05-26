cmake_minimum_required(VERSION 3.14)

project(oled-graphics LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(oled-graphics SHARED
  oled-graphics_global.h
  oledgraphics.cpp
  oledgraphics.h
  include/display.h
  src/display.c
  include/display_comm.h
)

target_include_directories(oled-graphics
    PUBLIC include)

target_compile_definitions(oled-graphics PRIVATE OLEDGRAPHICS_LIBRARY)

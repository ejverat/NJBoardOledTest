cmake_minimum_required(VERSION 3.14)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

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
  include/ssd1322.h
  src/ssd1322.c
  include/queue.h
  src/queue.c
  include/ssd1322_def.h
  include/ssd1322_cmd.h
  src/ssd1322_cmd.c
  include/NHD-312-25664UCB2.h
  include/graphic2d_objects.h
  src/NHD-312-25664UCB2.c
  include/gdisplay.h
  include/gdisplay_driver.h
  include/timer.h
  include/ssd1322_utils.h
  include/ssd1306_def.h
  include/ssd1306_cmd.h
  src/ssd1306_cmd.c
  include/ssd1306.h
  include/ssd1306_utils.h
  include/fetcher.h
  src/fetcher.c
  src/ssd1306.c
  include/display_ssd1306.h
  src/display_ssd1306.c
)

target_include_directories(oled-graphics
    PUBLIC include)

target_compile_definitions(oled-graphics PRIVATE OLEDGRAPHICS_LIBRARY)

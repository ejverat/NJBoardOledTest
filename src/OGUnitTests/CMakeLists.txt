cmake_minimum_required(VERSION 3.5)

project(OledGraphicsUnitTests LANGUAGES CXX)

enable_testing()


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "/home/evera/Software/googletest-release-1.11.0" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "/home/evera/Software/googletest-release-1.11.0")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes}
                        ${CMAKE_CURRENT_LIST_DIR}/../oled-graphics/src)

add_executable(OledGraphicsUnitTests main.cpp
                tst_createdisplaywithwidthorheightzeroreturnserror.cpp
                src/tst_display_comm.cpp
                src/tst_ssd1322.cpp
                src/tst_queue.cpp
                src/tst_nhd31125664ucb2.cpp
                src/tst_ssd1322_utils.cpp
                src/tst_ssd1306_utils.cpp
                src/tst_ssd1306_generic_display.cpp
                src/tst_ssd1306_pixels_fetcher.cpp
               ${GTestFiles})
add_test(NAME OledGraphicsUnitTests COMMAND OledGraphicsUnitTests)
target_link_libraries(OledGraphicsUnitTests PRIVATE Threads::Threads
                        PUBLIC oled-graphics)


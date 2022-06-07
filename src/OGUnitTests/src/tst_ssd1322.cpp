#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <sstream>
#include <string>


extern "C"{

#include "ssd1322.h"
#include "timer.h"
#include "display_comm.h"
#include "ssd1322_cmd.c"

}

using namespace testing;

display_comm_t commSpy;
waiter_t waiter_test;
std::ostringstream spiedStream;

bool init_test()
{
    spiedStream << "I";
    return true;
}

void enable_test()
{
    spiedStream << "E";
}

void disable_test()
{
    spiedStream << "S";
}

void start_reset_test()
{
    spiedStream << "sr";
}

void end_reset_test()
{
    spiedStream << "er";
}

void enable_cmd_test()
{
    spiedStream << "ec";
}

void disable_cmd_test()
{
    spiedStream << "dc";
}

void enable_data_test()
{
    spiedStream << "ed";
}

void disable_data_test()
{
    spiedStream << "dd";
}

bool send_byte_test(uint8_t byte)
{
    spiedStream << (unsigned int)byte;

    return true;
}

void wait_ms_tst(uint16_t ms)
{
    spiedStream << "W" << (unsigned int)ms;
}

void TestSetup()
{
    commSpy.init_fn = init_test;
    commSpy.enable_fn = enable_test;
    commSpy.disable_fn = disable_test;
    commSpy.start_reset_fn = start_reset_test;
    commSpy.end_reset_fn = end_reset_test;
    commSpy.enable_cmd_fn = enable_cmd_test;
    commSpy.disable_cmd_fn = disable_cmd_test;
    commSpy.enable_data_fn = enable_data_test;
    commSpy.disable_data_fn = disable_data_test;
    commSpy.send_byte_fn = send_byte_test;

    waiter_test.wait_ms = wait_ms_tst;

    spiedStream.flush();
    gdisplay_driver_t driver;
    ssd1322_setup(&driver,&commSpy,&waiter_test);
}

TEST(ssd1322, nothing)
{
    TestSetup();

    bool status = ssd1322_init();
    std::string spiedStr = spiedStream.str();
    ASSERT_EQ(status,true);
}

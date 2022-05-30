#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "ssd1322.h"
#include "ssd1322.c"
#include "display_comm.h"

using namespace testing;

static display_payload_t payload = display_comm_default;
static display_comm_t comm;
std::string events_str;

void set_command_bit(bool cmd)
{
    events_str += "c";
    events_str += std::to_string(static_cast<int>(cmd));
}

TEST(SSD1322, SendCommandSetCommandBitTrue)
{
    ssd1322_set_command_bit_handler(ssd1322_instance(),set_command_bit);

    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    payload.isCommand = true;

    comm.send_cmd_fn = ssd1322_send_command;
    comm.send_data_fn = ssd1322_send_data;

    events_str = "";

    bool result = display_comm_send(&comm,&payload);
    ASSERT_EQ(events_str,"c1");
    ASSERT_EQ(result,true);
}

TEST(SSD1322, SendCommandSetCommandBitFalse)
{
    ssd1322_set_command_bit_handler(ssd1322_instance(),set_command_bit);

    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    payload.isCommand = false;

    comm.send_cmd_fn = ssd1322_send_command;
    comm.send_data_fn = ssd1322_send_data;

    events_str = "";

    bool result = display_comm_send(&comm,&payload);
    ASSERT_EQ(events_str,"c0");
    ASSERT_EQ(result,true);
}

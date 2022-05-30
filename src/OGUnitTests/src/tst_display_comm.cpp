#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>
#include "display_comm.h"

using namespace testing;

static display_payload_t payload = display_comm_default;
static display_comm_t comm;

std::string cmd_call_str = "";
std::string data_call_str = "";

bool test_send_cmd(uint8_t* buffer, uint16_t size)
{
    cmd_call_str += "c";
    return true;
}

bool test_send_data(uint8_t* buffer, uint16_t size)
{
    data_call_str += "c";
    return true;
}

TEST(DisplayComm, IfDispCommIsNullOnSendingReturnFalse)
{
    bool result = display_comm_send(NULL,&payload);

    ASSERT_EQ(result,false);
}

TEST(DisplayComm, IfPayloadIsNullOnSendingReturnFalse)
{
    bool result = display_comm_send(&comm,NULL);

    ASSERT_EQ(result,false);
}

TEST(DisplayComm, IfPayloadBufferIsNullReturnFalse)
{

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(result,false);
}

TEST(DisplayComm, IfFunctionSendCommandIsNullReturnFalse)
{
    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    comm.send_cmd_fn = NULL;

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(result,false);
}

TEST(DisplayComm, IfFunctionSendDataIsNullReturnFalse)
{
    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;

    comm.send_cmd_fn = test_send_cmd;
    comm.send_data_fn = NULL;

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(result,false);
}


TEST(DisplayComm, IfPayloadBufferSizeIsZeroReturnTrue)
{
    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    comm.send_cmd_fn = test_send_cmd;
    comm.send_data_fn = test_send_data;

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(result,true);
}

TEST(DisplayComm, IfPayloadsFlagIsCommandTrueThenSendCommandFunctionIsCalled)
{
    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    payload.isCommand = true;

    comm.send_cmd_fn = test_send_cmd;
    comm.send_data_fn = test_send_data;

    cmd_call_str = "";

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(cmd_call_str,"c");
    EXPECT_EQ(result,true);
}

TEST(DisplayComm, IfPayloadsFlagIsCommandFalseThenSendDataFunctionIsCalled)
{
    uint8_t buff;

    payload.buffer = &buff;
    payload.size = 0;
    payload.isCommand = false;

    comm.send_cmd_fn = test_send_cmd;
    comm.send_data_fn = test_send_data;

    data_call_str = "";

    bool result = display_comm_send(&comm,&payload);

    ASSERT_EQ(data_call_str,"c");
    EXPECT_EQ(result,true);
}

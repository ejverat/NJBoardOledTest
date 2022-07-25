#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <sstream>
#include <string>

std::stringstream calls;

extern "C"{

#include "ssd1306.h"
#include "ssd1306.c"
#include "ssd1306_cmd.h"
#include "ssd1306_cmd.c"
#include "timer.h"
#include "display_ssd1306.h"
#include "display_ssd1306.c"
#include "display_comm.h"
#include "gdisplay.h"

gdisplay_t fakeDisp;
display_comm_t fakeComm;
waiter_t fakeTimer;

}

bool fakeClear(area2d_t* area)
{
    calls << "C{(" << area->start_row << "," << area->end_row << "),"
          << "(" << area->start_col << "," << area->end_col << ")}";
    return true;
}

bool fakeDraw(pos2d_t* p, graphic_t* g)
{
    calls << "D{(" << p->row << "," << p->col << "),"
          << "(" << g->width << "," << g->height << "," << g->pixel_bit_size << ")}";
    return true;
}

bool fakeInitComm()
{
    calls << "Ic";
    return true;
}

void fakeEnableComm()
{
    calls << "Ec";
}

void fakeDisableComm()
{
    calls << "Dc";
}

void fakeStartResetComm()
{
    calls << "Src";
}

void fakeEndResetComm()
{
    calls << "Erc";
}

void fakeEnableCmdComm()
{
    calls << "Ecc";
}

void fakeDisableCmdComm()
{
    calls << "Dcc";
}

void fakeEnableDataComm()
{
    calls << "Edc";
}

void fakeDisableDataComm()
{
    calls << "Ddc";
}

bool fakeSendByte(uint8_t byte)
{
    calls << "B{" << (int)byte << "}";
    return true;
}

void fakeWait(uint16_t t)
{
    calls << "W{" << (int)t << "}";
}

using namespace testing;

TEST(ssd1306_generic_display,initDisp)
{
    fakeDisp.clear_fn = fakeClear;
    fakeDisp.draw_fn = fakeDraw;
    fakeComm.disable_cmd_fn = fakeDisableCmdComm;
    fakeComm.disable_data_fn = fakeDisableDataComm;
    fakeComm.enable_data_fn = fakeEnableDataComm;
    fakeComm.disable_fn = fakeDisableComm;
    fakeComm.enable_cmd_fn = fakeEnableCmdComm;
    fakeComm.enable_fn = fakeEnableComm;
    fakeComm.end_reset_fn = fakeEndResetComm;
    fakeComm.start_reset_fn = fakeStartResetComm;
    fakeComm.init_fn = fakeInitComm;
    fakeComm.send_byte_fn = fakeSendByte;

    fakeTimer.wait_ms = fakeWait;

    calls << std::flush;
    std::string Str;

    display_ssd1306_setup(&fakeDisp,&fakeComm,&fakeTimer);

    EXPECT_TRUE(display_ssd1306_init(128,64));
    Str = calls.str();
}

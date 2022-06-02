
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "display.h"
#include "display.c"

using namespace testing;

TEST(DisplayType, DisplayStructStoresWidthAndHeight)
{
    display_t disp;

    uint16_t width = 128;
    uint16_t height = 128;

    bool result = set_display_size(&disp,width,height);

    ASSERT_EQ(disp.width, width);
    ASSERT_EQ(disp.height, height);
    ASSERT_EQ(result,true);

}

TEST(DisplayType, SetDisplaySizeWithWidthAndHeighGreaterThanZeroReturnsTrue)
{
    display_t disp;

    uint16_t width = 128;
    uint16_t height = 128;

    bool result = set_display_size(&disp,width,height);

    ASSERT_EQ(result,true);
}

TEST(DisplayType, SetDisplaySizeWithWidthOrHeightZeroReturnsFalse)
{
    display_t disp;
    bool result1 = set_display_size(&disp,0,0);
    bool result2 = set_display_size(&disp,1,0);
    bool result3 = set_display_size(&disp,0,1);
    ASSERT_EQ(result1, false);
    ASSERT_EQ(result2, false);
    ASSERT_EQ(result3, false);
}

TEST(DisplayType, SetDisplaySizeWithDisplayPointerNullReturnsFalse)
{
    bool result = set_display_size(NULL,128,128);

    ASSERT_EQ(result,false);
}

static bool clearFunctionWasCalled = false;

static bool Clear()
{
    clearFunctionWasCalled = true;
    return true;
}

TEST(DisplayType, GIVEN_ADisplay_WHEN_ClearFunctionIsCalled_THEN_ClearPointerFunctionShouldBeCalled)
{
    display_t disp;
    disp.clear_fn = Clear;

    clearFunctionWasCalled = false;

    display_clear(&disp);

    ASSERT_EQ(clearFunctionWasCalled,true);
}

TEST(DisplayType, GIVEN_ADisplay_WHEN_DrawFunctionIsCalled_THEN_DrawPointerFunctionShouldBeCalled)
{
    display_t disp;
    image_t img;
    disp.draw_fn = Draw;

    drawFunctionWasCalled = false;

    display_draw(&disp,&img,)
}


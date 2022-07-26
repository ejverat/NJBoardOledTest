#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


extern "C"{

#include "ssd1306_utils.h"

}

TEST(ssd1306_utils,GIVEN_row0to7_WHEN_row2page_is_called_THEN_return0)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        ASSERT_EQ(0,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row8to15_WHEN_row2page_is_called_THEN_return1)
{
    for (uint8_t i = 8; i < 16; i++)
    {
        ASSERT_EQ(1,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row16to23_WHEN_row2page_is_called_THEN_return2)
{
    for (uint8_t i = 16; i < 24; i++)
    {
        ASSERT_EQ(2,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row24to31_WHEN_row2page_is_called_THEN_return3)
{
    for (uint8_t i = 24; i < 31; i++)
    {
        ASSERT_EQ(3,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row32to39_WHEN_row2page_is_called_THEN_return4)
{
    for (uint8_t i = 32; i < 40; i++)
    {
        ASSERT_EQ(4,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row40to47_WHEN_row2page_is_called_THEN_return5)
{
    for (uint8_t i = 40; i < 48; i++)
    {
        ASSERT_EQ(5,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row48to55_WHEN_row2page_is_called_THEN_return6)
{
    for (uint8_t i = 48; i < 56; i++)
    {
        ASSERT_EQ(6,ssd1306_row2page(i));
    }
}

TEST(ssd1306_utils,GIVEN_row56to63_WHEN_row2page_is_called_THEN_return7)
{
    for (uint8_t i = 56; i < 64; i++)
    {
        ASSERT_EQ(7,ssd1306_row2page(i));
    }
}

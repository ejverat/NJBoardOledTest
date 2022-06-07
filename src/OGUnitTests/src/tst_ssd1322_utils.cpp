#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>


extern "C"{

#include "ssd1322_utils.h"

}

TEST(ssd1322_utils, GIVEN_AnPixelColPositionAndAnOffsetColInAddresFormatEqualZero_WHEN_ColPixelToAddresIsCalled_THEN_ReturnTheColAddresForThePixel)
{
    ASSERT_EQ(ssd1322_col_pixel_to_address(0,0),0);
    ASSERT_EQ(ssd1322_col_pixel_to_address(1,0),0);
    ASSERT_EQ(ssd1322_col_pixel_to_address(2,0),0);
    ASSERT_EQ(ssd1322_col_pixel_to_address(3,0),0);
    ASSERT_EQ(ssd1322_col_pixel_to_address(4,0),1);
    ASSERT_EQ(ssd1322_col_pixel_to_address(5,0),1);
    ASSERT_EQ(ssd1322_col_pixel_to_address(6,0),1);
    ASSERT_EQ(ssd1322_col_pixel_to_address(7,0),1);
    ASSERT_EQ(ssd1322_col_pixel_to_address(8,0),2);
    ASSERT_EQ(ssd1322_col_pixel_to_address(9,0),2);
    ASSERT_EQ(ssd1322_col_pixel_to_address(10,0),2);
    ASSERT_EQ(ssd1322_col_pixel_to_address(11,0),2);
    ASSERT_EQ(ssd1322_col_pixel_to_address(472,0),0x76);
    ASSERT_EQ(ssd1322_col_pixel_to_address(473,0),0x76);
    ASSERT_EQ(ssd1322_col_pixel_to_address(474,0),0x76);
    ASSERT_EQ(ssd1322_col_pixel_to_address(475,0),0x76);
    ASSERT_EQ(ssd1322_col_pixel_to_address(476,0),0x77);
    ASSERT_EQ(ssd1322_col_pixel_to_address(477,0),0x77);
    ASSERT_EQ(ssd1322_col_pixel_to_address(478,0),0x77);
    ASSERT_EQ(ssd1322_col_pixel_to_address(479,0),0x77);
}

TEST(ssd1322_utils, GIVEN_AnPixelColPositionAndAnOffsetColInAddresFormatEqual1C_WHEN_ColPixelToAddresIsCalled_THEN_ReturnTheColAddresForThePixel)
{
    ASSERT_EQ(ssd1322_col_pixel_to_address(0,0x1C),0x1C);
    ASSERT_EQ(ssd1322_col_pixel_to_address(1,0x1C),0x1C);
    ASSERT_EQ(ssd1322_col_pixel_to_address(2,0x1C),0x1C);
    ASSERT_EQ(ssd1322_col_pixel_to_address(3,0x1C),0x1C);
    ASSERT_EQ(ssd1322_col_pixel_to_address(4,0x1C),0x1D);
    ASSERT_EQ(ssd1322_col_pixel_to_address(5,0x1C),0x1D);
    ASSERT_EQ(ssd1322_col_pixel_to_address(6,0x1C),0x1D);
    ASSERT_EQ(ssd1322_col_pixel_to_address(7,0x1C),0x1D);
    ASSERT_EQ(ssd1322_col_pixel_to_address(8,0x1C),0x1E);
    ASSERT_EQ(ssd1322_col_pixel_to_address(9,0x1C),0x1E);
    ASSERT_EQ(ssd1322_col_pixel_to_address(10,0x1C),0x1E);
    ASSERT_EQ(ssd1322_col_pixel_to_address(11,0x1C),0x1E);
    ASSERT_EQ(ssd1322_col_pixel_to_address(248,0x1C),0x5A);
    ASSERT_EQ(ssd1322_col_pixel_to_address(249,0x1C),0x5A);
    ASSERT_EQ(ssd1322_col_pixel_to_address(250,0x1C),0x5A);
    ASSERT_EQ(ssd1322_col_pixel_to_address(251,0x1C),0x5A);
    ASSERT_EQ(ssd1322_col_pixel_to_address(252,0x1C),0x5B);
    ASSERT_EQ(ssd1322_col_pixel_to_address(253,0x1C),0x5B);
    ASSERT_EQ(ssd1322_col_pixel_to_address(254,0x1C),0x5B);
    ASSERT_EQ(ssd1322_col_pixel_to_address(255,0x1C),0x5B);
}

TEST(ssd1322_utils, GIVEN_AnPixelRowPositionAndAnOffsetRowInAddresFormatEqualZero_WHEN_RowPixelToAddresIsCalled_THEN_ReturnTheRowAddresForThePixel)
{
    ASSERT_EQ(ssd1322_row_pixel_to_address(0,0),0);
    ASSERT_EQ(ssd1322_row_pixel_to_address(1,0),1);
    ASSERT_EQ(ssd1322_row_pixel_to_address(2,0),2);
    ASSERT_EQ(ssd1322_row_pixel_to_address(3,0),3);
    ASSERT_EQ(ssd1322_row_pixel_to_address(4,0),4);
    ASSERT_EQ(ssd1322_row_pixel_to_address(5,0),5);
    ASSERT_EQ(ssd1322_row_pixel_to_address(6,0),6);
    ASSERT_EQ(ssd1322_row_pixel_to_address(7,0),7);
    ASSERT_EQ(ssd1322_row_pixel_to_address(8,0),8);
    ASSERT_EQ(ssd1322_row_pixel_to_address(9,0),9);
    ASSERT_EQ(ssd1322_row_pixel_to_address(10,0),10);
    ASSERT_EQ(ssd1322_row_pixel_to_address(11,0),11);
    ASSERT_EQ(ssd1322_row_pixel_to_address(124,0),124);
    ASSERT_EQ(ssd1322_row_pixel_to_address(125,0),125);
    ASSERT_EQ(ssd1322_row_pixel_to_address(126,0),126);
    ASSERT_EQ(ssd1322_row_pixel_to_address(127,0),127);
}

TEST(ssd1322_utils, GIVEN_AnPixelRowPositionAndAnOffsetRowInAddresFormatEqual1_WHEN_RowPixelToAddresIsCalled_THEN_ReturnTheRowAddresForThePixel)
{
    ASSERT_EQ(ssd1322_row_pixel_to_address(0,1),1);
    ASSERT_EQ(ssd1322_row_pixel_to_address(1,1),2);
    ASSERT_EQ(ssd1322_row_pixel_to_address(2,1),3);
    ASSERT_EQ(ssd1322_row_pixel_to_address(3,1),4);
    ASSERT_EQ(ssd1322_row_pixel_to_address(4,1),5);
    ASSERT_EQ(ssd1322_row_pixel_to_address(5,1),6);
    ASSERT_EQ(ssd1322_row_pixel_to_address(6,1),7);
    ASSERT_EQ(ssd1322_row_pixel_to_address(7,1),8);
    ASSERT_EQ(ssd1322_row_pixel_to_address(8,1),9);
    ASSERT_EQ(ssd1322_row_pixel_to_address(9,1),10);
    ASSERT_EQ(ssd1322_row_pixel_to_address(10,1),11);
    ASSERT_EQ(ssd1322_row_pixel_to_address(11,1),12);
    ASSERT_EQ(ssd1322_row_pixel_to_address(124,1),125);
    ASSERT_EQ(ssd1322_row_pixel_to_address(125,1),126);
    ASSERT_EQ(ssd1322_row_pixel_to_address(126,1),127);
    ASSERT_EQ(ssd1322_row_pixel_to_address(127,1),128);
}

TEST(ssd1322_utils, GIVEN_EndColMinusStartColLessThan4OrEndRowMinusStartRowLessThan4_WHEN_WordsToSendIsCalledShouldReturn0)
{
    ASSERT_EQ(ssd1322_words_to_send(0,0,0,0),0);
    ASSERT_EQ(ssd1322_words_to_send(0,1,0,0),0);
    ASSERT_EQ(ssd1322_words_to_send(0,2,0,0),0);
    ASSERT_EQ(ssd1322_words_to_send(0,3,0,0),0);
    ASSERT_EQ(ssd1322_words_to_send(0,0,0,1),0);
    ASSERT_EQ(ssd1322_words_to_send(0,0,0,2),0);
    ASSERT_EQ(ssd1322_words_to_send(0,0,0,3),0);
}

TEST(ssd1322_utils, GIVEN_EndColMinusStartCol4AndEndRowMinusStartRow1_WHEN_WordsToSendIsCalledShouldReturn1)
{
    ASSERT_EQ(ssd1322_words_to_send(0,4,0,1),1);
    ASSERT_EQ(ssd1322_words_to_send(0,5,0,1),1);
    ASSERT_EQ(ssd1322_words_to_send(0,6,0,1),1);
    ASSERT_EQ(ssd1322_words_to_send(0,7,0,1),1);
}

TEST(ssd1322_utils, GIVEN_EndColMinusStartCol4To7AndEndRowMinusStartRow4_WHEN_WordsToSendIsCalledShouldReturn4)
{
    ASSERT_EQ(ssd1322_words_to_send(0,4,0,4),4);
    ASSERT_EQ(ssd1322_words_to_send(0,5,0,4),4);
    ASSERT_EQ(ssd1322_words_to_send(0,6,0,4),4);
    ASSERT_EQ(ssd1322_words_to_send(0,7,0,4),4);
}

TEST(ssd1322_utils, GIVEN_EndColMinusStartCol480AndEndRowMinusStartRow128_WHEN_WordsToSendIsCalledShouldReturn15360)
{
    ASSERT_EQ(ssd1322_words_to_send(0,480,0,128),15360);
}

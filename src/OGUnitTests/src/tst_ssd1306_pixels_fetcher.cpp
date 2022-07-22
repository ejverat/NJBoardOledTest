#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
#include "fetcher.h"
#include "fetcher.c"

const uint8_t test_array_8x8[] =
{
    0b00010000,
    0b00000111,
    0b01100000,
    0b00000101,
    0b00100000,
    0b00000011,
    0b01000000,
    0b00000001
};

graphic_t test_image_8x8 =
{
    8,8,(const uint8_t*)&test_array_8x8[0],1
};

const uint8_t test_array_8x4[]
{
    0b00100000,
    0b00000011,
    0b01000000,
    0b00000001
};

graphic_t test_image_8x4 =
{
    8,4,(const uint8_t*)&test_array_8x4[0],1
};

const uint8_t test_array_16x4[]
{
    0b00000111,0b00010000,
    0b00000101,0b01100000,
    0b00000011,0b00100000,
    0b00000001,0b01000000
};

graphic_t test_image_16x4 =
{
    16,4,(const uint8_t*)&test_array_16x4[0],1
};

const uint8_t test_array_8x16[] =
{
    0b00010000,
    0b00000111,
    0b01100000,
    0b00000101,
    0b00100000,
    0b00000011,
    0b01000000,
    0b00000001,
    0b00010000,
    0b00000111,
    0b01100000,
    0b00000101,
    0b00100000,
    0b00000011,
    0b01000000,
    0b00000001
};

graphic_t test_image_8x16 =
{
    8,16,(const uint8_t*)&test_array_8x16[0],1
};

}

TEST(ssd1306_fecther, fetch_bytes_in_range)
{
    uint8_t byte;
    pos2d_t pos;
    pos.row = 0;
    pos.col = 0;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0x00);
    pos.col = 1;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b01000100);
    pos.col = 2;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00010100);
    pos.col = 3;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00000001);
    pos.col = 4;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 5;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00001010);
    pos.col = 6;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00100010);
    pos.col = 7;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b10101010);


    pos.col = 0;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0x00);
    pos.col = 1;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000100);
    pos.col = 2;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000001);
    pos.col = 3;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 4;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 5;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 6;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00000010);
    pos.col = 7;
    byte = fetch_vertical_byte(&test_image_8x4,&pos);
    EXPECT_EQ(byte,0b00001010);

    pos.col = 0;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 1;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 2;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 3;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 4;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 5;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000011);
    pos.col = 6;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00000101);
    pos.col = 7;
    byte = fetch_vertical_byte(&test_image_16x4,&pos);
    EXPECT_EQ(byte,0b00001111);

    pos.row = 8;
    pos.col = 0;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0x00);
    pos.col = 1;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b01000100);
    pos.col = 2;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b00010100);
    pos.col = 3;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b00000001);
    pos.col = 4;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.col = 5;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b00001010);
    pos.col = 6;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b00100010);
    pos.col = 7;
    byte = fetch_vertical_byte(&test_image_8x16,&pos);
    EXPECT_EQ(byte,0b10101010);
}

TEST(ssd1308_fetcher,fetch_outrange_bytes_from_rowsize8)
{
    uint8_t byte;
    pos2d_t pos;

    pos.row = 0;
    pos.col = 8;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0);
    pos.col = 100;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0);
    pos.row = 100;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0);

    pos.row = 7;
    pos.col = 3;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00000000);
    pos.row = 2;
    pos.col = 7;
    byte = fetch_vertical_byte(&test_image_8x8,&pos);
    EXPECT_EQ(byte,0b00101010);
}

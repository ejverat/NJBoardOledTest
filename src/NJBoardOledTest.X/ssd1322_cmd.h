/* 
 * File:   ssd1322_cmd.h
 * Author: evera
 *
 * Created on December 15, 2021, 12:59 AM
 */

#ifndef SSD1322_CMD_H
#define	SSD1322_CMD_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum 
{
	SSD1322_CMD_ENABLE_GS_TABLE = 0x00,
	SSD1322_CMD_SET_COLUMN_ADDRESS = 0x15,
	SSD1322_CMD_WRITE_RAM = 0x5C,
	SSD1322_CMD_READ_RAM = 0x5D,
	SSD1322_CMD_SET_ROW_ADDRESS = 0x75,
	SSD1322_CMD_SET_REMAP_DUAL_COM = 0xA0,
	SSD1322_CMD_SET_DISPLAY_START_L = 0xA1,
	SSD1322_CMD_SET_DISPLAY_OFFSET = 0xA2,
	SSD1322_CMD_SET_DISPLAY_MODE_N = 0xA4,
	SSD1322_CMD_SET_DISPLAY_MODE_EON = 0xA5,
	SSD1322_CMD_SET_DISPLAY_MODE_EOFF = 0xA6,
	SSD1322_CMD_SET_DISPLAY_MODE_INV = 0xA7,
	SSD1322_CMD_ENABLE_PARTIAL_DISPLAY = 0xA8,
	SSD1322_CMD_EXIT_PARTIAL_DISPLAY = 0xA9,
	SSD1322_CMD_SET_FUNCTION_SEL = 0xAB,
	SSD1322_CMD_DISPLAY_OFF = 0xAE,
	SSD1322_CMD_DISPLAY_ON = 0xAF,
	SSD1322_CMD_SET_PHASE_L = 0xB1,
	SSD1322_CMD_SET_FCD_OSCFREQ = 0xB3,
	SSD1322_CMD_DISPLAY_ENH_A = 0xB4,
	SSD1322_CMD_SET_GPIO = 0xB5,
	SSD1322_CMD_SET_2ND_PRE_PERIOD = 0xB6,
	SSD1322_CMD_SET_GS_TABLE = 0xB8,
	SSD1322_CMD_SEL_DEF_LIN_GS_TABLE = 0xB9,
	SSD1322_CMD_SET_PRE_CHARGE_V = 0xBB,
	SSD1322_CMD_SET_VCOMH = 0xBE,
	SSD1322_CMD_SET_CONTRAST_CURR = 0xC1,
	SSD1322_CMD_MASTER_CURR_CONTROL = 0xC7,
	SSD1322_CMD_SET_MULT_RATIO = 0xCA,
	SSD1322_CMD_DISPLAY_ENH_B = 0xD1,
	SSD1322_CMD_LOCK = 0xFD,
} ssd1322_cmd_t;


#ifdef	__cplusplus
}
#endif

#endif	/* SSD1322_CMD_H */


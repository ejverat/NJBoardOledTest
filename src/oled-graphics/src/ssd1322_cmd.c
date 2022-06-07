#include "ssd1322_cmd.h"
#include "ssd1322.h"

uint8_t ssd1322_cmd_num_params(ssd1322_cmd_t cmd)
{
    uint8_t num_params = 0;
    switch(cmd)
    {
        /*case SSD1322_CMD_ENABLE_GS_TABLE:
        case SSD1322_CMD_WRITE_RAM:
        case SSD1322_CMD_READ_RAM:
        case SSD1322_CMD_SET_DISPLAY_MODE_N:
        case SSD1322_CMD_SET_DISPLAY_MODE_EON:
        case SSD1322_CMD_SET_DISPLAY_MODE_EOFF:
        case SSD1322_CMD_SET_DISPLAY_MODE_INV:
        case SSD1322_CMD_EXIT_PARTIAL_DISPLAY:
        case SSD1322_CMD_DISPLAY_OFF:
        case SSD1322_CMD_DISPLAY_ON:
        case SSD1322_CMD_SEL_DEF_LIN_GS_TABLE:
            num_params = 0;
        break;*/
        case SSD1322_CMD_SET_COLUMN_ADDRESS:
        case SSD1322_CMD_SET_ROW_ADDRESS:
        case SSD1322_CMD_SET_REMAP_DUAL_COM:
        case SSD1322_CMD_ENABLE_PARTIAL_DISPLAY:
        case SSD1322_CMD_DISPLAY_ENH_A:
        case SSD1322_CMD_DISPLAY_ENH_B:
            num_params = 2;
        break;
        case SSD1322_CMD_SET_DISPLAY_START_L:
        case SSD1322_CMD_SET_DISPLAY_OFFSET:
        case SSD1322_CMD_SET_FUNCTION_SEL:
        case SSD1322_CMD_SET_PHASE_L:
        case SSD1322_CMD_SET_FCD_OSCFREQ:
        case SSD1322_CMD_SET_GPIO:
        case SSD1322_CMD_SET_2ND_PRE_PERIOD:
        case SSD1322_CMD_SET_PRE_CHARGE_V:
        case SSD1322_CMD_SET_VCOMH:
        case SSD1322_CMD_SET_CONTRAST_CURR:
        case SSD1322_CMD_MASTER_CURR_CONTROL:
        case SSD1322_CMD_SET_MULT_RATIO:
        case SSD1322_CMD_LOCK:
            num_params = 1;
        break;
        case SSD1322_CMD_SET_GS_TABLE:
            num_params = 15;
        break;
    default:
        num_params = 0;
        break;
    }
    return num_params;
}

void ssd1322_param_mask(ssd1322_cmd_t cmd, uint8_t param_index, uint8_t *param)
{
    uint8_t and_mask = 0xff;
    uint8_t or_mask = 0x00;
    switch(cmd)
    {
        /*case SSD1322_CMD_ENABLE_GS_TABLE:
        case SSD1322_CMD_WRITE_RAM:
        case SSD1322_CMD_READ_RAM:
        case SSD1322_CMD_SET_DISPLAY_MODE_N:
        case SSD1322_CMD_SET_DISPLAY_MODE_EON:
        case SSD1322_CMD_SET_DISPLAY_MODE_EOFF:
        case SSD1322_CMD_SET_DISPLAY_MODE_INV:
        case SSD1322_CMD_EXIT_PARTIAL_DISPLAY:
        case SSD1322_CMD_DISPLAY_OFF:
        case SSD1322_CMD_DISPLAY_ON:
        case SSD1322_CMD_SEL_DEF_LIN_GS_TABLE:
        case SSD1322_CMD_SET_PHASE_L:
        case SSD1322_CMD_SET_FCD_OSCFREQ:
        case SSD1322_CMD_SET_CONTRAST_CURR:
        case SSD1322_CMD_SET_GS_TABLE:
            and_mask = 0xff;
            or_mask = 0x00;
        break;*/
        case SSD1322_CMD_SET_COLUMN_ADDRESS:
        case SSD1322_CMD_SET_ROW_ADDRESS:
        case SSD1322_CMD_ENABLE_PARTIAL_DISPLAY:
        case SSD1322_CMD_SET_DISPLAY_START_L:
        case SSD1322_CMD_SET_DISPLAY_OFFSET:
        case SSD1322_CMD_SET_MULT_RATIO:
            and_mask = 0b01111111;
        break;
        case SSD1322_CMD_SET_REMAP_DUAL_COM:
            if (param_index == 0)
                and_mask = 0b00110111;
            else
            {
                and_mask = 0b00010000;
                or_mask =  0b00000001;
            }
        break;
        case SSD1322_CMD_DISPLAY_ENH_A:
            if (param_index == 0)
            {
                and_mask = 0b00000011;
                or_mask =  0b10100000;
            }
            else
            {
                and_mask = 0b11111000;
                or_mask =  0b00000101;
            }
        break;
        case SSD1322_CMD_DISPLAY_ENH_B:
            if (param_index == 0)
            {
                and_mask = 0b00110000;
                or_mask =  0b10000010;
            }
            else
            {
                and_mask = 0b00000000;
                or_mask =  0x20;
            }
        break;
        case SSD1322_CMD_SET_FUNCTION_SEL:
                and_mask = 0b00000001;
        break;
        case SSD1322_CMD_SET_GPIO:
        case SSD1322_CMD_SET_2ND_PRE_PERIOD:
        case SSD1322_CMD_MASTER_CURR_CONTROL:
                and_mask = 0b00001111;
        break;
        case SSD1322_CMD_SET_PRE_CHARGE_V:
                and_mask = 0b00011111;
        break;
        case SSD1322_CMD_SET_VCOMH:
                and_mask = 0b00000111;
        break;
        case SSD1322_CMD_LOCK:
                and_mask = 0b00000100;
                or_mask =  0b00100010;
        break;
    default:
            and_mask = 0xff;
            or_mask = 0x00;
        break;
    }
    *param &= and_mask;
    *param |= or_mask;
}

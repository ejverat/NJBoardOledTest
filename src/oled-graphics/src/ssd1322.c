#include "ssd1322.h"
#include "gdisplay_driver.h"
#include "ssd1322_def.h"
#include "ssd1322_cmd.h"

static display_comm_t* ssd1322_comm;
static waiter_t* ssd1322_timer;
static uint8_t params[15];

void ssd1322_setup(gdisplay_driver_t* driver, display_comm_t* comm, waiter_t* timer)
{
    driver->init_fn = ssd1322_init;
    driver->send_cmd_fn = ssd1322_send_cmd;
    driver->send_data_fn = ssd1322_send_data;
    driver->comm = comm;
    driver->timer = timer;
    ssd1322_comm = comm;
    ssd1322_timer = timer;
}

bool ssd1322_init()
{
    ssd1322_timer->wait_ms(1000);
    if (!ssd1322_comm->init_fn())
        return false;

    //reset device
    ssd1322_comm->disable_fn();
    ssd1322_comm->start_reset_fn();
    ssd1322_timer->wait_ms(150);
    ssd1322_comm->end_reset_fn();
    ssd1322_timer->wait_ms(300);

    //init commands
    ssd1322_timer->wait_ms(2);
    ssd1322_comm->enable_fn();
    ssd1322_timer->wait_ms(2);

    params[0] = 0x12;
    ssd1322_send_cmd(SSD1322_CMD_LOCK, params);				// FDh (0001 0[A2=0]10) Unlock OLED driver IC MCU interface from entering command [reset] p.36
    ssd1322_send_cmd(SSD1322_CMD_DISPLAY_OFF, params);		// AEh Sleep mode ON (Display OFF) p.33
    params[0] = 0x91;
    ssd1322_send_cmd(SSD1322_CMD_SET_FCD_OSCFREQ, params);	// B3h (1001) freq=(while more higher value more freq)  (0001) divided by 2 p.34
    params[0] = 0x3f;
    ssd1322_send_cmd(SSD1322_CMD_SET_MULT_RATIO, params);		// CAh (0011 1111) <= 63 when dual COM mode is enabled p.41 p.36
    params[0] = 0x00;
    ssd1322_send_cmd(SSD1322_CMD_SET_DISPLAY_OFFSET, params);		// A2h (0000 0000) (no offset/vertical scroll) Set vertical scroll by COM from 0-127 p.33 p.43
    params[0] = 0x00;
    ssd1322_send_cmd(SSD1322_CMD_SET_DISPLAY_START_L, params);	// A1h (0000 0000) Set display RAM display start line register from 0-127 p.32 p.42
    params[0] = 0x14;
    params[1] = 0x11;
    ssd1322_send_cmd(SSD1322_CMD_SET_REMAP_DUAL_COM, params);		// A0h A(0001 0100) B(0001 0001) p.32 p.39 p.40 p.41
                            // 	A[5]=0b, Disable COM Split Odd Even [reset] pin assignment of common is in sequential as COM127 COM126...COM 65 COM64...SEG479...SEG0...COM0 COM1...COM62 COM63
                            // 	A[4]=1b, Scan from COM[N-1] to COM0, where N is the Multiplex ratio
                            // 	A[2]=1b, Enable Nibble Re-map
                            // 	A[1]=0b, Disable Column Address Re-map [reset]
                            // 	A[0]=0b, Horizontal address increment [reset]
                            // 	B[4]=1b, Enable Dual COM mode (MUX <= 63)
    params[0] = 0x01;
    ssd1322_send_cmd(SSD1322_CMD_SET_FUNCTION_SEL, params);		// ABh (0000 0001) A[0]=1b, Enable internal VDD regulator [reset]
    params[0] = 0xa0;
    params[1] = 0x05|0xfd;
    ssd1322_send_cmd(SSD1322_CMD_DISPLAY_ENH_A, params);	// B4h (1010 0000) (1111 1101) p.34
                            // 	A[1:0] = 00b: Enable external VSL
                            // 	B[7:3] = 11111b: Enhanced low GS display quality
    params[0] = 0x9f;
    ssd1322_send_cmd(SSD1322_CMD_SET_CONTRAST_CURR, params);		// C1h (1001 1111) p.35 A[7:0]: Contrast current value, range:00h~FFh, i.e. 256 steps for I SEG current [reset = 7Fh]
    params[0] = 0x0f;
    ssd1322_send_cmd(SSD1322_CMD_MASTER_CURR_CONTROL, params);	// C7h (0000 1111) A[3:0] = 1111b, no change [reset] p.36
    ssd1322_send_cmd(SSD1322_CMD_SEL_DEF_LIN_GS_TABLE, params);	// B9h Default Linear Grayscale Table
    params[0] = 0xe2;
    ssd1322_send_cmd(SSD1322_CMD_SET_PHASE_L, params);		// B1h (1110 0010) Set Phase Length
                            // 	0010 = 5 DCLKs A[3:0] Phase 1 period (reset phase length) of 5~31 DCLK(s)
                            // 	1110 = 15 DCLKs A[7:4] Phase 2 period (first pre-charge phase length)
    params[0] = 0x082|0x020;
    ssd1322_send_cmd(SSD1322_CMD_DISPLAY_ENH_B, params);		// D1h (1010 0010) A[5:4] = 10b: Normal [reset] (Display Enhancement) p.36
    params[0] = 0x1f;
    ssd1322_send_cmd(SSD1322_CMD_SET_PRE_CHARGE_V, params);	// BBh (0001 1111) Set Precharge Voltage  0.60 x VCC p.35
    params[0] = 0x08;
    ssd1322_send_cmd(SSD1322_CMD_SET_2ND_PRE_PERIOD, params);	// B6h (0000 1000) Set Second Precharge Period   8 dclks [reset] p.34
    params[0] = 0x07;
    ssd1322_send_cmd(SSD1322_CMD_SET_VCOMH, params);		// BEh (0000 0111) Set VCOMH Voltage     0.86 x VCC  p.35
    ssd1322_send_cmd(SSD1322_CMD_SET_DISPLAY_MODE_EOFF, params);	// A6h Set Normal Display    p.33
    ssd1322_send_cmd(SSD1322_CMD_EXIT_PARTIAL_DISPLAY, params);	// A9h Exit Partial Display Mode p.33

    ssd1322_timer->wait_ms(2);
    ssd1322_send_cmd(SSD1322_CMD_DISPLAY_ON, params);		// AF Sleep Mode OFF
    ssd1322_timer->wait_ms(2);
    ssd1322_comm->disable_fn();

    return true;
}

bool ssd1322_send_cmd(uint8_t cmd, uint8_t* params)
{
    ssd1322_comm->enable_cmd_fn();
    if (!ssd1322_comm->send_byte_fn(cmd))
        return false;
    ssd1322_comm->disable_cmd_fn();
    ssd1322_comm->enable_data_fn();
    uint8_t num_params = ssd1322_cmd_num_params((ssd1322_cmd_t)cmd);
    uint8_t p_idx;
    for (p_idx = 0; p_idx < num_params; p_idx++)
    {
        uint8_t param = params[p_idx];
        ssd1322_param_mask((ssd1322_cmd_t)cmd,p_idx,&param);
        if (!ssd1322_comm->send_byte_fn(param))
            return false;
    }
    ssd1322_comm->disable_data_fn();
    return true;
}

bool ssd1322_send_data(uint8_t* data, uint16_t size)
{
    ssd1322_comm->enable_data_fn();

    uint8_t p_idx;
    for (p_idx = 0; p_idx < size; p_idx++)
    {
        if (!ssd1322_comm->send_byte_fn(data[p_idx]))
            return false;
    }

    ssd1322_comm->disable_data_fn();
    return true;
}

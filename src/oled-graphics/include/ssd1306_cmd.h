#ifndef SSD1306_CMD_H
#define SSD1306_CMD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ssd1306_def.h"
#include <stdint.h>
#include <stdbool.h>

uint8_t ssd1306_cmd_num_params(ssd1306_cmd_t cmd);
void ssd1306_param_mask(ssd1306_cmd_t cmd, uint8_t param_index, uint8_t* param);

#ifdef	__cplusplus
}
#endif

#endif // SSD1306_CMD_H

#ifndef SSD1322_CMD_H
#define SSD1322_CMD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "ssd1322_def.h"
#include <stdint.h>
#include <stdbool.h>

uint8_t ssd1322_cmd_num_params(ssd1322_cmd_t cmd);
void ssd1322_param_mask(ssd1322_cmd_t cmd, uint8_t param_index, uint8_t* param);

#ifdef	__cplusplus
}
#endif
#endif // SSD1322_CMD_H

#ifndef SSD1322_H
#define SSD1322_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    void (*set_command_bit_fn)(bool);
}ssd1322_t;


inline void ssd1322_set_command_bit_handler(ssd1322_t* driver, void (*handler)(bool))
{
    driver->set_command_bit_fn = handler;
}

ssd1322_t* ssd1322_instance();
bool ssd1322_send_command(uint8_t* commands, uint16_t size);
bool ssd1322_send_data(uint8_t* data, uint16_t size);

#ifdef	__cplusplus
}
#endif

#endif // SSD1322_H

#include "timer_delay.h"
#include "mcc_generated_files/timer/delay.h"

static waiter_t timer;

waiter_t* timer_delay_instance()
{
  timer.wait_ms = timer_delay_ms;
  return &timer;
}


void timer_delay_ms(uint16_t ms)
{
  DELAY_milliseconds (ms);
}



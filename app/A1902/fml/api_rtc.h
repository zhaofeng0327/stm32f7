#ifndef _API_RTC_H_
#define _API_RTC_H_
#include <stdint.h>
void RTC_CalendarConfig(void);
void RTC_CalendarShow(uint8_t *showtime, uint8_t *showdate);

#endif

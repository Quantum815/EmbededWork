#ifndef RTC_TIME_H_
#define RTC_TIME_H_

#include "rtc.h"
#include "Miscellaneous.h"

void ShowDateBuffer(uint8_t* buffer, RTC_DateTypeDef date);
void ShowTimeBuffer(uint8_t* buffer, RTC_TimeTypeDef time);

#endif
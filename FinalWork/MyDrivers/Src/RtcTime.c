#include "RtcTime.h"
#include "ILI9341_STM32_Driver.h"
#include "Gui.h"
#include "Miscellaneous.h"

void ShowDateBuffer(uint8_t* buffer, RTC_DateTypeDef date)
{
	HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
	memset(buffer, 0x00, sizeof(*buffer));
	switch(date.WeekDay)
	{
		case 1:sprintf((char*)buffer, "%d/%02d/%02d Monday", 2000+date.Year, date.Month, date.Date);break;
		case 2:sprintf((char*)buffer, "%d/%02d/%02d Tuesday", 2000+date.Year, date.Month, date.Date);break;
		case 3:sprintf((char*)buffer, "%d/%02d/%02d Wednesday", 2000+date.Year, date.Month, date.Date);break;			
		case 4:sprintf((char*)buffer, "%d/%02d/%02d Thursday", 2000+date.Year, date.Month, date.Date);break;		
		case 5:sprintf((char*)buffer, "%d/%02d/%02d Friday", 2000+date.Year, date.Month, date.Date);break;		
		case 6:sprintf((char*)buffer, "%d/%02d/%02d Saturday", 2000+date.Year, date.Month, date.Date);break;		
		case 7:sprintf((char*)buffer, "%d/%02d/%02d Sunday", 2000+date.Year, date.Month, date.Date);break;		
		default:sprintf((char*)buffer, "%d/%02d/%02d Unknown", 2000+date.Year, date.Month, date.Date);break;
		
	}
	Gui_DrawFont_GBK24(45, 25, RED, WHITE, buffer);
}

void ShowTimeBuffer(uint8_t* buffer, RTC_TimeTypeDef time)
{
	HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);	
	memset(buffer, 0x00, sizeof(*buffer));
	sprintf((char*)buffer, "%02d:%02d:%02d:%02d", time.Hours, time.Minutes, time.Seconds, time.SubSeconds*100/256);
	Gui_DrawFont_GBK24(70, 50, RED, WHITE, buffer);
}

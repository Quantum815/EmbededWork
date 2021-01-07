#include "UserMain.h"
#include "main.h"
#include "adc.h"
#include "fatfs.h"
#include "rtc.h"
#include "sdio.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "ILI9341_Touchscreen.h"
#include "Gui.h"
#include "MatrixKeyboard.h"
#include "RtcTime.h"
#include "BatADC.h"
#include "Picture.h"
#include "ff.h"
#include "Miscellaneous.h"

// FATFS内容
FATFS   fs;         /* FATFS 文件系统对象 */
FRESULT fr;         /* FATFS 错误代码返回值 */
FIL     fd;         /* FATFS 文件对象    */

//RTC内容
RTC_DateTypeDef date;
RTC_TimeTypeDef time;

//标志位
uint8_t EnableShowRtcFlag;
uint8_t EnableShowBPRateFlag;
uint8_t EnableShowPicFlag;
uint8_t EnableBuzzerFlag;

//缓冲区
uint8_t buffer[28];

void UserInit(void)
{
	ILI9341_Init();
	ILI9341_Fill_Screen(WHITE);
	ILI9341_Set_Rotation(SCREEN_VERTICAL_1);
	Gui_DrawFont_GBK24(20, 15, BLACK, WHITE, (uint8_t*)"System initializing......");
	printf("System initializing...... \r\n");
//Initialization
//************************************************************
	HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 1);  //后备寄存器写1
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_ADC_Start(&hadc1);
	memset(FrameBuffer, 0x00, sizeof(FrameBuffer));
//************************************************************
	EnableBuzzerFlag = 1;
	HAL_Delay(1000);
	EnableBuzzerFlag = 0;
	ILI9341_Fill_Screen(WHITE);

//FATFS测试
	uint32_t byteswritten;                /* File write counts */
	uint32_t bytesread;                   /* File read counts */
	uint8_t errorflag = 0;
	uint8_t wtext[] = "This is STM32 testing with FatFs"; /* File write buffer */
	uint8_t rtext[sizeof(wtext)+1];                   /* File read buffers */
	char filename[] = "STM32cube.txt";
//	char SensorBuff[100];
	
	Gui_DrawFont_GBK24(10, 15, BLACK, WHITE, (uint8_t*)"** STM32CubeMX FatFs TEST **");
	printf("********* STM32CubeMX FatFs TEST ********* \r\n");

	//SD卡挂载测试
	if(f_mount(&fs,"0:",1) == FR_OK)
	{
		Gui_DrawFont_GBK24(10, 40, BLACK, WHITE, (uint8_t*)"f_mount sucess!!! ");
    printf("f_mount sucess!!! \r\n");
  }
	else
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_mount error code: %d ", fr);
		Gui_DrawFont_GBK24(10, 40, RED, WHITE, buffer);
		printf("f_mount error code: %d \r\n", fr);
	}
	
	//文件创建打开测试
	if(f_open(&fd,filename,FA_CREATE_ALWAYS|FA_WRITE) == FR_OK)
	{
		Gui_DrawFont_GBK24(10, 65, BLACK, WHITE, (uint8_t*)"f_open file sucess!!! ");
		printf("f_open file sucess!!! \r\n");
	}
	else
	{
		errorflag = 1;
		Gui_DrawFont_GBK24(10, 65, RED, WHITE, (uint8_t*)"f_open file error!!! ");
		printf("f_open file error!!! \r\n");
	}

	//文件创建写入测试
	if(f_write(&fd,wtext,sizeof(wtext),&byteswritten) == FR_OK)
	{
		Gui_DrawFont_GBK24(10, 90, BLACK, WHITE, (uint8_t*)"f_write file sucess!!! ");
		printf("f_write file sucess!!! \r\n");
		printf("f_write Data : %s\r\n", wtext);
	}
	else
	{
		errorflag = 1;
		Gui_DrawFont_GBK24(10, 90, RED, WHITE, (uint8_t*)"f_write file error!!! ");
		printf("f_write file error!!! \r\n"); 
	}

	//文件创建关闭测试
	if(f_close(&fd) == FR_OK)
	{
		Gui_DrawFont_GBK24(10, 115, BLACK, WHITE, (uint8_t*)"f_close sucess!!! ");
		printf("f_close sucess!!! \r\n");
	}
	else
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_close error code: %d\r\n", fr);
		Gui_DrawFont_GBK24(10, 115, RED, WHITE, buffer);
		printf("f_close error code: %d\r\n", fr);
	}

	//文件读取打开测试	
	fr = f_open(&fd, filename, FA_READ);
	if(fr)
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_open file error code: %d ", fr);
		Gui_DrawFont_GBK24(10, 140, RED, WHITE, buffer);
		printf("f_open file error : %d\r\n",fr);
	}
	else
	{
		Gui_DrawFont_GBK24(10, 140, BLACK, WHITE, (uint8_t*)"f_open file sucess!!! ");
		printf("f_open file sucess!!! \r\n");
	}

	//文件读取读出测试
	fr = f_read(&fd, rtext, sizeof(rtext), (UINT*)&bytesread);
	if(fr)
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_read error code: %d",fr);
		Gui_DrawFont_GBK24(10, 165, RED, WHITE, buffer);
		printf("f_read error code: %d\r\n",fr);
	}
	else
	{
		Gui_DrawFont_GBK24(10, 165, BLACK, WHITE, (uint8_t*)"f_read sucess!!! ");
		printf("f_read sucess!!! \r\n");
		printf("f_read Data : %s\r\n",rtext);
	}

	//文件读取关闭测试
	fr = f_close(&fd);
	if(fr)
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_close error code: %d", fr);
		Gui_DrawFont_GBK24(10, 190, RED, WHITE, buffer);		
		printf("f_close error code: %d\r\n",fr);
	}
	else
	{
		Gui_DrawFont_GBK24(10, 190, BLACK, WHITE, (uint8_t*)"f_close sucess!!! ");
		printf("f_close sucess!!! \r\n");
	}
	
	//文件删除测试
	fr = f_unlink(filename);
	if(fr)
	{
		errorflag = 1;
		memset(buffer, 0x00, sizeof(*buffer));
		sprintf((char*)buffer, "f_unlink error code: %d", fr);
		Gui_DrawFont_GBK24(10, 215, RED, WHITE, buffer);		
		printf("f_unlink error code: %d\r\n",fr);
	}
	else
	{
		Gui_DrawFont_GBK24(10, 215, BLACK, WHITE, (uint8_t*)"f_unlink sucess!!! ");
		printf("f_unlink sucess!!! \r\n");
	}

	//FATFS测试结果
	if(errorflag)
	{
		Gui_DrawFont_GBK24(10, 240, RED, WHITE, (uint8_t*)"FatFs is not working well!!! ");
		printf("FatFs is not working well!!!\r\n");
		while(1);
	}
	else
	{
		Gui_DrawFont_GBK24(10, 240, BLACK, WHITE, (uint8_t*)"FatFs is working well!!! ");
		printf("FatFs is working well!!!\r\n");
	}

//	if(f_open(&fd,(const char*)"Sensor.csv",FA_CREATE_ALWAYS|FA_WRITE) == FR_OK)
//	{
//		printf("Sensor.csv was opened/created!!!\r\n");
//		sprintf(SensorBuff, "Item,Temp,Humi,Light\r\n");
//		f_write(&fd,SensorBuff,strlen(SensorBuff),&byteswritten);
//	
//		for(int i = 0; i < 10; i++){
//			sprintf(SensorBuff, "%d,%d,%d,%d\r\n",i + 1, i + 20, i + 30, i + 40);
//			f_write(&fd,SensorBuff,strlen(SensorBuff),&byteswritten);
//			f_sync(&fd);
//		}
//		f_close(&fd);
//	}
	
	HAL_Delay(1000);
	ILI9341_Fill_Screen(WHITE);
	ClearReaginSet(40,100,190,140,RED);
	Gui_DrawFont_GBK24(80, 110, BLACK, RED, (uint8_t*)"Show Time");
	DisplayButtonUp(40,100,190,140);
	ClearReaginSet(40,160,190,200,YELLOW);
	Gui_DrawFont_GBK24(70, 170, BLACK, YELLOW, (uint8_t*)"Show BPRate");
	DisplayButtonUp(40,160,190,200);
	ClearReaginSet(40,220,190,260,GREEN);
	Gui_DrawFont_GBK24(68, 230, BLACK, GREEN, (uint8_t*)"Show Picture");
	DisplayButtonUp(40,220,190,260);
}

void UserMain(void)
{
	if(TP_Touchpad_Pressed())
	{	
		uint16_t x_pos = 0;
		uint16_t y_pos = 0;
		uint16_t position_array[2];
		if(TP_Read_Coordinates(position_array) == TOUCHPAD_DATA_OK)
		{
			x_pos = position_array[0];
			y_pos = position_array[1];
			if(x_pos > 40 && x_pos < 190 && y_pos > 100 && y_pos < 140)
			{
				DisplayButtonDown(40,100,190,140);
				Gui_DrawFont_GBK24(80, 110, GRAY1, RED, (uint8_t*)"Show Time");
				EnableShowRtcFlag = 1;
				while(EnableShowRtcFlag)
				{
					ShowDateBuffer(buffer, date);
					ShowTimeBuffer(buffer, time);
					MatrixKeyboardScanning();					
				}
			}
			if(x_pos > 40 && x_pos < 190 && y_pos > 160 && y_pos < 200)
			{
				DisplayButtonDown(40,160,190,200);
				Gui_DrawFont_GBK24(70, 170, GRAY1, YELLOW, (uint8_t*)"Show BPRate");
				EnableShowBPRateFlag = 1;
				while(EnableShowBPRateFlag)
				{
					GetBatteryPowerRate(buffer,5);
					MatrixKeyboardScanning();					
				}
			}
			if(x_pos > 40 && x_pos < 190 && y_pos > 220 && y_pos < 260)
			{
				char f_name[10];
				
				DisplayButtonDown(40,220,190,260);
				Gui_DrawFont_GBK24(68, 230, GRAY1, GREEN, (uint8_t*)"Show Picture");
				EnableShowPicFlag = 1;
				memset(f_name, 0x00, sizeof(*f_name));
				sprintf((char*)f_name, "Pic%d.txt", PicNum);
				Show_Pic(&fd, f_name);
				while(EnableShowPicFlag)
				{
					MatrixKeyboardScanning();					
				}
			}
//			printf("%d	%d\r\n", x_pos, y_pos);
		}							
	}
}
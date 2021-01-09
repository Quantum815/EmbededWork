#include "MatrixKeyboard.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "Gui.h"
#include "Picture.h"
#include <stdio.h>

int KeyFlag;
uint32_t PicNum = 1;

void MatrixKeyboardScanning(void)
{
	LL_GPIO_ResetOutputPin(Row1_GPIO_Port, Row1_Pin);
	LL_GPIO_SetOutputPin(Row2_GPIO_Port, Row2_Pin);
	LL_GPIO_SetOutputPin(Row3_GPIO_Port, Row3_Pin);
	LL_GPIO_SetOutputPin(Row4_GPIO_Port, Row4_Pin);
	if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
			KeyFlag = 1;
	}
	else if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
			KeyFlag = 2;
	}
	else if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
			KeyFlag = 3;
	}
	else if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
			KeyFlag = 4;
	}
	else
		KeyFlag = 0;
	
	LL_GPIO_SetOutputPin(Row1_GPIO_Port, Row1_Pin);
	LL_GPIO_ResetOutputPin(Row2_GPIO_Port, Row2_Pin);
	LL_GPIO_SetOutputPin(Row3_GPIO_Port, Row3_Pin);
	LL_GPIO_SetOutputPin(Row4_GPIO_Port, Row4_Pin);
	if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
			KeyFlag = 5;
	}
	else if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
			KeyFlag = 6;
	}
	else if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
			KeyFlag = 7;
	}
	else if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
			KeyFlag = 8;
	}

	LL_GPIO_SetOutputPin(Row1_GPIO_Port, Row1_Pin);
	LL_GPIO_SetOutputPin(Row2_GPIO_Port, Row2_Pin);
	LL_GPIO_ResetOutputPin(Row3_GPIO_Port, Row3_Pin);
	LL_GPIO_SetOutputPin(Row4_GPIO_Port, Row4_Pin);	
	if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
			KeyFlag = 9;
	}
	else if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
			KeyFlag = 10;
	}
	else if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
			KeyFlag = 11;
	}
	else if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
			KeyFlag = 12;
	}

	LL_GPIO_SetOutputPin(Row1_GPIO_Port, Row1_Pin);
	LL_GPIO_SetOutputPin(Row2_GPIO_Port, Row2_Pin);
	LL_GPIO_SetOutputPin(Row3_GPIO_Port, Row3_Pin);
	LL_GPIO_ResetOutputPin(Row4_GPIO_Port, Row4_Pin);
	if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column1_GPIO_Port, Column1_Pin))
			KeyFlag = 13;
	}
	else if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column2_GPIO_Port, Column2_Pin))
			KeyFlag = 14;
	}
	else if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column3_GPIO_Port, Column3_Pin))
			KeyFlag = 15;
	}
	else if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
	{
		HAL_Delay(1);
		if(!LL_GPIO_IsInputPinSet(Column4_GPIO_Port, Column4_Pin))
			KeyFlag = 16;
	}
	
	switch(KeyFlag)
	{
		case 1: R1C1Fuction(); break;
		case 2: R1C2Fuction(); break;
		case 3: R1C3Fuction(); break;
		case 4: R1C4Fuction(); break;
		case 5: R2C1Fuction(); break;
		case 6: R2C2Fuction(); break;
		case 7: R2C3Fuction(); break;
		case 8: R2C4Fuction(); break;
		case 9: R3C1Fuction(); break;
		case 10: R3C2Fuction(); break;
		case 11: R3C3Fuction(); break;
		case 12: R3C4Fuction(); break;
		case 13: R4C1Fuction(); break;
		case 14: R4C2Fuction(); break;
		case 15: R4C3Fuction(); break;
		case 16: R4C4Fuction(); break;
		default: ElseFuction(); break;
	}
}

void R1C1Fuction(void)
{
	EnableShowRtcFlag = 0;
	EnableShowBPRateFlag = 0;
	EnableShowPicFlag = 0;

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

void R1C2Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum--;
		if(PicNum < 1)
			PicNum = 1;
		else
		{
			memset(f_name, 0x00, sizeof(*f_name));
			sprintf((char*)f_name, "Pic%d.txt", PicNum);
			Show_Pic(&fd, f_name);
		}
	}
}
void R1C3Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum++;
		memset(f_name, 0x00, sizeof(*f_name));
		sprintf((char*)f_name, "Pic%d.txt", PicNum);
		Show_Pic(&fd, f_name);
	}
}
void R1C4Fuction(void)
{

}
void R2C1Fuction(void)
{
	EnableShowRtcFlag = 0;
	EnableShowBPRateFlag = 0;
	EnableShowPicFlag = 0;

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

void R2C2Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum--;
		if(PicNum < 1)
			PicNum = 1;
		else
		{
			memset(f_name, 0x00, sizeof(*f_name));
			sprintf((char*)f_name, "Pic%d.txt", PicNum);
			Show_Pic(&fd, f_name);
		}
	}
}

void R2C3Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum++;
		memset(f_name, 0x00, sizeof(*f_name));
		sprintf((char*)f_name, "Pic%d.txt", PicNum);
		Show_Pic(&fd, f_name);
	}
}

void R2C4Fuction(void)
{

}

void R3C1Fuction(void)
{
	EnableShowRtcFlag = 0;
	EnableShowBPRateFlag = 0;
	EnableShowPicFlag = 0;

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

void R3C2Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum--;
		if(PicNum < 1)
			PicNum = 1;
		else
		{
			memset(f_name, 0x00, sizeof(*f_name));
			sprintf((char*)f_name, "Pic%d.txt", PicNum);
			Show_Pic(&fd, f_name);
		}
	}
}

void R3C3Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum++;
		memset(f_name, 0x00, sizeof(*f_name));
		sprintf((char*)f_name, "Pic%d.txt", PicNum);
		Show_Pic(&fd, f_name);
	}
}

void R3C4Fuction(void)
{

}

void R4C1Fuction(void)
{
	EnableShowRtcFlag = 0;
	EnableShowBPRateFlag = 0;
	EnableShowPicFlag = 0;

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

void R4C2Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum--;
		if(PicNum < 1)
			PicNum = 1;
		else
		{
			memset(f_name, 0x00, sizeof(*f_name));
			sprintf((char*)f_name, "Pic%d.txt", PicNum);
			Show_Pic(&fd, f_name);
		}
	}
}

void R4C3Fuction(void)
{
	char f_name[10];
	
	if(EnableShowPicFlag)
	{
		PicNum++;
		memset(f_name, 0x00, sizeof(*f_name));
		sprintf((char*)f_name, "Pic%d.txt", PicNum);
		Show_Pic(&fd, f_name);
	}
}

void R4C4Fuction(void)
{

}

void ElseFuction(void)
{

}

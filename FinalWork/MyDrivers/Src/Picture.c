#include "Picture.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "MatrixKeyboard.h"
#include "Miscellaneous.h"

char FrameBuffer[240*2];

char Char2Hex(char c1, char c2)
{
	if(c1 <= '9' && c2 <= '9')
		return (c1 - '0') * 16 + (c2 - '0');
	else if(c1 <= '9' && c2 >= 'a')
		return (c1 - '0') * 16 + (c2 - 'a' + 10);
	else if(c1 >= 'a' && c2 <= '9')
		return (c1 - 'a' + 10) * 16 + (c2 - '0');
	else
		return (c1 - 'a' + 10) * 16 + (c2 - 'a' + 10);	
}

void Show_Pic(FIL* fd, char* f_name)
{
	char SDBuffer[6];
	char temp;
	uint32_t index = 0;  //数组位
	int32_t complement = 0;  //行末换行符补充数
	uint32_t reservation = 0;  // 保留一次绘图后文件指针处  
	uint16_t multiple;  //图片显示份数
	
	if(f_open(fd, f_name , FA_READ) == FR_OK)
	{			
		for(multiple = 1; multiple <= 320; multiple++)
		{
			reservation += 5 * index + complement;
			index = 0;
			complement = 0;
			while(index <= 240*2-1)
			{
				f_lseek(fd, reservation + 5*index + complement);
				f_gets(SDBuffer,6,fd);
				//末尾处理
				if(SDBuffer[2] == '\n')
				{
					f_lseek(fd, reservation + 5*index + complement + 4);
					f_gets(SDBuffer,6,fd);
					FrameBuffer[index] = Char2Hex(SDBuffer[0], SDBuffer[1]);
					complement += 2;
				}
				else if(SDBuffer[3] == '\n')
				{
					temp = SDBuffer[2];
					f_lseek(fd, reservation + 5*index + complement + 5);
					f_gets(SDBuffer,6,fd);
					FrameBuffer[index] = Char2Hex(temp, SDBuffer[0]);
					complement += 2;
				}
				else if(SDBuffer[4] == '\n')
				{
					FrameBuffer[index] = Char2Hex(SDBuffer[2], SDBuffer[3]);
					complement += 2;
				}
				else
				{
					FrameBuffer[index] = Char2Hex(SDBuffer[2], SDBuffer[3]);
				}
				index++;
			}
			ILI9341_Draw_Image(FrameBuffer, SCREEN_VERTICAL_1, 0, multiple-1, 240, multiple);
		}	
		f_close(fd);
	}
	else
		PicNum--;
}

#ifndef MATRIXKEYBOARD_H_
#define MATRIXKEYBOARD_H_

#include "main.h"
#include "ff.h"

//#define Row1_GPIO_Port     GPIOF
//#define Row1_Pin           GPIO_PIN_2
//#define Row2_GPIO_Port     GPIOF
//#define Row2_Pin           GPIO_PIN_3
//#define Row3_GPIO_Port     GPIOF
//#define Row3_Pin           GPIO_PIN_4
//#define Row4_GPIO_Port     GPIOF
//#define Row4_Pin           GPIO_PIN_5
//#define Column1_GPIO_Port  GPIOF
//#define Column1_Pin        GPIO_PIN_6
//#define Column2_GPIO_Port  GPIOF
//#define Column2_Pin        GPIO_PIN_7
//#define Column3_GPIO_Port  GPIOF
//#define Column3_Pin        GPIO_PIN_8
//#define Column4_GPIO_Port  GPIOF
//#define Column4_Pin        GPIO_PIN_9

#define TOTAL_PIC_NUM 10

extern uint8_t EnableShowRtcFlag;
extern uint8_t EnableShowBPRateFlag;
extern uint8_t EnableShowPicFlag;
extern FIL fd;
extern uint32_t PicNum;

void MatrixKeyboardScanning(void);
void R1C1Fuction(void);
void R1C2Fuction(void);
void R1C3Fuction(void);
void R1C4Fuction(void);
void R2C1Fuction(void);
void R2C2Fuction(void);
void R2C3Fuction(void);
void R2C4Fuction(void);
void R3C1Fuction(void);
void R3C2Fuction(void);
void R3C3Fuction(void);
void R3C4Fuction(void);
void R4C1Fuction(void);
void R4C2Fuction(void);
void R4C3Fuction(void);
void R4C4Fuction(void);
void ElseFuction(void);

#endif

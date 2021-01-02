#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"

extern uint8_t EnableBuzzerFlag;

int fputc(int ch,FILE *f);
int fgetc(FILE *f);

#endif
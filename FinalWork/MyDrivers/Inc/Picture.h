#ifndef PICTURE_H_
#define PICTURE_H_

#include "main.h"
#include "ff.h"

extern char FrameBuffer[240*4];

char Char2Hex(char c1, char c2);
void Show_Pic(FIL* fd, char* f_name);

#endif

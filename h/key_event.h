#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>



#define KEY_UP		1072
#define KEY_DOWN	1080
#define KEY_LEFT	1075
#define KEY_RIGHT	1077
#define KEY_NONE	-1

//Lay nut nguoi dung nhap tu ban phim
int InputKey();

//Di chuyen co tro den vi tri x, y
void gotoXY(int x, int y);

//Xoa con tro nhay
void noCursorType();

//Doi mau chu
void setTextColor(int color);
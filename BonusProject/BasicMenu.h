#ifndef BasicMenu_h
#define BasicMenu_h

#include"GraphicBasic.h"
#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>

using namespace std;



enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER };
typedef char str[31];



TRANGTHAI key(int z);

void Menu(int n);

#endif

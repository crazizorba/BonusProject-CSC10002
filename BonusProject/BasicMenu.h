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


//10. Ke bang
void drawBox(int x, int y, int w, int h, int t_color, int b_color);

//11. Thanh sang
void thanh_sang(int x, int y, int w, int h, int b_color, string a);
void thanh_sang_cu(int x, int y, int w, int h, int b_color, string a);

//12. menu3
void menu(int x, int y, int w, int h, int t_color, int b_color, string sentences[], int n);
int central(int w, string a);


#endif

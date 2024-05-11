#ifndef Graphics_h
#define Graphics_h

#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<cstdlib>
#include<string>

using namespace std;

void resizeConsole(int width, int height);

void setColor(int n);

void textColor(int x);

void gotoxy(int x, int y);

void deleteScreen();

void writeText(int x, int y, char* a, int color);

void drawBox(int x, int y, int w, int h, int t_color, int b_color, string content);

void drawTable(int x, int y, int w, int h, int t_color, int b_color, string content, int nRow);

void lightRow(int x, int y, int w, int h, int b_color, string content);

void menu(int x, int y);

#endif

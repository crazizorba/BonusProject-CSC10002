#ifndef GraphicBasic_h
#define GraphicBasic_h

#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>

#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

using namespace std;

//1.Thay doi kich thuoc man hinh console /Chua chay duoc
void resizeConsole(int width, int height);

//2. Mau nen va mau chu, chi nen dung lam mau nen
void textColor(int x);

//3. Mau chu, ghi de len ham mau nen o tren
void SetColor(WORD color);

//4. Di chuyen con tro toi vi tri (x,y)
void gotoxy(int x, int y);

//5. Xoa man hinh
void deleteScreen();//nen dung
void clrscr();

//6. Vi tri con tro hien tai
int whereX();
int whereY();

//7. Tra ve phim duoc bam tu ban phim
int inputKey();

//8. An con tro chuot
void ShowCur(bool CursorVisibility);

//9. Viet chu
void writeText(int x, int y, string content, int color);

//10. Ke bang
void drawBox(int x, int y, int w, int h, int t_color);



#endif

#ifndef BasicMenu_h
#define BasicMenu_h


#include"GraphicBasic.h"
#include"Struct.h"
#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>

using namespace std;



enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACKSPACE };
typedef char str[31];



TRANGTHAI key(int z);


void MainMenu();
void push_enter_main_menu(int y);

void LoginMenu();
void push_enter_menu_login_2(int y);



void LoginMenu();

void StudentMenu();
void push_enter_student_menu(int y);
void StaffMenu();
void push_enter_staff_menu(int y);

void AboutusMenu();
void HelpMenu();

void StudentMenu();
void push_enter_student_menu(int y);

void StaffMenu();
void push_enter_staff_menu(int y);
void Create_School_Year_Menu();
void Info_Menu();


#endif

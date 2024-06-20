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

void SuccessMenu();

void MainMenu();
	void LoginMenu();
		void StaffMenu();
			void Create_School_Year_Menu();
			void Info_Menu();
			void ViewschoolyearMenu();
				//CreateSemester
				//ViewSemesterList
					//CreateCourse
					//ViewCourse
					//InfoCourse
		void StudentMenu();
	
		
		
		
	void AboutusMenu();
	void HelpMenu();
	
	
	
	
	

	
void push_enter_main_menu(int y);


void push_enter_menu_login_2(int y);






void push_enter_student_menu(int y);

void push_enter_staff_menu(int y);





void push_enter_student_menu(int y);


void push_enter_staff_menu(int y);
void Create_School_Year_Menu();
void Cre_sy_menu(int y);


#endif

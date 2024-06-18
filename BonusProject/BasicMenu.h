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
			void CreateSchoolYearMenu();
			void ViewschoolyearMenu();
				void CreateSemesterMenu();
				void ViewSemesterMenu();
					void SpringMenu();
						void CreateCourseMenu();
						void ViewCourseMenu();
							void Course_1_Menu();
					void SummerMenu();
					void CreateCourseMenu();
					void ViewCourseMenu();
						void Course_1_Menu();
					void FallMenu();
					void CreateCourseMenu();
					void ViewCourseMenu();
						void Course_1_Menu();
			void Info_Menu();
		void StudentMenu();
	void AboutusMenu();
	void HelpMenu();



	

	

void push_enter_main_menu(int y);

void push_enter_menu_login_2(int y);

void push_enter_student_menu(int y);

void push_enter_staff_menu(int y);

void push_cre_sy_menu(int y);

void push_enter_view_semester_list(int y);

void push_enter_season_menu(int y);

void push_enter_view_course_list(int y);



#endif

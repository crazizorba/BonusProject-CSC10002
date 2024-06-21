#ifndef BasicMenu_h
#define BasicMenu_h


#include"GraphicBasic.h"
#include"Struct.h"
#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>
#include "Struct.h"
using namespace std;



enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER, BACKSPACE };
typedef char str[31];
TRANGTHAI key(int z);

void SuccessMenu();

void MainMenu(Staff* p);
	void LoginMenu(Staff* p);
	void StaffMenu(Staff* p);
			void CreateSchoolYearMenu(Staff* p);
			void ViewschoolyearMenu(Staff* p);
				void SchoolYearMenu(string year,Staff* p);
					void CreateSemesterMenu(Staff* p);
					void ViewSemesterMenu(Staff* p);
						void SpringMenu(Staff* p);
							void CreateCourseMenu(Staff* p);
							void ViewCourseMenu(Staff* p);
								void Course_1_Menu(Staff* p);
						void SummerMenu(Staff* p);
							void CreateCourseMenu(Staff* p);
							void ViewCourseMenu(Staff* p);
								void Course_1_Menu(Staff* p);
						void FallMenu(Staff* p);
							void CreateCourseMenu(Staff* p);
							void ViewCourseMenu(Staff* p);
								void Course_1_Menu(Staff* p);
			void Info_Menu(Staff* p);
		void StudentMenu(Staff* p);
	void AboutusMenu(Staff* p);
	void HelpMenu(Staff* p);




	

	void push_enter_main_menu(int y, Staff* p);

	void push_enter_menu_login_2(int y, Staff* p);

	void push_enter_student_menu(int y, Staff* p);

	void push_enter_staff_menu(int y, Staff* p);

	void push_cre_sy_menu(int y, Staff* p);

	void push_enter_view_semester_list(int y, Staff* p);

	void push_enter_season_menu(int y, Staff* p);

	void push_enter_view_course_list(int y, Staff* p);






	int count_shoolyear(SchoolYear* p);

	SchoolYear* cre(string a);
	SchoolYear* init_sy();
	void add_year(Staff* p, SchoolYear* tmp);

	void push_enter_view_semester_list(int y, int n, Staff* p);







#endif

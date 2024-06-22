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
					void CreateSemesterMenu_1(Staff* p);
					void CreateSemesterMenu_2(Staff* p);
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
				void EditinfoMenu(Staff* p);
			void ChangePasswordMenu(Staff* p);
		void StudentMenu(Staff* p);
	void AboutusMenu(Staff* p);
	void HelpMenu(Staff* p);

	void CourseMenu(string a, Staff* p);



	void push_enter_main_menu(int y, Staff* p);

	void push_enter_menu_login_2(int y, Staff* p);

	void push_enter_student_menu(int y, Staff* p);

	void push_enter_staff_menu(int y, Staff* p);

	void push_cre_sy_menu(int y, Staff* p);

	void push_enter_view_semester_list_2(int y, Staff* p);
	void push_enter_view_semester_list(int y, int n, Staff* p);


	void push_enter_season_menu(int y, Staff* p);

	void push_enter_view_course_list(int y, Staff* p);


void push_enter_editinfo_menu(int y, Staff* p);

void Edit_ID_Menu(Staff* p);

void Edit_Firstname_Menu(Staff* p);

void Edit_Lastname_Menu(Staff* p);

void Edit_Gender_Menu(Staff* p);

void Edit_DateOfBirth_Menu(Staff* p);

void Edit_SocialID_Menu(Staff* p);





SchoolYear* cre(string a);
SchoolYear* init_sy();
int count_shoolyear(SchoolYear* p);
void add_year(Staff* p, SchoolYear* tmp);

void push_enter_view_schoolyear_list(int y, int n, Staff* p);



Semester* cre_s(int n);
Semester* init_s();
int count_semester(Semester* p);
void AddSemester1(SchoolYear* p, Semester* q);




#endif

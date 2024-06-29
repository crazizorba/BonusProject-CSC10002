#ifndef Merge_h
#define Merge_h



#include"BasicMenu.h"
#include"Struct.h"
#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>

using namespace std;






void MainMenu_s();
	void AboutusMenu_s();//1
	void HelpMenu_s();//2
	void LoginMenu_s(School &S);//3
		void StaffMenu_s(Staff* &p);//3.1
			void AddSchoolYearMenu_s(Staff* &p);//3.1.1
			void InfoMenu_s(Staff*&p);//3.1.2
				void EditInfoMenu_s(Staff* &p);//3.1.2.1
					void Edit_ID_Menu_s(Staff* &p);//3.1.2.1.1
					void Edit_Firstname_Menu_s(Staff* &p);//3.1.2.1.2
					void Edit_Lastname_Menu_s(Staff* &p);//3.1.2.1.3
					void Edit_Gender_Menu_s(Staff* &p);	//3.1.2.1.4
					void Edit_DateOfBirth_Menu_s(Staff* &p);	//3.1.2.1.5
					void Edit_SocialID_Menu_s(Staff* &p);//3.1.2.1.6
			void ViewschoolyearList_s(Staff* &p);//3.1.3
				void SchoolYearMenu_s(Staff*& p, SchoolYear*& q);//3.1.3.1
					void CreateSemesterMenu_s(Staff*& q, SchoolYear*& p);
					void ViewSemesterMenu_s(Staff*& q, SchoolYear*& p);
						void SemesterMenu_s(Staff*& p, SchoolYear*& q, Semester*& r);
							void CreateCourseMenu_s(Staff*& p, SchoolYear*& q, Semester*& r);
							void ViewCourseMenu_s(Staff*& p, SchoolYear*& q, Semester*& r);
		void StudentMenu_s(Student *&p);//3.2
			void InfoMenu_s(Student* &p);//3.2.1


			


#endif

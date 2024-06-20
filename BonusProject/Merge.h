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
	void AboutusMenu_s();
	void HelpMenu_s();
	void LoginMenu_s(School S);
		void StaffMenu_s(Staff* p);
			void AddSchoolYearMenu_s(Staff* &p);
			void InfoMenu_s(Staff*p);

		void StudentMenu_s(Student *p);
			void InfoMenu_s(Student* p);


			void ListSchoolYear(Staff* p);


#endif

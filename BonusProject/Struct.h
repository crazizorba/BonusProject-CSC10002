#ifndef Struct_h
#define Struct_h

#include<iostream>

using namespace std;

struct Student{
	string Password;
	string StudentID;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;
	Student* pNextClass;
	Student* pNextCourse;
};

struct Class{
	string NameClass;
	Student* pHead;
	Class* pNext;
};

struct Course {
	string ID;
	string CourseName;
	string ClassName;
	string TeacherName;
	string Session;
	Student* pHead;
	Course* pNext;
};

struct Semester {
	int Season;
	string StartDay;
	string EndDay;
	Course* pHead;
	Semester* pNext;
};

struct SchoolYear {
	string Year;
	Semester* pHead;
	SchoolYear* pNext;
};

struct Staff{
	string staffID;
	string password;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;
	Class* pHead;
	SchoolYear* pHead;
};



#endif
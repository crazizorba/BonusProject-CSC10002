#ifndef Struct_h
#define Struct_h

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>


using namespace std;

struct InforPerSon {
	string Password;
	string ID;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;
};

struct Student{
	InforPerSon Info;
	Student* pNextClass;
	Student* pNextCourse;
};

struct Class{
	string NameClass;
	Student* pHead;
	Class* pNext;
};

struct Course {
	string CourseID;
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
	InforPerSon Info;
	Class* pClassHead;
	SchoolYear* pSchoolHead;
	Staff* pNext;
};

struct School {
	Staff* pHead;
	string name;
};

//INIT

School InitSchool();

void InitStaff(School p);

void InitSchoolYear(Staff *p);

void InitSemester(SchoolYear* p);

void InitCourse(Semester* p);

void InitStudent(Course* p);

void InitClass(Staff* p);

//ADD

void AddStaff(School p);

void AddSchoolYear(Staff *p);

void AddSemester(SchoolYear* p);

void AddCourse(Semester* p);

void AddStudent(Course* p);

void AddClass(Staff* p);

//CREATE

Staff* CreateStaff(InforPerSon p);

SchoolYear* CreateSchoolYear(string y);

Semester* CreateSemester(int season, string start, string end);

Course* CreateCourse(string CourseID, string CourseName, string ClassName, string TeacherName, string Session);

Student* CreateStudent(InforPerSon p);

Class* CreateClass(string NameClass);

void split();//-----------Tao csv------

void ReadCSVStudent();

Student* getNodeTailClass(Student* pHead);

#endif
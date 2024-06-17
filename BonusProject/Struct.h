#ifndef Struct_h
#define Struct_h

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include"GraphicBasic.h"


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
	int Credit;
	int Size;
	string DayOfWeek;
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


void StaticMain();

//INIT

School InitSchool();



//ADD

void AddStaff(School &p, Staff* q);

void AddSchoolYear(Staff*& p, SchoolYear* q);

void AddSemester(SchoolYear*& p, Semester* q);

void AddCourse(Semester*& p, Course* q);

void AddStudentInCourse(Course*& p, Student* q);

void AddStudentInClass(Class*& p, Student* q);

void AddClass(Staff*& p, Class* q);

//CREATE

Staff* CreateStaff(InforPerSon p);

SchoolYear* CreateSchoolYear(string y);

Semester* CreateSemester(int season, string start, string end);

Course* CreateCourse(string CourseID, string CourseName, string ClassName, string TeacherName, int credit,int size, string dayOfWeek, string Session);

Student* CreateStudent(InforPerSon p);

Class* CreateClass(string NameClass);

void split();//-----------Tao csv------

Class* ReadCSVStudent(const char *p, string name);

string ExtractPassWord(string SocailID);

Student* getNodeTailClass(Student* pHead);

Student* getNodeTailCourse(Student* pHead);

void Build(School &s);

void BuildStaffByReadCSV(School& s, const char* p);

void BuildAllClass(Staff* &p);

void BuildSchoolYear(Staff*& p);

void BuildSemester2122(SchoolYear*& p);

void BuildSemester2223(SchoolYear*& p);

void BuildSemester2324(SchoolYear*& p);

void BuildCourseForSemester1_2324(Semester* p);

void BuildCourseForSemester2_2324(Semester* p);

void BuildCourseForSemester3_2324(Semester* p);

void BuildCourseForSemester1_2223(Semester* p);

void BuildCourseForSemester2_2223(Semester* p);

void BuildCourseForSemester3_2223(Semester* p);

void BuildCourseForSemester1_2122(Semester* p);

void BuildCourseForSemester2_2122(Semester* p);

void BuildCourseForSemester3_2122(Semester* p);

void ReadCSVStudentForCourse( char* p, Course*&c);

char* ConvertStringToCharPath(string a);

void BuildCourse(Staff* p);

void AscendingCourse(Course*&pHead);

void AscendingStudentInCourse(Student*&pHead);

void AscendingStudentInClass(Student*& pHead);

int CountSchoolYearNode(Staff* p);

Staff* LoginStaff(School c, string a, string b);

string getPassword();
#endif
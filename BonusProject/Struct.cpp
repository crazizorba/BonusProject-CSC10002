#include"Struct.h"

//INIT

School InitSchool() {
	School p;
	p.name = "Truong Dai Hoc Khoa Hoc Tu Nhien";
	p.pHead = NULL;
	return p;
}

void InitStaff(School p) {
	p.pHead = NULL;
}

void InitSchoolYear(Staff* p) {
	p->pSchoolHead = NULL;
}

void InitSemester(SchoolYear* p) {
	p->pHead = NULL;
}

void InitCourse(Semester* p) {
	p->pHead = NULL;
}

void InitStudent(Course* p) {
	p->pHead = NULL;
}

void InitClass(Staff* p) {
	p->pClassHead = NULL;
}

//ADD

//void AddStaff(School p);
//
//void AddSchoolYear(Staff* p);
//
//void AddSemester(SchoolYear* p);
//
//void AddCourse(Semester* p);
//
//void AddStudent(Course* p);
//
//void AddClass(Staff* p);

//CREATE

Staff* CreateStaff(InforPerSon p) {
	Staff* q = new Staff;
	q->Info = p;
	InitClass(q);
	InitSchoolYear(q);
	q->pNext = NULL;
	return q;
}

SchoolYear* CreateSchoolYear(string y) {
	SchoolYear* p = new SchoolYear;
	p->Year = y;
	p->pNext = NULL;
	InitSemester(p);
	return p;
}

Semester* CreateSemester(int season, string start, string end) {
	Semester* p = new Semester;
	p->Season = season;
	p->StartDay = start;
	p->EndDay = end;
	p->pNext = NULL;
	InitCourse(p);
	return p;
}

Course* CreateCourse(string CourseID,string CourseName,string ClassName,string TeacherName,string Session) {
	Course* p = new Course;
	p->CourseID = CourseID;
	p->CourseName = CourseName;
	p->TeacherName = TeacherName;
	p->Session = Session;
	p->pNext = NULL;
	InitStudent(p);
	return p;
}

Student* CreateStudent(InforPerSon p) {
	Student* q = new Student;
	q->Info = p;
	q->pNextClass = NULL;
	q->pNextCourse = NULL;
	return q;
}

Class* CreateClass(string NameClass) {
	Class* p = new Class;
	p->NameClass = NameClass;
	p->pHead = NULL;
	p->pNext = NULL;
	return p;
}


void split() {
	vector<string> v;
	ifstream fin;
	fin.open("a.txt");
	while (!fin.eof()) {
		string tmp;
		getline(fin, tmp);
		v.push_back(tmp);
	}
	fin.close();
	for (string x : v) cout << x << endl;
	vector<pair<string, string>> p;
	for (string i : v) {
		int tail = i.size();
		while (i[tail] != ' ')tail--;
		string a = i.substr(0, tail);
		string b = i.substr(tail+1, i.size());
		p.push_back(make_pair(a, b));
	}

	int i = 50;
	for (pair<string, string>x : p) {
		cout << "23200";
		i++;
		if (i < 10) cout << "0" << i;
		else cout << i;
		cout << ",";
		cout << x.first <<","<<x.second<< ","<<rand()%2<<","<<rand() % 31 + 1 << "/" << rand() % 12 + 1 << "/2005,";
		cout << rand() % 89999 + 10000<< rand() % 89999 + 10000 <<rand()%89+10<<endl;

	}
	
}

void ReadCSVStudent() {
	ifstream fin;
	fin.open("23APCS2.csv");
	Class c;
	c.pNext = NULL;
	c.pHead = NULL;
	string tmp;
	
	getline(fin, tmp, '\n');
	cout << tmp<<endl;
	

	while (!fin.eof()) {
		Student* p = new Student;
		p->pNextClass = NULL;
		p->pNextCourse = NULL;
		getline(fin, p->Info.ID, ',');
		getline(fin, p->Info.LastName, ',');
		getline(fin, p->Info.FirstName, ',');
		string tmpG;
		getline(fin, tmpG, ',');
		if (tmpG.compare("0") == 0) p->Info.Gender = 0;
		else p->Info.Gender = 1;
		getline(fin, p->Info.DateOfBirth, ',');
		getline(fin, p->Info.SocialID, '\n');
	
	
		if (c.pHead == NULL) c.pHead = p;
		else {
			Student* tail = getNodeTailClass(c.pHead);
			tail->pNextClass = p;
		}
		
	}
	Student* q = c.pHead;
	int i = 1;
	while (q != NULL) {
		cout << i << ". ";
		cout <<q->Info.ID<<" "<< q->Info.LastName << " " << q->Info.FirstName << " " << q->Info.Gender << endl;
		i++;
		q = q->pNextClass;
	}
	
	fin.close();
}

Student* getNodeTailClass(Student* pHead) {
	Student* p = pHead;
	if (p == NULL) return p;
	else {
		while (p->pNextClass != NULL) p = p->pNextClass;
		return p;
	}

}

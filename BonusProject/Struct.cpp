#include"Struct.h"

void StaticMain() {
	School c;
	Build(c);
	if (1) {
		clrscr();
		cout << "1. Login"<<endl;
		cout << "2.About us" << endl;
		cout << "3. Help" << endl;
		cout << "4. Exit" << endl;
		cout << "**Nhap lua chon: ";
		int tc1;
		cin >> tc1;
		if (tc1 == 1) {
			clrscr();
			//Staff* p = LoginStaff(c);
			//if (p == NULL) cout << "Sai tai khoan hoac mat khau\n";
			//else cout << p->Info.LastName << " " << p->Info.FirstName << endl;
			int n;
			cin >> n;

		}
	}

}

//INIT

School InitSchool() {
	School p;
	p.name = "Truong Dai Hoc Khoa Hoc Tu Nhien";
	p.pHead = NULL;
	return p;
}



//ADD

void AddStaff(School &p, Staff* q) {
	if (p.pHead == NULL) p.pHead = q;
	else {
		Staff* tmp = p.pHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
		q->pClassHead = tmp->pClassHead;
		q->pSchoolHead = tmp->pSchoolHead;
	}
}

void AddSchoolYear(Staff* &p, SchoolYear* q) {
	if (p->pSchoolHead == NULL) p->pSchoolHead = q;
	else {
		SchoolYear* tmp = p->pSchoolHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
	}
}

void AddSemester(SchoolYear* &p, Semester* q) {
	if (p->pHead == NULL) p->pHead = q;
	else {
		Semester* tmp = p->pHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
	}
}

void AddCourse(Semester* &p,Course*q) {
	if (p->pHead == NULL) p->pHead = q;
	else {
		Course* tmp = p->pHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
	}
}

void AddStudentInCourse(Course* &p, Student* q) {
	if (p->pHead == NULL) p->pHead = q;
	else {
		Student* tail = getNodeTailCourse(p->pHead);
		tail->pNextCourse = q;
	}
}

void AddStudentInClass(Class* &p,Student *q) {
	if (p->pHead == NULL) p->pHead = q;
	else {
		Student* tail = getNodeTailClass(p->pHead);
		tail->pNextClass = q;
	}
}

Student* getNodeTailClass(Student* pHead) {
	Student* p = pHead;
	if (p == NULL) return p;
	else {
		while (p->pNextClass != NULL) p = p->pNextClass;
		return p;
	}

}

Student* getNodeTailCourse(Student* pHead) {
	Student* p = pHead;
	if (p == NULL) return p;
	else {
		while (p->pNextCourse != NULL) p = p->pNextCourse;
		return p;
	}
}

void AddClass(Staff* &p, Class* q) {
	if (p->pClassHead == NULL) p->pClassHead = q;
	else {
		Class* tmp = p->pClassHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
	}
}

//CREATE

Staff* CreateStaff(InforPerSon p) {
	Staff* q = new Staff;
	q->Info = p;
	q->pClassHead = NULL;
	q->pSchoolHead = NULL;
	q->pNext = NULL;
	return q;
}

SchoolYear* CreateSchoolYear(string y) {
	SchoolYear* p = new SchoolYear;
	p->Year = y;
	p->pNext = NULL;
	p->pHead = NULL;
	return p;
}

Semester* CreateSemester(int season, string start, string end) {
	Semester* p = new Semester;
	p->Season = season;
	p->StartDay = start;
	p->EndDay = end;
	p->pNext = NULL;
	p->pHead = NULL;
	return p;
}

Course* CreateCourse(string CourseID,string CourseName,string ClassName,string TeacherName,int credit,int size,string dayOfWeek,string Session) {
	Course* p = new Course;
	p->Size = size;
	p->Credit = credit;
	p->CourseID = CourseID;
	p->CourseName = CourseName;
	p->ClassName = ClassName;
	p->TeacherName = TeacherName;
	p->DayOfWeek = dayOfWeek;
	p->Session = Session;
	p->pNext = NULL;
	p->pHead = NULL;
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

	int i = 0;
	for (pair<string, string>x : p) {
		cout << "C19000";
		i++;
		if (i < 10) cout << "0" << i;
		else cout << i;
		cout << ",";
		cout << x.first <<","<<x.second<< ","<<rand()%2<<","<<rand() % 31 + 1 << "/" << rand() % 12 + 1 << "/1980,";
		cout << rand() % 89999 + 10000<< rand() % 89999 + 10000 <<rand()%89+10<<endl;

	}
	
}

Class* ReadCSVStudent(const char* p, string name) {
	ifstream fin;
	fin.open(p);
	Class *c=CreateClass(name);
	string tmp;
	
	getline(fin, tmp, '\n');
	while (!fin.eof()) {
		InforPerSon q;
		getline(fin, q.ID, ',');
		getline(fin, q.LastName, ',');
		getline(fin, q.FirstName, ',');
		string tmpG;
		getline(fin, tmpG, ',');
		if (tmpG.compare("0") == 0) q.Gender = 0;
		else q.Gender = 1;
		getline(fin, q.DateOfBirth, ',');
		getline(fin, q.SocialID, '\n');
		q.Password = ExtractPassWord(q.SocialID);
		Student* p = CreateStudent(q);
		AddStudentInClass(c, p);
		
	}
	fin.close();
	return c;
}

string ExtractPassWord(string SocailID) {
	string pass = SocailID.substr(0, 6);
	return pass;
}

//-------------------IMPORTANT-------------------
//-----------------------------------------------

void Build(School &s) {
	s = InitSchool();
	
	BuildStaffByReadCSV(s, "Staff.csv");
	
	BuildAllClass(s.pHead);
	
	BuildSchoolYear(s.pHead);
	
	BuildSemester2122(s.pHead->pSchoolHead);
	BuildSemester2223(s.pHead->pSchoolHead->pNext);
	BuildSemester2324(s.pHead->pSchoolHead->pNext->pNext);
	
	BuildCourseForSemester1_2122(s.pHead->pSchoolHead->pHead);
	BuildCourseForSemester2_2122(s.pHead->pSchoolHead->pHead->pNext);
	BuildCourseForSemester3_2122(s.pHead->pSchoolHead->pHead->pNext->pNext);
	BuildCourseForSemester1_2223(s.pHead->pSchoolHead->pNext->pHead);
	BuildCourseForSemester2_2223(s.pHead->pSchoolHead->pNext->pHead->pNext);
	BuildCourseForSemester3_2223(s.pHead->pSchoolHead->pNext->pHead->pNext->pNext);
	BuildCourseForSemester1_2324(s.pHead->pSchoolHead->pNext->pNext->pHead);
	BuildCourseForSemester2_2324(s.pHead->pSchoolHead->pNext->pNext->pHead->pNext);
	BuildCourseForSemester3_2324(s.pHead->pSchoolHead->pNext->pNext->pHead->pNext->pNext);
	
	AscendingCourse(s.pHead->pSchoolHead->pHead->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pHead->pNext->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pHead->pNext->pNext->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pHead->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pHead->pNext->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pHead->pNext->pNext->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pNext->pHead->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pNext->pHead->pNext->pHead);
	AscendingCourse(s.pHead->pSchoolHead->pNext->pNext->pHead->pNext->pNext->pHead);
	
	BuildCourse(s.pHead);

	Staff* tmp = s.pHead->pNext;
	while (tmp != NULL) {
		tmp->pClassHead = s.pHead->pClassHead;
		tmp->pSchoolHead = s.pHead->pSchoolHead;
		tmp = tmp->pNext;
	}
	

}

void BuildStaffByReadCSV(School& s, const char* p) {
	ifstream fin;
	fin.open(p);
	while (!fin.eof()) {
		InforPerSon q;
		getline(fin, q.ID, ',');
		getline(fin, q.LastName, ',');
		getline(fin, q.FirstName, ',');
		string tmpG;
		getline(fin, tmpG, ',');
		if (tmpG.compare("0") == 0) q.Gender = 0;
		else q.Gender = 1;
		getline(fin, q.DateOfBirth, ',');
		getline(fin, q.SocialID, '\n');
		q.Password = ExtractPassWord(q.SocialID);
		Staff* k = CreateStaff(q);
		AddStaff(s, k);

	}
	fin.close();
}

void BuildAllClass(Staff* &p) {
	Class* p1 = ReadCSVStudent("20APCS1.csv", "20APCS1");
	Class* p2 = ReadCSVStudent("20APCS2.csv", "20APCS2");
	Class* p3 = ReadCSVStudent("20CLC1.csv", "20CLC1");
	Class* p4 = ReadCSVStudent("20CLC2.csv", "20CLC2");
	Class* p5 = ReadCSVStudent("20CTT1.csv", "20CTT1");
	Class* p6 = ReadCSVStudent("20CTT2.csv", "20CTT2");
	Class* p7 = ReadCSVStudent("21APCS1.csv", "21APCS1");
	Class* p8 = ReadCSVStudent("21APCS2.csv", "21APCS2");
	Class* p9 = ReadCSVStudent("21CLC1.csv", "21CLC1");
	Class* p10 = ReadCSVStudent("21CLC2.csv", "21CLC2");
	Class* p11 = ReadCSVStudent("21CTT1.csv", "21CTT1");
	Class* p12 = ReadCSVStudent("21CTT2.csv", "21CTT2");
	Class* p13 = ReadCSVStudent("22APCS1.csv", "22APCS1");
	Class* p14 = ReadCSVStudent("22APCS2.csv", "22APCS2");
	Class* p15 = ReadCSVStudent("22CLC1.csv", "22CLC1");
	Class* p16 = ReadCSVStudent("22CLC2.csv", "22CLC2");
	Class* p17 = ReadCSVStudent("22CTT1.csv", "22CTT1");
	Class* p18 = ReadCSVStudent("22CTT2.csv", "22CTT2");
	Class* p19 = ReadCSVStudent("23APCS1.csv", "23APCS1");
	Class* p20 = ReadCSVStudent("23APCS2.csv", "23APCS2");
	Class* p21 = ReadCSVStudent("23CLC1.csv", "23CLC1");
	Class* p22 = ReadCSVStudent("23CLC2.csv", "23CLC2");
	Class* p23 = ReadCSVStudent("23CTT1.csv", "23CTT1");
	Class* p24 = ReadCSVStudent("23CTT2.csv", "23CTT2");
	AddClass(p, p1);
	AddClass(p, p2);
	AddClass(p, p3);
	AddClass(p, p4);
	AddClass(p, p5);
	AddClass(p, p6);
	AddClass(p, p7);
	AddClass(p, p8);
	AddClass(p, p9);
	AddClass(p, p10);
	AddClass(p, p11);
	AddClass(p, p12);
	AddClass(p, p13);
	AddClass(p, p14);
	AddClass(p, p15);
	AddClass(p, p16);
	AddClass(p, p17);
	AddClass(p, p18);
	AddClass(p, p19);
	AddClass(p, p20);
	AddClass(p, p21);
	AddClass(p, p22);
	AddClass(p, p23);
	AddClass(p, p24);
}

void BuildSchoolYear(Staff*& p) {
	SchoolYear* p2 = CreateSchoolYear("2021-2022");
	SchoolYear* p3 = CreateSchoolYear("2022-2023");
	SchoolYear* p4 = CreateSchoolYear("2023-2024");
	AddSchoolYear(p, p2);
	AddSchoolYear(p, p3);
	AddSchoolYear(p, p4);
}

void BuildSemester2122(SchoolYear*& p) {
	Semester* p1 = CreateSemester(1, "25/09/2021", "30/01/2022");
	Semester* p2 = CreateSemester(2, "01/03/2022", "07/07/2022");
	Semester* p3 = CreateSemester(3, "14/08/2022", "15/09/2022");
	AddSemester(p, p1);
	AddSemester(p, p2);
	AddSemester(p, p3);
}

void BuildSemester2223(SchoolYear*& p) {
	Semester* p1 = CreateSemester(1, "25/09/2022", "30/01/2023");
	Semester* p2 = CreateSemester(2, "01/03/2023", "07/07/2023");
	Semester* p3 = CreateSemester(3, "14/08/2023", "15/09/2023");
	AddSemester(p, p1);
	AddSemester(p, p2);
	AddSemester(p, p3);
}

void BuildSemester2324(SchoolYear*& p) {
	Semester* p1 = CreateSemester(1, "25/09/2023", "30/01/2024");
	Semester* p2 = CreateSemester(2, "01/03/2024", "07/07/2024");
	Semester* p3 = CreateSemester(3, "14/08/2024", "15/09/2024");
	AddSemester(p, p1);
	AddSemester(p, p2);
	AddSemester(p, p3);
}

void BuildCourseForSemester1_2324(Semester* p) {
	Course* p1 = CreateCourse("CSC10001", "Nhap mon lap trinh", "23CTT1", "Le Van Lang", 3,120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10001", "Nhap mon lap trinh", "23APCS1", "Pham Tran Khanh Ngoc",120, 3, "WED", "S2");
	Course* p3 = CreateCourse("CSC10001", "Nhap mon lap trinh", "23APCS2", "Tran Le Cam Nhan", 3,120, "TUE", "S3");
	Course* p4 = CreateCourse("CSC10001", "Nhap mon lap trinh", "23CLC1", "Huynh Minh Hieu", 3,120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00041", "Toan roi rac", "23CTT2", "Bao Gia Bao", 3,120, "FRI", "S1");
	Course* p6 = CreateCourse("MTH00041", "Toan roi rac", "23CLC2", "Doan Xuan Khanh", 3,120, "SAT", "S2");
	Course* p7 = CreateCourse("MTH00041", "Toan roi rac", "23APCS1", "Tran Dinh Van", 3,120, "MON", "S3");
	Course* p8 = CreateCourse("MTH00003", "Vi tich phan 1B", "23CTT1", "Bao Gia Bao", 3,120, "TUE", "S4");
	Course* p9 = CreateCourse("MTH00003", "Vi tich phan 1B", "23CLC1", "Huynh Nhi Thuong", 3, 120, "WED", "S1");
	Course* p10 = CreateCourse("MTH00003", "Vi tich phan 1B", "23APCS2", "Diep Bao Ngoc", 3, 120, "THU", "S2");
	Course* p11 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "22CTT1", "Nong Van Dien", 3, 120, "FRI", "S3");
	Course* p12 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "22CTT2", "Pham Van Minh Tuan", 3, 120, "SAT", "S4");
	Course* p13 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "22CLC1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p14 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "22APCS1", "Duong Phuoc Hai Tho", 3, 120, "TUE", "S2");
	Course* p15 = CreateCourse("CSC10006", "Co so du lieu", "22CLC2", "Nguyen Van Tu Anh", 3, 120, "WED", "S3");
	Course* p16 = CreateCourse("CSC10006", "Co so du lieu", "22APCS2", "Nguyen Kieu My", 3, 120, "THU", "S4");
	Course* p17 = CreateCourse("CSC00006", "Co so du lieu", "22CTT1", "Phan Kha Khat", 3, 120, "FRI", "S1");
	Course* p18 = CreateCourse("MTH00040", "Xac suat thong ke", "22CTT2", "Ngo Thi Yen Nhi", 3, 120, "SAT", "S2");
	Course* p19 = CreateCourse("MTH00040", "Xac suat thong ke", "22APCS1", "Nguyen Bich Tram", 3, 120, "MON", "S3");
	Course* p20 = CreateCourse("MTH00040", "Xac suat thong ke", "22CLC1", "Truong Thi Lien", 3, 120, "TUE", "S4");
	Course* p21 = CreateCourse("CSC10007", "He dieu hanh", "21APCS1", "Pham Nang Tuan", 3, 120, "WED", "S1");
	Course* p22 = CreateCourse("CSC10007", "He dieu hanh", "21CTT1", "Huynh Ngoc Cong Danh", 3, 120, "WED", "S2");
	Course* p23 = CreateCourse("CSC10007", "He dieu hanh", "21CTT2", "Huynh Thi Thu Xoan", 3, 120, "THU", "S3");
	Course* p24 = CreateCourse("CSC10007", "He dieu hanh", "21CLC2", "Kieu Chi Minh", 3, 120, "FRI", "S4");
	Course* p25 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "21CLC1", "Huynh Bao Uyen", 3, 120, "SAT", "S1");
	Course* p26 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "21APCS1", "Pham Tran Khanh Ngoc", 3, 120, "MON", "S2");
	Course* p27 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "21CTT1", "Tran Duy Huong", 3, 120, "TUE", "S3");
	Course* p28 = CreateCourse("MTH00053", "Ly thuat so", "21CTT2", "Doan Xuan Khanh", 3, 120, "WED", "S4");
	Course* p29 = CreateCourse("MTH00053", "Ly thuat so", "21CLC2", "Hoang Xuan Vuong", 3, 120, "THU", "S1");
	Course* p30 = CreateCourse("MTH00053", "Ly thuat so", "21APCS2", "Nguyen Son Lam", 3, 120, "FRI", "S2");
	Course* p31 = CreateCourse("CSC10251", "Khoa luan tot nghiep", "20CTT1", "Ngo Hoang Duong", 3, 1200, "SAT", "S3");
	Course* p32 = CreateCourse("CSC10252", "Thuc tap tot nghiep", "20APCS1", "Le Chi Dung", 3, 1200, "MON", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20); AddCourse(p, p21); AddCourse(p, p22); AddCourse(p, p23); AddCourse(p, p24); 
	AddCourse(p, p25); AddCourse(p, p26); AddCourse(p, p27); AddCourse(p, p28); AddCourse(p, p29); AddCourse(p, p30); 
	AddCourse(p, p31); AddCourse(p, p32);
}

void BuildCourseForSemester2_2324(Semester* p) {
	Course* p1 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "23CTT1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "23CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S2");
	Course* p3 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "23APCS1", "Duong Thanh Dat", 3, 120, "WED", "S3");
	Course* p4 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "23CLC1", "Vu Hoang Phuong Bac", 3, 120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00030", "Dai so tuyen tinh", "23APCS2", "Ho Anh Dung", 3, 120, "FRI", "S4");
	Course* p6 = CreateCourse("MTH00030", "Dai so tuyen tinh", "23CLC2", "Le Anh Khoa", 3, 120, "SAT", "S1");
	Course* p7 = CreateCourse("MTH00030", "Dai so tuyen tinh", "23CTT1", "Le Doan Thao Lien", 3, 120, "MON", "S2");
	Course* p8 = CreateCourse("MTH00004", "Vi tich phan 2B", "23CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S3");
	Course* p9 = CreateCourse("MTH00004", "Vi tich phan 2B", "23APCS1", "Ho Anh Dung", 3, 120, "WED", "S4");
	Course* p10 = CreateCourse("MTH00004", "Vi tich phan 2B", "23CLC1", "Nguyen Van Phu", 3, 120, "THU", "S1");
	Course* p11 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "22CTT1", "Chu Minh Anh", 3, 120, "FRI", "S2");
	Course* p12 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "22CTT2", "Nguyen Thanh Tam", 3, 120, "SAT", "S3");
	Course* p13 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "22APCS1", "Nguyen Gia Vinh", 3, 120, "MON", "S4");
	Course* p14 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "22CLC1", "Vuong Gia An", 3, 120, "TUE", "S1");
	Course* p15 = CreateCourse("CSC10008", "Mang may tinh", "22CTT1", "Luong Huu Vuong", 3, 120, "WED", "S2");
	Course* p16 = CreateCourse("CSC10008", "Mang may tinh", "22APCS2", "Nguyen Tan Dieu", 3, 120, "THU", "S3");
	Course* p17 = CreateCourse("CSC10008", "Mang may tinh", "22CLC2", "Huynh Nhu Y", 3, 120, "FRI", "S4");
	Course* p18 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "22CTT2", "Pham Thi Dai Trang", 3, 120, "SAT", "S1");
	Course* p19 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "22APCS1", "Pham Thanh Huy", 3, 120, "MON", "S2");
	Course* p20 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "22CLC2", "Tran Thi Diem Le", 3, 120, "TUE", "S3");
	Course* p21 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "21CLC1", "Tran Vinh Khang", 3, 120, "WED", "S3");
	Course* p22 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "21CLC2", "Tat Tan Hy", 3, 120, "THU", "S4");
	Course* p23 = CreateCourse("CSC14003", "Co so tri tue nhan tao","21CTT1", "Trinh Thanh Tu", 3, 120, "FRI", "S1");
	Course* p24 = CreateCourse("CSC14003", "Co so tri tue nhan tao","21APCS1", "Trinh Hoang Nguyen", 3, 120, "SAT", "S2");
	Course* p25 = CreateCourse("CSC10009", "He thong may tinh", "21CTT2", "Tran Quoc Truong", 3, 120, "MON", "S3");
	Course* p26 = CreateCourse("CSC10009", "He thong may tinh", "21APCS2", "Vo Nguyen Bao Loc", 3, 120, "TUE", "S4");
	Course* p27 = CreateCourse("CSC10009", "He thong may tinh", "21CLC1", "Tran Vinh Khang", 3, 120, "WED", "S1");
	Course* p28 = CreateCourse("MTH00052", "Phuong phap tinh", "21CTT1", "Do Thanh Kiet", 3, 120, "THU", "S2");
	Course* p29 = CreateCourse("MTH00052", "Phuong phap tinh", "21APCS1", "Huynh Phuoc Thanh", 3, 120, "FRI", "S3");
	Course* p30 = CreateCourse("MTH00052", "Phuong phap tinh", "21CLC2", "Pham Nang Tuan", 3, 120, "SAT", "S4");
	Course* p31 = CreateCourse("CSC10251", "Khoa luan tot nghiep", "20CTT2", "Truong Hong Hai", 3, 1200, "MON", "S1");
	Course* p32 = CreateCourse("CSC10252", "Thuc tap tot nghiep", "20APCS2", "Huynh Ngoc Cong Danh", 3, 1200, "TUE", "S2");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20); AddCourse(p, p21); AddCourse(p, p22); AddCourse(p, p23); AddCourse(p, p24);
	AddCourse(p, p25); AddCourse(p, p26); AddCourse(p, p27); AddCourse(p, p28); AddCourse(p, p29); AddCourse(p, p30);
	AddCourse(p, p31); AddCourse(p, p32);
}

void BuildCourseForSemester3_2324(Semester* p) {
	Course* p1 = CreateCourse("MTH00041", "Toan roi rac", "23C2_1", "Nguyen Hoang Nhat Ha", 3,120, "MON", "S1");
	Course* p2 = CreateCourse("MTH00003", "Vi tich phan 1B", "23C3_2", "Pham Duy Linh", 3,120, "TUE", "S2");
	Course* p3 = CreateCourse("MTH00004", "Vi tich phan 2B", "23C4_3", "Thach Canh Nhat", 3,120, "WED", "S3");
	Course* p4 = CreateCourse("MTH00030", "Dai so tuyen tinh", "23C5_1", "Tran The My Ngu", 3,120, "THU", "S1");
	Course* p5 = CreateCourse("CSC10006", "Co so du lieu", "22C6_2", "Tran Quoc Son", 3,120, "FRI", "S2");
	Course* p6 = CreateCourse("MTH00040", "Xac suat thong ke", "22C7_3", "Tram Thanh Huy", 3,120, "SAT", "S3");
	Course* p7 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "22C2_4", "Nguyen Phan Khiet Thanh", 3,120, "MON", "S4");
	Course* p8 = CreateCourse("MTH00053", "Ly thuat so", "21C3_1", "Dang Duc Bao", 3,120, "TUE", "S1");
	Course* p9 = CreateCourse("MTH00052", "Phuong phap tinh", "21C4_2", "Hoang Thi Kim Phuong", 3,120, "WED", "S2");
	Course* p10 = CreateCourse("CSC10008", "Mang may tinh", "22C5_4", "Tran Thi Tu Uyen", 3,120, "THU", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10);
}

void BuildCourseForSemester1_2223(Semester* p) {
	Course* p1 = CreateCourse("CSC10001", "Nhap mon lap trinh", "22CTT1", "Le Van Lang", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10001", "Nhap mon lap trinh", "22APCS1", "Pham Tran Khanh Ngoc", 120, 3, "WED", "S2");
	Course* p3 = CreateCourse("CSC10001", "Nhap mon lap trinh", "22APCS2", "Tran Le Cam Nhan", 3, 120, "TUE", "S3");
	Course* p4 = CreateCourse("CSC10001", "Nhap mon lap trinh", "22CLC1", "Huynh Minh Hieu", 3, 120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00041", "Toan roi rac", "22CTT2", "Bao Gia Bao", 3, 120, "FRI", "S1");
	Course* p6 = CreateCourse("MTH00041", "Toan roi rac", "22CLC2", "Doan Xuan Khanh", 3, 120, "SAT", "S2");
	Course* p7 = CreateCourse("MTH00041", "Toan roi rac", "22APCS1", "Tran Dinh Van", 3, 120, "MON", "S3");
	Course* p8 = CreateCourse("MTH00003", "Vi tich phan 1B", "22CTT1", "Bao Gia Bao", 3, 120, "TUE", "S4");
	Course* p9 = CreateCourse("MTH00003", "Vi tich phan 1B", "22CLC1", "Huynh Nhi Thuong", 3, 120, "WED", "S1");
	Course* p10 = CreateCourse("MTH00003", "Vi tich phan 1B", "22APCS2", "Diep Bao Ngoc", 3, 120, "THU", "S2");
	Course* p11 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "21CTT1", "Nong Van Dien", 3, 120, "FRI", "S3");
	Course* p12 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "21CTT2", "Pham Van Minh Tuan", 3, 120, "SAT", "S4");
	Course* p13 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "21CLC1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p14 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "21APCS1", "Duong Phuoc Hai Tho", 3, 120, "TUE", "S2");
	Course* p15 = CreateCourse("CSC10006", "Co so du lieu", "21CLC2", "Nguyen Van Tu Anh", 3, 120, "WED", "S3");
	Course* p16 = CreateCourse("CSC10006", "Co so du lieu", "21APCS2", "Nguyen Kieu My", 3, 120, "THU", "S4");
	Course* p17 = CreateCourse("CSC00006", "Co so du lieu", "21CTT1", "Phan Kha Khat", 3, 120, "FRI", "S1");
	Course* p18 = CreateCourse("MTH00040", "Xac suat thong ke", "21CTT2", "Ngo Thi Yen Nhi", 3, 120, "SAT", "S2");
	Course* p19 = CreateCourse("MTH00040", "Xac suat thong ke", "21APCS1", "Nguyen Bich Tram", 3, 120, "MON", "S3");
	Course* p20 = CreateCourse("MTH00040", "Xac suat thong ke", "21CLC1", "Truong Thi Lien", 3, 120, "TUE", "S4");
	Course* p21 = CreateCourse("CSC10007", "He dieu hanh", "20APCS1", "Pham Nang Tuan", 3, 120, "WED", "S1");
	Course* p22 = CreateCourse("CSC10007", "He dieu hanh", "20CTT1", "Huynh Ngoc Cong Danh", 3, 120, "WED", "S2");
	Course* p23 = CreateCourse("CSC10007", "He dieu hanh", "20CTT2", "Huynh Thi Thu Xoan", 3, 120, "THU", "S3");
	Course* p24 = CreateCourse("CSC10007", "He dieu hanh", "20CLC2", "Kieu Chi Minh", 3, 120, "FRI", "S4");
	Course* p25 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "20CLC1", "Huynh Bao Uyen", 3, 120, "SAT", "S1");
	Course* p26 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "20APCS1", "Pham Tran Khanh Ngoc", 3, 120, "MON", "S2");
	Course* p27 = CreateCourse("CSC13002", "Nhap mon cong nghe phan mem", "20CTT1", "Tran Duy Huong", 3, 120, "TUE", "S3");
	Course* p28 = CreateCourse("MTH00053", "Ly thuat so", "20CTT2", "Doan Xuan Khanh", 3, 120, "WED", "S4");
	Course* p29 = CreateCourse("MTH00053", "Ly thuat so", "20CLC2", "Hoang Xuan Vuong", 3, 120, "THU", "S1");
	Course* p30 = CreateCourse("MTH00053", "Ly thuat so", "20APCS2", "Nguyen Son Lam", 3, 120, "FRI", "S2");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20); AddCourse(p, p21); AddCourse(p, p22); AddCourse(p, p23); AddCourse(p, p24);
	AddCourse(p, p25); AddCourse(p, p26); AddCourse(p, p27); AddCourse(p, p28); AddCourse(p, p29); AddCourse(p, p30);
}

void BuildCourseForSemester2_2223(Semester* p) {
	Course* p1 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "22CTT1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "22CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S2");
	Course* p3 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "22APCS1", "Duong Thanh Dat", 3, 120, "WED", "S3");
	Course* p4 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "22CLC1", "Vu Hoang Phuong Bac", 3, 120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00030", "Dai so tuyen tinh", "22APCS2", "Ho Anh Dung", 3, 120, "FRI", "S4");
	Course* p6 = CreateCourse("MTH00030", "Dai so tuyen tinh", "22CLC2", "Le Anh Khoa", 3, 120, "SAT", "S1");
	Course* p7 = CreateCourse("MTH00030", "Dai so tuyen tinh", "22CTT1", "Le Doan Thao Lien", 3, 120, "MON", "S2");
	Course* p8 = CreateCourse("MTH00004", "Vi tich phan 2B", "22CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S3");
	Course* p9 = CreateCourse("MTH00004", "Vi tich phan 2B", "22APCS1", "Ho Anh Dung", 3, 120, "WED", "S4");
	Course* p10 = CreateCourse("MTH00004", "Vi tich phan 2B", "22CLC1", "Nguyen Van Phu", 3, 120, "THU", "S1");
	Course* p11 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "21CTT1", "Chu Minh Anh", 3, 120, "FRI", "S2");
	Course* p12 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "21CTT2", "Nguyen Thanh Tam", 3, 120, "SAT", "S3");
	Course* p13 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "21APCS1", "Nguyen Gia Vinh", 3, 120, "MON", "S4");
	Course* p14 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "21CLC1", "Vuong Gia An", 3, 120, "TUE", "S1");
	Course* p15 = CreateCourse("CSC10008", "Mang may tinh", "21CTT1", "Luong Huu Vuong", 3, 120, "WED", "S2");
	Course* p16 = CreateCourse("CSC10008", "Mang may tinh", "21APCS2", "Nguyen Tan Dieu", 3, 120, "THU", "S3");
	Course* p17 = CreateCourse("CSC10008", "Mang may tinh", "21CLC2", "Huynh Nhu Y", 3, 120, "FRI", "S4");
	Course* p18 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "21CTT2", "Pham Thi Dai Trang", 3, 120, "SAT", "S1");
	Course* p19 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "21APCS1", "Pham Thanh Huy", 3, 120, "MON", "S2");
	Course* p20 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "21CLC2", "Tran Thi Diem Le", 3, 120, "TUE", "S3");
	Course* p21 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "20CLC1", "Tran Vinh Khang", 3, 120, "WED", "S3");
	Course* p22 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "20CLC2", "Tat Tan Hy", 3, 120, "THU", "S4");
	Course* p23 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "20CTT1", "Trinh Thanh Tu", 3, 120, "FRI", "S1");
	Course* p24 = CreateCourse("CSC14003", "Co so tri tue nhan tao", "20APCS1", "Trinh Hoang Nguyen", 3, 120, "SAT", "S2");
	Course* p25 = CreateCourse("CSC10009", "He thong may tinh", "20CTT2", "Tran Quoc Truong", 3, 120, "MON", "S3");
	Course* p26 = CreateCourse("CSC10009", "He thong may tinh", "20APCS2", "Vo Nguyen Bao Loc", 3, 120, "TUE", "S4");
	Course* p27 = CreateCourse("CSC10009", "He thong may tinh", "20CLC1", "Tran Vinh Khang", 3, 120, "WED", "S1");
	Course* p28 = CreateCourse("MTH00052", "Phuong phap tinh", "20CTT1", "Do Thanh Kiet", 3, 120, "THU", "S2");
	Course* p29 = CreateCourse("MTH00052", "Phuong phap tinh", "20APCS1", "Huynh Phuoc Thanh", 3, 120, "FRI", "S3");
	Course* p30 = CreateCourse("MTH00052", "Phuong phap tinh", "20CLC2", "Pham Nang Tuan", 3, 120, "SAT", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20); AddCourse(p, p21); AddCourse(p, p22); AddCourse(p, p23); AddCourse(p, p24);
	AddCourse(p, p25); AddCourse(p, p26); AddCourse(p, p27); AddCourse(p, p28); AddCourse(p, p29); AddCourse(p, p30);
}

void BuildCourseForSemester3_2223(Semester* p) {
	Course* p1 = CreateCourse("MTH00041", "Toan roi rac", "22C2_1", "Nguyen Hoang Nhat Ha", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("MTH00003", "Vi tich phan 1B", "22C3_2", "Pham Duy Linh", 3, 120, "TUE", "S2");
	Course* p3 = CreateCourse("MTH00004", "Vi tich phan 2B", "22C4_3", "Thach Canh Nhat", 3, 120, "WED", "S3");
	Course* p4 = CreateCourse("MTH00030", "Dai so tuyen tinh", "22C5_1", "Tran The My Ngu", 3, 120, "THU", "S1");
	Course* p5 = CreateCourse("CSC10006", "Co so du lieu", "21C6_2", "Tran Quoc Son", 3, 120, "FRI", "S2");
	Course* p6 = CreateCourse("MTH00040", "Xac suat thong ke", "21C7_3", "Tram Thanh Huy", 3, 120, "SAT", "S3");
	Course* p7 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "21C2_4", "Nguyen Phan Khiet Thanh", 3, 120, "MON", "S4");
	Course* p8 = CreateCourse("MTH00053", "Ly thuat so", "20C3_1", "Dang Duc Bao", 3, 120, "TUE", "S1");
	Course* p9 = CreateCourse("MTH00052", "Phuong phap tinh", "20C4_2", "Hoang Thi Kim Phuong", 3, 120, "WED", "S2");
	Course* p10 = CreateCourse("CSC10008", "Mang may tinh", "21C5_4", "Tran Thi Tu Uyen", 3, 120, "THU", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10);
}

void BuildCourseForSemester1_2122(Semester* p) {
	Course* p1 = CreateCourse("CSC10001", "Nhap mon lap trinh", "21CTT1", "Le Van Lang", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10001", "Nhap mon lap trinh", "21APCS1", "Pham Tran Khanh Ngoc", 120, 3, "WED", "S2");
	Course* p3 = CreateCourse("CSC10001", "Nhap mon lap trinh", "21APCS2", "Tran Le Cam Nhan", 3, 120, "TUE", "S3");
	Course* p4 = CreateCourse("CSC10001", "Nhap mon lap trinh", "21CLC1", "Huynh Minh Hieu", 3, 120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00041", "Toan roi rac", "21CTT2", "Bao Gia Bao", 3, 120, "FRI", "S1");
	Course* p6 = CreateCourse("MTH00041", "Toan roi rac", "21CLC2", "Doan Xuan Khanh", 3, 120, "SAT", "S2");
	Course* p7 = CreateCourse("MTH00041", "Toan roi rac", "21APCS1", "Tran Dinh Van", 3, 120, "MON", "S3");
	Course* p8 = CreateCourse("MTH00003", "Vi tich phan 1B", "21CTT1", "Bao Gia Bao", 3, 120, "TUE", "S4");
	Course* p9 = CreateCourse("MTH00003", "Vi tich phan 1B", "21CLC1", "Huynh Nhi Thuong", 3, 120, "WED", "S1");
	Course* p10 = CreateCourse("MTH00003", "Vi tich phan 1B", "21APCS2", "Diep Bao Ngoc", 3, 120, "THU", "S2");
	Course* p11 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "20CTT1", "Nong Van Dien", 3, 120, "FRI", "S3");
	Course* p12 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "20CTT2", "Pham Van Minh Tuan", 3, 120, "SAT", "S4");
	Course* p13 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "20CLC1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p14 = CreateCourse("CSC10004", "Cau truc du lieu & Giai thuat", "20APCS1", "Duong Phuoc Hai Tho", 3, 120, "TUE", "S2");
	Course* p15 = CreateCourse("CSC10006", "Co so du lieu", "20CLC2", "Nguyen Van Tu Anh", 3, 120, "WED", "S3");
	Course* p16 = CreateCourse("CSC10006", "Co so du lieu", "20APCS2", "Nguyen Kieu My", 3, 120, "THU", "S4");
	Course* p17 = CreateCourse("CSC00006", "Co so du lieu", "20CTT1", "Phan Kha Khat", 3, 120, "FRI", "S1");
	Course* p18 = CreateCourse("MTH00040", "Xac suat thong ke", "20CTT2", "Ngo Thi Yen Nhi", 3, 120, "SAT", "S2");
	Course* p19 = CreateCourse("MTH00040", "Xac suat thong ke", "20APCS1", "Nguyen Bich Tram", 3, 120, "MON", "S3");
	Course* p20 = CreateCourse("MTH00040", "Xac suat thong ke", "20CLC1", "Truong Thi Lien", 3, 120, "TUE", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20);
}

void BuildCourseForSemester2_2122(Semester* p) {
	Course* p1 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "21CTT1", "Le Nguyen Tuan", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "21CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S2");
	Course* p3 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "21APCS1", "Duong Thanh Dat", 3, 120, "WED", "S3");
	Course* p4 = CreateCourse("CSC10002", "Ky thuat Lap trinh", "21CLC1", "Vu Hoang Phuong Bac", 3, 120, "THU", "S4");
	Course* p5 = CreateCourse("MTH00030", "Dai so tuyen tinh", "21APCS2", "Ho Anh Dung", 3, 120, "FRI", "S4");
	Course* p6 = CreateCourse("MTH00030", "Dai so tuyen tinh", "21CLC2", "Le Anh Khoa", 3, 120, "SAT", "S1");
	Course* p7 = CreateCourse("MTH00030", "Dai so tuyen tinh", "21CTT1", "Le Doan Thao Lien", 3, 120, "MON", "S2");
	Course* p8 = CreateCourse("MTH00004", "Vi tich phan 2B", "21CTT2", "Nguyen Tan Dieu", 3, 120, "TUE", "S3");
	Course* p9 = CreateCourse("MTH00004", "Vi tich phan 2B", "21APCS1", "Ho Anh Dung", 3, 120, "WED", "S4");
	Course* p10 = CreateCourse("MTH00004", "Vi tich phan 2B", "21CLC1", "Nguyen Van Phu", 3, 120, "THU", "S1");
	Course* p11 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "20CTT1", "Chu Minh Anh", 3, 120, "FRI", "S2");
	Course* p12 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "20CTT2", "Nguyen Thanh Tam", 3, 120, "SAT", "S3");
	Course* p13 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "20APCS1", "Nguyen Gia Vinh", 3, 120, "MON", "S4");
	Course* p14 = CreateCourse("CSC10003", "Phuong phap lap trinh huong doi tuong", "20CLC1", "Vuong Gia An", 3, 120, "TUE", "S1");
	Course* p15 = CreateCourse("CSC10008", "Mang may tinh", "20CTT1", "Luong Huu Vuong", 3, 120, "WED", "S2");
	Course* p16 = CreateCourse("CSC10008", "Mang may tinh", "20APCS2", "Nguyen Tan Dieu", 3, 120, "THU", "S3");
	Course* p17 = CreateCourse("CSC10008", "Mang may tinh", "20CLC2", "Huynh Nhu Y", 3, 120, "FRI", "S4");
	Course* p18 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "20CTT2", "Pham Thi Dai Trang", 3, 120, "SAT", "S1");
	Course* p19 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "20APCS1", "Pham Thanh Huy", 3, 120, "MON", "S2");
	Course* p20 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "20CLC2", "Tran Thi Diem Le", 3, 120, "TUE", "S3");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p8); AddCourse(p, p9); AddCourse(p, p10); AddCourse(p, p11); AddCourse(p, p12);
	AddCourse(p, p13); AddCourse(p, p14); AddCourse(p, p15); AddCourse(p, p16); AddCourse(p, p17); AddCourse(p, p18);
	AddCourse(p, p19); AddCourse(p, p20);
}

void BuildCourseForSemester3_2122(Semester* p) {
	Course* p1 = CreateCourse("MTH00041", "Toan roi rac", "21C2_1", "Nguyen Hoang Nhat Ha", 3, 120, "MON", "S1");
	Course* p2 = CreateCourse("MTH00003", "Vi tich phan 1B", "21C3_2", "Pham Duy Linh", 3, 120, "TUE", "S2");
	Course* p3 = CreateCourse("MTH00004", "Vi tich phan 2B", "21C4_3", "Thach Canh Nhat", 3, 120, "WED", "S3");
	Course* p4 = CreateCourse("MTH00030", "Dai so tuyen tinh", "21C5_1", "Tran The My Ngu", 3, 120, "THU", "S1");
	Course* p5 = CreateCourse("CSC10006", "Co so du lieu", "20C6_2", "Tran Quoc Son", 3, 120, "FRI", "S2");
	Course* p6 = CreateCourse("MTH00040", "Xac suat thong ke", "20C7_3", "Tram Thanh Huy", 3, 120, "SAT", "S3");
	Course* p7 = CreateCourse("MTH00051", "Toan ung dung va thong ke", "20C2_4", "Nguyen Phan Khiet Thanh", 3, 120, "MON", "S4");
	Course* p10 = CreateCourse("CSC10008", "Mang may tinh", "20C5_4", "Tran Thi Tu Uyen", 3, 120, "THU", "S4");
	AddCourse(p, p1); AddCourse(p, p2); AddCourse(p, p3); AddCourse(p, p4); AddCourse(p, p5); AddCourse(p, p6);
	AddCourse(p, p7); AddCourse(p, p10);
}

void ReadCSVStudentForCourse( char* p, Course*& c) {
	ifstream fin;
	fin.open(p);
	if (!fin.is_open()) {
		return;
	}
	string tmp;
	getline(fin, tmp, '\n');
	while (!fin.eof()) {
		InforPerSon q;
		getline(fin, q.ID, ',');
		getline(fin, q.LastName, ',');
		getline(fin, q.FirstName, ',');
		string tmpG;
		getline(fin, tmpG, ',');
		if (tmpG.compare("0") == 0) q.Gender = 0;
		else q.Gender = 1;
		getline(fin, q.DateOfBirth, ',');
		getline(fin, q.SocialID, '\n');
		q.Password = ExtractPassWord(q.SocialID);
		Student* p = CreateStudent(q);
		AddStudentInCourse(c, p);

	}
	fin.close();

}

char* ConvertStringToCharPath(string a) {
	char* p = new char[a.size()+1+4 ];
	strcpy_s(p, a.size() + 1 + 4, a.c_str());
	strcat_s(p, a.size() + 1 + 4, ".csv");
	return p;
}

void BuildCourse(Staff*p) {
	Course* p1 = p->pSchoolHead->pHead->pHead;
	Course* p2 = p->pSchoolHead->pHead->pNext->pHead;
	Course* p3 = p->pSchoolHead->pHead->pNext->pNext->pHead;
	Course* p4 = p->pSchoolHead->pNext->pHead->pHead;
	Course* p5 = p->pSchoolHead->pNext->pHead->pNext->pHead;
	Course* p6 = p->pSchoolHead->pNext->pHead->pNext->pNext->pHead;
	Course* p7 = p->pSchoolHead->pNext->pNext->pHead->pHead;
	Course* p8 = p->pSchoolHead->pNext->pNext->pHead->pNext->pHead;
	Course* p9 = p->pSchoolHead->pNext->pNext->pHead->pNext->pNext->pHead;
	while (p1 != NULL) {
		char* path = ConvertStringToCharPath(p1->ClassName);
		ReadCSVStudentForCourse(path, p1);
		p1 = p1->pNext;
	}
	while (p2 != NULL) {
		char* path = ConvertStringToCharPath(p2->ClassName);
		ReadCSVStudentForCourse(path, p2);
		p2 = p2->pNext;
	}
	while (p3 != NULL) {
		char* path = ConvertStringToCharPath(p3->ClassName);
		ReadCSVStudentForCourse(path, p3);
		p3 = p3->pNext;
	}
	while (p4 != NULL) {
		char* path = ConvertStringToCharPath(p4->ClassName);
		ReadCSVStudentForCourse(path, p4);
		p4 = p4->pNext;
	}
	while (p5 != NULL) {
		char* path = ConvertStringToCharPath(p5->ClassName);
		ReadCSVStudentForCourse(path, p5);
		p5 = p5->pNext;
	}
	while (p6 != NULL) {
		char* path = ConvertStringToCharPath(p6->ClassName);
		ReadCSVStudentForCourse(path, p6);
		p6 = p6->pNext;
	}
	while (p7!= NULL) {
		char* path = ConvertStringToCharPath(p7->ClassName);
		ReadCSVStudentForCourse(path, p7);
		p7 = p7->pNext;
	}
	while (p8 != NULL) {
		char* path = ConvertStringToCharPath(p8->ClassName);
		ReadCSVStudentForCourse(path, p8);
		p8 = p8->pNext;
	}
	while (p9 != NULL) {
		char* path = ConvertStringToCharPath(p9->ClassName);
		ReadCSVStudentForCourse(path, p9);
		p9 = p9->pNext;
	}
}

void AscendingCourse(Course*& pHead) {
	if (pHead == NULL || pHead->pNext==NULL) return;
	Course* p = pHead;
	while (p->pNext != NULL) {
		Course* q = p->pNext;
		while (q != NULL) {
			if (p->CourseName.compare(q->CourseName) == 1) {
				swap(p->ClassName, q->ClassName);
				swap(p->CourseID, q->CourseID);
				swap(p->CourseName, q->CourseName);
				swap(p->TeacherName, q->TeacherName);
				swap(p->Credit, q->Credit);
				swap(p->DayOfWeek, q->DayOfWeek);
				swap(p->Session, q->Session);
				swap(p->Size, q->Size);
			}
			q = q->pNext;
		}
		p = p->pNext;
	}
}

void AscendingStudentInCourse(Student*& pHead) {
	if (pHead == NULL || pHead->pNextCourse == NULL) return;
	Student* p = pHead;
	while (p->pNextCourse != NULL) {
		Student* q = pHead->pNextCourse;
		while (q != NULL) {
			if (p->Info.ID.compare(q->Info.ID) == 1) {
				swap(p->Info, q->Info);
			}
			q = q->pNextCourse;
		}
		p = p->pNextCourse;
	}
}

void AscendingStudentInClass(Student*& pHead) {
	if (pHead == NULL || pHead->pNextClass == NULL) return;
	Student* p = pHead;
	while (p->pNextClass != NULL) {
		Student* q = pHead->pNextClass;
		while (q != NULL) {
			if (p->Info.ID.compare(q->Info.ID) == 1) {
				swap(p->Info, q->Info);
			}
			q = q->pNextClass;
		}
		p = p->pNextClass;
	}
}

//------WORKING FUNCTION-----

Staff* LoginStaff(School c, string a, string b) {
	Staff* p = c.pHead;
	while (p != NULL) {
		if (a.compare(p->Info.ID) == 0 && b.compare(p->Info.Password) == 0) return p;
		p = p->pNext;
	}
	return p;
}

string getPassword(){
	string password;
	char ch;

	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!password.empty()){
				password.pop_back();
				cout << "\b"<<"\b"; 
			}
		}
		else{
			password.push_back(ch);
			cout << "*";
		}
	}

	cout << endl;
		
	return password;
}

bool checkSchoolYear(Staff* s, string a) {
	SchoolYear* p = s->pSchoolHead;
	while (p != NULL) {
		if (p->Year.compare(a) == 0) return false;
		p = p->pNext;
	}
	for (int i = 0;i < a.size();i++) {
		if(isalpha(a[i])) return false;
	}
	if (a.size() != 9) return false;
	return true;
}

Student* LoginStudent(School c, string a, string b) {
	Class* p = c.pHead->pClassHead;
	while (p != NULL) {
		Student* q = p->pHead;
		while (q != NULL) {
			if (a.compare(q->Info.ID) == 0 && b.compare(q->Info.Password) == 0) return q;
			q = q->pNextClass;
		}
		p = p->pNext;
	}
	return NULL;
}

int CountNodeSchoolYear(Staff* p) {
	int i = 0;
	SchoolYear* q = p->pSchoolHead;
	if (q == NULL) return i;
	while (q != NULL) {
		i++;
		q = q->pNext;
	}
	return i;
}

SchoolYear* getSchoolYearByNum(Staff* p,int a) {
	SchoolYear* q = p->pSchoolHead;
	int i = 0;
	while (i != a) {
		q = q->pNext;
		i++;
	}
	return q;
}
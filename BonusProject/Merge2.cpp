#include"Merge.h"


#define MAUNEN 11
#define MAUCHU 7

//KICH THUOC MAN HINH CONSOLE
#define WConsole 120
#define HConsole 30

//KICH THUOC HOP MAC DINH
#define Xbox 40   //40+40
#define Ybox 5
#define Wbox 40
#define Hbox 20

//LE TEXT TRONG HOP
#define Upbox 8
#define DownBox 23
#define LeftBox 55
#define RightBox 65
#define Line 3

//KICH THUOC HOP login
#define XboxLG_1 45
#define YboxLG_1 10
#define WboxLG 30
#define HboxLG 2
#define XboxLG_2 45
#define YboxLG_2 14

// VI TRI CHU EXIT
#define Xexit 58
#define Yexit 21

//BOX DANH SACH

void SchoolYearMenu_s(Staff*& p, SchoolYear*& q) {
	int n = 3;
	int tt = 0;
	string a = { "[BACK]" };
	string thaotac[3] = { "Create Semester","View Semester","[BACK]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	//drawTable(45, 10, 30, 2, 2, MAUCHU);
	//drawBox(45, 12, 30, 2, MAUCHU);


	int* mau = new int[n];
	writeText(central(WConsole, q->Year), 7, q->Year, MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		if (tt != 2) {
			gotoxy(48, 11+tt);
			cout << char(175);
			gotoxy(66, 11+tt);
			cout << char(174);
		}
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(55, 14, thaotac[i], mau[i]);
			}
			else {
				writeText(50, 11 + i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;

			}
			break;
		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 0) {
				clrscr();
				CreateSemesterMenu_s(p,q);
			}
			else if (tt == 2) {
				clrscr();
				ViewschoolyearList_s(p);
			}
			else if (tt == 1) {
				clrscr();
				ViewSemesterMenu_s(p,q);
			}
			
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);

		gotoxy(48, 11 + tmp);
		cout << " ";
		gotoxy(66, 11 + tmp);
		cout << " ";
	}
}

void CreateSemesterMenu_s(Staff*& q, SchoolYear*& p) {
	int n = 2;
	int tt = 0;
	string a = { "[SAVE]" };
	string b = { "[BACK]" };
	int c;
	string d;
	string e;
	str thaotac[2] = { "[SAVE]","[BACK]" };
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 12, "Semester: ", 7);
	writeText(45, 13, "Start Day: ", 7);
	writeText(45, 14, "End day: ", 7);
	writeText(45, 19, thaotac[0], 7);
	writeText(65, 19, thaotac[1], 7);
	textColor(MAUNEN);
	gotoxy(45, 12 );
	cout << "Semester: ";
	cin >> c;
	gotoxy(45, 12);
	textColor(7);
	cout << "Semester: " << c;
	gotoxy(45, 13 );
	textColor(MAUNEN);
	cout << "Start Day: ";
	cin >> d;
	textColor(7);
	gotoxy(45, 13);
	cout << "Start Day: "<< d;

	textColor(MAUNEN);
	gotoxy(45, 14 );
	cout << "End Day: ";
	cin >> e;
	textColor(7);
	gotoxy(45, 14 );
	cout << "End Day: "<< e;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(65, 19, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			if (tt == 0) {
				Semester* x = CreateSemester(c, d, e);
				AddSemester(p, x);
				clrscr();
				SchoolYearMenu_s(q,p);
			}
			else if (tt == 1) {
				clrscr();
				SchoolYearMenu_s(q, p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewSemesterMenu_s(Staff*&q,SchoolYear* &p) {
	int n = CountNodeSemester(p)+1;
	if (n-1 == 0) {
		int n = 2;
		int tt = 0;
		string a = { "[CREATE SEMESTER]" };
		string b = { "[BACK]" };
		str thaotac[2] = { "[CREATE SEMESTER]","[BACK]" };
		drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
		int* mau = new int[n];
		writeText(central(WConsole, "SEMESTER " + p->Year), 7, "SEMESTER " + p->Year, MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		gotoxy(45, 10);
		cout << "Semester is empty.............";
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			for (int i = 0; i < n; i++) {
				if (thaotac[i] == a) {
					writeText(50, 12, thaotac[i], mau[i]);
				}
				if (thaotac[i] == b) {
					writeText(56, 14, thaotac[i], mau[i]);
				}
			}
			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
			case UP:
			{
				if (tt == 0)
				{
					tt = n - 1;
				}
				else {
					tt--;
				}
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = 0;
				}
				else {
					tt++;
				}
				break;
			}
			case ENTER:
				if (tt == 1) {
					clrscr();
					SchoolYearMenu_s(q, p);
				}
				else if (tt == 0) {
					clrscr();
					CreateSemesterMenu_s(q,p);
				}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
	else {
		int tt = 0;
		string* thaotac = new string[n];
		int i = 0;
		thaotac[n - 1] = "[BACK]" ;
		int chay = 0;

		Semester* point = p->pHead;

		for (Semester* k = p->pHead; k != NULL; k = k->pNext) {
			if (k->Season == 1) {
				thaotac[i] = { "Semester 1" };
				gotoxy(45, 9 + chay);
				cout << "Semester 1";
				gotoxy(45, 10 + chay);
				cout << "Start Day: " <<k->StartDay;
				gotoxy(45, 11 + chay);
				cout << "End day: " << k->EndDay;
			}
			if (k->Season == 2) {
				thaotac[i] = { "Semester 2" };
				gotoxy(45, 9 + chay);
				cout << "Semester 2";
				gotoxy(45, 10 + chay);
				cout << "Start Day: " << k->StartDay;
				gotoxy(45, 11 + chay);
				cout << "End day: " << k->EndDay;
			}
			if (k->Season == 3) {
				thaotac[i] = { "Semester 3" };
				gotoxy(45, 9 + chay);
				cout << "Semester 3";
				gotoxy(45, 10 + chay);
				cout << "Start Day: " << k->StartDay;
				gotoxy(45, 11 + chay);
				cout << "End day: " << k->EndDay;
			}
			chay += 4;
			i++;
		}

		drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);


		int* mau = new int[n];
		writeText(central(WConsole, "SEMESTER - " + p->Year), 7, "SEMESTER - " + p->Year, MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;


		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			int tmp = tt;
			chay = 0;
			for (int i = 0; i < n; i++) {
				if (thaotac[i] == "[BACK]") {
					writeText(55, 21, thaotac[i], mau[i]);
				}
				else {
					writeText(45, 9 + chay, thaotac[i], mau[i]);
				}
				chay += 4;
			}

			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
			case UP:
			{
				if (tt == 0)
				{
					tt = n - 1;
				}
				else {
					tt--;
				}
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = 0;
				}
				else {
					tt++;
				}
				break;
			}
			case ENTER:
			{
				if (tt == n - 1) {
					clrscr();
					SchoolYearMenu_s(q, p);
				}
				else {
					clrscr();
					Semester* k = getSemeterByNum(p, tt+1 );
					SemesterMenu_s(q, p, k);
				}
			}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
}

void SemesterMenu_s(Staff* &p,SchoolYear*&q, Semester*&r) {
	int n = 3;
	int tt = 0;
	string a = { "Create Course" };
	string b = { "View course" };
	string c = { "[BACK]" };
	str thaotac[3] = { "Create Course","View course","[BACK]"};

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER "+to_string(r->Season)), 7, "SEMESTER "+to_string(r->Season), MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		if (tt != n - 1) {
			gotoxy(LeftBox - 2, Upbox + Line + tt);
			cout << char(175);
			gotoxy(RightBox + 4, Upbox + Line + tt);
			cout << char(174);
		}
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(LeftBox, Upbox+Line+i, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(LeftBox, Upbox + Line + i, thaotac[i], mau[i]);
			}
			if (thaotac[i] == c) {
				writeText(central(WConsole,c), Upbox + Line + i + 1, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 2) {
				clrscr();
				ViewSemesterMenu_s(p,q);
			}
			else if (tt == 0) {
				clrscr();
				CreateCourseMenu_s(p, q, r);
			}
			else if (tt == 1) {
				clrscr();
				ViewCourseMenu_s(p, q, r);
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);

		gotoxy(LeftBox - 2, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox + 4, Upbox + Line + tmp);
		cout << " ";
	}
}

void CreateCourseMenu_s(Staff* &p,SchoolYear*&q,Semester*&r) {
	string a = { "Course ID: " };
	string b = { "Course name: " };
	string c = { "Class name: " };
	string d = { "Teacher name: " };
	string e = { "Credit: " };
	string f = { "Size: " };
	string g = { "Day of week: " };
	string h = { "Season: " };
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };
	writeText(central(WConsole, "CREATE COURSE"), 7, "CREATE COURSE", MAUCHU);
	int n = 2;
	int tt = 0;
	string j = { "[CREATE]" };
	string k = { "[BACK]" };
	str thaotac[2] = { "[CREATE]","[BACK]" };
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	gotoxy(45, 10);
	cout << a;
	gotoxy(45, 11);
	cout << b;
	gotoxy(45, 12);
	cout << c;
	gotoxy(45, 13);
	cout << d;
	gotoxy(45, 14);
	cout << e;
	gotoxy(45, 15);
	cout << f;
	gotoxy(45, 16);
	cout << g;
	gotoxy(45, 17);
	cout << h;
	writeText(45, 21, thaotac[0], 7);
	writeText(65, 21, thaotac[1], 7);

	string k0, k1, k2, k3, k6, k7;
	int k4, k5;
	for (int i = 0; i < 8; i++) {
		textColor(MAUNEN);
		gotoxy(45, 10 + i);
		cout << temp[i];
		if (i == 0) {
			cin >> k0;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k0;
		}
		if (i == 1) {
			cin >> k1;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k1;
		}
		if (i == 2) {
			cin >> k2;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k2;
		}
		if (i == 3) {
			cin >> k3;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k3;
		}
		if (i == 4) {
			cin >> k4;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k4;
		}
		if (i == 5) {
			cin >> k5;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k5;
		}
		if (i == 6) {
			cin >> k6;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k6;
		}
		if (i == 7) {
			cin >> k7;
			textColor(7);
			gotoxy(45, 10 + i);
			cout << temp[i] << k7;
		}
	}
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == j) {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
				writeText(65, 21, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (tt == 1) {
				SemesterMenu_s(p, q, r);
			}
			else if (tt == 0) {
				Course* s = CreateCourse(k0, k1, k2, k3, k4, k5, k6, k7);
				AddCourse(r, s);
				AscendingCourse(r->pHead);
				SemesterMenu_s(p, q, r);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewCourseMenu_s(Staff*& p, SchoolYear*& q, Semester*& r) {
	int max = CountNodeCourse(r);
	if (max == 0) {
		int n = 2;
		int tt = 0;
		string a = { "[CREATE COURSE]" };
		string b = { "[BACK]" };
		str thaotac[2] = { "[CREATE COURSE]","[BACK]" };
		drawBox(Xbox-5, Ybox, Wbox+10, Hbox, MAUCHU);
		int* mau = new int[n];
		writeText(central(WConsole, "SEMESTER " + to_string(r->Season)), 7, "SEMESTER " + to_string(r->Season), MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		gotoxy(45, 10);
		cout << "Course is empty.............";
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			for (int i = 0; i < n; i++) {
				if (thaotac[i] == a) {
					writeText(50, 12, thaotac[i], mau[i]);
				}
				if (thaotac[i] == b) {
					writeText(56, 14, thaotac[i], mau[i]);
				}
			}
			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
			case UP:
			{
				if (tt == 0)
				{
					tt = n - 1;
				}
				else {
					tt--;
				}
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = 0;
				}
				else {
					tt++;
				}
				break;
			}
			case ENTER:
				if (tt == 0) {
					clrscr();
					CreateCourseMenu_s(p, q, r);
				}
				else if (tt == 1) {
					clrscr();
					SemesterMenu_s(p, q, r);
				}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
	else {
		int tt = 0;
		int n = 8;
		string* thaotac = new string[n];
		int chay = 0;
		drawBox(Xbox-5, Ybox, Wbox+10, Hbox, MAUCHU);
		int* mau = new int[n];
		writeText(central(WConsole, "SEMESTER - " + to_string(r->Season)), 7, "SEMESTER - " +to_string(r->Season), MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		int first = 1;
		int second = 8;
		int point = 1;
		writeText(central(WConsole, "Push [LEFT] to back"), 23, "Push [LEFT] to back", 7);
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			int tmp = tt;
			
			for (int i = LeftBox-9;i < LeftBox+29;i++) {
				for (int j = Upbox + Line;j < Upbox + Line + 9;j++) {
					gotoxy(i, j);
					cout << " ";
				}
			}
			//writeText(central(WConsole, "Push [LEFT] to back"), 23, "Push [LEFT] to back", 7);
			writeText(LeftBox - 9, Upbox + Line - 2, "Course Name", 7);
			writeText(LeftBox - 12, Upbox + Line - 2, "No", 7);
			cout << "-";
			for (int i = 0; i < 8; i++) {
				Course* t = getCourseByNum(r, i+first);
				writeText(LeftBox-9, Upbox + Line + i, t->CourseName, mau[i]);
				if (i+first < 10) {
					writeText(LeftBox - 12, Upbox + Line + i, "0" + to_string(i + first), mau[i]);
					cout << "-";
				}
				else {
					writeText(LeftBox - 12, Upbox + Line + i, to_string(i + first), mau[i]);
					cout << "-";
				}

			}
		
			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
			case UP:
			{
				if (tt == 0)
				{
					tt = 0;
				}
				else {
					tt--;
				}
				if (point == first && first != 1) {
					first--;
					second--;
				}
				if (point == 1) {
					point = 1;
				}
				else point--;
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = n-1;
				}
				else {
					tt++;
				}
				if (point == second && second != max) {
					first++;
					second++;
				}
				if (point == max) {
					point = max;
				}
				else {
					point++;
				}
				break;
			}
			case LEFT:
			{
				clrscr();
				SemesterMenu_s(p, q, r);
			}
			case ENTER:
			{
				clrscr();
				Course* s = getCourseByNum(r, point);
				CourseMenu_s(p, q, r, s);
			}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
}

void CourseMenu_s(Staff* &p,SchoolYear*&q,Semester*&r, Course*&s) 
{
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };

	gotoxy(42, 10);
	cout << temp[0] << s->CourseID;
	gotoxy(42, 11);
	cout << temp[1] << s->CourseName;
	gotoxy(42, 12);
	cout << temp[2] << s->ClassName;
	gotoxy(42, 13);
	cout << temp[3] << s->TeacherName;
	gotoxy(42, 14);
	cout << temp[4] << s->Credit;
	gotoxy(42, 15);
	cout << temp[5] << s->Size;
	gotoxy(42, 16);
	cout << temp[6] << s->DayOfWeek;
	gotoxy(42, 17);
	cout << temp[7] << s->Session;
	int n = 4;
	string thaotac[4] = { "[BACK]","[ADD STUDENT]","[DELETE]","[STUDENT LIST]"};
	int tt = 0;
	drawBox(Xbox-5, Ybox, Wbox+10, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "COURSE"), 7, "COURSE", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "[BACK]") {
				writeText(37, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "[ADD STUDENT]") {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "[DELETE]") {
				writeText(60, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "[STUDENT LIST]") {
				writeText(70, 21, thaotac[i], mau[i]);
			}
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			if (tt == 0) {
				system("cls");
				ViewCourseMenu_s(p, q, r);
			}
			else if (tt == 2) {
				if (s == r->pHead) {
					r->pHead == r->pHead->pNext;
					delete s;
				}
				else {
					Course* tmp = r->pHead;
					while (tmp->pNext != s) tmp = tmp->pNext;
					tmp->pNext = s->pNext;
					delete s;
				}
				writeText(central(WConsole, "Success! Press any key to [BACK]"), 22, "Success! Press any key to [BACK]", MAUNEN);
				int x = _getch();
				system("cls");
				ViewCourseMenu_s(p, q, r);
			}
			else if (tt == 1) {
				clrscr();
				AddStudentMenu_s(p, q, r, s);
			}
			else if (tt == 3) {
				clrscr();
				ViewStudentMenu_s(p, q, r, s);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void AddStudentMenu_s(Staff* p, SchoolYear*&q,Semester*&r,Course*&s) //  1 or csv
{
	int n = 3;
	int tt = 0;
	string thaotac[3] = { "Up Load File CSV","Add One Student", "[BACK]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "COURSE - STUDENT"), 7, "COURSE - STUDENT", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		if (tt != n - 1) {
			gotoxy(47, 12 + tt * 2);
			cout << char(175);
			gotoxy(66, 12 + tt * 2);
			cout << char(174);
		}
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "[BACK]") {
				writeText(55, 20, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "Up Load File CSV") {
				writeText(49, 12, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "Add One Student") {
				writeText(49, 14, thaotac[i], mau[i]);
			}
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 0) {

				clrscr();
				AddCSVStudent_s(p, q, r, s);
				break;
			}
			else if (tt == 1) {
				clrscr();
				AddOneStudent_s(p, q, r, s);
				break;
			}
			else if (tt == 2) {
				clrscr();
				CourseMenu_s(p, q, r, s);
				break;
			}

		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
		if (tmp != n - 1) {
			gotoxy(47, 12 + tmp * 2);
			cout << " ";
			gotoxy(66, 12 + tmp * 2);
			cout << " ";
		}
	}
}

void AddOneStudent_s(Staff* &p,SchoolYear*&q,Semester*&r,Course*&s ) {
	InforPerSon in;

	string b = { "ID: " };
	string c = { "FirstName: " };
	string d = { "LastName: " };
	string e = { "Gender (1: Male or 2: Female): " };
	string f = { "DateOfBirth: " };
	string g = { "SocialID: " };

	string temp[6] = {  "ID: ", "FirstName: " ,  "LastName: " , "Gender (1: Male or 2: Female): " , "DateOfBirth: " , "SocialID: " };
	writeText(central(WConsole, "ADD ONE STUDENT"), 7, "ADD ONE STUDENT", MAUCHU);
	int n = 2;
	int tt = 0;
	string j = { "[CREATE]" };
	string k = { "[BACK]" };
	str thaotac[2] = { "[CREATE]","[BACK]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 21, thaotac[0], 7);

	writeText(65, 21, thaotac[1], 7);

	gotoxy(45, 11);
	cout << b;
	gotoxy(45, 12);
	cout << c;
	gotoxy(45, 13);
	cout << d;
	gotoxy(45, 14);
	cout << e;
	gotoxy(45, 15);
	cout << f;
	gotoxy(45, 16);
	cout << g;


	textColor(MAUNEN);
	gotoxy(45, 11);
	cout << temp[0];
	cin >> in.ID;
	textColor(7);
	gotoxy(45, 11);
	cout << temp[0] << in.ID;

	textColor(MAUNEN);
	gotoxy(45, 12);
	cout << temp[1];
	cin >> in.FirstName;
	textColor(7);
	gotoxy(45, 12);
	cout << temp[1] << in.FirstName;

	textColor(MAUNEN);
	gotoxy(45, 13);
	cout << temp[2];
	cin >>in.LastName;
	textColor(7);
	gotoxy(45, 13);
	cout << temp[2] << in.LastName;

	textColor(MAUNEN);
	gotoxy(45, 14);
	cout << temp[3];
	cin >>in.Gender;
	textColor(7);
	gotoxy(45, 14);
	cout << temp[3] << in.Gender;

	textColor(MAUNEN);
	gotoxy(45, 15);
	cout << temp[4];
	cin >> in.DateOfBirth;
	textColor(7);
	gotoxy(45, 15);
	cout << temp[4] <<in.DateOfBirth;

	textColor(MAUNEN);
	gotoxy(45, 16);
	cout << temp[5];
	cin >>in.SocialID;
	textColor(7);
	gotoxy(45, 16);
	cout << temp[5] <<in.SocialID;

	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == j) {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
				writeText(65, 21, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			if (tt == 0) {
				clrscr();
				Student* x = CreateStudent(in);
				AddStudentInCourse(s, x);
				AscendingStudentInCourse(s->pHead);
				CourseMenu_s(p, q, r, s);
			}
			else if (tt == 1) {
				clrscr();
				CourseMenu_s(p, q, r, s);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}

}

void AddCSVStudent_s(Staff*& p, SchoolYear*&q, Semester*&r,Course*&s) {
	writeText(central(WConsole, "ADD STUDENT CSV"), 7, "ADD STUDENT CSV", MAUCHU);
	int n = 2;
	int tt = 0;
	string j = { "[CREATE]" };
	string k = { "[BACK]" };
	str thaotac[2] = { "[CREATE]","[BACK]" };
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 19, thaotac[0], 7);
	writeText(65, 19, thaotac[1], 7);
	writeText(52, 15, "Path: ", MAUNEN);
	char nameFile[200];
	textColor(MAUNEN);
	cin.ignore();
	cin >> nameFile;
	writeText(52, 15, "Path: ", MAUCHU);
	cout << nameFile;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == j) {
				writeText(45, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
				writeText(65, 19, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 1) {
				clrscr();
				CourseMenu_s(p, q, r, s);
			}
			else if (tt == 0) {
				bool k = ReadCSVStudentForCourse_s(nameFile, s);
				if (k) {
					writeText(central(WConsole, "Success. Push any [KEY] to Back"), 21, "Success. Push any [KEY] to Back", MAUNEN);
				}
				else writeText(central(WConsole, "Fail. Push any [KEY] to Back"), 21, "Fail. Push any [KEY] to Back", MAUNEN);
				char x = _getch();
				clrscr();
				CourseMenu_s(p, q, r, s);
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewStudentMenu_s(Staff*& p, SchoolYear*& q, Semester*& r,Course*&s) {
	int max = CountNodeStudent(s);
	if (max == 0) {
		int n = 2;
		int tt = 0;
		string b = { "[BACK]" };
		str thaotac[1] = { "[BACK]" };
		drawBox(Xbox - 5, Ybox, Wbox + 10, Hbox, MAUCHU);
		int* mau = new int[n];
		writeText(central(WConsole, "COURSE " + s->CourseName+"-"+s->ClassName), 7, "COURSE " + s->CourseName + "-" + s->ClassName, MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		gotoxy(45, 10);
		cout << "Course is empty.............";
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			
	
			writeText(56, 14, thaotac[0], mau[0]);
			
			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
		
			case ENTER:
				clrscr();
				CourseMenu_s(p, q, r, s);
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
	else {
		int tt = 0;
		int n = 8;
		string* thaotac = new string[n];
		int chay = 0;
		drawBox(Xbox - 5, Ybox, Wbox + 10, Hbox, MAUCHU);
		int* mau = new int[n];
		writeText(central(WConsole, "COURSE " + s->CourseName + "-" + s->ClassName), 7, "COURSE " + s->CourseName + "-" + s->ClassName, MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		int first = 1;
		int second = 8;
		int point = 1;
		writeText(38, 11, "No", 7);
		writeText(42, 11, "ID", 7);
		writeText(51, 11, "FullName", 7);
		writeText(72, 11, "AverageScore", 7);
		drawBox(Xbox -3, Ybox + Line+4, Wbox +6, Hbox - 11,7);
		writeText(central(WConsole, "Push [ENTER] to REMOVE this student"), 22, "Push [LEFT] to BACK", 7);
		writeText(central(WConsole, "Push [ENTER] to REMOVE this student"), 23, "Push [ENTER] to REMOVE this student", 7);
		writeText(central(WConsole, "Push [ENTER] to REMOVE this student"), 24, "Push [RIGHT] to go BOARDSCORE MENU", 7);
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			int tmp = tt;

			for (int i = Xbox - 2;i <= Xbox - 2+ Wbox + 4;i++) {
				for (int j = Ybox + Line + 5;j <= Ybox + Line + Hbox - 8;j++) {
					gotoxy(i, j);
					cout << " ";
				}
			}


			for (int i = 0; i < 8; i++) {
				Student* t = getStudentByNum(s, i + first);
				if (i + first < 10) {
					writeText(38, 13 +i, "0" + to_string(i + first), mau[i]);
				}
				else {
					writeText(38, 13 + i, to_string(i + first), mau[i]);
				}
				writeText(42, 13 + i, t->Info.ID, mau[i]);
				writeText(51, 13 + i, t->Info.LastName+" "+t->Info.FirstName, mau[i]);
				writeText(78, 13 + i, t->Info.dTB, mau[i]);
			}

			int z = _getch();
			TRANGTHAI trangthai = key(z);
			switch (trangthai) {
			case UP:
			{
				if (tt == 0)
				{
					tt = 0;
				}
				else {
					tt--;
				}
				if (point == first && first != 1) {
					first--;
					second--;
				}
				if (point == 1) {
					point = 1;
				}
				else point--;
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = n - 1;
				}
				else {
					tt++;
				}
				if (point == second && second != max) {
					first++;
					second++;
				}
				if (point == max) {
					point = max;
				}
				else {
					point++;
				}
				break;
			}
			case LEFT:
			{
				clrscr();
				CourseMenu_s(p, q, r, s);
			}
			case ENTER:
			{
				clrscr();
				Student* x = getStudentByNum(s, point);
				if (x == s->pHead) {
					s->pHead = s->pHead->pNextCourse;
					delete x;
				}
				else {
					Student* x2 = s->pHead;
					while (x2->pNextCourse != x) {
						x2 = x2->pNextCourse;
					}
					x2->pNextCourse = x->pNextCourse;
					delete x;
				}
				CourseMenu_s(p, q, r, s);
			}
			case RIGHT:
			{
				clrscr();
				ScoreBoardMenu_s(p, q, r, s);
			}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
}

void ScoreBoardMenu_s(Staff*& p, SchoolYear*& q, Semester*& r, Course*& s) {
	int n = 3;
	str thaotac[3] = { "Import CSV Score Board","Export CSV For Teacher","BACK"};
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "SCOREBOARD"), Upbox, "SCOREBOARD", MAUCHU);
	for (int i = 0;i < n;i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();

		textColor(MAUNEN);
		int tmp = tt;
		if (tt != 2) {
			gotoxy(LeftBox - 7, Upbox + Line + tt);
			cout << char(175);
			gotoxy(RightBox + 8, Upbox + Line + tt);
			cout << char(174);
		}
		else {
			gotoxy(LeftBox +1, Upbox + Line + tt);
			cout << char(175);
			gotoxy(LeftBox+8 , Upbox + Line + tt);
			cout << char(174);
		}
		for (int i = 0;i < n;i++) {
			if(i==2) writeText(LeftBox +3, Upbox + Line + i, thaotac[i], mau[i]);
			else writeText(LeftBox-5, Upbox + Line + i, thaotac[i], mau[i]);
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (tt == 2) {
				ViewStudentMenu_s(p,q, r, s);
			}
			else if (tt == 1) {
				ExportScoreBoard_s(p, q, r, s);
			}
			else if (tt == 0) {
				ImportScoreBoard_s(p, q, r, s);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;

		textColor(MAUNEN);
		if (tmp != 2) {
			gotoxy(LeftBox - 7, Upbox + Line + tmp);
			cout << " ";
			gotoxy(RightBox + 8, Upbox + Line + tmp);
			cout << " ";
		}
		else {
			gotoxy(LeftBox + 1, Upbox + Line + tmp);
			cout << " ";
			gotoxy(LeftBox + 8, Upbox + Line + tmp);
			cout << " ";
		}
	}
}

void ImportScoreBoard_s(Staff*& p, SchoolYear*& q, Semester*& r, Course*& s) {
	writeText(central(WConsole, "IMPORT SCORE BOARD"), 7, "IMPORT SCORE BOARD", MAUCHU);
	int n = 2;
	int tt = 0;
	string j = { "[IMPORT]" };
	string k = { "[BACK]" };
	str thaotac[2] = { "[IMPORT]","[BACK]" };
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 19, thaotac[0], 7);
	writeText(65, 19, thaotac[1], 7);
	writeText(52, 15, "Path: ", MAUNEN);
	char nameFile[200];
	textColor(MAUNEN);
	cin.ignore();
	cin >> nameFile;
	writeText(52, 15, "Path: ", MAUCHU);
	cout << nameFile;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == j) {
				writeText(45, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
				writeText(65, 19, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 1) {
				clrscr();
				ScoreBoardMenu_s(p, q, r, s);
			}
			else if (tt == 0) {
				bool k = ReadScoreBorad(nameFile, s);
				if (k) {
					writeText(central(WConsole, "Success. Push any [KEY] to Back"), 21, "Success. Push any [KEY] to Back", MAUNEN);
				}
				else writeText(central(WConsole, "Fail. Push any [KEY] to Back"), 21, "Fail. Push any [KEY] to Back", MAUNEN);
				char x = _getch();
				clrscr();
				ScoreBoardMenu_s(p, q, r, s);
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ExportScoreBoard_s(Staff*& p, SchoolYear*& q, Semester*& r, Course*& s) {
	writeText(central(WConsole, "EXPORT SCORE BOARD"), 7, "EXPORT SCORE BOARD", MAUCHU);
	int n = 2;
	int tt = 0;
	string j = { "[EXPORT]" };
	string k = { "[BACK]" };
	str thaotac[2] = { "[EXPORT]","[BACK]" };
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 19, thaotac[0], 7);
	writeText(65, 19, thaotac[1], 7);
	writeText(52, 15, "Path: ", MAUNEN);
	char nameFile[200];
	textColor(MAUNEN);
	cin.ignore();
	cin >> nameFile;
	writeText(52, 15, "Path: ", MAUCHU);
	cout << nameFile;
	int* mau = new int[n];
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == j) {
				writeText(45, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
				writeText(65, 19, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 1) {
				clrscr();
				ScoreBoardMenu_s(p, q, r, s);
			}
			else if (tt == 0) {
				bool k = WriteScoreBoard(nameFile, s);
				if (k) {
					writeText(central(WConsole, "Success. Push any [KEY] to Back"), 21, "Success. Push any [KEY] to Back", MAUNEN);
				}
				else writeText(central(WConsole, "Fail. Push any [KEY] to Back"), 21, "Fail. Push any [KEY] to Back", MAUNEN);
				char x = _getch();
				clrscr();
				ScoreBoardMenu_s(p, q, r, s);
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void EditInfoMenu_s(Staff*& p) {
	string a = { "[BACK]" };
	int n = 7;
	string thaotac[7] = { "ID","FirstName", "LastName","Gender", "DateOfBirth","SocialID","[BACK]" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "PERSONAL INFORMATION"), 7, "PERSONAL INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		if (tt != n - 1) {
			gotoxy(LeftBox - 2, 10 + tt);
			cout << char(175);
			gotoxy(RightBox + 2, 10 + tt);
			cout << char(174);
		}
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(56, 21, thaotac[i], mau[i]);
			}
			else {
				writeText(central(WConsole, "DateOfBirth"), 10 + i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case ENTER:
			if (tt == 6) {
				clrscr();
				InfoMenu_s(p);
			}
			else if (tt == 0) {
				clrscr();
				Edit_ID_Menu_s(p);
			}
			else if (tt == 1) {
				clrscr();
				Edit_Firstname_Menu_s(p);
			}
			else if (tt == 2) {
				clrscr();
				Edit_Lastname_Menu_s(p);
			}
			else if (tt == 3) {
				clrscr();
				Edit_Gender_Menu_s(p);
			}
			else if (tt == 4) {
				clrscr();
				Edit_DateOfBirth_Menu_s(p);
			}
			else if (tt == 5) {
				clrscr();
				Edit_SocialID_Menu_s(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
		gotoxy(LeftBox - 2, 10 + tmp);
		cout << " ";
		gotoxy(RightBox + 2, 10 + tmp);
		cout << " ";
	}
}

void Edit_ID_Menu_s(Staff*& p) {
	string a = { "[SAVE]" };
	string b = { "ID: " };
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[SAVE]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "ID - INFORMATION"), 7, "ID - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.ID;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.ID;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;

		writeText(56, 21, a, mau[0]);

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			system("cls");
			EditInfoMenu_s(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Firstname_Menu_s(Staff*& p) {
	string a = { "[SAVE]" };
	string b = { "Firstname: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[SAVE]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "FIRSTNAME - INFORMATION"), 7, "FIRSTNAME - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.FirstName;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.FirstName;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		writeText(56, 21, a, mau[0]);
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			system("cls");
			EditInfoMenu_s(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Lastname_Menu_s(Staff*& p) {
	string a = { "[SAVE]" };
	string b = { "Lastname: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[SAVE]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "LASTNAME - INFORMATION"), 7, "LASTNAME - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.LastName;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.LastName;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;

		writeText(56, 21, a, mau[0]);

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			system("cls");
			EditInfoMenu_s(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Gender_Menu_s(Staff*& p) {
	string a = "Gender: ";
	string c = "[FEMALE]";
	string b = "[MALE]";
	int n = 2;
	int tt = 0;
	string thaotac[2] = { "[MALE]","[FEMALE]" };
	writeText(45, 10, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "GENDER - INFORMATION"), 7, "GENDER - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		writeText(58, 10, b, mau[0]);
		writeText(66, 10, c, mau[1]);
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
			}
			else {
				tt++;
			}
			break;
		}
		case LEFT:
		{
			if (tt == 0)
			{
				tt = n - 1;
			}
			else {
				tt--;
			}
			break;
		}
		case ENTER:
		{
			if (tt == 0) {
				p->Info.Gender = 1;
				clrscr();
				EditInfoMenu_s(p);
			}
			else if (tt == 1) {
				p->Info.Gender = 0;
				clrscr();
				EditInfoMenu_s(p);
			}
		}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_DateOfBirth_Menu_s(Staff*& p) {
	string a = { "[SAVE]" };
	string b = { "DateOfBirth: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[SAVE]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "DATE OF BIRTH - INFORMATION"), 7, "DATE OF BIRTH - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.DateOfBirth;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.DateOfBirth;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;

		writeText(56, 21, a, mau[0]);

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			system("cls");
			EditInfoMenu_s(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_SocialID_Menu_s(Staff*& p) {
	string a = { "[SAVE]" };
	string b = { "SocialID: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[SAVE]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "SOCIAL ID - INFORMATION"), 7, "SOCIAL ID - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.SocialID;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.SocialID;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;

		writeText(56, 21, a, mau[0]);

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			system("cls");
			EditInfoMenu_s(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}


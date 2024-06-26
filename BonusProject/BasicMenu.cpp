﻿#include"BasicMenu.h"

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

TRANGTHAI key(int z) {
	if (z == 224) {
		char c;
		c = _getch();
		if (c == 72) {
			return UP;
		}
		if (c == 80) {
			return DOWN;
		}
		if (c == 77) {
			return RIGHT;
		}
		if (c == 75) {
			return LEFT;
		}
	}
	else if (z == 13) return ENTER;
	else if (z == 8) return BACKSPACE;
}


void MainMenu(Staff* p) {
	p->pSchoolHead = init_sy();
	//p->pSchoolHead->pHead = init_s();
	School c;
	Build(c);
	int y = 10;
	int n = 4;
	str thaotac[4] = { "Login", "About us","Help","Exit"};
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "PORTAL HCMUS"), Upbox, "PORTAL HCMUS", MAUCHU);
	for (int i = 0;i < n;i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();

		textColor(MAUNEN);
		int tmp = tt;
		gotoxy(LeftBox - 2, Upbox + Line + tt);
		cout << char(175);
		gotoxy(RightBox+ 2, Upbox + Line + tt);
		cout << char(174);

		for (int i = 0;i < n;i++) {
			writeText(LeftBox, Upbox+Line+i, thaotac[i], mau[i]);
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 13;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_main_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;

		textColor(MAUNEN);
		gotoxy(LeftBox - 2, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox + 2, Upbox + Line + tmp);
		cout << " ";
	}
	gotoxy(LeftBox - 2, Upbox + Line );
	textColor(MAUNEN);
	cout << char(41) << char(41);
}

// hàm enter ở vị trí nào 
void push_enter_main_menu(int y, Staff* p) {
	switch (y) {
	case 10:
		LoginMenu(p);
		break;
	case 11:
		AboutusMenu(p);
		break;
	case 12:
		HelpMenu(p);
		break;
	case 13:
		MainMenu(p);
		return;
	}
}



void LoginMenu(Staff* p) {
	string z;
	string s;
	string c = { "[ Staff ]" };
	string d = { "[ Student ]" };
	int y = 10;
	int n = 2;
	

	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:";
	str thaotac[2] = { "[ Staff ]", "[ Student ]" };

	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(XboxLG_1, YboxLG_1, WboxLG, HboxLG, MAUCHU);
	drawBox(XboxLG_2, YboxLG_2, WboxLG, HboxLG, MAUCHU);
	

	int* mau = new int[n];
	writeText(central(WConsole, "LOGIN"), Upbox, "LOGIN", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	writeText(45, 19, c, 7);
	writeText(65, 19, d, 7);

	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	string id;
	cin >> id;
	textColor(7);
	gotoxy(47, 11);
	cout << "ID:" << id;

	gotoxy(47, 15);
	textColor(MAUNEN);
	cout << "Password:";
	string pass = getPassword();
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:" ;
	for (int i = 0;i < pass.size();i++)cout << "*";

	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == c) {
				writeText(45, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == d) {
				writeText(65, 19, thaotac[i], mau[i]);
			}
			gotoxy(50, 11);
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_menu_login_2(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}



void push_enter_menu_login_2(int y, Staff* p) {
	switch (y) {
	case 10:
		SuccessMenu();
		StaffMenu(p);
		break;
	case 11:
		SuccessMenu();
		StudentMenu(p);
		break;
	case 14:
		MainMenu(p);
	}
}

void AboutusMenu(Staff* p) {
	str thaotac = { "[ EXIT ]" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(central(WConsole, "ABOUT US"), Upbox, "ABOUT US", MAUCHU);
	gotoxy(45, 10);
	cout << "HOANG VAN SANG MSSV: 23120350";
	gotoxy(45, 11);
	cout << "Graphic design";
	gotoxy(45, 13);
	cout << "TRAN DINH THI MSSV: 23120359";
	gotoxy(45, 14);
	cout << "Content design";
	ShowCur(false);
	deleteScreen();
	textColor(MAUNEN);
	gotoxy(54, 22);
	cout << "[ EXIT ]";
	int z = _getch();
	TRANGTHAI trangthai = key(z);
	switch (trangthai) {
	case DOWN:
		AboutusMenu(p);
	case UP:
		AboutusMenu(p);
	case LEFT:
		system("cls");
		MainMenu(p);
	case ENTER:
		system("cls");
		MainMenu(p);
	
	}
	gotoxy(45, 22);
	cout << "press ";
	textColor(MAUNEN);
	cout << "ENTER";
	textColor(7);
	cout << " to back....";
}


void HelpMenu(Staff* p) {
	str thaotac = { "[ EXIT ]" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(central(WConsole, "HELP"), Upbox, "HELP", MAUCHU);

	gotoxy(45, 10);
	cout << "Password is the last six numbers ";
	gotoxy(45, 11);
	cout << "of the social ID. ";

	ShowCur(false);
	deleteScreen();
	textColor(MAUNEN);
	gotoxy(54, 22);
	cout << "[ EXIT ]";
	int z = _getch();
	TRANGTHAI trangthai = key(z);
	switch (trangthai) {
	case DOWN:
		HelpMenu(p);
	case UP:
		HelpMenu(p);
	case LEFT:
		system("cls");
		MainMenu(p);
	case ENTER:
		system("cls");
		MainMenu(p);
	
	}
	gotoxy(45, 22);
	cout << "press ";
	textColor(MAUNEN);
	cout << "ENTER";
	textColor(7);
	cout << " to back....";
}


void StudentMenu(Staff* p) {
	int y = 10;
	int n = 5;
	str thaotac[5] = { "Infomation","Course", "Class","Score","Back to menu" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "PORTAL HCMUS - STUDENT"), Upbox, "PORTAL HCMUS - STUDENT", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();

		textColor(MAUNEN);
		int tmp = tt;
		gotoxy(LeftBox - 2, Upbox + Line + tt);
		cout << char(175);
		gotoxy(RightBox + 2, Upbox + Line + tt);
		cout << char(174);

		for (int i = 0; i < n; i++) {
			writeText(LeftBox, Upbox + Line + i, thaotac[i], mau[i]);
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 14;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case LEFT:
			system("cls");
			LoginMenu(p);
			break;
		case ENTER:
			system("cls");
			push_enter_student_menu(y,p);
			break;
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;

		textColor(MAUNEN);
		gotoxy(LeftBox - 2, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox + 2, Upbox + Line + tmp);
		cout << " ";
	}
}


void push_enter_student_menu(int y, Staff* p) {  //"Infomation","Course", "Class","Score","Back to menu"
	switch (y) {
	case 10:
		LoginMenu(p);
		break;
	case 11:
		LoginMenu(p);
		break;
	case 12:
		LoginMenu(p);
		break;
	case 13:
		LoginMenu(p);
		break;
	case 14:
		MainMenu(p);
		break;
	}
}

void StaffMenu(Staff* p) {
	int y = 10;
	int n = 7;
	str thaotac[7] = { "Create school year","View school year", "Create class","View course","Personal Information","Change password","Logout"};
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "PORTAL HCMUS - STAFF"), Upbox, "PORTAL HCMUS - STAFF", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		gotoxy(LeftBox - 2, Upbox + Line + tt);
		cout << char(175);
		gotoxy(RightBox + 2, Upbox + Line + tt);
		cout << char(174);

		for (int i = 0; i < n; i++) {
			writeText(LeftBox, Upbox + Line + i, thaotac[i], mau[i]);
		}
		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 16;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case LEFT:
			system("cls");
			LoginMenu(p);
		case ENTER:
			system("cls");
			push_enter_staff_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;

		textColor(MAUNEN);
		gotoxy(LeftBox - 2, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox + 2, Upbox + Line + tmp);
		cout << " ";
	}
}


void push_enter_staff_menu(int y, Staff* p) {  
	switch (y) {
	case 10:
		CreateSchoolYearMenu(p);
		break;
	case 11:
		ViewschoolyearMenu(p);
		break;
	case 12:
		LoginMenu(p);
		break;
	case 13:
		LoginMenu(p);
		break;
	case 14:
		Info_Menu(p);
		break;
	case 15:
		ChangePasswordMenu(p);
		break;
	case 16:
		MainMenu(p);
		break;
	}
}

void ChangePasswordMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "[ SAVE ]" };
	string b = { "[ BACK ]" };
	str thaotac[2] = { "[ SAVE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	gotoxy(45, 10);
	cout << "Old Password: ";
	gotoxy(45, 11);
	cout << "New Password: ";
	gotoxy(45, 12);
	cout << "New Password Again: ";

	gotoxy(45, 16);
	cout << "[ SAVE ]";
	gotoxy(65, 16);
	cout << "[ BACK ]";

	int* mau = new int[n];
	writeText(central(WConsole, "CHANGE PASSWORD"), 7, "CHANGE PASSWORD", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << "Old Password: ";
	cin >> p->Info.Password;
	textColor(7);
	gotoxy(45, 10);
	cout << "Old Password: " << p->Info.Password;

	textColor(MAUNEN);
	gotoxy(45, 11);
	cout << "New Password: ";
	cin >> p->Info.Password;
	textColor(7);
	gotoxy(45, 11);
	cout << "New Password: " << p->Info.Password;

	textColor(MAUNEN);
	gotoxy(45, 12);
	cout << "New Password Again: ";
	cin >> p->Info.Password;
	textColor(7);
	gotoxy(45, 12);
	cout << "New Password Again: " << p->Info.Password;
	

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 16, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(65, 16, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_cre_sy_menu(y, p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void CreateSchoolYearMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "[ CREATE ]" };
	string b = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);

	gotoxy(45, 16);
	cout << "[ CREATE ]";
	gotoxy(65, 16);
	cout << "[ BACK ]";

	int* mau = new int[n];
	writeText(central(WConsole, "CREATE SCHOOL YEAR"), 7, "CREATE SCHOOL YEAR", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(47, 11);
	string year;
	cout << "school year:";
	cin >> year;
	textColor(7);
	gotoxy(47, 11);
	cout << "school year:" << year;
	
	SchoolYear* point = cre(year);
	point->pHead = init_s();
	add_year(p, point);

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 16, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(65, 16, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_cre_sy_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_cre_sy_menu(int y,Staff* p) {
	switch (y) {
	case 10:
		SuccessMenu();
		StaffMenu(p);
		break;
	case 11:
		StaffMenu(p);
		break;
	}
}

void SuccessMenu(){
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	gotoxy(45, 9);
	cout << "Create scucess press ";
	textColor(MAUNEN);
	cout << "ENTER";
	textColor(7);
	cout << " to " << endl;
	gotoxy(43, 10);
	cout << "continue.....";
	int z = _getch();
	TRANGTHAI trangthai = key(z);
	switch (trangthai) {
	case UP:
	{
		SuccessMenu();
		break;
	}
	case DOWN:
	{
		SuccessMenu();
		break;
	}
	case ENTER:
		system("cls");
		break;
	}
}

SchoolYear* cre(string a) {
	SchoolYear* p = new SchoolYear;
	p->Year = a;
	p->pNext = NULL;
	return p;
}

void add_year(Staff* p,SchoolYear *tmp) {
	if (p->pSchoolHead == NULL) {
		p->pSchoolHead = tmp;
	}
	else {
		tmp->pNext = p->pSchoolHead;
		p->pSchoolHead = tmp;
	}
}

SchoolYear* init_sy() {
	SchoolYear* p = NULL;
	return p;
}

int count_shoolyear(SchoolYear* p) {
	SchoolYear* tmp = p;
	int count = 0;
	if (tmp == NULL) return count;
	while (tmp != NULL) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}
	
void ViewschoolyearMenu(Staff* p) {
	
	if (p->pSchoolHead == NULL) {
		int y = 10;
		int n = 2;
		int tt = 0;
		string a = { "[ CREATE NEW SCHOOL YEAR ]" };
		string b = { "[ BACK ]" };
		str thaotac[2] = { "[ CREATE NEW SCHOOL YEAR ]","[ BACK ]" };

		drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

		int* mau = new int[n];
		writeText(central(WConsole, "SCHOOL YEARS"), 7, "SCHOOL YEARS", MAUCHU);
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[0] = MAUNEN;
		gotoxy(45, 10);
		cout << "School year is empty.........";
		while (1) {
			ShowCur(false);
			deleteScreen();
			textColor(MAUNEN);
			int tmp = tt;
			for (int i = 0; i < n; i++) {
				if (thaotac[i] == a) {
					writeText(47, 12, thaotac[i], mau[i]);
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
					y = 11;
					tt = n - 1;
				}
				else {
					tt--;
					y--;
				}
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = 0;
					y = 10;
				}
				else {
					tt++;
					y++;
				}
				break;
			}
			case ENTER:
				system("cls");
				if (y == 10) {
					CreateSchoolYearMenu(p);
				}
				else {
					StaffMenu(p);
				}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}


	int y = 10;
	int n = count_shoolyear(p->pSchoolHead) + 1;
	int tt = 0;
	
	SchoolYear* point = p->pSchoolHead;
	string* thaotac = new string[n];
	thaotac[n - 1] = { "[ BACK ]" };
	
	for (int i = 0; i < n - 1; i++) {
		thaotac[i] = point->Year;
		point = point->pNext;
	}
	
	
	
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	int run = 0;
	for (int i = 0; i < n - 1; i++) {
		drawBox(45, 10 + run, 30, 2, MAUCHU);
		run += 2;
	}
	int* mau = new int[n];
	writeText(central(WConsole, "SCHOOL YEARS"), 7, "SCHOOL YEARS", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		int chay = 0;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "[ BACK ]") {
				writeText(55, 20, thaotac[i], mau[i]);
			}
			else {
				writeText(55, 11 + chay, thaotac[i], mau[i]);
				chay += 2;
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 10 + n - 1;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_view_schoolyear_list(y, n,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_schoolyear_list(int y, int n,Staff*p) {
	if (y == 10 + n - 1) {
		StaffMenu(p);
	}
	else {
		SchoolYear* point = p->pSchoolHead;
		string* thaotac = new string[n];
		thaotac[n - 1] = { "[ BACK ]" };

		for (int i = 0; i < n - 1; i++) {
			thaotac[i] = point->Year;
			point = point->pNext;
		}
		int var = y - 10;
		SchoolYearMenu(thaotac[var], p);
	}
}

void SchoolYearMenu(string year, Staff* p) {
	int y = 10;
	int n = 3;
	int tt = 0;
	string a = { "[ BACK ]" };
	string thaotac[3] = { "Create Semester","View Semester","[ BACK ]"};

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	

	int* mau = new int[n];
	writeText(central(WConsole, year), 7, year, MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		int chay = 0;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(55, 20, thaotac[i], mau[i]);
			}
			else {
				writeText(50, 11 + chay, thaotac[i], mau[i]);
			}
			chay += 2;
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 12;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				CreateSemesterMenu_1(p);
			}
			else if(y==11){
				ViewSemesterMenu(p);
			}
			else {
				ViewschoolyearMenu(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Info_Menu(Staff* p) {
	string a = { "[ BACK ]" };
	string b = { "[ EDIT ]" };
	int y = 10;
	int n = 2;
	str thaotac[2] ={ "[ BACK ]", "[ EDIT ]" };
	string temp[6] = { "ID:","FirstName:", "LastName:","Gender:", "DateOfBirth:","SocialID:" };
	for (int i = 0; i < 6; i++) {
		writeText(57, 9 + i, temp[i], 7);
	}
	int tt = 0;

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(42, 9, 10, 6, MAUCHU);
	
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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
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
				y = 13;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				StaffMenu(p);
			}
			else {
				EditinfoMenu(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void EditinfoMenu(Staff* p) {
	string a = { "[ BACK ]" };
	
	int y = 10;
	int n = 7;
	
	string thaotac[7] = { "ID: ","FirstName: ", "LastName: ","Gender: ", "DateOfBirth: ","SocialID: ","[ BACK ]"};

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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(56, 21, thaotac[i], mau[i]);
			}
			else {
				writeText(45, 10+i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 16;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_editinfo_menu(y, p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_editinfo_menu(int y, Staff* p) {
	switch (y) { //{ "ID: ","FirstName: ", "LastName: ","Gender: ", "DateOfBirth: ","SocialID: ","[ BACK ]"};
	case 10:
		Edit_ID_Menu(p);
		break;
	case 11:
		Edit_Firstname_Menu(p);
		break;
	case 12:
		Edit_Lastname_Menu(p);
		break;
	case 13:
		Edit_Gender_Menu(p);
		break;
	case 14:
		Edit_DateOfBirth_Menu(p);
		break;
	case 15:
		Edit_SocialID_Menu(p);
		break;
	case 16:
		StaffMenu(p);
		break;
	}
}

void Edit_ID_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "ID: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = {"[ SAVE ]" };
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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Firstname_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "Firstname: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[ SAVE ]" };
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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Lastname_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "Lastname: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[ SAVE ]" };
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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}
		
void Edit_Gender_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "Gender: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[ SAVE ]" };
	writeText(56, 21, a, 7);
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "GENDER - INFORMATION"), 7, "GENDER - INFORMATION", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << b;
	cin >> p->Info.Gender;
	textColor(7);
	gotoxy(45, 10);
	cout << b << p->Info.Gender;

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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_DateOfBirth_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "DateOfBirth: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[ SAVE ]" };
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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_SocialID_Menu(Staff* p) {
	string a = { "[ SAVE ]" };
	string b = { "SocialID: " };
	int y = 10;
	int n = 1;
	int tt = 0;
	string thaotac[1] = { "[ SAVE ]" };
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
			EditinfoMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

Semester* cre_s(int n) {
	Semester* p = new Semester;
	p->Season = n;
	p->pNext = NULL;
	return p;
}

Semester* init_s() {
	Semester* p = NULL;
	return p;
}

int count_semester(Semester* p) {
	Semester* tmp = p;
	int count = 0;
	if (p == NULL) return count;
	while (tmp != NULL) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}


void AddSemester1(SchoolYear* p, Semester* q) {
	if (p->pHead == NULL) {
		p->pHead = q;
	}
	else {
		Semester* tmp = p->pHead;
		while (tmp->pNext != NULL) tmp = tmp->pNext;
		tmp->pNext = q;
	}
}


void CreateSemesterMenu_1(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "[ NEXT ]" };
	string b = { "[ BACK ]" };
	string c = { "Semester 1" };
	string d = { "Semester 2" };
	string e = { "Semester 3" };
	str thaotac[2] = { "[ NEXT ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	drawBox(45, 14, 30, 2, MAUCHU);


	gotoxy(45, 19);
	cout << "[ NEXT ]";
	gotoxy(68, 19);
	cout << "[ BACK ]";
	gotoxy(47, 11);
	cout << "Semester 1: ";
	gotoxy(47, 13);
	cout << "Semester 2: ";
	gotoxy(47, 15);
	cout << "Semester 3: ";

	gotoxy(44, 22);
	cout << "Use number ";
	textColor(MAUNEN);
	cout << "1 OR 0";
	textColor(7);
	cout << " to create ";
	gotoxy(44, 23);
	cout << "Example: Semester 1: 1, ";	
	gotoxy(44, 24);
	cout << "Semester 2: 0, Semester 3: 1";
	int* mau = new int[n];
	writeText(central(WConsole, "CREATE SEMESTER"), 7, "CREATE SEMESTER", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	Semester* point = new Semester;

	p->pSchoolHead->pHead = NULL;

	textColor(MAUNEN);
	gotoxy(47, 11);
	int semester;
	cout << "Semester 1: ";
	cin >> semester;
	if (semester == 1) {
		point = cre_s(1);
		AddSemester1(p->pSchoolHead, point);
	}
	textColor(7);
	gotoxy(47, 11);
	cout << "Semester 1: " << semester;

	textColor(MAUNEN);
	gotoxy(47, 13);
	cout << "Semester 2: ";
	cin >> semester;
	if (semester == 1) {
		point = cre_s(2);
		AddSemester1(p->pSchoolHead, point);
	}
	textColor(7);
	gotoxy(47, 13);
	cout << "Semester 2: " << semester;

	textColor(MAUNEN);
	gotoxy(47, 15);
	cout << "Semester 3: ";
	cin >> semester;
	if (semester == 1) {
		point = cre_s(3);
		AddSemester1(p->pSchoolHead, point);
	}
	textColor(7);
	gotoxy(47, 15);
	cout << "Semester 3: " << semester;

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
				writeText(68, 19, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			//push_cre_sy_menu(y,p);
			CreateSemesterMenu_2(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void CreateSemesterMenu_2(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "[ CREATE ]" };
	string b = { "[ BACK ]" };
	string c = { "Semester 1" };
	string d = { "Semester 2" };
	string e = { "Semester 3" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };
	
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);


	int* mau = new int[n];
	writeText(central(WConsole, "CREATE SEMESTER " + p->pSchoolHead->Year), 7, "CREATE SEMESTER " + p->pSchoolHead->Year, MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;




	gotoxy(45, 22);
	cout << "[ CREATE ]";
	gotoxy(68, 22);
	cout << "[ BACK ]";
	
	int count = count_semester(p->pSchoolHead->pHead);
	int chay = 0;
	for (Semester* q = p->pSchoolHead->pHead; q != NULL; q = q->pNext) {
		if (q->Season == 1) {
			gotoxy(45, 9 + chay);
			cout << "Semester 1";
			gotoxy(45, 10 + chay);
			cout << "Start Day: ";
			gotoxy(45, 11 + chay);
			cout << "End day: ";
		}
		if (q->Season == 2) {
			gotoxy(45, 9 + chay);
			cout << "Semester 2";
			gotoxy(45, 10 + chay);
			cout << "Start Day: ";
			gotoxy(45, 11 + chay);
			cout << "End day: ";
		}
		if (q->Season == 3) {
			gotoxy(45, 9 + chay);
			cout << "Semester 3";
			gotoxy(45, 10 + chay);
			cout << "Start Day: ";
			gotoxy(45, 11 + chay);
			cout << "End day: ";
		}
		chay += 4;
	}

	chay = 0;
	Semester* point = p->pSchoolHead->pHead;

	for (Semester* q = p->pSchoolHead->pHead; q != NULL; q = q->pNext) {
		if (q->Season == 1) {
			gotoxy(45, 9 + chay);
			cout << "Semester 1";
			gotoxy(45, 10 + chay);
			textColor(MAUNEN);
			cout << "Start Day: ";
			cin >> p->pSchoolHead->pHead->StartDay;
			textColor(7);
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;

			textColor(MAUNEN);
			gotoxy(45, 11 + chay);
			cout << "End Day: ";
			cin >> p->pSchoolHead->pHead->EndDay;
			textColor(7);
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
			p->pSchoolHead->pHead->pHead = new Course;
		}
		if (q->Season == 2) {
			gotoxy(45, 9 + chay);
			cout << "Semester 2";
			gotoxy(45, 10 + chay);
			textColor(MAUNEN);
			cout << "Start Day: ";
			cin >> p->pSchoolHead->pHead->StartDay;
			textColor(7);
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;

			textColor(MAUNEN);
			gotoxy(45, 11 + chay);
			cout << "End Day: ";
			cin >> p->pSchoolHead->pHead->EndDay;
			textColor(7);
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
			p->pSchoolHead->pHead->pHead = new Course;
		}
		if (q->Season == 3) {
			gotoxy(45, 9 + chay);
			cout << "Semester 3";
			gotoxy(45, 10 + chay);
			textColor(MAUNEN);
			cout << "Start Day: ";
			cin >> p->pSchoolHead->pHead->StartDay;
			textColor(7);
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;

			textColor(MAUNEN);
			gotoxy(45, 11 + chay);
			cout << "End Day: ";
			cin >> p->pSchoolHead->pHead->EndDay;
			textColor(7);
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
			p->pSchoolHead->pHead->pHead = new Course;
		}
		chay += 4;
		p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
	}

	p->pSchoolHead->pHead = point;


	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 22, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(68, 22, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			//push_cre_sy_menu(y,p);
			//SchoolYearMenu(p->pSchoolHead->Year, p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewSemesterMenu(Staff* p) {

	int nu = count_semester(p->pSchoolHead->pHead);
	
	if (nu == 0) {
		int y = 10;
		int n = 2;
		int tt = 0;
		string a = { "[ CREATE SEMESTER ]" };
		string b = { "[ BACK ]" };
		str thaotac[2] = { "[ CREATE SEMESTER ]","[ BACK ]" };

		drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
		
		int* mau = new int[n];
		writeText(central(WConsole, "SEMESTER - " + p->pSchoolHead->Year), 7, "SEMESTER - " + p->pSchoolHead->Year, MAUCHU);
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
			int tmp = tt;
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
					y = 11;
					tt = n - 1;
				}
				else {
					tt--;
					y--;
				}
				break;

			}
			case DOWN:
			{
				if (tt == n - 1) {
					tt = 0;
					y = 10;
				}
				else {
					tt++;
					y++;
				}
				break;
			}
			case ENTER:
				system("cls");
				if (y == 10) {
					CreateSemesterMenu_1(p);
				}
				else {
					ViewschoolyearMenu(p);
				}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}

	
	int y = 10;
	int tt = 0;
	int n = count_semester(p->pSchoolHead->pHead) + 1;
	string* thaotac = new string[n];
	int i = 0;
	thaotac[n - 1] = { "[ BACK ]" };	
	int chay = 0;

	Semester* point = p->pSchoolHead->pHead;
	for (Semester* q = p->pSchoolHead->pHead ;  q != NULL;  q = q->pNext) {
		if (q->Season == 1) {
			thaotac[i] = { "Semester 1" };
			gotoxy(45, 9 + chay);
			cout << "Semester 1";
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
		}
		if (q->Season == 2) {
			thaotac[i] = { "Semester 2" };
			gotoxy(45, 9 + chay);
			cout << "Semester 2";
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
		}
		if (q->Season == 3) {
			thaotac[i] = { "Semester 3" };
			gotoxy(45, 9 + chay);
			cout << "Semester 3";
			gotoxy(45, 10 + chay);
			cout << "Start Day: " << p->pSchoolHead->pHead->StartDay;
			gotoxy(45, 11 + chay);
			cout << "End Day: " << p->pSchoolHead->pHead->EndDay;
		}
		chay += 4;
		i++;
		p->pSchoolHead->pHead=p->pSchoolHead->pHead->pNext;
	}
	p->pSchoolHead->pHead = point;
	
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);	
	

	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER - " + p->pSchoolHead->Year), 7, "SEMESTER - " + p->pSchoolHead->Year, MAUCHU);
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
			if (thaotac[i] == "[ BACK ]") {
				writeText(55, 21, thaotac[i], mau[i]);
			}
			else{
				writeText(45, 9 + chay , thaotac[i], mau[i]);
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
				y = 10 + n - 1;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_view_semester_list(y,n,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_semester_list(int y, int n, Staff* p) {
	if (y == 10 + n - 1) {
		SchoolYearMenu(p->pSchoolHead->Year, p);
	}
	else {
		string* thaotac = new string[5];
		int i = 0;
		thaotac[n - 2] = { "[ BACK ]" };
		int chay = 0;
		Semester* point = p->pSchoolHead->pHead;
		for (Semester* q = p->pSchoolHead->pHead; q != NULL; q = q->pNext) {
			if (q->Season == 1) {
				thaotac[i] = { "Semester 1" };
			}
			if (q->Season == 2) {
				thaotac[i] = { "Semester 2" };
			}
			if (q->Season == 3) {
				thaotac[i] = { "Semester 3" };
			}
			chay += 4;
			i++;
			p->pSchoolHead->pHead->pHead = new Course;   // init course 
			p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
		}
		p->pSchoolHead->pHead = point;
		int var = y - 10;
		CourseMenu(thaotac[var], var + 1, p);
	}
}

void CourseMenu(string semester, int num,Staff* p) {
	int y = 10;
	int n = 3;
	int tt = 0;
	string a = { "Create Course" };
	string b = { "View course" };
	string thaotac[3] = { "Create Course","View course", "[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, semester), 7, semester, MAUCHU);

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
				writeText(50, 11, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(50, 13, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "[ BACK ]") {
				writeText(56, 20, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 12;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_season_menu(semester, num ,y, p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}


void push_enter_season_menu(string semester,int n, int y, Staff* p) {
	switch (y) {
	case 10:
		CreateCourseMenu(semester, n , p);
		break;
	case 11:
		ViewCourseMenu(semester,n,p);
		break;
	case 12:
		ViewSemesterMenu(p);
		break;
	}
}

Course* init_c() {
	Course* p = new Course;
	p = NULL;
	return p;
}

void CreateCourseMenu(string semester,int num , Staff* p) {
	p->pSchoolHead->pHead->pHead = init_c();

	string a = { "Course ID: " };
	string b = { "Course name: " };
	string c = { "Class name: " };
	string d = { "Teacher name: " };
	string e = { "Credit: " };
	string f = { "Size: " };
	string g = { "Day of week: " };
	string h = { "Season: " };
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };
	writeText(central(WConsole, "CREATE COURSE - " + semester), 7, "CREATE COURSE - " + semester, MAUCHU);
	int y = 10;
	int n = 2;
	int tt = 0;
	string j = { "[ CREATE ]" };
	string k = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 21, thaotac[0],7);

	writeText(65, 21, thaotac[1], 7);
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

	/*struct Course {
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
};*/
	Course* tmp = new Course;
	Semester* pp = p->pSchoolHead->pHead;
	for (int i = 0; i < num - 1; i++) {
		p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
	}

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << temp[0];
	cin >> p->pSchoolHead->pHead->pHead->CourseID;
	textColor(7);
	gotoxy(45, 10);
	cout << temp[0] << p->pSchoolHead->pHead->pHead->CourseID;

	textColor(MAUNEN);
	gotoxy(45, 11);
	cout << temp[1];
	cin >> p->pSchoolHead->pHead->pHead->CourseName;
	textColor(7);
	gotoxy(45, 11);
	cout << temp[1] << p->pSchoolHead->pHead->pHead->CourseName;

	textColor(MAUNEN);
	gotoxy(45, 12);
	cout << temp[2];
	cin >> p->pSchoolHead->pHead->pHead->ClassName;
	textColor(7);
	gotoxy(45, 12);
	cout << temp[2] << p->pSchoolHead->pHead->pHead->ClassName;

	textColor(MAUNEN);
	gotoxy(45, 13);
	cout << temp[3];
	cin >> p->pSchoolHead->pHead->pHead->TeacherName;
	textColor(7);
	gotoxy(45, 13);
	cout << temp[3] << p->pSchoolHead->pHead->pHead->TeacherName;

	textColor(MAUNEN);
	gotoxy(45, 14);
	cout << temp[4];
	cin >> p->pSchoolHead->pHead->pHead->Credit;
	textColor(7);
	gotoxy(45, 14);
	cout << temp[4] << p->pSchoolHead->pHead->pHead->Credit;

	textColor(MAUNEN);
	gotoxy(45, 15);
	cout << temp[5];
	cin >> p->pSchoolHead->pHead->pHead->Size;
	textColor(7);
	gotoxy(45, 15);
	cout << temp[5] << p->pSchoolHead->pHead->pHead->Size;

	textColor(MAUNEN);
	gotoxy(45, 16);
	cout << temp[6];
	cin >> p->pSchoolHead->pHead->pHead->DayOfWeek;
	textColor(7);
	gotoxy(45, 16);
	cout << temp[6] << p->pSchoolHead->pHead->pHead->DayOfWeek;

	textColor(MAUNEN);
	gotoxy(45, 17);
	cout << temp[7];
	cin >> p->pSchoolHead->pHead->pHead->Session;
	textColor(7);
	gotoxy(45, 17);
	cout << temp[7] << p->pSchoolHead->pHead->pHead->Session;
	
	p->pSchoolHead->pHead = pp;


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
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				SuccessMenu();
				CourseMenu(semester,num, p);
			}
			else {
				CourseMenu(semester,num, p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void addcourse(Semester* p, Course* q) {
	if (p->pHead == NULL) {
		p->pHead = q;
	}
	else {
		q->pNext = p->pHead;
		p->pHead = q;
	}
}

int countcourse(Semester* p) {
	Semester* tmp = p;
	int count = 0;
	if (p == NULL) return count;
	while (tmp != NULL) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}

void ViewCourseMenu(string semester, int num, Staff* p) {
	for (int i = 0; i < num - 1; i++) {
		p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
	}
	Semester* tmp = p->pSchoolHead->pHead;

	int y = 10;
	int tt = 0;
	int n = countcourse(tmp) + 3;
	string* thaotac = new string[n];
	Course* poin = tmp->pHead;
	for (int i = 0; i < n; i++) {
		thaotac[i] = poin->CourseName;
		i++;
		//poin = poin->pNext;
	}

	thaotac[n - 3] = { "[ BACK ]" };
	thaotac[n - 2] = { "[ ADD MORE ]" };
	thaotac[n - 1] = { "[ DELETE ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "COURSE"), 7, "COURSE", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	for (int i = 0; i < countcourse(tmp); i++) {
		gotoxy(45, 10 + i);
		cout << i + 1;
	}
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "[ BACK ]") {
				writeText(55, 20, thaotac[i], mau[i]);
			}
			else if (thaotac[i] == "[ ADD MORE ]") {
				writeText(55, 21, thaotac[i], mau[i]);
			}
			else if (thaotac[i] == "[ DELETE ]") {
				writeText(55, 22, thaotac[i], mau[i]);
			}
			else {
				writeText(47, 10 + i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 10 + n - 1;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			push_enter_view_course_list(poin->CourseName,num,y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_course_list(string semester,int num, int y, Staff* p) {
	
	cout << "y = " << y << endl;
	for (int i = 0; i < num - 1; i++) {
		p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
	}
	Semester* tmp = p->pSchoolHead->pHead;

	int n = countcourse(tmp) + 3;
	int z = y;
	string* thaotac = new string[n];
	Course* poin = tmp->pHead;
	for (int i = 0; i < n; i++) {
		thaotac[i] = poin->CourseName;
		i++;
		//poin = poin->pNext;
	}
	cout << countcourse(tmp) << endl;
	cout << 10 + n - 1 << endl;
	if (z == 10 + n - 1) {
		DeleteCourseMenu(p);
	}
	if (z == 10 + n - 2) {
		AddCourseMenu(p);
	}
	if (z == 10 + n - 3) {
		CourseMenu(semester, num, p);
	}
	z = y - 10;
	CourseMenuInside(thaotac[z],num,p);
}

void CourseMenuInside(string q,int num, Staff* p) {

	for (int i = 0; i < num - 1; i++) {
		p->pSchoolHead->pHead = p->pSchoolHead->pHead->pNext;
	}

	Course* tmp = p->pSchoolHead->pHead->pHead;

	gotoxy(57, 10);
	cout << tmp->CourseID;
	gotoxy(58, 11);
	cout << tmp->CourseName;
	gotoxy(57, 12);
	cout << tmp->ClassName;
	gotoxy(58, 13); 
	cout << tmp->TeacherName;
	gotoxy(53, 14); 
	cout << tmp->Credit;
	gotoxy(51, 16);
	cout << tmp->Size;
	gotoxy(58, 17);
	cout << tmp->DayOfWeek;
	gotoxy(53, 18);
	cout << tmp->Session;


	string a = { "[ BACK ]" };
	string b = { "[ MEMBER ]" };
	int y = 10;
	int n = 2;
	str thaotac[2] = { "[ BACK ]", "[ MEMBER ]" };
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };
	for (int i = 0; i < 8; i++) {
		writeText(45, 9 + i, temp[i], 7);
	}

	int tt = 0;

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);



	int* mau = new int[n];
	writeText(central(WConsole, "COURSE INFORMATION"), 7, "COURSE INFORMATION", MAUCHU);
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
				writeText(45, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
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
				y = 13;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				ViewCourseMenu(q,num,p);
			}
			else {
				StaffMenu(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void DeleteCourseMenu(Staff* p) {

}

void AddCourseMenu(Staff* p) {

}

int count_class(Staff* p) {
	int count = 0;
	if (p->pClassHead == NULL) return count;
	Class* tmp = p->pClassHead;
	while (tmp) {
		count++;
		tmp = tmp->pNext;
	}
	return count;
}

void ViewClassMenu(Staff* p) {
	/*struct Class{
	string NameClass;
	Student* pHead;
	Class* pNext;
};
*/
	Class* tmp = p->pClassHead;
	
	string a = { "[ BACK ]" };
	string b = { "[ EDIT ]" };
	int y = 10;
	int n = count_class(p) + 2;

	string* thaotac = new string[n];
	thaotac[n - 2] = "[ BACK ]";
	thaotac[n - 1] = "[ EDIT ]";
	int tt = 0;
	int i = 0;
	while (tmp) {
		thaotac[i] = tmp->NameClass;
		i++;
	}

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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			else if (thaotac[i] == b) {
				writeText(65, 21, thaotac[i], mau[i]);
			}
			else {
				writeText(45, 10+i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 10 + n - 1;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			//push_enter_view_class_menu(y, p);
			break;
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_class_menu(int y,Class*tmp, Staff*p) {
	int z = y;
	int n = count_class(p) + 1;
	if (z == 10 + n - 1) {
		edit_class(p);
	}
	if (z == 10 + n - 2) {
		MainMenu(p);
	}
	inside_class(tmp, p);
}

void edit_class(Staff* p) {

}

int count_student(Class* p) {
	int count = 0;
	if (p->pHead == NULL)return count;
	Student* tmp = p->pHead;
	while (tmp) {
		count++;
		tmp = tmp->pNextClass;
	}
	return count;
}

void inside_class(Class* q, Staff* p) {
	/*
struct InforPerSon {
	string Password;
	string ID;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;
};
*/

	Student* tmp = q->pHead;

	string a = { "[ BACK ]" };
	string b = { "[ EDIT ]" };
	int y = 10;
	int n = count_student(q) + 2;

	string* thaotac = new string[n];
	thaotac[n - 2] = "[ BACK ]";
	thaotac[n - 1] = "[ EDIT ]";
	int tt = 0;
	int i = 0;


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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(45, 21, thaotac[i], mau[i]);
			}
			else if (thaotac[i] == b) {
				writeText(65, 21, thaotac[i], mau[i]);
			}
			else {
				writeText(45, 10 + i, thaotac[i], mau[i]);
			}
		}

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 10 + n - 1;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			//push_enter_view_class_menu(y, p);
			break;
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_student(int num, Staff* p) {

}

void Viewinfocourse(Staff* p, Semester* s, Course*& q, string file_csv) //  gồm delete , add student,  back
{
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };

	gotoxy(45, 10);
	cout << temp[0] << q->CourseID;

	gotoxy(45, 11);
	cout << temp[1] << q->CourseName;

	gotoxy(45, 12);
	cout << temp[2] << q->ClassName;

	gotoxy(45, 13);
	cout << temp[3] << q->TeacherName;

	gotoxy(45, 14);
	cout << temp[4] << q->Credit;

	gotoxy(45, 15);
	cout << temp[5] << q->Size;

	gotoxy(45, 16);
	cout << temp[6] << q->DayOfWeek;

	gotoxy(45, 17);
	cout << temp[7] << q->Session;

	int y = 10;
	int n = 3;

	string thaotac[3] = { "*BACK*","*ADD STUDENT*","*DELETE*" };

	int tt = 0;



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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "*BACK*") {
				writeText(43 , 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "*ADD STUDENT*") {
				writeText(52, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "*DELETE*") {
				writeText(69, 21, thaotac[i], mau[i]);
			}
		}


		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case LEFT:
		{
			if (tt == 0)
			{
				y = 12;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				// back to course list    void ViewCourseMenu_s(Staff*& p, SchoolYear*& q, Semester*& r)
			}
			if (y == 11) {
				AddStudentMenu(p, s,q, file_csv);
			}
			if (y == 12) {
				DelelteCourse(s,q);
				// back to course list    void ViewCourseMenu_s(Staff*& p, SchoolYear*& q, Semester*& r)
			}
			break;
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void DelelteCourse(Semester*s,Course * q) {
	Course* tmp = s->pHead;
	for (tmp; tmp->pNext != q; tmp = tmp->pNext);
	tmp->pNext = q->pNext;
	delete q;
}

void AddStudentMenu(Staff* p,Semester*s, Course*& q, string file_csv) //  1 or csv
{
	int y = 10;
	int n = 4;
	int tt = 0;
	string thaotac[4] = { "UP Load File CSV","Add One Student","View List Student", "[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawTable(45, 11, 30, 2, 3, 7);
	gotoxy(47, 12);
	cout << "UP Load File CSV";
	gotoxy(47, 14);
	cout << "Add One Student";
	gotoxy(47, 16);
	cout << "View List Student";
	gotoxy(55, 20);
	cout << "[ BACK ]";


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
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == "[ BACK ]") {
				writeText(55, 20, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "UP Load File CSV") {
				writeText(47, 12, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "Add One Student") {
				writeText(47, 14, thaotac[i], mau[i]);
			}
			if (thaotac[i] == "View List Student") {
				writeText(47, 16, thaotac[i], mau[i]);
			}
		}


		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case UP:
		{
			if (tt == 0)
			{
				y = 13;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				AddStudent_CSV(p, s,q, file_csv);
			}
			if (y == 11) {
				AddOneStudent(p, s, q,file_csv);
			}
			if (y == 12) {
				ViewStudentMenu(p, s, q,file_csv);
			}
			if (y == 13) {
				Viewinfocourse(p, s, q, file_csv);
			}
			break;
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void AddOneStudent(Staff* p, Semester* s, Course* q,string file_csv) {
	Student* sv = new Student;

	string a = { "Password: " };
	string b = { "ID: " };
	string c = { "FirstName: " };
	string d = { "LastName: " };
	string e = { "Gender: " };
	string f = { "DateOfBirth: " };
	string g = { "SocialID: " };
	string h = { "dTB: " };

	str temp[8] = {"Password: ", "ID: ", "FirstName: " ,  "LastName: " , "Gender: " , "DateOfBirth: " , "SocialID: " ,  "dTB: " };
	writeText(central(WConsole, "ADD ONE STUDENT" ), 7, "ADD ONE STUDENT", MAUCHU);
	int y = 10;
	int n = 2;
	int tt = 0;
	string j = { "[ CREATE ]" };
	string k = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 21, thaotac[0], 7);

	writeText(65, 21, thaotac[1], 7);
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

	/*struct InforPerSon {
	string Password;
	string ID;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;
	string dTB;
};
*/

	textColor(MAUNEN);
	gotoxy(45, 10);
	cout << temp[0];
	cin >> sv->Info.Password;
	textColor(7);
	gotoxy(45, 10);
	cout << temp[0] << sv->Info.Password;

	textColor(MAUNEN);
	gotoxy(45, 11);
	cout << temp[1];
	cin >> sv->Info.ID;
	textColor(7);
	gotoxy(45, 11);
	cout << temp[1] << sv->Info.ID;

	textColor(MAUNEN);
	gotoxy(45, 12);
	cout << temp[2];
	cin >> sv->Info.FirstName;
	textColor(7);
	gotoxy(45, 12);
	cout << temp[2] << sv->Info.FirstName;

	textColor(MAUNEN);
	gotoxy(45, 13);
	cout << temp[3];
	cin >> sv->Info.LastName;
	textColor(7);
	gotoxy(45, 13);
	cout << temp[3] << sv->Info.LastName;

	textColor(MAUNEN);
	gotoxy(45, 14);
	cout << temp[4];
	cin >> sv->Info.Gender;
	textColor(7);
	gotoxy(45, 14);
	cout << temp[4] << sv->Info.Gender;

	textColor(MAUNEN);
	gotoxy(45, 15);
	cout << temp[5];
	cin >> sv->Info.DateOfBirth;
	textColor(7);
	gotoxy(45, 15);
	cout << temp[5] << sv->Info.DateOfBirth;

	textColor(MAUNEN);
	gotoxy(45, 16);
	cout << temp[6];
	cin >> sv->Info.SocialID;
	textColor(7);
	gotoxy(45, 16);
	cout << temp[6] << sv->Info.SocialID;

	textColor(MAUNEN);
	gotoxy(45, 17);
	cout << temp[7];
	cin >> sv->Info.dTB;
	textColor(7);
	gotoxy(45, 17);
	cout << temp[7] << sv->Info.dTB;



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
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				SuccessMenu();
				AddStudentMenu(p, s, q, file_csv);
			}
			else {
				AddStudentMenu(p, s, q, file_csv);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}

}

void AddStudent_CSV(Staff* p, Semester* s, Course* q,string file_csv) {
	Student* sv = new Student;

	writeText(central(WConsole, "ADD STUDENT CSV"), 7, "ADD STUDENT CSV", MAUCHU);
	int y = 10;
	int n = 2;
	int tt = 0;
	string j = { "[ CREATE ]" };
	string k = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 21, thaotac[0], 7);

	writeText(65, 21, thaotac[1], 7);

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
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				SuccessMenu();
				AddStudentMenu(p, s, q, file_csv);
			}
			else {
				AddStudentMenu(p, s, q, file_csv);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewStudentMenu(Staff* p, Semester* s, Course* q,string file_csv)  // rỗng thì xuất ra đường dẫn tới add menu
{
	Student* sv = new Student;

	writeText(central(WConsole, "VIEW STUDENT LIST"), 7, "VIEW STUDENT LIST", MAUCHU);
	int y = 10;
	int n = 2;
	int tt = 0;
	string j = { "[ CREATE ]" };
	string k = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	writeText(45, 21, thaotac[0], 7);

	writeText(65, 21, thaotac[1], 7);

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
				y = 11;
				tt = n - 1;
			}
			else {
				tt--;
				y--;
			}
			break;

		}
		case RIGHT:
		{
			if (tt == n - 1) {
				tt = 0;
				y = 10;
			}
			else {
				tt++;
				y++;
			}
			break;
		}
		case ENTER:
			system("cls");
			if (y == 10) {
				SuccessMenu();
				AddStudentMenu(p, s, q, file_csv);
			}
			else {
				AddStudentMenu(p, s, q, file_csv);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}

}
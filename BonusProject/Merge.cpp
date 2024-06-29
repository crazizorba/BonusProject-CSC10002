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



void MainMenu_s() {
	School S;
	Build(S);
	int n = 4;
	str thaotac[4] = { "Login", "About us","Help","Exit" };
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
		gotoxy(RightBox + 2, Upbox + Line + tt);
		cout << char(174);

		for (int i = 0;i < n;i++) {
			writeText(LeftBox, Upbox + Line + i, thaotac[i], mau[i]);
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
			if (tt == 0) {
				LoginMenu_s(S);
			}
			else if (tt == 1) {
				clrscr();
				AboutusMenu_s();
			}
			else if (tt == 2) {
				clrscr();
				HelpMenu_s();
			}
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
	gotoxy(LeftBox - 2, Upbox + Line);
	textColor(MAUNEN);
	cout << char(41) << char(41);
}

void LoginMenu_s(School &S) {
	string c = { "[Staff]" };
	string d = { "[Student]" };
	int n = 2;
	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:";
	str thaotac[2] = { "[Staff]", "[Student]" };

	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(XboxLG_1, YboxLG_1, WboxLG, HboxLG, MAUCHU);
	drawBox(XboxLG_2, YboxLG_2, WboxLG, HboxLG, MAUCHU);
	//drawBox(45, 18, 10, 2, MAUCHU);
	//drawBox(65, 18, 10, 2, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "LOGIN"), Upbox, "LOGIN", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	writeText(48, 19, c, 7);
	writeText(64, 19, d, 7);

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
	cout << "Password:";
	for (int i = 0;i < pass.size();i++)cout << "*";

	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == c) {
				writeText(48, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == d) {
				writeText(64, 19, thaotac[i], mau[i]);
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
				Staff* p = LoginStaff(S, id, pass);
				if (p == NULL) {
					writeText(central(WConsole, "Incorrect ID or password."), 22, "Incorrect ID or password.", MAUNEN);
					writeText(central(WConsole, "Incorrect ID or password."), 23, "Press any key to back.", MAUNEN);
					int z1 = _getch();
					clrscr();
					MainMenu_s();
				}
				else {
					clrscr();
					StaffMenu_s(p);
				}
			}
			else if (tt == 1) {
				Student* p = LoginStudent(S, id, pass);
				if (p == NULL) {
					writeText(central(WConsole, "Incorrect ID or password."), 22, "Incorrect ID or password.", MAUNEN);
					writeText(central(WConsole, "Incorrect ID or password."), 23, "Press any key to back.", MAUNEN);
					int z1 = _getch();
					clrscr();
					MainMenu_s();
				}
				else {
					clrscr();
					StudentMenu_s(p,S);
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

void StaffMenu_s(Staff*&p) {
	int n = 6;
	str thaotac[6] = { "Add school year","List school year", "Add class","List class","Personal Information","[LOG OUT]" };
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
		if (tt != n - 1) {
			gotoxy(LeftBox - 6, Upbox + Line + tt);
			cout << char(175);
			gotoxy(RightBox + 7, Upbox + Line + tt);
			cout << char(174);
		}
		for (int i = 0; i < n; i++) {
			if (i != n-1) writeText(LeftBox - 4, Upbox + Line + i, thaotac[i], mau[i]);
			else writeText(Xexit-2, Yexit, thaotac[i], mau[i]);
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
			if (tt == 4) {
				system("cls");
				InfoMenu_s(p);
			}
			else if (tt == 5) {
				clrscr();
				MainMenu_s();
			}
			else if (tt == 0) {
				clrscr();
				AddSchoolYearMenu_s(p);
			}
			else if (tt == 1) {
				clrscr();
				ViewschoolyearList_s(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;

		textColor(MAUNEN);
		gotoxy(LeftBox - 6, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox + 7, Upbox + Line + tmp);
		cout << " ";
	}
}

void AboutusMenu_s() {
	str thaotac = { "EXIT" };
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
	cout << "*** EXIT ***";
	int z = _getch();
	TRANGTHAI trangthai = key(z);
	switch (trangthai) {
	case ENTER:
		system("cls");
		MainMenu_s();
	}
	
}


void HelpMenu_s() {
	str thaotac = { "EXIT" };
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
	cout << "*** EXIT ***";
	int z = _getch();
	TRANGTHAI trangthai = key(z);
	switch (trangthai) {
	case ENTER:
		system("cls");
		MainMenu_s();
	}
	
}

void InfoMenu_s(Staff*&p) {
	string a = { "[BACK]" };
	string b = { "[EDIT]" };
	int n = 2;
	str thaotac[2] = { "[BACK]", "[EDIT]" };
	string temp[6] = { "ID: ","FirstName: ", "LastName: ","Gender: ", "DateOfBirth: ","SocialID: " };
	
	writeText(57, 10 , temp[0], 7);
	cout << p->Info.ID;
	writeText(57, 11, temp[1], 7);
	cout << p->Info.FirstName;
	writeText(57,12, temp[2], 7);
	cout << p->Info.LastName;
	writeText(57, 13, temp[3], 7);
	if (p->Info.Gender == 1) cout << "Male";
	else cout << "Female";
	writeText(57, 14, temp[4], 7);
	cout << p->Info.DateOfBirth;
	writeText(57, 15, temp[5], 7);
	cout << p->Info.SocialID;
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(42, 10, 10, 6, MAUCHU);
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
				writeText(46, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
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
				StaffMenu_s(p);
			}
			if (tt == 1) {
				clrscr();
				EditInfoMenu_s(p);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void AddSchoolYearMenu_s(Staff* &p) {
	int n = 2;
	int tt = 0;
	string a = { "[ADD]" };
	string b = { "[BACK]" };
	str thaotac[2] = { "[ADD]","[BACK]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(43, 10, 34, 2, MAUCHU);

	writeText(47, 16, thaotac[0], MAUCHU);
	writeText(69, 16, thaotac[1], MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "ADD SCHOOL YEAR"), 7, "ADD SCHOOL YEAR", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	writeText(44, 11, "School Year(yyyy-yyyy): ", MAUNEN);
	textColor(MAUNEN);
	string year;
	cin >> year;
	writeText(44, 11, "School Year(yyyy-yyyy): ", MAUCHU);

	cout <<year;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == a) {
				writeText(47, 16, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(69, 16, thaotac[i], mau[i]);
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
			if (tt == 1) {
				system("cls");
				StaffMenu_s(p);
			}
			else if (tt == 0) {
				if (!checkSchoolYear(p, year)) {
					writeText(central(WConsole, "Invalid school year."), 20, "Invalid school year.", MAUNEN);
					writeText(central(WConsole, "Invalid school year."), 21, "Press any key to back.", MAUNEN);
					int z1 = _getch();
					clrscr();
					StaffMenu_s(p);
				}
				else {
					SchoolYear* s = CreateSchoolYear(year);
					AddSchoolYear(p, s);
					writeText(central(WConsole, "Press any key to back."), 20, "Success.", MAUNEN);
					writeText(central(WConsole, "Press any key to back."), 21, "Press any key to back.", MAUNEN);
					int z1 = _getch();
					clrscr();
					StaffMenu_s(p);
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

void StudentMenu_s(Student *&p,School &s) {
	int n = 3;
	str thaotac[4] = { "Infomation", "Score Board","LOG OUT" };
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
				system("cls");
				InfoMenu_s(p,s);
			}
			else if (tt == 2) {
				system("cls");
				MainMenu_s();
			}
			else if (tt == 1) {
				clrscr();
				ScoreBoardMenu_s(p, s);
			}
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

void InfoMenu_s(Student* &p,School&S) {
	string a = { "[BACK]" };
	string b = { "[EDIT]" };
	int n = 2;
	str thaotac[2] = { "[BACK]", "[EDIT]" };
	string temp[6] = { "ID: ","FirstName: ", "LastName: ","Gender: ", "DateOfBirth: ","SocialID: " };

	writeText(57, 10, temp[0], 7);
	cout << p->Info.ID;
	writeText(57, 11, temp[1], 7);
	cout << p->Info.FirstName;
	writeText(57, 12, temp[2], 7);
	cout << p->Info.LastName;
	writeText(57, 13, temp[3], 7);
	if (p->Info.Gender == 1) cout << "Male";
	else cout << "Female";
	writeText(57, 14, temp[4], 7);
	cout << p->Info.DateOfBirth;
	writeText(57, 15, temp[5], 7);
	cout << p->Info.SocialID;

	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(42, 10, 10, 6, MAUCHU);


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
				writeText(46, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
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
				StudentMenu_s(p,S);
			}
			else if (tt == 1) {
				clrscr();
				EditInfoMenu_s(p, S);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewschoolyearList_s(Staff* &p) {
	if (p->pSchoolHead == NULL) {
		int n = 3;
		int tt = 0;
		string a = { "[ADD]" };
		string b = { "[BACK]" };
		str thaotac[2] = { "[ADD]","[BACK]" };

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
				if (tt == 0) {
					
				}
				else if (tt == 1) {
					StaffMenu_s(p);
				}
			}
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}

	int n = count_shoolyear(p->pSchoolHead) + 1;
	int tt = 0;

	SchoolYear* point = p->pSchoolHead;
	string* thaotac = new string[n];
	thaotac[n - 1] = { "[BACK]" };

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
	for (int i = 0;i < n - 2;i++) {
		gotoxy(45, 10 + (i+1) * 2);
		cout << char(195);
		gotoxy(75, 10 + (i + 1) * 2);
		cout << char(180);
	
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
			if (thaotac[i] == "[BACK]") {
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
			if (tt == n - 1) {
				StaffMenu_s(p);
			}
			else {
				SchoolYear* q = getSchoolYearByNum(p, tt);
				SchoolYearMenu_s(p, q);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void EditInfoMenu_s(Student*& p, School& S) {
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
			gotoxy(LeftBox-2, 10 + tt);
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
				InfoMenu_s(p,S);
			}
			else if (tt == 0) {
				clrscr();
				Edit_ID_Menu_s(p,S);
			}
			else if (tt == 1) {
				clrscr();
				Edit_Firstname_Menu_s(p,S);
			}
			else if (tt == 2) {
				clrscr();
				Edit_Lastname_Menu_s(p,S);
			}
			else if (tt == 3) {
				clrscr();
				Edit_Gender_Menu_s(p,S);
			}
			else if (tt == 4) {
				clrscr();
				Edit_DateOfBirth_Menu_s(p,S);
			}
			else if (tt == 5) {
				clrscr();
				Edit_SocialID_Menu_s(p,S);
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
		gotoxy(LeftBox-2, 10 + tmp);
		cout << " ";
		gotoxy(RightBox+2, 10 + tmp);
		cout << " ";
	}
}

void Edit_ID_Menu_s(Student*& p, School& S) {
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
			EditInfoMenu_s(p,S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Firstname_Menu_s(Student*& p, School& S) {
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
			EditInfoMenu_s(p,S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Lastname_Menu_s(Student*& p, School& S) {
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
			EditInfoMenu_s(p,S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_Gender_Menu_s(Student*& p, School& S) {
	string a = "Gender: ";
	string c = "[FEMALE]";
	string b = "[MALE]";
	int n = 2;
	int tt = 0;
	string thaotac[2] = { "[MALE]","[FEMALE]"};
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
				EditInfoMenu_s(p,S);
			}
			else if (tt == 1) {
				p->Info.Gender = 0;
				clrscr();
				EditInfoMenu_s(p,S);
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

void Edit_DateOfBirth_Menu_s(Student*& p, School& S) {
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
			EditInfoMenu_s(p,S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void Edit_SocialID_Menu_s(Student*& p, School& S) {
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
			EditInfoMenu_s(p,S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ScoreBoardMenu_s(Student*& p, School& S) {
	Semester* k = S.pHead->pSchoolHead->pNext->pNext->pHead;
	int i = 0;
	Course* q = k->pHead;
	while (q != NULL) {
		Student* q1 = q->pHead;
		while (q1 != NULL) {
			if (p->Info.ID.compare(q1->Info.ID) == 0) {
				writeText(LeftBox - 5, Upbox + Line + i, q->CourseName, 7);
				writeText(LeftBox + 20, Upbox + Line + i, q1->Info.dTB, 7);
				i++;
			}
			q1 = q1->pNextCourse;
		}
		q = q->pNext;
		
	}
	string a = { "[BACK]" };

	int n = 1;
	str thaotac[1] = { "[BACK]" };
	
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "SCORE BOARD"), 7, "SCORE BOARD", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		writeText(central(WConsole, a), DownBox, a, MAUNEN);

		int z = _getch();
		TRANGTHAI trangthai = key(z);
		switch (trangthai) {
		case ENTER:
			clrscr();
			StudentMenu_s(p, S);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

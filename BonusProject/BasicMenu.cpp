#include"BasicMenu.h"

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
	int n = 6;
	str thaotac[6] = { "Create school year","View school year", "Create class","View course","Personal Information","Logout" };
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
				y = 15;
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
		MainMenu(p);
		break;
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
	/*//p->pSchoolHead = init_sy();
	SchoolYear* tmp = new SchoolYear;
	
	string a[3] = { "2021-2022","2022-2023","2023-2024" };
	for (int i = 0; i < 3; i++) {
		tmp = cre(a[i]);
		add_year(p, tmp);
	}*/
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
			push_enter_view_semester_list(y, n,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_semester_list(int y, int n,Staff*p) {
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
	int n = 2;
	int tt = 0;
	str thaotac[3] = { "Create Semester","View Semester"};

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
			writeText(50, 11 + chay, thaotac[i], mau[i]);
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
				CreateSemesterMenu(p);
			}
			else {
				ViewSemesterMenu(p);
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

void CreateSemesterMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "[ CREATE ]" };
	string b = { "[ BACK ]" };
	string c = { "Spring" };
	string d = { "Summer" };
	string e = { "Fall" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	drawBox(45, 14, 30, 2, MAUCHU);


	gotoxy(45, 19);
	cout << "[ CREATE ]";
	gotoxy(68, 19);
	cout << "[ BACK ]";
	gotoxy(47, 11);
	cout << "Semester Spring :";
	gotoxy(47, 13);
	cout << "Semester Summer :";
	gotoxy(47, 15);
	cout << "Semester Fall :";

	gotoxy(44, 22);
	cout << "Use number ";
	textColor(MAUNEN);
	cout << "1 OR 0";
	textColor(7);
	cout << " to create ";
	gotoxy(44, 23);
	cout << "Example: Semester Spring: 1, ";
	gotoxy(44, 24);
	cout << "Semester Summer: 0, Semester Fall: 1";
	int* mau = new int[n];
	writeText(central(WConsole, "CREATE SEMESTER"), 7, "CREATE SEMESTER", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	mau[0] = MAUNEN;

	textColor(MAUNEN);
	gotoxy(47, 11);
	int semester;
	cout << "Semester Spring :";
	cin >> semester;
	textColor(7);
	gotoxy(47, 11);
	cout << "Semester Spring :" << semester;

	textColor(MAUNEN);
	gotoxy(47, 13);
	//int semester;
	cout << "Semester Summer :";
	cin >> semester;
	textColor(7);
	gotoxy(47, 13);
	cout << "Semester Summer :" << semester;

	textColor(MAUNEN);
	gotoxy(47, 15);
	//int semester;
	cout << "Semester Fall :";
	cin >> semester;
	textColor(7);
	gotoxy(47, 15);
	cout << "Semester Fall :" << semester;

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
			push_cre_sy_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewSemesterMenu(Staff* p) {
	int y = 10;
	int n = 3;
	int tt = 0;
	string a = { "Semester Spring" };
	string b = { "Semester Summer" };
	string c = { "Semester Fall" };
	
	str thaotac[3] = { "Semester Spring","Semester Summer" ,"Semester Fall" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	drawBox(45, 14, 30, 2, MAUCHU);
	
	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER"), 7, "SEMESTER", MAUCHU);
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
			if (thaotac[i] == c) {
				writeText(50, 15, thaotac[i], mau[i]);
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
			push_enter_view_semester_list(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_semester_list(int y, Staff* p) {
	switch (y) {
	case 10:
		SpringMenu(p);
		break;
	case 11:
		SummerMenu(p);
		break;
	case 12:
		FallMenu(p);
		break;
	}
}

void SpringMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "Create Course" };
	string b = { "View course" };
	str thaotac[2] = { "Create Course","View course" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	
	gotoxy(50, 11);
	cout << "Create Course";
	gotoxy(50, 13);
	cout << "View course";
	

	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER - SPRING"), 7, "SEMESTER - SPRING", MAUCHU);
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
			push_enter_season_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_season_menu(int y, Staff* p) {
	switch (y) {
	case 10:
		CreateCourseMenu(p);
		break;
	case 11:
		ViewCourseMenu(p);
		break;
	}
}

void SummerMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;

	string a = { "Create Course" };
	string b = { "View course" };
	str thaotac[2] = { "Create Course","View course" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);

	gotoxy(50, 11);
	cout << "Create Course";
	gotoxy(50, 13);
	cout << "View course";

	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER - SUMMER"), 7, "SEMESTER - SUMMER", MAUCHU);
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
			push_enter_season_menu(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

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

void FallMenu(Staff* p) {
	int y = 10;
	int n = 2;
	int tt = 0;

	string a = { "Create Course" };
	string b = { "View course" };
	str thaotac[2] = { "Create Course","View course" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);

	gotoxy(50, 11);
	cout << "Create Course";
	gotoxy(50, 13);
	cout << "View course";

	int* mau = new int[n];
	writeText(central(WConsole, "SEMESTER - FALL"), 7, "SEMESTER - FALL", MAUCHU);
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
			push_enter_season_menu(y,p);
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
}

void CreateCourseMenu(Staff* p) {
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
	int y = 10;
	int n = 2;
	int tt = 0;
	string j = { "[ CREATE ]" };
	string k = { "[ BACK ]" };
	str thaotac[2] = { "[ CREATE ]","[ BACK ]" };

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

	
	for (int i = 0; i < 8; i++) {
		textColor(MAUNEN);
		gotoxy(45, 10 + i);
		cout << temp[i];
		string aa;
		cin >> aa;
		textColor(7);
		gotoxy(45, 10 + i);
		cout << temp[i] << aa;
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
			SpringMenu(p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewCourseMenu(Staff* p) {
	int y = 10;
	int n = 3;
	int tt = 0;
	string a = { "Course 1" };
	string b = { "Course 2" };
	string c = { "Course 3" };

	str thaotac[3] = { "Course 1" , "Course 2" , "Course 3" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	drawBox(45, 14, 30, 2, MAUCHU);

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
			if (thaotac[i] == a) {
				writeText(50, 11, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(50, 13, thaotac[i], mau[i]);
			}
			if (thaotac[i] == c) {
				writeText(50, 15, thaotac[i], mau[i]);
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
			push_enter_view_course_list(y,p);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_course_list(int y, Staff* p) {
	switch (y) {
	case 10:
		Course_1_Menu(p);
		break;
	case 11:
		Course_1_Menu(p);
		break;
	case 12:
		Course_1_Menu(p);
		break;
	}
}

void Course_1_Menu(Staff* p) {
	string a = { "[ BACK ]" };
	string b = { "[ EDIT ]" };
	int y = 10;
	int n = 2;
	str thaotac[2] = { "[ BACK ]", "[ EDIT ]" };
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
				StaffMenu(p);
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


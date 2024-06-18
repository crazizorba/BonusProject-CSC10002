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


void MainMenu() {
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
			push_enter_main_menu(y);
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
void push_enter_main_menu(int y) {
	switch (y) {
	case 10:
		LoginMenu();
		break;
	case 11:
		AboutusMenu();
		break;
	case 12:
		HelpMenu();
		break;
	case 13:
		MainMenu();
		return;
	}
}



void LoginMenu() {
	string z;
	string s;
	string c = { "Staff" };
	string d = { "Student" };
	int y = 10;
	int n = 2;
	int tt = 0;

	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:";
	str thaotac[2] = { "Staff", "Student" };


	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(XboxLG_1, YboxLG_1, WboxLG, HboxLG, MAUCHU);
	drawBox(XboxLG_2, YboxLG_2, WboxLG, HboxLG, MAUCHU);
	drawBox(45, 18, 10, 2, MAUCHU);
	drawBox(65, 18, 10, 2, MAUCHU);

	int* mau = new int[n];
	writeText(central(WConsole, "LOGIN"), Upbox, "LOGIN", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}
	writeText(48, 19, c, 7);
	writeText(67, 19, d, 7);

	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	cin >> z;
	textColor(7);
	gotoxy(47, 11);
	cout << "ID:" << z;

	gotoxy(47, 15);
	textColor(MAUNEN);
	cout << "Password:";
	cin >> s;
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:" << s;


	mau[0] = MAUNEN;
	while (1) {
		ShowCur(true);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			if (thaotac[i] == c) {
				writeText(48, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == d) {
				writeText(67, 19, thaotac[i], mau[i]);
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
			push_enter_menu_login_2(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}



void push_enter_menu_login_2(int y) {
	switch (y) {
	case 10:
		SuccessMenu();
		StaffMenu();
		break;
	case 11:
		SuccessMenu();
		StudentMenu();
		break;
	case 14:
		MainMenu();
	}
}

void AboutusMenu() {
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
	case DOWN:
		AboutusMenu();
	case UP:
		AboutusMenu();
	case LEFT:
		system("cls");
		MainMenu();
	case ENTER:
		system("cls");
		MainMenu();
	
	}
	gotoxy(45, 22);
	cout << "press ";
	textColor(MAUNEN);
	cout << "ENTER";
	textColor(7);
	cout << " to back....";
}


void HelpMenu() {
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
	case DOWN:
		HelpMenu();
	case UP:
		HelpMenu();
	case LEFT:
		system("cls");
		MainMenu();
	case ENTER:
		system("cls");
		MainMenu();
	
	}
	gotoxy(45, 22);
	cout << "press ";
	textColor(MAUNEN);
	cout << "ENTER";
	textColor(7);
	cout << " to back....";
}


void StudentMenu() {
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
			LoginMenu();
			break;
		case ENTER:
			system("cls");
			push_enter_student_menu(y);
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


void push_enter_student_menu(int y) {  //"Infomation","Course", "Class","Score","Back to menu"
	switch (y) {
	case 10:
		LoginMenu();
		break;
	case 11:
		LoginMenu();
		break;
	case 12:
		LoginMenu();
		break;
	case 13:
		LoginMenu();
		break;
	case 14:
		MainMenu();
		break;
	}
}

void StaffMenu() {
	int y = 10;
	int n = 8;
	str thaotac[8] = { "Create school year","View school year", "Create class","View course","Personal Information","Logout","Createsemester","ViewSemester"};
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
				y = 17;
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
			LoginMenu();
		case ENTER:
			system("cls");
			push_enter_staff_menu(y);
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


void push_enter_staff_menu(int y) {  //"Infomation","Course", "Class","Score","Back to menu"
	switch (y) {
	case 10:
		CreateSchoolYearMenu();
		break;
	case 11:
		ViewschoolyearMenu();
		break;
	case 12:
		LoginMenu();
		break;
	case 13:
		LoginMenu();
		break;
	case 14:
		Info_Menu();
		break;
	case 15:
		MainMenu();
		break;
	case 16:
		CreateSemesterMenu();
		break;
	case 17:
		ViewSemesterMenu();
		break;
	}
}

void CreateSchoolYearMenu() {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "CREATE" };
	string b = { "BACK" };
	str thaotac[2] = { "CREATE","BACK" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 15, 10, 2, MAUCHU);
	drawBox(65, 15, 10, 2, MAUCHU);
	gotoxy(47, 16);
	cout << "CREATE";
	gotoxy(69, 16);
	cout << "BACK";

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
			push_cre_sy_menu(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_cre_sy_menu(int y) {
	switch (y) {
	case 10:
		SuccessMenu();
		StaffMenu();
		break;
	case 11:
		StaffMenu();
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

void ViewschoolyearMenu() {
	

}

void Info_Menu() {
	string a = { "BACK" };
	string b = { "EDIT" };
	int y = 10;
	int n = 2;
	str thaotac[2] ={ "BACK", "EDIT" };
	string temp[6] = { "ID:","FirstName:", "LastName:","Gender:", "DateOfBirth:","SocialID:" };
	for (int i = 0; i < 6; i++) {
		writeText(57, 9 + i, temp[i], 7);
	}
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(42, 9, 10, 6, MAUCHU);
	drawBox(43, 20, 9, 2, MAUCHU);
	drawBox(67, 20, 9, 2, MAUCHU);
	

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
				StaffMenu();
			}
			else {
				StaffMenu();
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void CreateSemesterMenu() {
	int y = 10;
	int n = 2;
	int tt = 0;
	string a = { "CREATE" };
	string b = { "BACK" };
	string c = { "Spring" };
	string d = { "Summer" };
	string e = { "Fall" };
	str thaotac[2] = { "CREATE","BACK" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 10, 30, 2, MAUCHU);
	drawBox(45, 12, 30, 2, MAUCHU);
	drawBox(45, 14, 30, 2, MAUCHU);
	drawBox(45, 18, 10, 2, MAUCHU);
	drawBox(65, 18, 10, 2, MAUCHU);

	gotoxy(47, 19);
	cout << "CREATE";
	gotoxy(69, 19);
	cout << "BACK";
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
	writeText(central(WConsole, "CREATE SCHOOL YEAR"), 7, "CREATE SCHOOL YEAR", MAUCHU);
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
				writeText(47, 19, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(69, 19, thaotac[i], mau[i]);
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
			push_cre_sy_menu(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewSemesterMenu() {
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
			push_enter_view_semester_list(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_semester_list(int y) {
	switch (y) {
	case 10:
		SpringMenu();
		break;
	case 11:
		SummerMenu();
		break;
	case 12:
		FallMenu();
		break;
	}
}

void SpringMenu() {
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
			push_enter_season_menu(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_season_menu(int y) {
	switch (y) {
	case 10:
		CreateCourseMenu();
		break;
	case 11:
		ViewCourseMenu();
		break;
	}
}

void SummerMenu() {
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
			push_enter_season_menu(y);
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

void FallMenu() {
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
			push_enter_season_menu(y);
			for (int i = 0; i < n; i++) {
				mau[i] = MAUCHU;
			}
			mau[tt] = MAUNEN;
			textColor(MAUNEN);
		}
	}
}

void CreateCourseMenu() {
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
	string j = { "CREATE" };
	string k = { "BACK" };
	str thaotac[2] = { "CREATE","BACK" };

	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);

	drawBox(45, 20, 10, 2, MAUCHU);
	drawBox(65, 20, 10, 2, MAUCHU);
	gotoxy(47, 21);
	cout << "CREATE";
	gotoxy(69, 21);
	cout << "BACK";

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
				writeText(47, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == k) {
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
			SpringMenu();
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void ViewCourseMenu() {
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
			push_enter_view_course_list(y);
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}

void push_enter_view_course_list(int y) {
	switch (y) {
	case 10:
		Course_1_Menu();
		break;
	case 11:
		Course_1_Menu();
		break;
	case 12:
		Course_1_Menu();
		break;
	}
}

void Course_1_Menu() {
	string a = { "BACK" };
	string b = { "EDIT" };
	int y = 10;
	int n = 2;
	str thaotac[2] = { "BACK", "EDIT" };
	str temp[8] = { "Course ID: ", "Course name: " ,  "Class name: " , "Teacher name: " , "Credit: " , "Size: " ,  "Day of week: " ,  "Season: " };
	for (int i = 0; i < 8; i++) {
		writeText(45, 9 + i, temp[i], 7);
	}
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(45, 20, 9, 2, MAUCHU);
	drawBox(67, 20, 9, 2, MAUCHU);


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
				writeText(48, 21, thaotac[i], mau[i]);
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
				StaffMenu();
			}
			else {
				StaffMenu();
			}
		}
		for (int i = 0; i < n; i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		textColor(MAUNEN);
	}
}
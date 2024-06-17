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
}


void MainMenu() {
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
	string a = { "ID:" };
	string b = { "Password:" };
	string c = { "Staff" };
	string d = { "Student" };
	int y = 10;
	int n = 2;
	string z;
	string s;
	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:";
	writeText(48, 20, c, 7);
	writeText(67, 20, d, 7);
	str thaotac[2] = { "Staff", "Student" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(XboxLG_1, YboxLG_1, WboxLG, HboxLG, MAUCHU);
	drawBox(XboxLG_2, YboxLG_2, WboxLG, HboxLG, MAUCHU);
	drawBox(45, 19, 10, 2, MAUCHU);
	drawBox(65, 19, 10, 2, MAUCHU);
	int* mau = new int[n];
	writeText(central(WConsole, "LOGIN"), Upbox, "LOGIN", MAUCHU);
	for (int i = 0; i < n; i++) {
		mau[i] = MAUCHU;
	}


	textColor(MAUNEN);
	gotoxy(47, 11);
	cout << "ID:";
	cin >> z;
	textColor(7);
	gotoxy(47, 11);
	cout << "ID:"<<z;
	gotoxy(47, 15);
	textColor(MAUNEN);
	cout << "Password:";
	cin >> s;
	textColor(7);
	gotoxy(47, 15);
	cout << "Password:" << s;


	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		textColor(MAUNEN);
		int tmp = tt;
		for (int i = 0; i < n; i++) {
			/*if (thaotac[i] == a) {
				writeText(47, 11, thaotac[i], mau[i]);
			}
			if (thaotac[i] == b) {
				writeText(47, 15, thaotac[i], mau[i]);
			}*/
			if (thaotac[i] == c) {
				writeText(48, 20, thaotac[i], mau[i]);
			}
			if (thaotac[i] == d) {
				writeText(67, 20, thaotac[i], mau[i]);
			}
			gotoxy(50, 11);
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
		case LEFT:
			system("cls");
			MainMenu();
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
		StaffMenu();
		break;
	case 11:
		StudentMenu();
		break;
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
	int n = 5;
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
		Create_School_Year_Menu();
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
		Info_Menu();
		break;
	case 15:
		MainMenu();
		break;
	}
}

/*	string ID;
	string FirstName;
	string LastName;
	int Gender;
	string DateOfBirth;//dd/mm/yyyy
	string SocialID;*/
void Create_School_Year_Menu() {
	string a = { "ID:" };
	string b = { "FirstName:" };
	string c = { "LastName:" };
	string d = { "Gender:" };
	string e = { "DateOfBirth:" };
	string f = { "SocialID:" };
	int y = 10;
	int n = 6;
	str thaotac[6] = { "ID:","FirstName:", "LastName:","Gender:", "DateOfBirth:","SocialID:" };
	int tt = 0;
	drawBox(Xbox, Ybox, Wbox, Hbox, MAUCHU);
	drawBox(42, 9, 8, 5, MAUCHU);

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
			writeText(54, 9 + i, thaotac[i], mau[i]);
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
		case LEFT:
			system("cls");
			MainMenu();
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


void Info_Menu() {
	string a = { "ID:" };
	string b = { "FirstName:" };
	string c = { "LastName:" };
	string d = { "Gender:" };
	string e = { "DateOfBirth:" };
	string f = { "SocialID:" };
	string g = { "BACK" };
	string h = { "EDIT" };
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
			if (thaotac[i] == g) {
				writeText(46, 21, thaotac[i], mau[i]);
			}
			if (thaotac[i] == h) {
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
		//case LEFT:
		//	system("cls");
		//	StaffMenu();
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
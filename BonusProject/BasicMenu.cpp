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
#define Upbox 7
#define DownBox 23
#define LeftBox 55
#define RightBox 65
#define Line 3

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
			return LEFT;
		}
		if (c == 75) {
			return RIGHT;
		}
	}
	else if (z == 13) return ENTER;
}


void MainMenu() {

	int n = 6;
	str thaotac[6] = { "Log in","Sign up", "About us","Help","Exit","More"};
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
			if (tt == 0) tt = n - 1;
			else {
				tt--;
			}
			break;

		}
		case DOWN:
		{
			if (tt == n - 1) tt = 0;
			else {
				tt++;
			}
			break;

		}
		case ENTER: 
		{
			clrscr();
			MainMenu();
		}
		}
		for (int i = 0;i < n;i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
		
		textColor(MAUNEN);
		gotoxy(LeftBox - 2, Upbox + Line + tmp);
		cout << " ";
		gotoxy(RightBox+2, Upbox + Line + tmp);
		cout << " ";

	}
	gotoxy(LeftBox - 2, Upbox + Line );
	textColor(MAUNEN);
	cout << char(41) << char(41);
}

#include"BasicMenu.h"

#define MAUNEN 11
#define MAUCHU 7

//KICH THUOC MAN HINH CONSOLE
#define WConsole 120
#define HConsole 30

//KICH THUOC HOP MAC DINH
#define Xbox 40
#define Ybox 5
#define Wbox 40
#define Hbox 20

//LE TEXT TRONG HOP
#define Upbox 7
#define DownBox 23
#define LeftBox 55
#define RightBox 65
#define Line 3


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

void Menu(int n) {
	str thaotac[5] = { "Thao Tac 1","Thao Tac 2", "Thao Tac 3", "Thao Tac 4","Thao Tac 5" };
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0;i < n;i++) {
		mau[i] = MAUCHU;

	}
	mau[0] = MAUNEN;
	while (1) {
		ShowCur(false);
		deleteScreen();
		for (int i = 0;i < n;i++) {
			textColor(mau[i]);
			cout << i + 1 << ") " << thaotac[i] << endl;
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
		case ENTER: Menu(5);
		}
		for (int i = 0;i < n;i++) {
			mau[i] = MAUCHU;
		}
		mau[tt] = MAUNEN;
	}
}


void drawBox(int x, int y, int w, int h, int t_color, int b_color) {

	textColor(t_color);
	for (int i = x; i <= x + w; i++) {
		gotoxy(i, y);
		cout << char(196);
		gotoxy(i, y + h);
		cout << char(196);
	}
	for (int i = y; i <= y + h; i++) {
		gotoxy(x, i);
		cout << char(179);
		gotoxy(x + w, i);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + w, y);
	cout << char(191);
	gotoxy(x, y + h);
	cout << char(192);
	gotoxy(x + w, y + h);
	cout << char(217);

	textColor(7);
	//*****************b_color xai o dau
}

void thanh_sang(int x, int y, int w, int h, int b_color, string a) {
	textColor(b_color);
	//int iy = y + 1;
	/* for (int ix = x + 1; ix <= x + w - 1; ix++) {
		gotoxy(ix, iy);
		cout << " ";
	}*/
	gotoxy(x - 1, y);
	cout << char(187);
	gotoxy(x + w - 3, y);
	cout << char(171);
	SetColor(7);
	int z = central(w, a);
	gotoxy(x + z - 1, y);
	cout << a;
	textColor(7);
}


void thanh_sang_cu(int x, int y, int w, int h, int b_color, string a) {
	textColor(0);
	int iy = y;
	for (int ix = x; ix < x + w - 1; ix++) {
		gotoxy(ix, iy);
		cout << " ";
	}

	SetColor(7);
	int z = central(w, a);
	gotoxy(x + z, y);
	cout << a;
	textColor(7);
}

int central(int w, string a) {
	int i = w / 2;
	int x = a.length() / 2;
	return i - x;
}

void menu(int x, int y, int w, int h, int t_color, int b_color, string sentences[], int n) {

	drawBox(x, y, w, h, t_color,b_color);
	cout << endl;
	int z = 0;
	z = central(w, sentences[0]);
	gotoxy(x + z, y + 1);
	cout << sentences[0];

	z = central(w, sentences[1]);
	gotoxy(x + z, y + 2);
	cout << sentences[1];

	z = central(w, sentences[2]);
	gotoxy(x + z + 1, y + 3);
	cout << sentences[2];

	int xp = x + 2, yp = y + 2;
	int xcu = xp, ycu = yp;
	int i = 1;
	int j = i;
	bool kt = true;

	while (true) {
		//--------in thanh sang---------
		if (kt) {
			//----------back space-------------
			gotoxy(xcu - 1, ycu);
			thanh_sang_cu(xcu - 1, ycu, w, h, b_color, sentences[j]);
			xcu = xp, ycu = yp;
			j = i;
			//---------------/-------------------
			thanh_sang(xp, yp, w, h, b_color, sentences[i]);
			kt = false;
		}
		//-----------------------
		if (_kbhit()) {
			char c = _getch();
			if (c == -32)
			{
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (yp != y + 2) {
						i--;
						yp -= 1;
					}
					else
					{	//string cuoi
						i = 2;
						yp = y + 3;
					}
				}
				else if (c == 80)
				{
					if (yp != y + 3) {
						i++;
						yp += 1;
					}
					else
					{	//string dau
						i = 1;
						yp = y + 2;
					}
				}
			}
		}
	}
}

void MainMenu() {
	int n = 5;
	str thaotac[5] = { "Log in","Sign up", "About us","Help", "Exit"};
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
		case ENTER: Menu(5);
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

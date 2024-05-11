#include"Graphics.h"

void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textColor(int x) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

void setColor(int n) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD savedAttributes = consoleInfo.wAttributes;
	WORD colorAttribute = n;
	SetConsoleTextAttribute(hConsole, colorAttribute);
	
}

void gotoxy(int x, int y) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void deleteScreen() {
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void writeText(int x, int y, string content, int color) {
	gotoxy(x, y);
	textColor(color);
	cout << content;
	textColor(7);
}

void drawBox(int x, int y, int w, int h, int t_color, int b_color, string content) {
	textColor(b_color);
	for (int i = x + 1;i < x + w;i++) {
		for (int j = y + 1;j < y + h;j++) {
			gotoxy(i, j); cout << " ";
		}
	}
	textColor(t_color);
	for (int i = x;i <= x + w;i++) {
		gotoxy(i, y);
		cout << char(196);
		gotoxy(i, y + h);
		cout << char(196);
	}
	for (int i = y;i <= y + h;i++) {
		gotoxy(x, i);
		cout << char(179);
		gotoxy(x+w, i);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x+w, y);
	cout << char(191);
	gotoxy(x , y+h);
	cout << char(192);
	gotoxy(x+w, y+h);
	cout << char(217);
	gotoxy(x + 1, y + 1);
	setColor(11);
	cout << content;
}

void drawTable(int x, int y, int w, int h, int t_color, int b_color, string content, int nRow) {
	


	for (int i = 0;i < nRow;i++) {
		drawBox(x, y + h * i, w, h,t_color,b_color,content);
		textColor(t_color);
		if (i != 0 ) {
			gotoxy(x, y + h * i);
			cout << char(195);
			gotoxy(x + w, y + h * i);
			cout << char(180);
		}
		
	}
	gotoxy(x + w, y + (h+1)*nRow);

}

void lightRow(int x, int y, int w, int h, int b_color, string content) {
	textColor(b_color);
	for (int i = x + 1;i < x + w;i++) {
		for (int j = y + 1;j < y + h;j++) {
			gotoxy(i, j); cout << " ";
		}
	}
	gotoxy(x + 1, y + 1);
	setColor(7);
	cout << content;
}


void menu(int x, int y) {
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 150;
	int b_color_light = 75;
	string content = "Hello";
	int nRow = 5;
	drawTable(50, 10, w, h, t_color, b_color, content, nRow);
	lightRow(x, y, w, h, b_color, content);
	gotoxy(x + w, y + h * nRow);
	cout << endl;
}
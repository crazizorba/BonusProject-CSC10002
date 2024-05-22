#include"BasicMenu.h"

#define MAUNEN 1
#define MAUCHU 12



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
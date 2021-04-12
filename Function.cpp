#include "Function.h"
int TOP = 4, LEFT = 5; // VI TRI BAT DAU VE BAN CO
int X = 0, Y = 0, COMMAND = 0; // X, Y LA TOA DO TREN CONSOLE
int score_p1 = 0, score_p2 = 0;
int count_p1 = 0, count_p2 = 0; // DEM LUOT CHOI
#define BOARDSIZE 10
bool TURN = true;
CHARACTER  A[BOARDSIZE][BOARDSIZE];

// HAM MOVE
void move(int x, int y) {
		HANDLE hConsoleOutput;
		COORD Cursor;
		Cursor.X = x;
		Cursor.Y = y;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor); // DI CHUYEN 
	}

void moveRight() {
		if (X < A[BOARDSIZE - 1][BOARDSIZE - 1].x) {
			X += 4;
			move(X, Y);
		}
	}

void moveLeft() {
		if (X > A[0][0].x) {
			X -= 4;
			move(X, Y);
		}
	}

void moveUp() {
		if (Y > A[0][0].y) {
			Y -= 2;
			move(X, Y);
		}
	}

void moveDown() {
		if (Y < A[BOARDSIZE - 1][BOARDSIZE - 1].y) {
			Y += 2;
			move(X, Y);
		}
	}

// HAM DRAW
void textColor(int x) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x); // TO MAU
}

void drawchiadoibanco() {
	for (int i = 2; i <= 26; i++) {
		move(49, i); // HANG DOC CHIA DOI MAN HINH
		printf_s("%c", 176);
	}
	move(49, 1); // DAU HANG DOC CHIA DOI
	printf_s("%c", 209);
	move(49, 27); // CUOI HANG DOC CHAN GIUA
	printf_s("%c", 207);
}

void drawbaoquanhbanco() {
	for (int i = 5; i <= 5 + 38; i++) {
		move(i, 3); // HANG NGANG TREN
		printf_s("%c", 219);
		move(i, 25); // HANG NGANG DUOI
		printf_s("%c", 219);
	}
	for (int i = 3; i <= 25; i++) {
		move(4, i); // HANG DOC BEN TRAI
		printf_s("%c", 219);
		move(44, i); // HANG DOC BEN PHAI
		printf_s("%c", 219);
	}
}

void drawPlayer1box() {
	for (int i = 54; i <= 54 + 38; i++) {
		move(i, 3); // HANG NGANG TREN
		printf_s("%c", 248);
		move(i, 8); // HANG NGANG DUOI
		printf_s("%c", 248);
	}
	for (int i = 3; i <= 8; i++) {
		move(53, i); // HANG DOC BEN TRAI
		printf_s("%c", 248);
		move(53 + 40, i); // HANG DOC BEN PHAI
		printf_s("%c", 248);
	}
}

void drawPlayer2box() {
	for (int i = 54; i <= 54 + 38; i++) {
		move(i, 10); // HANG NGANG TREN
		printf_s("%c", 248);
		move(i, 15); // HANG NGANG DUOI
		printf_s("%c", 248);
	}
	for (int i = 10; i <= 15; i++) {
		move(53, i); // HANG DOC BEN TRAI 
		printf_s("%c", 248);
		move(53 + 40, i); // HANG DOC BEN PHAI
		printf_s("%c", 248);
	}
}

void drawTurnbox() {
	for (int i = 54; i <= 54 + 38; i++) {
		move(i, 17); // HANG NGANG TREN
		printf_s("%c", 177);
		move(i, 25); // HANG NGANG DUOI
		printf_s("%c", 177);
	}
	for (int i = 17; i <= 25; i++) {
		move(53, i); // HANG DOC BEN TRAI
		printf_s("%c", 177);
		move(53 + 40, i); // HANG DOC BEN PHAI
		printf_s("%c", 177);
	}
	for (int i = 17; i <= 25; i++) {
		move(54 + 19, i); // HANG DOC CHAN GIUA
		printf_s("%c", 179);
	}
}

void drawCoverpage() {
	while (1) {
		move(4, 3);
		cout << "DAI HOC QUOC GIA THANH PHO HO CHI MINH";
		move(7, 4);
		cout << "TRUONG DAI HOC KHOA HOC TU NHIEN";
		move(11, 5);
		cout << "KHOA CONG NGHE THONG TIN";
		move(15, 10);
		cout << "BAO CAO CUOI KY";
		move(19, 11);
		cout << "NHOM 10";
		move(11, 12);
		cout << "19127631: DUONG TIEN VINH";
		move(11, 13);
		cout << "19127384: NGUYEN TRUONG GIANG";
		move(11, 14);
		cout << "19127385: PHAM LE HA";
		move(11, 15);
		cout << "19127369: LE MINH DUC";
		move(8, 26);
		cout << "Thanh pho Ho Chi Minh - 2019";
		move(55, 3);
		cout << "DAI HOC QUOC GIA THANH PHO HO CHI MINH";
		move(58, 4);
		cout << "TRUONG DAI HOC KHOA HOC TU NHIEN";
		move(62, 5);
		cout << "KHOA CONG NGHE THONG TIN";
		move(66, 10);
		cout << "BAO CAO CUOI KY";
		move(70, 11);
		cout << "NHOM 10";
		move(69, 12);
		cout << "|DE TAI|";
		move(68, 13);
		cout << "DO AN CARO";
		move(63, 15);
		cout << "|GIAO VIEN HUONG DAN|";
		move(62, 16);
		cout << "ThS. TRUONG TOAN THINH";
		move(62, 17);
		cout << "ThS. HO TUAN THANH";
		move(62, 18);
		cout << "ThS. NGUYEN LE HOANG DUNG";
		move(60, 26);
		cout << "Thanh pho Ho Chi Minh - 2019";
		drawchiadoibanco();
		move(70, 27);
		cout << "Enter de tiep tuc >>>>";
		int INPUT = toupper(_getch()); // #include <conio.h> 
		if (INPUT == 13) { // 13 LA ENTER
			break;
		}
	}
}

void drawThankyoupage() {
	while (1) {
		move(4, 3);
		cout << "LOI CAM ON";
		move(5, 5);
		cout << " Trong thoi gian lam bao cao cuoi ky, chung em da nhan duoc nhieu su giup do, dong gop";
		move(5, 6);
		cout << "y kien va chi bao nhiet tinh cua thay co va ban be.  Chung em xin gui loi cam on  chan";
		move(5, 7);
		cout << "thanh den ThS. Truong  Toan  Thinh, ThS. Ho  Tuan  Thanh va ThS.  Nguyen Le Hoang Dung";
		move(5, 8);
		cout << "giang vien mon Nhap mon Lap trinh - truong Dai hoc Khoa hoc Tu nhien TPHCM, nhung giao";
		move(5, 9);
		cout << "vien da tan tinh huong dan, chi bao chung em trong suot ca qua trinh lam do an caro.";
		move(82, 11);
		cout << "- NHOM 10";
		move(70, 27);
		cout << "Enter de tiep tuc >>>>";
		int INPUT = toupper(_getch());
		if (INPUT == 13) { // 13 LA ENTER
			break;
		}
	}
}

void drawInstruction() {
	move(4, 3);
	cout << "INSTRUCTIONS";
	move(6, 4);
	cout << "DI CHUYEN : W, S, A, D";
	move(6, 5);
	cout << "DANH DAU: Enter";
	move(6, 6);
	cout << "SAVE: I";
	move(6, 7);
	cout << "EXIT: Esc";
	move(70, 27);
	cout << "Esc de quay lai <<<";
}

void drawBoard(int pSize) {
	for (int row = 0; row <= pSize; row++) {
		for (int column = 0; column < pSize * 2; column++) {
			move(LEFT + (2 * column), TOP + (2 * row));
			cout << "."; // VE BAN CO
		}
	}
	drawbaoquanhbanco();
	drawchiadoibanco();
	drawPlayer1box();
	drawPlayer2box();
	drawTurnbox();
}

void drawX() {
	textColor(1);
	move(59, 19);
	cout << "X       X" << endl;
	move(59, 20);
	cout << "  X   X" << endl;
	move(59, 21);
	cout << "    X" << endl;
	move(59, 22);
	cout << "  X   X" << endl;
	move(59, 23);
	cout << "X       X" << endl;
	textColor(15);
}

void deleteX() {
	move(59, 19);
	cout << "         " << endl;
	move(59, 20);
	cout << "       " << endl;
	move(59, 21);
	cout << "     " << endl;
	move(59, 22);
	cout << "       " << endl;
	move(59, 23);
	cout << "         " << endl;
}

void drawO() {
	textColor(4);
	move(79, 19);
	cout << "  O O O  " << endl;
	move(79, 20);
	cout << "O       O" << endl;
	move(79, 21);
	cout << "O       O" << endl;
	move(79, 22);
	cout << "O       O" << endl;
	move(79, 23);
	cout << "  O O O  " << endl;
	textColor(15);
}

void deleteO() {
	move(79, 19);
	cout << "         " << endl;
	move(79, 20);
	cout << "         " << endl;
	move(79, 21);
	cout << "         " << endl;
	move(79, 22);
	cout << "         " << endl;
	move(79, 23);
	cout << "         " << endl;
}

void drawSave() {
	textColor(5);
	move(17, 10);
	cout << "1. FILE SAVE 1";
	textColor(6);
	move(17, 12);
	cout << "2. FILE SAVE 2";
	textColor(4);
	move(17, 14);
	cout << "3. FILE SAVE 3";
	textColor(8);
	move(17, 16);
	cout << "4. FILE SAVE 4";
	textColor(7);
	move(17, 18);
	cout << "5. FILE SAVE 5";
}

void drawLogo() {
	for (int i = 28; i < 36; i++) {
		move(i, 5);
		printf_s("%c", 219);
	}
	for (int i = 5; i < 10; i++) {
		move(31, i);
		printf_s("%c", 219);
		move(32, i);
		printf_s("%c", 219);
	} // T
	for (int i = 2; i < 7; i++) {
		move(38, i);
		printf_s("%c", 219);
		move(39, i);
		printf_s("%c", 219);
	}
	for (int i = 2; i < 7; i++) {
		move(44, i);
		printf_s("%c", 219);
		move(45, i);
		printf_s("%c", 219);
	}
	for (int i = 38; i < 46; i++) {
		move(i, 4);
		printf_s("%c", 219);
	} // H
	textColor(1);
	for (int i = 4; i < 9; i++) {
		move(48, i);
		printf_s("%c", 219);
		move(49, i);
		printf_s("%c", 219);
	}
	for (int i = 48; i < 56; i++) {
		move(i, 4);
		printf_s("%c", 219);
	}
	for (int i = 48; i < 56; i++) {
		move(i, 6);
		printf_s("%c", 219);
	}
	for (int i = 48; i < 56; i++) {
		move(i, 8);
		printf_s("%c", 219);
	} // E
	textColor(4);
	for (int i = 6; i < 11; i++) {
		move(48, i);
		printf_s("%c", 219);
		move(49, i);
		printf_s("%c", 219);
	}
	int j = 50;
	for (int i = 6; i < 11; i++) {
		move(j, i);
		printf_s("%c", 219);
		j++;
	}
	for (int i = 6; i < 11; i++) {
		move(55, i);
		printf_s("%c", 219);
		move(56, i);
		printf_s("%c", 219);
	} // N
	textColor(15);
	for (int i = 8; i < 13; i++) {
		move(38, i);
		printf_s("%c", 219);
		move(39, i);
		printf_s("%c", 219);
	}
	for (int i = 38; i < 46; i++) {
		move(i, 8);
		printf_s("%c", 219);
	}
	for (int i = 38; i < 46; i++) {
		move(i, 10);
		printf_s("%c", 219);
	}
	for (int i = 38; i < 46; i++) {
		move(i, 12);
		printf_s("%c", 219);
	} // E
}

void drawMenu() {
	move(83, 0);
	cout << "just play it";
	move(36, 14);
	cout << "\"CARO GAME\"";
	textColor(5);
	move(36, 17);
	cout << "START GAME";
	textColor(6);
	move(36, 18);
	cout << "LOAD GAME";
	textColor(4);
	move(36, 19);
	cout << "INSTRUCTIONS";
	textColor(15);
	move(36, 20);
	cout << "EXIT GAME";
}

// HAM CHECK 
int checkBoard(int pX, int pY) {
	for (int row = 0; row <= BOARDSIZE; row++) {
		for (int column = 0; column <= BOARDSIZE; column++) {
			if (A[row][column].x == pX && A[row][column].y == pY && A[row][column].m == 0) {
				TURN = !TURN;
				if (TURN == true) {
					A[row][column].m = -1;
				}
				else {
					A[row][column].m = 1;
				}
				return A[row][column].m;
			}
		}
	}
	return 0;
}

int checkwinngang(int row, int column, int turn) {
	int i, count = 0;
	for (i = 1; i <= 4; i++) {
		if (A[row][column].m == turn && A[row][column - i].m == turn) {
			count += 1;
		}
		else break;
	}
	if (count < 4) {
		int count2 = count;
		for (i = 1; i <= 4 - count2; i++) {
			if (A[row][column].m == turn && A[row][column + i].m == turn) {
				count += 1;
			}
			else break;
		}
	}
	return count;
}

int checkwindoc(int row, int column, int turn) {
	int i, count = 0;
	for (i = 1; i <= 4; i++) {
		if (A[row][column].m == turn && A[row - i][column].m == turn) {
			count += 1;
		}
		else break;
	}
	if (count < 4) {
		int count2 = count;
		for (i = 1; i <= 4 - count2; i++) {
			if (A[row][column].m == turn && A[row + i][column].m == turn) {
				count += 1;
			}
			else break;
		}
	}
	return count;
}

int checkwincheo1(int row, int column, int turn) {
	int i, count = 0;
	for (i = 1; i <= 4; i++) {
		if (A[row][column].m == turn && A[row - i][column - i].m == turn) {
			count += 1;
		}
		else break;
	}
	if (count < 4) {
		int count2 = count;
		for (i = 1; i <= 4 - count2; i++) {
			if (A[row][column].m == turn && A[row + i][column + i].m == turn) {
				count += 1;
			}
			else break;
		}
	}
	return count;
}

int checkwincheo2(int row, int column, int turn) {
	int i, count = 0;
	for (i = 1; i <= 4; i++) {
		if (A[row][column].m == turn && A[row - i][column + i].m == turn) {
			count += 1;
		}
		else break;
	}
	if (count < 4) {
		int count2 = count;
		for (i = 1; i <= 4 - count2; i++) {
			if (A[row][column].m == turn && A[row + i][column - i].m == turn) {
				count += 1;
			}
			else break;
		}
	}
	return count;
}

bool checkWin(int pX, int pY, int turn) {
	int  i = 0, j = 0;
	for (int row = 0; row <= BOARDSIZE; row++) {
		for (int column = 0; column <= BOARDSIZE; column++) {
			if (A[row][column].x == pX && A[row][column].y == pY) {
				if (checkwinngang(row, column, turn) == 4) { return true; }
				if (checkwindoc(row, column, turn) == 4) { return true; }
				if (checkwincheo1(row, column, turn) == 4) { return true; }
				if (checkwincheo2(row, column, turn) == 4) { return true; }
			}
		}
	}
	return false;
}

// HAM HOI 
int secondchance() {
	move(4, 1);
	cout << "SECOND CHANCE ??? (Y/N)";
	while (1) {
		COMMAND = toupper(_getch());
		if (COMMAND == 'N') {
			system("cls");
			return 0;
		}
		if (COMMAND == 'Y') {
			move(4, 1);
			cout << "                             ";
			break;
		}
	}
	return 1;
}

int exitGame() {
	move(4, 1);
	cout << "DO YOU WANT TO EXIT ??? (Y/N)";
	while (1) {
		COMMAND = toupper(_getch());
		if (COMMAND == 'Y') {
			move(5, 1);
			system("cls");
			return 0;
		}
		if (COMMAND == 'N') {
			move(4, 1);
			cout << "                             ";
			break;
		}
	}
	return 1;
}

// HAM MENU
int menu() {
	X = 32, Y = 17;
	move(X, Y);
	cout << "-> ";
	while (1) {
		COMMAND = toupper(_getch());
		if (Y > 17) {
			if (COMMAND == 'W') {
				Y -= 1;
				move(X, Y + 1);
				cout << "   ";
				move(X, Y);
				cout << "-> ";
				continue;
			}
		}
		if (Y < 20) {
			if (COMMAND == 'S') {
				Y += 1;
				move(X, Y - 1);
				cout << "   ";
				move(X, Y);
				cout << "-> ";
				continue;
			}
		}
		if (COMMAND == 13) {
			break;
		}
	}
	if (Y == 17) {
		return 1;
	}
	if (Y == 18) {
		return 2;

	}
	if (Y == 19) {
		return 3;
	}
	if (Y == 20) {
		return 4;
	}
	return 0;
}

// HAM SAVE
void saveGame(char name1[], char name2[], int count_p1, int count_p2, int score_p1, int score_p2) {
	ofstream file;
	//int choose = menu();
	//drawSave();
	//if (menu() == 1) {
	//	file.open("save1.txt", ios::in);
	//}
	//if (menu() == 2) {
	//	file.open("save2.txt", ios::in);
	//}
	//if (menu() == 3) {
	//	file.open("save2.txt", ios::in);
	//}
	//if (menu() == 4) {
	//	file.open("save2.txt", ios::in);
	//}
	//if (menu() == 5) {
	//	file.open("save2.txt", ios::in);
	//}
	file.open("save1.txt", ios::in);
	file << name1 << endl;
	file << name2 << endl;
	file << count_p1 << " " << count_p2 << endl;
	file << score_p1 << " " << score_p2 << endl;
	for (int row = 0; row < BOARDSIZE; row++) {
		for (int column = 0; column < BOARDSIZE; column++) {
			file << A[row][column].x << " " << A[row][column].y << " " << A[row][column].m << " ";
		}
	}
	file.close();
}

// HAM LOAD
int loadGame(int count_p1, int count_p2, int score_p1, int score_p2) {
	char name1[50] = "ANONYMOUS", name2[50] = "ANONYMOUS";
	ifstream file;
	//int choose = menu();
	//if (menu() == 1) {
	//	file.open("save1.txt", ios::out);
	//}
	//if (menu() == 2) {
	//	file.open("save2.txt", ios::out);
	//}
	//if (menu() == 3) {
	//	file.open("save2.txt", ios::out);
	//}
	//if (menu() == 4) {
	//	file.open("save2.txt", ios::out);
	//}
	//if (menu() == 5) {
	//	file.open("save2.txt", ios::out);
	//}
	file.open("save1.txt", ios::out);
	file.getline(name1, 50);
	file.getline(name2, 50);
	file >> count_p1 >> count_p2;
	file >> score_p1 >> score_p2;
	move(55, 5);
	cout << "TURN: " << count_p1;
	move(55, 6);
	cout << "SCORE: " << score_p1;
	move(55, 12);
	cout << "TURN: " << count_p2;
	move(55, 13);
	cout << "SCORE: " << score_p2;
	for (int row = 0; row < BOARDSIZE; row++) {
		for (int column = 0; column < BOARDSIZE; column++) {
			file >> A[row][column].x >> A[row][column].y >> A[row][column].m;
			move(A[row][column].x, A[row][column].y);
			if (A[row][column].m == 1) {
				textColor(4);
				cout << "O";
				textColor(15);
			}
			if (A[row][column].m == -1) {
				textColor(1);
				cout << "X";
				textColor(15);
			}
		}
	}
	file.close();
	if (START(name1, name2, count_p1, count_p2, score_p1, score_p2) == 0) return 0;
	return 1;
}

// HAM INPUT NAME
void inputname(char name1[50], char name2[50]) {
	move(60, 5);
	cout << "NHAP TEN NGUOI CHOI 1: ";
	move(60, 7);
	cout << "NHAP TEN NGUOI CHOI 2: ";
	move(60, 6);
	cin.getline(name1, 20);
	move(60, 8);
	cin.getline(name2, 20);
}

// HAM FUNCTION
void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	LONG style = GetWindowLong(console, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(console, GWL_STYLE, style); // LAM MO NUT MAXIMIZE
	GetWindowRect(console, &r); // THAY DOI KICH CO CMD
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void resetData() {
	for (int row = 0; row < BOARDSIZE; row++) {
		for (int column = 0; column < BOARDSIZE; column++) {
			A[row][column].x = LEFT + 1 + 4 * column;
			A[row][column].y = TOP + 1 + 2 * row;
			A[row][column].m = 0;
		}
	}
	TURN = true;
	COMMAND = -1;
	X = A[0][0].x, Y = A[0][0].y;
}

void loading() {
	system("cls");
	move(5, 26);
	cout << "LOADING";
	for (int i = 0; i < 95; i++) {
		Sleep(25);
		move(i, 27);
		printf("%c", 176);
	}
	system("cls");
}

void prepareGame() {
	loading();
	drawBoard(BOARDSIZE);
	resetData();
}

int START(char name1[50], char name2[50], int count_p1, int count_p2, int score_p1, int score_p2) {
	bool validEnter = true;
	move(55, 4);
	cout << "PLAYER 1: " << name1;
	move(55, 11);
	cout << "PLAYER 2: " << name2;
	move(LEFT + 1, TOP + 1);
	while (1) {
		COMMAND = toupper(_getch());
		if (COMMAND == 27) {
			if (exitGame() == 0) {
				return 0;
			}
			else move(X, Y);
		}
		if (COMMAND == 'I') {
			saveGame(name1, name2, count_p1, count_p2, score_p1, score_p2);
		}
		if (COMMAND == 'W') {
			moveUp();
		}
		if (COMMAND == 'S') {
			moveDown();
		}
		if (COMMAND == 'A') {
			moveLeft();
		}
		if (COMMAND == 'D') {
			moveRight();
		}
		if (COMMAND == 13) {
			switch (checkBoard(X, Y)) {
			case -1: {
				drawO();
				deleteX();
				move(X, Y);
				textColor(1);
				cout << "X";
				textColor(15);
				count_p1 += 1;
				move(55, 5);
				cout << "TURN: " << count_p1;
				move(55, 6);
				cout << "SCORE: " << score_p1;
				if (checkWin(X, Y, -1) == true) {
					move(55, 7);
					cout << "X win!!!";
					score_p1 += 1;
					if (secondchance() == 0) {
						prepareGame();
						count_p1 = 0, count_p2 = 0;
						if (START(name1, name2, count_p1, count_p2, score_p1, score_p2) == 0) return 0;
					}
					else move(X, Y);
				}
				else move(X, Y);
				break;
			}
			case 1: {
				drawX();
				deleteO();
				move(X, Y);
				textColor(4);
				cout << "O";
				textColor(15);
				count_p2 += 1;
				move(55, 12);
				cout << "TURN: " << count_p2;
				move(55, 13);
				cout << "SCORE: " << score_p2;
				if (checkWin(X, Y, 1) == true) {
					move(55, 14);
					cout << "O win!!!";
					score_p2 += 1;
					if (secondchance() == 0) {
						prepareGame();
						count_p1 = 0, count_p2 = 0;
						if (START(name1, name2, count_p1, count_p2, score_p1, score_p2) == 0) return 0;
					}
					else move(X, Y);
				}
				else move(X, Y);
				break;
			}
			case 0: {
				if (count_p1 == 50 && count_p2 == 50) {
					move(4, 2);
					cout << "TIE!!!!";
					Sleep(10000);
					system("cls");
					return 0;
				}
			}
			}
		}
}
	return 0;
}

int LOAD(int count_p1, int count_p2, int score_p1, int score_p2) {
	prepareGame();
	if (loadGame(count_p1, count_p2, score_p1, score_p2) == 0) return 0;
	return 1;
}

int INSTRUCTION() {
	system("cls");
	drawInstruction();
	while (1) {
		int INPUT = toupper(_getch());
		if (INPUT == 27) {
			system("cls");
			return 0;
		}
		else continue;
	}
	return 1;
}

int EXIT() {
	system("cls");
	return 0;
}

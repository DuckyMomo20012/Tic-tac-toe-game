#include "Function.h"

int main() {
	resizeConsole(800, 500);
	drawCoverpage();
	system("cls");
	drawThankyoupage();
	system("cls");
	int i = 400;
	// PlaySound(L"SONG_.wav", NULL, SND_ASYNC); //MO AM THANH
	while(i > 0) {
		Sleep(i);
		drawLogo();
		Sleep(i);
		system("cls");
		move(46, 12);
		i -= 10;
	}
	char name1[50] = "ANONYMOUS", name2[50] = "ANONYMOUS";
	int count_p1 = 0, count_p2 = 0, score_p1 = 0, score_p2 = 0;
	int choose;
	OPTION Option;
	while (1) {
		//drawLogo();
		drawMenu();
		choose = menu();
		if (choose == 1) {
			inputname(name1, name2);
			prepareGame();
			if (START(name1, name2, count_p1, count_p2, score_p1, score_p2) == 0) continue;
		}
		if (choose == 2) {
			if (LOAD(count_p1, count_p2, score_p1, score_p2) == 0) continue;
		}
		if (choose == 3) {
			if (INSTRUCTION() == 0) {
				continue;
			}
			
		}
		if (choose == 4) {
			EXIT();
			break;
		}
	}
	system("pause");
}
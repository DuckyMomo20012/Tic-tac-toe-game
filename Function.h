#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct CHARACTER {
	int x, y, m; // x, y LA TOA DO TRONG MANG; m DE DANH DAU
};
typedef struct CHARACTER CHARACTER;
struct OPTION {
	int draw = 0, character = 0, start = 0, load = 0, instruction = 0, option = 0, exit = 0;
};
typedef struct OPTION OPTION;
void resizeConsole(int width, int height);
void drawMenu();
void drawLogo();
void drawCoverpage();
void drawThankyoupage();
void move(int x, int y);
void inputname(char name1[50], char name2[50]);
void prepareGame();
int menu();
int START(char name1[50], char name2[50], int count_p1, int count_p2, int score_p1, int score_p2);
int LOAD(int count_p1, int count_p2, int score_p1, int score_p2);
int INSTRUCTION();
int EXIT();
#endif

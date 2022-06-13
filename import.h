/*-----import.h----*/
/*----group-9_2022_mis102_final----*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*-----調整座標、顏色-------*/
void color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);	//更改文字顏色
}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);	//座標設置
}
/*-----調整座標、顏色_end-------*/

/*---------建立子彈-------*/ 
struct bullet
{
	COORD xy;
	int start;
	int end;
	
};
/*---------建立子彈_end-------*/ 

/*---------隕石-------*/ 
struct monster
{
	COORD xy;
    COORD old_xy;
    COORD hit1_xy;
    COORD hit2_xy;
    COORD hit3_xy;
    COORD hit4_xy;

};
/*---------隕石_end-------*/ 

/*-----import.h_end----*/

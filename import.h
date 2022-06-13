/*-----import.h----*/
/*----group-9_2022_mis102_final----*/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*-----�վ�y�СB�C��-------*/
void color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);	//����r�C��
}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);	//�y�г]�m
}
/*-----�վ�y�СB�C��_end-------*/

/*---------�إߤl�u-------*/ 
struct bullet
{
	COORD xy;
	int start;
	int end;
	
};
/*---------�إߤl�u_end-------*/ 

/*---------�k��-------*/ 
struct monster
{
	COORD xy;
    COORD old_xy;
    COORD hit1_xy;
    COORD hit2_xy;
    COORD hit3_xy;
    COORD hit4_xy;

};
/*---------�k��_end-------*/ 

/*-----import.h_end----*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#define SIZE 100
int color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//更改文字顏色
	return 0;
}


void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void game_statement();
int score[SIZE] = {0};
void leadboard(int a) {
	int i = 0,len = 0;
	for{i = 0; score[i] ! = 0; }

}
void welcome_to_game() {//主畫面
	color(15);
	gotoxy(43, 13);
	printf("飛 機 大 戰");

	color(11);
	gotoxy(43, 18);
	printf("1.進入遊戲");

	color(11);
	gotoxy(43, 20);
	printf("2.查詢排行榜");

	color(11);
	gotoxy(43, 22);
	printf("3.退出遊戲");

	color(13);
	gotoxy(43, 26);
	printf("請選擇1 2 3 : ");

	int set_Condition;
	scanf_s("%d", &set_Condition);
	switch (set_Condition) {
	case 1:
		system("cls");
		game_statement();
		break;
	case 2:
		//排行榜函式
		break;
	case 3:
		exit(0);
		break;

	default:
		color(12);
		gotoxy(43, 28);
		printf("請輸入1-3之間的數 : ");
		_getch;//輸入任意鍵
		system("cls");
		welcome_to_game();
	}
}

int main(void) {


	welcome_to_game();//主畫面


	//system("pause");
	printf("\n\n\n\n\n\n\n\n\n");

	return(0);
}
void game_statement(){
	
    system("cls");
    color(10);
    gotoxy(44,1);
    printf("遊戲說明");
    color(2);
    /*框線
    int i,j = 1;
    for (i = 3; i <= 28; i++)  //輸出上下邊框===
   {
   for (j = 6; j <= 80; j++) //輸出左右邊框||
   {
    gotoxy(j,i);
    if (i == 3 || i == 28) 
	    printf("=");
    else if (j == 6 || j == 80) 
	    printf("||");
    }
    }*/
    color(3);
    gotoxy(20,5);
    printf("1. W,A,S,D,分別控制飛機的上下左右移動");
    
    color(10);
    gotoxy(20,8);
    printf("2. 按空格發射子彈，打中敵機即可得到一分");
    
    color(14);
    gotoxy(20,11);
    printf("3.碰到敵機子彈死亡");
  
    color(4);
    gotoxy(20,14);
    printf("4. 玩的愉快！！！");
    
    color(8);
    gotoxy(34,20);
    printf("*****按任意鍵開始遊戲*****");
    _getch();        //按任意鍵返回主介面
    system("cls");
}

/*----main.c------*/
/*----group-9_2022_mis102_final----*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include<string.h>
#include <conio.h>

#define SIZE 10
#include "final_game.c"   	//game it self

int welcome_to_game();		//enter game
void endgame();				//close game
void game_statement();		//explain game
void leadboard();			//scoreboard
void print_border();		//the windows of game's border
void user_in();

int score;				   //分數	
int scorelist[SIZE] = {0};


/*------main-------*/
int main(void) {
	srand((unsigned int)time(NULL));		//生成亂數用 
	
	/*-----for keep enter game----*/
	int game_key=1;
	while(game_key!=0){
		
		color(15);
		game_key=welcome_to_game();		//進入主畫面，並回傳是否繼續遊戲 
		if(game_key==1){
			endgame();					//計分並結束上一場 
		}
		else if (game_key==3){			//結束程式 
			game_key=0;
		}
		else{
			game_key=1;
		}
	}	
	
	gotoxy(45,30);
	color(78);
	printf("bye bye!!\n\n\n\n\n\n");
	color(15);
	return(0);
}
/*---------------main_end-------*/


/*--------------進入主畫面------*/
int welcome_to_game() {
	system("cls");
	system("cls");
	
	
	int set_Condition;				//遊戲介面 and 功能表 
	
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
	printf("請按 1 2 3 :  ");
	gotoxy(57,26);
	
	
	if(set_Condition!=3) scanf("%d", &set_Condition);     //選擇功能 
	
	
	switch (set_Condition) {
		case 1:
			system("cls");
			
		
			/*------遊戲本人-----*/ 
			game_statement();		
			
	    	print_border();		//遊戲邊框 
	    	
			game_start();		//遊戲開始 
			
			break;
		case 2:
			leadboard();		//排行榜函式
			_getch();        	//按任意鍵返回主介面
			system("cls");
			//welcome_to_game();
			break;
		case 3:
			//exit(0);			//也可用直接跳出 
			break;
			
		default:				//按錯的 case 
			color(79);
			gotoxy(45, 28);
			printf("1-3 only !!");	//容錯功能，回至main 可重新輸入 
			Sleep(600);
	}
		
	return(set_Condition);		//回傳 case  
}
/*----------進入主畫面_end----------*/



/*-------排行榜-------*/
void leadboard() {
	system("cls");                                        //列印排行榜 
	color(11);
	gotoxy(49, 1);
	printf("排行榜:\n");

	FILE *pfile;										//開啟user_in 檔 
	if((pfile=fopen("scoreboard.txt","r+"))==NULL){
		printf("openfail");
	}
	
	int this_score;										//宣告抓檔用的變數 
	int i=0, num=0;
	int rank[11]={0};
	char name_in[20];
	char blank1[30],blank2[30];
	
	while(!feof(pfile)){								//先抓分數 
		
		fgets(name_in,20,pfile);
		fgets(blank1,5,pfile);

		fscanf(pfile,"%d",&this_score);
		fgets(blank2,6,pfile);
		
		if(!feof(pfile)){
			rank[num]=this_score;						//分數存入rank[]中	
			//printf("%-20s %d\n",name_in,this_score);
			num++;
		}
		
	}
	close(pfile);										//抓好分數 關檔 

	
	int tra, key;										//tra 當交換 ，key確認有無switch 
	
	/*-------bubble sort 排序 rank[]-------*/ 
	do{
		key=0;
		for(i=0;i<5;i++){
			if(rank[i]<rank[i+1]){
				tra=rank[i];rank[i]=rank[i+1];rank[i+1]=tra;
				key=1;
			}
		}
	}while(key);
	

	char name_in2[20]={0};				//怕資料打架多宣告的 
	char pre_name[20]={0};
	char blank3[30]={0};
	char blank4[30]={0};
	
	for(i=0;i<num;i++){					//將分數對應到 名字 
	
		FILE *opfile;
		if((opfile=fopen("scoreboard.txt","r+"))==NULL){ 	//再次開檔 
			printf("openfail");
		}
	
		while(!feof(opfile)){
	
			fgets(name_in2,20,opfile);						//抓姓名 
			fgets(blank3,5,opfile);							//*看裝置 調整字元數 

			fscanf(opfile,"%d",&this_score);				//抓分數 
		
			fgets(blank4,6,opfile);
	
			if(!feof(opfile)){
				
				if(rank[i]==this_score&&strncmp(pre_name,name_in2,19)!=0){					//分數對應姓名  且考慮同分case 
					gotoxy(40, 4+2*i);
					color(5+i);
					/*--------輸出排名-------*/
					printf("第%d名! : %-20s %d\n",i+1,name_in2,this_score);
					int j;
					for(j=0;j++;j<20){
						pre_name[j]=name_in2[j];
					}
				}
			}
			close(opfile);										//關檔 
		}
		close(opfile);										//final關檔
	}
	
	gotoxy(37,30);
	color(15);
	printf("*****按任意鍵返回主介面*****");
	
}
/*-------排行榜_end-------*/


/*--------遊戲說明------*/
void game_statement() {

	system("cls");
	color(10);
	gotoxy(44, 1);
	printf("遊戲說明");
	color(2);

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
	}
	color(3);
	gotoxy(20, 5);
	printf("1. 上,下,左,右,分別控制飛機的上下左右移動");

	color(10);
	gotoxy(20, 8);
	printf("2. 按空格發射子彈，打中敵機即可得到1-2分");

	color(14);
	gotoxy(20, 11);
	printf("3. 60秒內攻擊 試著拿下最高分吧!!!");

	color(4);
	gotoxy(20, 14);
	printf("4. 按shift ctrl alt 可切換飛機武器");
	gotoxy(20,16);
	printf("(分別為為6顆單發，8顆可連發，10顆無冷卻子彈)");

	color(8);
	gotoxy(34, 20);
	printf("*****按任意鍵開始遊戲*****");
	getch();        //按任意鍵
	system("cls");
}
/*--------遊戲說明_end------*/


/*--------遊戲結束------*/ 
void endgame(){
    system("cls");
  
    color(14);
	gotoxy(30, 11);
    printf("your score is: %d\n",score);
    sleep(2);
    user_in();						//呼叫user_in 接收玩家資訊 
    score=0;
    system("cls");
    color(15);
}
/*--------遊戲結束_end--------*/ 


/*--------玩家資訊--------*/ 
void user_in(){
	
	char name[20];				//宣告儲存姓名位置 
	char name_in[20];
	
	system("cls");
	gotoxy(30, 18);
	printf("請輸入姓名:\n");
	gotoxy(30, 18);
	printf("\r");
	gotoxy(40, 18);
	scanf("%s",name_in);		//接姓名 
	
	
	FILE *opfile;										//開檔 
	if((opfile=fopen("scoreboard.txt","a"))==NULL){
		printf("openfail");
	}
	fprintf(opfile,"%-20s %3d\n",name_in,score);		//連分數 存入文字檔 
	close(opfile);										//關檔 
}
/*--------玩家資訊_end--------*/ 

	
/*----main.c_end------*/

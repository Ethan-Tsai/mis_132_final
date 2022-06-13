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

int score;				   //����	
int scorelist[SIZE] = {0};


/*------main-------*/
int main(void) {
	srand((unsigned int)time(NULL));		//�ͦ��üƥ� 
	
	/*-----for keep enter game----*/
	int game_key=1;
	while(game_key!=0){
		
		color(15);
		game_key=welcome_to_game();		//�i�J�D�e���A�æ^�ǬO�_�~��C�� 
		if(game_key==1){
			endgame();					//�p���õ����W�@�� 
		}
		else if (game_key==3){			//�����{�� 
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


/*--------------�i�J�D�e��------*/
int welcome_to_game() {
	system("cls");
	system("cls");
	
	
	int set_Condition;				//�C������ and �\��� 
	
	color(15);
	gotoxy(43, 13);
	printf("�� �� �j ��");

	color(11);
	gotoxy(43, 18);
	printf("1.�i�J�C��");

	color(11);
	gotoxy(43, 20);
	printf("2.�d�߱Ʀ�]");

	color(11);
	gotoxy(43, 22);
	printf("3.�h�X�C��");

	color(13);
	gotoxy(43, 26);
	printf("�Ы� 1 2 3 :  ");
	gotoxy(57,26);
	
	
	if(set_Condition!=3) scanf("%d", &set_Condition);     //��ܥ\�� 
	
	
	switch (set_Condition) {
		case 1:
			system("cls");
			
		
			/*------�C�����H-----*/ 
			game_statement();		
			
	    	print_border();		//�C����� 
	    	
			game_start();		//�C���}�l 
			
			break;
		case 2:
			leadboard();		//�Ʀ�]�禡
			_getch();        	//�����N���^�D����
			system("cls");
			//welcome_to_game();
			break;
		case 3:
			//exit(0);			//�]�i�Ϊ������X 
			break;
			
		default:				//������ case 
			color(79);
			gotoxy(45, 28);
			printf("1-3 only !!");	//�e���\��A�^��main �i���s��J 
			Sleep(600);
	}
		
	return(set_Condition);		//�^�� case  
}
/*----------�i�J�D�e��_end----------*/



/*-------�Ʀ�]-------*/
void leadboard() {
	system("cls");                                        //�C�L�Ʀ�] 
	color(11);
	gotoxy(49, 1);
	printf("�Ʀ�]:\n");

	FILE *pfile;										//�}��user_in �� 
	if((pfile=fopen("scoreboard.txt","r+"))==NULL){
		printf("openfail");
	}
	
	int this_score;										//�ŧi���ɥΪ��ܼ� 
	int i=0, num=0;
	int rank[11]={0};
	char name_in[20];
	char blank1[30],blank2[30];
	
	while(!feof(pfile)){								//������� 
		
		fgets(name_in,20,pfile);
		fgets(blank1,5,pfile);

		fscanf(pfile,"%d",&this_score);
		fgets(blank2,6,pfile);
		
		if(!feof(pfile)){
			rank[num]=this_score;						//���Ʀs�Jrank[]��	
			//printf("%-20s %d\n",name_in,this_score);
			num++;
		}
		
	}
	close(pfile);										//��n���� ���� 

	
	int tra, key;										//tra ��洫 �Akey�T�{���Lswitch 
	
	/*-------bubble sort �Ƨ� rank[]-------*/ 
	do{
		key=0;
		for(i=0;i<5;i++){
			if(rank[i]<rank[i+1]){
				tra=rank[i];rank[i]=rank[i+1];rank[i+1]=tra;
				key=1;
			}
		}
	}while(key);
	

	char name_in2[20]={0};				//�ȸ�ƥ��[�h�ŧi�� 
	char pre_name[20]={0};
	char blank3[30]={0};
	char blank4[30]={0};
	
	for(i=0;i<num;i++){					//�N���ƹ����� �W�r 
	
		FILE *opfile;
		if((opfile=fopen("scoreboard.txt","r+"))==NULL){ 	//�A���}�� 
			printf("openfail");
		}
	
		while(!feof(opfile)){
	
			fgets(name_in2,20,opfile);						//��m�W 
			fgets(blank3,5,opfile);							//*�ݸ˸m �վ�r���� 

			fscanf(opfile,"%d",&this_score);				//����� 
		
			fgets(blank4,6,opfile);
	
			if(!feof(opfile)){
				
				if(rank[i]==this_score&&strncmp(pre_name,name_in2,19)!=0){					//���ƹ����m�W  �B�Ҽ{�P��case 
					gotoxy(40, 4+2*i);
					color(5+i);
					/*--------��X�ƦW-------*/
					printf("��%d�W! : %-20s %d\n",i+1,name_in2,this_score);
					int j;
					for(j=0;j++;j<20){
						pre_name[j]=name_in2[j];
					}
				}
			}
			close(opfile);										//���� 
		}
		close(opfile);										//final����
	}
	
	gotoxy(37,30);
	color(15);
	printf("*****�����N���^�D����*****");
	
}
/*-------�Ʀ�]_end-------*/


/*--------�C������------*/
void game_statement() {

	system("cls");
	color(10);
	gotoxy(44, 1);
	printf("�C������");
	color(2);

	int i,j = 1;
	for (i = 3; i <= 28; i++)  //��X�W�U���===
   {
   for (j = 6; j <= 80; j++) //��X���k���||
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
	printf("1. �W,�U,��,�k,���O��������W�U���k����");

	color(10);
	gotoxy(20, 8);
	printf("2. ���Ů�o�g�l�u�A�����ľ��Y�i�o��1-2��");

	color(14);
	gotoxy(20, 11);
	printf("3. 60������ �յۮ��U�̰����a!!!");

	color(4);
	gotoxy(20, 14);
	printf("4. ��shift ctrl alt �i���������Z��");
	gotoxy(20,16);
	printf("(���O����6����o�A8���i�s�o�A10���L�N�o�l�u)");

	color(8);
	gotoxy(34, 20);
	printf("*****�����N��}�l�C��*****");
	getch();        //�����N��
	system("cls");
}
/*--------�C������_end------*/


/*--------�C������------*/ 
void endgame(){
    system("cls");
  
    color(14);
	gotoxy(30, 11);
    printf("your score is: %d\n",score);
    sleep(2);
    user_in();						//�I�suser_in �������a��T 
    score=0;
    system("cls");
    color(15);
}
/*--------�C������_end--------*/ 


/*--------���a��T--------*/ 
void user_in(){
	
	char name[20];				//�ŧi�x�s�m�W��m 
	char name_in[20];
	
	system("cls");
	gotoxy(30, 18);
	printf("�п�J�m�W:\n");
	gotoxy(30, 18);
	printf("\r");
	gotoxy(40, 18);
	scanf("%s",name_in);		//���m�W 
	
	
	FILE *opfile;										//�}�� 
	if((opfile=fopen("scoreboard.txt","a"))==NULL){
		printf("openfail");
	}
	fprintf(opfile,"%-20s %3d\n",name_in,score);		//�s���� �s�J��r�� 
	close(opfile);										//���� 
}
/*--------���a��T_end--------*/ 

	
/*----main.c_end------*/

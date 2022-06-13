/*----game.c------*/
/*----group-9_2022_mis102_final----*/
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>
#include <time.h>
#include "import.h"
#include "print_fun.h"
#include<string.h>
#define SIZE 10

/*----------�ŧi�n�Ψ쪺�禡---------*/ 
int exceed_border(COORD* current_xy);							
int air_plane_move(COORD *current_xy);
void PRINT_airplane(COORD* current_xy,int choose_weapon);
void shoot(COORD* current_xy,struct bullet *Bullet);
void startup_bullet(COORD* current_xy,struct bullet *Bullet);
void show_surplus_bullet();
void monster(struct monster *Monster);
void startup_monster();
void reset_monster(struct bullet* Bullet,struct monster*Monster);
void Hit();
void show_score();
void HideCursor();

/*-------�ŧi�n�Ψ쪺�����ܼ�-------*/ 
int score=0;
int health=1;
int weapon_choose=1;
int count_main_while_time = 1;
int bullet_situation=1;

							
int refill;				//�N�o��


COORD surplus_loc;
COORD old_airplane_pos;


/*-----�غc�n�Ψ쪺�F��-----*/ 
struct bullet bullet1;
struct bullet bullet2;
struct bullet bullet3;
struct bullet bullet4;
struct bullet bullet5;
struct bullet bullet6;
struct monster monster1;
struct monster monster2;
struct monster monster3;
struct monster monster4;
struct monster monster5;
struct bullet bullet7;
struct bullet bullet8;
struct bullet bullet9;
struct bullet bullet10;


/*-----------------------game�D�禡---------*/ 
void game_start(){

/*------------��l��----------*/ 
	COORD current_xy;
	current_xy.X = 26;
	current_xy.Y = 43;

	startup_bullet(&current_xy,&bullet1);		//�l�u��l 
	startup_bullet(&current_xy,&bullet2);
	startup_bullet(&current_xy,&bullet3);
	startup_bullet(&current_xy,&bullet4);
	startup_bullet(&current_xy,&bullet5);
	startup_bullet(&current_xy,&bullet6);
	startup_bullet(&current_xy,&bullet7);
	startup_bullet(&current_xy,&bullet8);
	startup_bullet(&current_xy,&bullet9);
	startup_bullet(&current_xy,&bullet10);
	
   	startup_monster();							//�k�۪�l 
   	
	surplus_loc.X=120;
	surplus_loc.Y=40;

    old_airplane_pos=current_xy;				//��m��l 
    
    
    /*------------------------�C���D�j��-----------------------------*/ 
    while(count_main_while_time<1500){
    	HideCursor();
    	
    	if (GetAsyncKeyState(0x10)){			//�������Z�� 
			weapon_choose = 1;
			bullet_situation=1;
		}
		if (GetAsyncKeyState(0x11)){
			weapon_choose = 2;
			bullet_situation=2;
		}
		if (GetAsyncKeyState(0x12)){
			weapon_choose = 3;
			bullet_situation=3;
		}
	
        if(count_main_while_time%3==1){			//�ť��F�ӫ�
        
	    	if (GetAsyncKeyState(0x20)){
	    		if(bullet1.end==1)
	        		bullet1.start=1;
	    		else if (bullet1.end==0&&bullet2.end==1)
	        		bullet2.start=1;
	    		else if (bullet2.end==0&&bullet3.end==1)
					bullet3.start=1;
	   			else if (bullet3.end==0&&bullet4.end==1)
	        		bullet4.start=1;
	    		else if (bullet4.end==0&&bullet5.end==1)
	        		bullet5.start=1;
           		else if (bullet5.end==0&&bullet6.end==1){
	        		bullet6.start=1;
				}
	    		if(bullet_situation>=2){	//------------------------------------------------------fly2
			
		    	 	if (bullet6.end==0&&bullet7.end==1)
		        		bullet7.start=1;
            		else if (bullet7.end==0&&bullet8.end==1)
		        	bullet8.start=1;
		    	}
		    	if(bullet_situation==3){
			
            		if (bullet8.end==0&&bullet9.end==1)
		        		bullet9.start=1;
            		else if (bullet9.end==0&&bullet10.end==1){
		        		bullet10.start=1;
		    		}
				}
	    	}
		}


/*----------------�l�u�o�g����------------*/ 
	    if(bullet1.start==1){
	        bullet1.end=0;
	        color(14);
		    shoot(&current_xy,&bullet1);
	    }

		if(bullet2.start==1){
	        bullet2.end=0;
	        color(13);
		    shoot(&current_xy,&bullet2);
	    }

		if(bullet3.start==1){
	        bullet3.end=0;
	        color(12);
		    shoot(&current_xy,&bullet3);
	    }

		if(bullet4.start==1){
	        bullet4.end=0;
	        color(11);
		    shoot(&current_xy,&bullet4);
	    }

		if(bullet5.start==1){
	        bullet5.end=0;
	        color(10);
		    shoot(&current_xy,&bullet5);
	    }
	    if(bullet6.start==1){
	        bullet6.end=0;
	        color(9);
		    shoot(&current_xy,&bullet6);
		    if(bullet_situation==1) refill=1;
	    }
		if(bullet7.start==1){
	        bullet7.end=0;
	        color(13);
		    shoot(&current_xy,&bullet7);
	    }
        if(bullet8.start==1){
	        bullet8.end=0;
	        color(12);
		    shoot(&current_xy,&bullet8);
		    if(bullet_situation==2) refill=1;
	    }
	    if(bullet9.start==1){
	        bullet9.end=0;
	        color(11);
		    shoot(&current_xy,&bullet9);
	    }
        if(bullet10.start==1){
	        bullet10.end=0;
	        color(10);
		    shoot(&current_xy,&bullet10);
		    if(bullet_situation==3) refill=1;  
	    }
	    

/*----------------�l�u�o�g��m------------*/ 
	    if (bullet1.end==1){
	    	bullet1.xy.X=current_xy.X+2;
	        bullet1.xy.Y=current_xy.Y+4;
		}

		if (bullet2.end==1){
	    	bullet2.xy.X=current_xy.X+2;
	        bullet2.xy.Y=current_xy.Y+4;
		}

		if (bullet3.end==1){
	    	bullet3.xy.X=current_xy.X+2;
	        bullet3.xy.Y=current_xy.Y+4;
		}

		if (bullet4.end==1){
	    	bullet4.xy.X=current_xy.X+2;
	        bullet4.xy.Y=current_xy.Y+4;
		}

		if (bullet5.end==1){
	    	bullet5.xy.X=current_xy.X+2;
	        bullet5.xy.Y=current_xy.Y+4;
		}
		if (bullet6.end==1){
	    	bullet6.xy.X=current_xy.X+2;
	        bullet6.xy.Y=current_xy.Y+4;
		}
		
		if (bullet7.end==1){
	    	bullet7.xy.X=current_xy.X+2;
	        bullet7.xy.Y=current_xy.Y+4;
		}
		if (bullet8.end==1){
	    	bullet8.xy.X=current_xy.X+2;
	        bullet8.xy.Y=current_xy.Y+4;
		}
		if (bullet9.end==1){
	    	bullet9.xy.X=current_xy.X+2;
	        bullet9.xy.Y=current_xy.Y+4;
		}
		if (bullet10.end==1){
	    	bullet10.xy.X=current_xy.X+2;
	        bullet10.xy.Y=current_xy.Y+4;
		}
/*--------------------�l�u�o�g����------------------*/ 
		
/*--------------------�j�P�]�w���������]�禡-------*/
		
	    show_surplus_bullet();						//�Ѿl�u�Ķq 
        air_plane_move(&current_xy);				//�������� 
        exceed_border(&current_xy);					//������� 
        PRINT_airplane(&current_xy,weapon_choose);	//��ܭ��� 
    	Hit();										//�����P�_ 
    	show_score();								//���ƭp�� 

/*-----------------------�D�n�禡-------------------*/


/*----------------------��u-------------------*/ 
		if(refill==1){								//��u 
			gotoxy(120,35);
			if(bullet_situation==1||bullet_situation==2)	
			printf("�N�o��!!");
			if(bullet_situation==3)
			printf("�ֳt�N�o!!!");
		}else{
				gotoxy(120,35);
				printf("              ");
		}

if(bullet_situation==1){

		if(refill==1&&bullet6.xy.Y<5){
			startup_bullet(&current_xy,&bullet1);
			startup_bullet(&current_xy,&bullet2);
			startup_bullet(&current_xy,&bullet3);
			startup_bullet(&current_xy,&bullet4);
			startup_bullet(&current_xy,&bullet5);
			startup_bullet(&current_xy,&bullet6);
			
				/*
			startup_bullet(&current_xy,&bullet7);
			startup_bullet(&current_xy,&bullet8);
			startup_bullet(&current_xy,&bullet9);
			startup_bullet(&current_xy,&bullet10);
			*/
			
			refill=0;
		}
}
if(bullet_situation==2){

		if(refill==1&&bullet8.xy.Y<5){
			startup_bullet(&current_xy,&bullet1);
			startup_bullet(&current_xy,&bullet2);
			startup_bullet(&current_xy,&bullet3);
			startup_bullet(&current_xy,&bullet4);
			startup_bullet(&current_xy,&bullet5);
			startup_bullet(&current_xy,&bullet6);
			
		
			startup_bullet(&current_xy,&bullet7);
			startup_bullet(&current_xy,&bullet8);
			/*
			startup_bullet(&current_xy,&bullet9);
			startup_bullet(&current_xy,&bullet10);
			*/
			
			refill=0;
		}
}
if(bullet_situation==3){
		if(refill==1&&bullet6.xy.Y<10){
			startup_bullet(&current_xy,&bullet1);
			startup_bullet(&current_xy,&bullet2);
			startup_bullet(&current_xy,&bullet3);
			startup_bullet(&current_xy,&bullet4);
			startup_bullet(&current_xy,&bullet5);
			startup_bullet(&current_xy,&bullet6);
			startup_bullet(&current_xy,&bullet7);
			startup_bullet(&current_xy,&bullet8);
			startup_bullet(&current_xy,&bullet9);
			startup_bullet(&current_xy,&bullet10);
			
			
			refill=0;
		}
}
    

/*--------------------�k�۪��A----------------------------*/
        int chan=rand()%5+1;
        
            if(chan==1){
                monster(&monster1);
            }
            else if(chan==2){
                monster(&monster1);
                monster(&monster2);
            }
            else if(chan==3){
               monster(&monster1);
               monster(&monster2);
               monster(&monster3);
            }
            else if(chan==4){
               monster(&monster1);
               monster(&monster2);
               monster(&monster3);
               monster(&monster4);
            }
            else if(chan==5){
               monster(&monster1);
               monster(&monster2);
               monster(&monster3);
               monster(&monster4);
               monster(&monster5);
            }
/*--------------------�k�۪��A_end----------------------------*/   

/*--------------------���n_�C���D�j�骺�p��----------------------------*/

        count_main_while_time++;  //---
		     
        gotoxy(60,50);
        printf("�Ѿl :%3d ��!",60-count_main_while_time/25);  //������� 25�i�����p���� 
        Sleep(25);
    }
    
   if(count_main_while_time>=1500){
   		count_main_while_time=1; 
	}
   
   	fflush(stdin);
	rewind(stdin);
}
/*--------game �D�禡_end------*/ 


int air_plane_move(COORD *current_xy){        //�������� 
    int up,down,left,right,space;

    up = GetAsyncKeyState(0x26);
	down = GetAsyncKeyState(0x28);
	left = GetAsyncKeyState(0x25);
	right = GetAsyncKeyState(0x27);
	space = GetAsyncKeyState(0x20);

	if (GetAsyncKeyState(0x25)){ //��
		current_xy->X -= 1;

		return 0;
	}
	if (GetAsyncKeyState(0x27)){//�k
	
		current_xy->X += 1;

		return 0;
	}
	if (GetAsyncKeyState(0x26)){//�W
	

		current_xy->Y -= 1;

		return 0;
	}
	if (GetAsyncKeyState(0x28)){//�U
	

		current_xy->Y += 1;

		return 0;
	}
}


int exceed_border(COORD* current_xy){ 		//�P�_�����������
	if (current_xy->X>91){
		current_xy->X = 91;
		return 0;
	}
	if (current_xy->X < 3){
		current_xy->X = 3;
		return 0;
	}
	if (current_xy->Y < 3){
		current_xy->Y = 3;
		return 0;
	}
	if (current_xy->Y >43){
		current_xy->Y = 43;
		return 0;
	}
	return 0;
}


void PRINT_airplane(COORD* current_xy,int choose_weapon)		//�L���� 
{
	int i;
	COORD xy;
	xy.X = current_xy->X;
	xy.Y = current_xy->Y;
	color(8);


	if (count_main_while_time != 1)  	//�Ĥ@������ 
	{
		for (i = 0; i < 6; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_airplane_pos);
			printf("        ");       //�������ʫ�_delete
			old_airplane_pos.Y += 1;  //�U�@�歸��
		}
	}

	old_airplane_pos = xy; //��{�b�o��l�s�_�ӯd���U�@�Ӱj�� �o���í�����
	for (i = 0; i < 6; i++)  //�L����
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);    //������m
		switch (choose_weapon){
		    case 1:
		    	weapon1(i);
		    	break;
	    	case 2:
		    	weapon2(i);
		    	break;
		    case 3:
		    	weapon3(i);
		    	break;
		    }
		xy.Y += 1;//�C�L���@�� �ǳƦC�L�U�@��
	}
}



void shoot(COORD* current_xy,struct bullet* Bullet){					//�l�u�o�g 
    if(bullet_situation==1||bullet_situation==2){
	
		gotoxy(70,20);
		gotoxy(Bullet->xy.X,Bullet->xy.Y);
		printf("^");
		if(count_main_while_time%(-2*bullet_situation+7)==0){
		gotoxy(Bullet->xy.X,Bullet->xy.Y);
		printf(" ");
		Bullet->xy.Y-=1;
			if (Bullet->xy.Y<=2){
	    		Bullet->xy.Y=current_xy->X+2;
	    		Bullet->xy.Y=current_xy->Y+4;
	    		Bullet->start=0;
    		}
    	}
	}else{
		gotoxy(70,20);
		gotoxy(Bullet->xy.X,Bullet->xy.Y);
		printf("^");
		if(count_main_while_time%2==0){
		gotoxy(Bullet->xy.X,Bullet->xy.Y);
		printf(" ");
		Bullet->xy.Y-=1;
			if (Bullet->xy.Y<=2){
	    		Bullet->xy.Y=current_xy->X+2;
	    		Bullet->xy.Y=current_xy->Y+4;
	    		Bullet->start=0;
	    		Bullet->end=1; 
    		}
    	}
	}
}

void startup_bullet(COORD* current_xy,struct bullet* Bullet){		//�l�u��l 
	Bullet->xy.Y=current_xy->X+2;
	Bullet->xy.Y=current_xy->Y+4;
	Bullet->start=0;
	Bullet->end=1;
}

void show_surplus_bullet(){										//�Ѿl�l�u 
	color(8);

	gotoxy( surplus_loc.X,surplus_loc.Y);
	static int surplus=10;
    if(bullet_situation==1 )surplus= bullet1.end+bullet2.end+bullet3.end+bullet4.end+bullet5.end+bullet6.end;
    if(bullet_situation==2 )surplus= bullet1.end+bullet2.end+bullet3.end+bullet4.end+bullet5.end+bullet6.end+bullet7.end+bullet8.end;
    if(bullet_situation==3 )surplus= bullet1.end+bullet2.end+bullet3.end+bullet4.end+bullet5.end+bullet6.end+bullet7.end+bullet8.end+bullet9.end+bullet10.end;
    printf("�Ѿl�l�u�� : %2d",surplus);

}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info ={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void monster(struct monster *Monster){			//�k�� 

    if(count_main_while_time%2==0){
        int i;
	    Monster->xy.X = Monster->old_xy.X;
        Monster->xy.Y = Monster->old_xy.Y+1;//�ĤH��m
	    if(Monster->xy.Y<48){
	        if (count_main_while_time != 1)  		
	       {

		        for (i = 0; i < 2; i++)
		        {
		         	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Monster->old_xy);
		        	printf("  ");       //���ʫ�_delete
		        	Monster->old_xy.Y += 1;  //�U�@��
		        }
	        }
    	    Monster->old_xy = Monster->xy; //��{�b�o��l�s�_�ӯd���U�@�Ӱj�� �o���í�����
    	    for (i = 0; i < 2; i++)  //�L
        	{
		        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Monster->xy);    //������m
		        printf("xx");
		        Monster->xy.Y += 1;//�C�L���@�� �ǳƦC�L�U�@��
	        }
        Monster->hit1_xy.X =Monster->xy.X;
        Monster->hit1_xy.Y =Monster->xy.Y-2;

        Monster->hit2_xy.X =Monster->xy.X+1;
        Monster->hit2_xy.Y =Monster->xy.Y-2;

        Monster->hit3_xy.X =Monster->xy.X;
        Monster->hit3_xy.Y =Monster->xy.Y-1;

        Monster->hit4_xy.X =Monster->xy.X+1;
        Monster->hit4_xy.Y =Monster->xy.Y-1;

     }
     else{
	        for (i = 0; i < 2; i++)   {
		        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Monster->old_xy);
		    	printf("  ");       //���ʫ�_delete
		    	Monster->old_xy.Y += 1;  //�U�@��
		    }
	        Monster->old_xy.X = rand()%96+2;
	        Monster->old_xy.Y = 2;
		}
	}
}


void startup_monster(){				//��l�k�� 


    monster1.old_xy.X=10;
    monster1.old_xy.Y=1;
	monster2.old_xy.X=14;
    monster2.old_xy.Y=1;
	monster3.old_xy.X=18;
    monster3.old_xy.Y=1;
	monster4.old_xy.X=22;
    monster4.old_xy.Y=1;
	monster5.old_xy.X=40;
    monster5.old_xy.Y=1;

    monster1.hit1_xy.X=10;
	monster2.hit1_xy.X=14;
	monster3.hit1_xy.X=18;
	monster4.hit1_xy.X=22;
	monster5.hit1_xy.X=26;

    monster1.hit1_xy.Y=0;
	monster2.hit1_xy.Y=0;
	monster3.hit1_xy.Y=0;
	monster4.hit1_xy.Y=0;
	monster5.hit1_xy.Y=0;

	monster1.hit2_xy.X=11;
	monster2.hit2_xy.X=15;
	monster3.hit2_xy.X=19;
	monster4.hit2_xy.X=23;
	monster5.hit2_xy.X=27;

	monster1.hit2_xy.Y=0;
	monster2.hit2_xy.Y=0;
	monster3.hit2_xy.Y=0;
	monster4.hit2_xy.Y=0;
	monster5.hit2_xy.Y=0;

    monster1.hit3_xy.X=10;
	monster2.hit3_xy.X=14;
	monster3.hit3_xy.X=18;
	monster4.hit3_xy.X=22;
	monster5.hit3_xy.X=26;

	monster1.hit3_xy.Y=1;
	monster2.hit3_xy.Y=1;
	monster3.hit3_xy.Y=1;
	monster4.hit3_xy.Y=1;
	monster5.hit3_xy.Y=1;

	monster1.hit4_xy.X=11;
	monster2.hit4_xy.X=15;
	monster3.hit4_xy.X=19;
	monster4.hit4_xy.X=23;
	monster5.hit4_xy.X=27;

	monster1.hit4_xy.Y=1;
	monster2.hit4_xy.Y=1;
	monster3.hit4_xy.Y=1;
	monster4.hit4_xy.Y=1;
	monster5.hit4_xy.Y=1;
}


void reset_monster(struct bullet* Bullet,struct monster*Monster){			//������ 
	
	int i=0;
	if ( (Bullet->xy.X==Monster->hit3_xy.X&&Bullet->xy.Y==Monster->hit3_xy.Y )|| (Bullet->xy.X==Monster->hit4_xy.X&&Bullet->xy.Y==Monster->hit4_xy.Y)){
		score+=1;
		
		
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Monster->xy);
        printf("  ");
        
        Monster->xy.Y-=1;
        
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Monster->xy);
        printf("  ");
        
        
	    Monster->old_xy.X=rand()%96+2;
    	Monster->old_xy.X=2;
    }
}


void Hit(){											//�� 
	reset_monster(&bullet1,&monster1);
	reset_monster(&bullet1,&monster2);
	reset_monster(&bullet1,&monster3);
	reset_monster(&bullet1,&monster4);
	reset_monster(&bullet1,&monster5);
	
	reset_monster(&bullet2,&monster1);
	reset_monster(&bullet2,&monster2);
	reset_monster(&bullet2,&monster3);
	reset_monster(&bullet2,&monster4);
	reset_monster(&bullet2,&monster5);
	
	reset_monster(&bullet3,&monster1);
	reset_monster(&bullet3,&monster2);
	reset_monster(&bullet3,&monster3);
	reset_monster(&bullet3,&monster4);
	reset_monster(&bullet3,&monster5);
	
	reset_monster(&bullet4,&monster1);
	reset_monster(&bullet4,&monster2);
	reset_monster(&bullet4,&monster3);
	reset_monster(&bullet4,&monster4);
	reset_monster(&bullet4,&monster5);
	
	reset_monster(&bullet5,&monster1);
	reset_monster(&bullet5,&monster2);
	reset_monster(&bullet5,&monster3);
	reset_monster(&bullet5,&monster4);
	reset_monster(&bullet5,&monster5);
/*	
	reset_monster(&bullet6,&monster1);
	reset_monster(&bullet6,&monster2);
	reset_monster(&bullet6,&monster3);
	reset_monster(&bullet6,&monster4);
	reset_monster(&bullet6,&monster5);
	
	reset_monster(&bullet7,&monster1);
	reset_monster(&bullet7,&monster2);
	reset_monster(&bullet7,&monster3);
	reset_monster(&bullet7,&monster4);
	reset_monster(&bullet7,&monster5);
	                     
	reset_monster(&bullet8,&monster1);
	reset_monster(&bullet8,&monster2);
	reset_monster(&bullet8,&monster3);
	reset_monster(&bullet8,&monster4);
	reset_monster(&bullet8,&monster5);
	                     
	reset_monster(&bullet9,&monster1);
	reset_monster(&bullet9,&monster2);
	reset_monster(&bullet9,&monster3);
	reset_monster(&bullet9,&monster4);
	reset_monster(&bullet9,&monster5);
	                     
	reset_monster(&bullet10,&monster1);
	reset_monster(&bullet10,&monster2);
	reset_monster(&bullet10,&monster3);
	reset_monster(&bullet10,&monster4);
	reset_monster(&bullet10,&monster5);
*/
	
}
											
void show_score(){					//������� 
	gotoxy(120,10);
	printf("����%4d",score);
}
/*----game.c_end------*/

/*-----print.h----*/
/*----group-9_2022_mis102_final----*/

/*-------����1------*/ 
void weapon1(int i){
	if (i == 0)
		printf("   �C");
	else if (i == 1)
		printf("   ^");
	else if (i == 2)
		printf("  ^^^ ");
    else if (i == 3)
		printf(" ^^^^^ ");
	else if (i == 4)
		printf("x||��||x");
    else if (i == 5)
		printf("V     V");
}
/*-------����1_end------*/ 


/*-------����2------*/ 
void weapon2(int i){
	if (i == 0)
		printf("   �C");
	else if (i == 1)
		printf("|  ^  |");
	else if (i == 2)
		printf("| ^^^ |");
    else if (i == 3)
		printf("|^^^^^|");
	else if (i == 4)
		printf("x||��||x");
    else if (i == 5)
		printf("V     V");
}
/*-------����2_end------*/ 


/*-------����3------*/ 
void weapon3(int i){
	if (i == 0)
		printf("  |||||");
	else if (i == 1)
		printf("    ^");
	else if (i == 2)
		printf("   ^^^ ");
    else if (i == 3)
		printf("  ^^^^^ ");
	else if (i == 4)
		printf(" x||||x");
    else if (i == 5)
		printf(" V     V");
}
/*-------����3_end------*/ 

/*-------���--------*/ 
void print_border(){
    color(9);
	int i, j;
	for (i = 1; i <= 50; i++){
		for (j = 1; j <= 100; j++){
			if (i == 1 || i == 50){
				if (j != 1){
					printf("=");
				}

				else{
					printf("  ");
				}
			}
			else{
				if (j == 1 || j == 100){
					printf("��");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
/*-------���_end--------*/ 

/*-----print.h_end----*/

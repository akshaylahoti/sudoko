#include<stdio.h>
#include<stdlib.h>
#include"sudoko.h"
int printmenu_1(){
	int choice;
	system("clear");
	printf("\t\t###################################################\n");
	printf("\t\t***************************************************\n\n\n");
	printf("\t\t------------------------SUDOKO---------------------\n\n\n");
	printf("\t\t***************************************************\n\n\n");
	printf("\t\t###################################################\n");
	printf("\t\t\t\t\t\t\t 1.Start Game\n");
	printf("\t\t\t\t\t\t\t 2.Exit\n");
	scanf("%d", &choice);
	return choice;
}
int printmenu_2(){
	int choice;
	char s[32];
	printf("1.Insert an element in sudoko\n"\
		"2.Remove a Digit\n"\
		"3.Check position\n"\
		"4.Check complete sudoko\n"\
		"5.Solution\n"\
		"6.End game\n");
	scanf("%[^0-9]%d", s, &choice);
	return choice;
}
int printmenu_3(){
	int choice;
	char s[32];
	printf("\t\t\t------LEVEL------\n\n\n"\
		"\t\t\t 1.Amature\n"\
		"\t\t\t 2.Professional\n"\
		"\t\t\t 3.Legendry\n");
	scanf("%[^0-9]%d", s, &choice);
	return choice;
}
int main(){
	int choice_1, choice_2, choice_3;
	int i = 0, p, q;
	int pos, s, x;
	time_t k;
	srand((unsigned)time(&k));
	for(p = 1; p < 10; p++){
		for(q = 1; q < 10; q++){
			t[p][q] = sudoko.a[p][q];/*copying array a into t forprinting*/
		}
	}
	choice_1 = printmenu_1();
	switch(choice_1){
		case 1:
			choice_2 = printmenu_3();
			generate(choice_2);
			sudoprint(t);
			while(1){
				choice_3 = printmenu_2();
				switch(choice_3){
					case 1:/*for insert*/
						if(i == 0 || i == 1)
							printf("Enter the position and value\n"\
								"||while entering position enter\n"\
								"row first and then column||\n");
						else
							printf("Enter position and value\n");
							i++;
							scanf("%d%d%d", &sudoko.ra, &sudoko.ca, &sudoko.va);
							insert();
							break;
					case 2:/*for remove*/
						printf("Enter the position\n");
						scanf("%d%d", &sudoko.ra, &sudoko.ca);
						removes();
						break;
					case 3:/*position check*/
						printf("Enter the position\n");
						scanf("%d%d", &sudoko.rc, &sudoko.cc);
						checkpos();
						break;
					case 4:
						checkcomp();
						break;
					case 5:
						sudoprint(sudoko.c);
						break;
					case 6:
						exit(0);
						break;
				}
			}
			break;
		case 2:
			exit(0);
			break;
		}
	return 0;
} 

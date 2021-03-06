/*******************************************************************************
It is a program which contains all the function required for playing suduko.
* Copyright (C) 2015  Akshay Lahoti akshaylahoti3105@gmail.com
*  
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"sudoko.h"
int printsuduko(){
	int i, x = 0, y = 0, z = 0;
	printf("\n\n");
	for(i = 0; i < 10; i++){
		if((z + 2) % 3 == 0){
			printf("****||***********||***********||***********|\n");
		}
		z++;
		if(i == 0 && x == 0){
			printf("|___|");
		}
		if(i != 0){
			sudoko.a[i][0] = i;
			printf("|_%d_|", sudoko.a[i][0]);
		}
		for(x = 0; x < 10; x++){
			if((y + 2) % 3 == 0){
				printf("|");
			}
			y++;
			if(i == 0 && x != 0){
				sudoko.a[i][x] = x;
				printf("_%d_|", sudoko.a[i][x]);
			}
			if(i != 0 && x != 0){
				printf("___|");/*improvement by substituting the a[i][j] element */
			}
		}
		y = 0;
		printf("\n");
	}
	return 0;
}
int sudoprint(int h[10][10]){
	int i, x = 0, y = 0, z = 0;
	for(i = 0; i < 10; i++){
		if((z + 2) % 3 == 0){
			printf("****||***********||***********||***********|\n");
		}
		z++;
		if(i == 0 && x == 0){
			printf("|___|");
		}
		if(i != 0){
			h[i][0] = i;
			printf("|_%d_|", h[i][0]);
		}
		for(x = 0; x < 10; x++){
			if((y + 2) % 3 == 0){
				printf("|");
			}
			y++;
			if(i == 0 && x != 0){
				h[i][x] = x;
				printf("_%d_|",h[i][x]);
			}
			if(i != 0 && x != 0){
				if(h[i][x] != 0)
					printf("_%d_|", h[i][x]);
				else
					printf("___|");
			}
		}
		y = 0;
		printf("\n");
	}
	return 0;
}
int insert(){
	int i, j, k;
	i = sudoko.ra;
	j = sudoko.ca;
	k = sudoko.va;
	if(i < 0 || k > 9){
		printf("Please enter number between 1 and 9 only\n");
		sudoprint(t);
		return 0;
	}
	if(j < 0 || j > 9){
		printf("Please enter number between 1 and 9 only\n");
		sudoprint(t);
		return 0;
	}
	if(k < 0 || k > 9){
		printf("Please enter a number between 1 to 9 only\n");
		sudoprint(t);
		return 0;
	}
	if(sudoko.a[i][j] == 0){
		sudoko.a[i][j] = t[i][j] = sudoko.va;
	}
	else{
		printf("number was already present in that location\nplease enter another location\n\n\n");
	}
	sudoprint(t);
	return 0;
}
int checkpos(){
	int i, j;
	i = sudoko.rc;
	j = sudoko.cc;
	if(sudoko.c[i][j] == sudoko.a[i][j]){
		printf("correct \n");
	}
	else{
		printf("Incorrect\n");
		printf("correct position is %d\n", sudoko.c[i][j]);
	}
	return 0;
}
int removes(){/* removes a particular value from position*/
	int i = sudoko.ra;
	int j = sudoko.ca;
	if(sudoko.a[i][j] != sudoko.b[i][j])
		sudoko.a[i][j] = t[i][j] = 0;
	else if(sudoko.a[i][j] == 0)
		printf("Already empty\n");
	else if(sudoko.a[i][j] == sudoko.b[i][j])
		printf("Value cannot be removed as this is given in the question\n");
	sudoprint(t);
	return 0;
}
int exits(){
	exit(0);
}
int a[100], b[100];
int generate(int x){
	time_t l;
	int p = 0, q = 0, i, j;
	srand((unsigned)time(&l));
	int k = rand() % 100;
	if(k % 2 == 1){
		answer1();
	}
	else
		answer2();
	switch(x){
		case 1:
			p = easy();
			break;
		case 2:
			p = medium();
			break;
		case 3:
			p = hard();
			break;
	}
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			sudoko.b[i][j] = 0;
		}
	}
	while(q < p){
		sudoko.b[a[q]][b[q]] = sudoko.c[a[q]][b[q]];
		q++;
	}
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			t[i][j] = sudoko.a[i][j] = 0;
		}
	}
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			t[i][j] = sudoko.a[i][j] = sudoko.b[i][j];
		}
	}
	return 0;
}
int hard() {
        int x = 0, i, j;
	time_t t;
	srand((unsigned) time(&t));
	while(x == 0) {
		x = rand() % 4;
	 }
	switch(x) {
		case 1:
						b[0] = 4;	             
			a[0] = 1, a[1] = 1, b[1] = 8, b[2] = 1;
			a[2] = 2, a[3] = 2, b[3] = 3, b[4] = 8;
			a[4] = 2, a[5] = 3, b[5] = 1, b[6] = 2;
			a[6] = 3, a[7] = 3, b[7] = 5, b[8] = 6;
			a[8] = 3, a[9] = 4, b[9] = 1, b[10] = 5;
			a[10] = 4, a[11] = 4, b[11] = 6, b[12] = 3;
			a[12] = 5, a[13] = 5, b[13] = 5, b[14] = 7;
			a[14] = 5, a[15] = 6, b[15] = 4, b[16] = 5;
			a[16] = 6, a[17] = 6, b[17] = 9, b[18] = 4;
			a[18] = 7, a[19] = 7, b[19] = 5, b[20] = 8;
			a[20] = 7, a[21] = 7, b[21] = 9, b[22] = 2;
			a[22] = 8, a[23] = 8, b[23] = 7, b[24] = 9;
			a[24] = 8, a[25] = 9, b[25] = 2, b[26] = 6;
			a[26] = 9;	
			i = j = 27;
			while (j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		 case 2:
			                             b[0] = 4;	             
			a[0] = 1, a[1] = 1, b[1] = 7, b[2] = 8;
			a[2] = 1, a[3] = 1, b[3] = 9, b[4] = 2;
			a[4] = 2, a[5] = 2, b[5] = 3, b[6] = 1;
			a[6] = 3, a[7] = 3, b[7] = 6, b[8] = 9;
			a[8] = 3, a[9] = 4, b[9] = 6, b[10] = 7;
			a[10] = 4, a[11] = 5, b[11] = 2, b[12] = 4;
                        a[12] = 5, a[13] = 5, b[13] = 6, b[14] = 8;
			a[14] = 5, a[15] = 6, b[15] = 3, b[16] = 4;
			a[16] = 6, a[17] = 7, b[17] = 1, b[18] = 4;
			a[18] = 7, a[19] = 7, b[19] = 9, b[20] = 7;
			a[20] = 8, a[21] = 8, b[21] = 8, b[22] = 1;
			a[22] = 9, a[23] = 9, b[23] = 2, b[24] = 3;
			a[24] = 9, a[25] = 9, b[25] = 6; 	
			i = j = 26;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 3:
						b[0] = 2;	          
			a[0] = 1, a[1] = 1, b[1] = 4, b[2] = 5;
			a[2] = 1, a[3] = 1, b[3] = 8, b[4] = 9;
			a[4] = 1, a[5] = 2, b[5] = 2, b[6] = 5;
			a[6] = 2, a[7] = 2, b[7] = 7, b[8] = 1;
			a[8] = 3, a[9] = 3, b[9] = 9, b[10] = 2;
			a[10] = 4, a[11] = 5, b[11] = 1, b[12] = 4;
			a[12] = 5, a[13] = 5, b[13] = 6, b[14] = 9;
			a[14] = 5, a[15] = 6, b[15] = 8, b[16] = 1;
			a[16] = 7, a[17] = 7, b[17] = 9, b[18] = 3;
			a[18] = 8, a[19] = 8, b[19] = 5, b[20] = 8;
			a[20] = 8, a[21] = 9, b[21] = 1, b[22] = 2;
			a[22] = 9, a[23] = 9, b[23] = 5, b[24] = 6;
			a[24] = 9, a[25] = 9, b[25] = 8; 	
			i = j = 26;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
	}
	return i;
}
int medium() {
	int x = 0, i, j;
	time_t t;
	srand((unsigned) time(&t));
	while(x == 0) {
		x = rand() % 6;
	}
	switch(x){
		case 1:
						b[0] = 2;
			a[0] = 1, a[1] = 1, b[1] = 4, b[2] = 8;
			a[2] = 1, a[3] = 2, b[3] = 1, b[4] = 6;
			a[4] = 2, a[5] = 2, b[5] = 7, b[6] = 3;
			a[6] = 3, a[7] = 3, b[7] = 4, b[8] = 5;
			a[8] = 3, a[9] = 3, b[9] = 8, b[10] = 1;
			a[10] = 4, a[11] = 4, b[11] = 3, b[12] = 1;
			a[12] = 5, a[13] = 5, b[13] = 2, b[14] = 8;
			a[14] = 5, a[15] = 5, b[15] = 9, b[16] = 7;
			a[16] = 6, a[17] = 6, b[17] = 9, b[18] = 2;
			a[18] = 7, a[19] = 7, b[19] = 5, b[20] = 6;
			a[20] = 7, a[21] = 7, b[21] = 7, b[22] = 3;
			a[22] = 8, a[23] = 8, b[23] = 4, b[24] = 9;
			a[24] = 8, a[25] = 9, b[25] = 2, b[26] = 6;
			a[26] = 9, a[27] = 9; b[27] = 8;
			i = j = 28;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 2:
						b[0] = 1;
			a[0] = 1, a[1] = 1, b[1] = 2, b[2] = 4;
			a[2] = 1, a[3] = 1, b[3] = 7, b[4] = 3;
			a[4] = 2, a[5] = 2, b[5] = 6, b[6] = 4;
			a[6] = 3, a[7] = 3, b[7] = 5, b[8] = 8;
			a[8] = 3, a[9] = 3, b[9] = 9, b[10] = 1;
			a[10] = 4, a[11] = 4, b[11] = 2, b[12] = 2;
			a[12] = 5, a[13] = 5, b[13] = 5, b[14] = 8;
			a[14] = 5, a[15] = 6, b[15] = 8, b[16] = 9;
			a[16] = 6, a[17] = 7, b[17] = 1, b[18] = 2;
			a[18] = 7, a[19] = 7, b[19] = 5, b[20] = 6;
			a[20] = 7, a[21] = 8, b[21] = 4, b[22] = 7;
			a[22] = 8, a[23] = 9, b[23] = 3, b[24] = 6;
			a[24] = 9, a[25] = 9, b[25] = 8, b[26] = 9;
			a[26] = 9;
			i = j = 27;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 3:
			b[0] = 1;	             
			a[0] = 1, a[1] = 1, b[1] = 2, b[2] = 4;
			a[2] = 1, a[3] = 1, b[3] = 6, b[4] = 8;
 			a[4] = 1, a[5] = 2, b[5] = 1, b[6] = 2;
			a[6] = 3, a[7] = 3, b[7] = 4, b[8] = 7;
 			a[8] = 3, a[9] = 4, b[9] = 3, b[10] = 4;
			a[10] = 4, a[11] = 4, b[11] = 9, b[12] = 2;
			a[12] = 5, a[13] = 5, b[13] = 3, b[14] = 7;
			a[14] = 5, a[15] = 5, b[15] = 8, b[16] = 1;
			a[16] = 6, a[17] = 6, b[17] = 6, b[18] = 7;
			a[18] = 6, a[19] = 7, b[19] = 3, b[20] = 6;
			a[20] = 7, a[21] = 7, b[21] = 8, b[22] = 9;
			a[22] = 8, a[23] = 9, b[23] = 2, b[24] = 4;
			a[24] = 9, a[25] = 9, b[25] = 6, b[26] = 8;
			a[26] = 9; a[27] = 9, b[27] = 9;	
			i = j = 28;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 4:
			                             b[0] = 4;	             
			a[0] = 1, a[1] = 1, b[1] = 7, b[2] = 8;
			a[2] = 1, a[3] = 1, b[3] = 9, b[4] = 1;
			a[4] = 2, a[5] = 2, b[5] = 2, b[6] = 5;
			a[6] = 2, a[7] = 3, b[7] = 2, b[8] = 7;
			a[8] = 3, a[9] = 4, b[9] = 1, b[10] = 5;
			a[10] = 4, a[11] = 4, b[11] = 6, b[12] = 7;
			a[12] = 4, a[13] = 4, b[13] = 9, b[14] = 5;
			a[14] = 5, a[15] = 6, b[15] = 1, b[16] = 3;
			a[16] = 6, a[17] = 6, b[17] = 4, b[18] = 5;
			a[18] = 6, a[19] = 6, b[19] = 9, b[20] = 3;
			a[20] = 7, a[21] = 7, b[21] = 8, b[22] = 5;
			a[22] = 8, a[23] = 8, b[23] = 8, b[24] = 9;
			a[24] = 8, a[25] = 9, b[25] = 1, b[26] = 2;
			a[26] = 9, a[27] = 9, b[27] = 3; b[28] = 6;	
			a[28] = 9;
			i = j = 28;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 5:
			b[0] = 1;
			a[0] = 1, a[1] = 1, b[1] = 5, b[2] = 2;
			a[2] = 2, a[3] = 2, b[3] = 9, b[4] = 1;
			a[4] = 3, a[5] = 3, b[5] = 6, b[6] = 8;
			a[6] = 3, a[7] = 3, b[7] = 9, b[8] = 3;
			a[8] = 4, a[9] = 4, b[9] = 5, b[10] = 8;
			a[10] = 4, a[11] = 4, b[11] = 9, b[12] = 2;
			a[12] = 5, a[13] = 5, b[13] = 4, b[14] = 6;
			a[14] = 5, a[15] = 5, b[15] = 5, b[16] = 1;
			a[16] = 6, a[17] = 6, b[17] = 2, b[18] = 5;
			a[18] = 6, a[19] = 6, b[19] = 7, b[20] = 1;
			a[20] = 7, a[21] = 7, b[21] = 2, b[22] = 4;
			a[22] = 7, a[23] = 7, b[23] = 9, b[24] = 1;
			a[24] = 8, a[25] = 8, b[25] = 8, b[26] = 5;
			a[26] = 9; a[27] = 9, b[27] = 9;	
			i = j = 28;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;	
	}
	return i;
}
int easy(){
	int x = 0, i, j;
	time_t t;
	srand((unsigned)time(&t));
	while(x == 0){
		x = rand() % 6;
	}
	switch(x){
		case 1:
			a[0] = 1, b[0] = 2; a[1] = 1, b[1] = 4;
			a[2] = 1, b[2] = 6; a[3] = 1, b[3] = 7;
			a[4] = 1, b[4] = 8; a[5] = 1, b[5] = 9;
			a[6] = 2, b[6] = 1; a[7] = 2, b[7] = 2;
			a[8] = 2, b[8] = 3; a[9] = 2, b[9] = 4;
			a[10] = 2, b[10] = 8; a[11] = 3, b[11] = 7;
			a[12] = 4, b[12] = 3; a[13] = 4, b[13] = 6;
			a[14] = 4, b[14] = 8; a[15] = 4, b[15] = 9;
			a[16] = 5, b[16] = 4; a[17] = 5, b[17] = 6;
			a[18] = 6, b[18] = 1; a[19] = 6, b[19] = 2;
			a[20] = 6, b[20] = 4; a[21] = 6, b[21] = 7;
			a[22] = 6, b[22] = 9; a[23] = 7, b[23] = 3;
			a[24] = 8, b[24] = 2; a[25] = 8, b[25] = 6;
			a[26] = 8, b[26] = 7; a[27] = 8, b[27] = 8;
			a[28] = 8, b[28] = 9; a[29] = 9, b[29] = 1;
			a[30] = 9, b[30] = 2; a[31] = 9, b[31] = 3;
			a[32] = 9, b[32] = 4; a[33] = 9, b[33] = 6;
			a[34] = 9, b[34] = 8;	
			i = j = 35;
			while (j != 100) {
				a[j] = b[j] = 0;
                                       j++;
			}
			break;
		case 2:
			a[0] = 1, b[0] = 1; a[1] = 1, b[1] = 2;
			a[2] = 1, b[2] = 4; a[3] = 1, b[3] = 6;
			a[4] = 1, b[4] = 7; a[5] = 2, b[5] = 1;
			a[6] = 2, b[6] = 5; a[7] = 2, b[7] = 8;
			a[8] = 2, b[8] = 9; a[9] = 3, b[9] = 1;
			a[10] = 3, b[10] = 3; a[11] = 3, b[11] = 5;
			a[12] = 3, b[12] = 8; a[13] = 4, b[13] = 3;
			a[14] = 4, b[14] = 6; a[15] = 4, b[15] = 8;
			a[16] = 5, b[16] = 4; a[17] = 5, b[17] = 5;
			a[18] = 5, b[18] = 6; a[19] = 6, b[19] = 2;
			a[20] = 6, b[20] = 4; a[21] = 6, b[21] = 7;
			a[22] = 7, b[22] = 2; a[23] = 7, b[23] = 4;
			a[24] = 7, b[24] = 7; a[25] = 7, b[25] = 9;
			a[26] = 8, b[26] = 1; a[27] = 8, b[27] = 2;
			a[28] = 8, b[28] = 5; a[29] = 8, b[29] = 9;
			a[30] = 9, b[30] = 2; a[31] = 9, b[31] = 4;
			a[32] = 9, b[32] = 6; a[33] = 9, b[33] = 8;
			a[34] = 9, b[34] = 9;   
			i = j = 35;
			while(j != 100){
				a[j] = b[j] = 0;
				j++;
			}
			break;
		case 3:
			a[0] = 1, b[0] = 4; a[1] = 1, b[1] = 8;
                        a[2] = 2, b[2] = 1; a[3] = 2, b[3] = 2;
                        a[4] = 2, b[4] = 3; a[5] = 2, b[5] = 6;
                        a[6] = 3, b[6] = 1; a[7] = 3, b[7] = 2;
                        a[8] = 3, b[8] = 5; a[9] = 3, b[9] = 7;
                        a[10] = 3, b[10] = 9; a[11] = 4, b[11] = 4;
                        a[12] = 4, b[12] = 5; a[13] = 4, b[13] = 7;
                        a[14] = 5, b[14] = 1; a[15] = 5, b[15] = 3;
                        a[16] = 5, b[16] = 4; a[17] = 5, b[17] = 6;
                        a[18] = 5, b[18] = 7; a[19] = 5, b[19] = 9;
                        a[20] = 6, b[20] = 3; a[21] = 6, b[21] = 7;
                        a[22] = 6, b[22] = 9; a[23] = 7, b[23] = 1;
                        a[24] = 7, b[24] = 3; a[25] = 7, b[25] = 5;
                        a[26] = 7, b[26] = 8; a[27] = 7, b[27] = 9;
                        a[28] = 8, b[28] = 4; a[29] = 8, b[29] = 7;
                        a[30] = 8, b[30] = 8; a[31] = 8, b[31] = 9;
                        a[32] = 9, b[32] = 3; a[33] = 9, b[33] = 6;
                        
                        i = j = 34;
                        while (j != 100) {
                                a[j] = b[j] = 0;
                                j++;
                        }
			break;
		case 4:
			 b[0] = 3;	             
			a[0] = 1, a[1] = 1, b[1] = 8, b[2] = 9;
                        a[2] = 1, a[3] = 2, b[3] = 1, b[4] = 3;
                        a[4] = 2, a[5] = 2, b[5] = 4, b[6] = 5;
                        a[6] = 2, a[7] = 2, b[7] = 7, b[8] = 2;
                        a[8] = 3, a[9] = 3, b[9] = 5, b[10] = 6;
                        a[10] = 3, a[11] = 3, b[11] = 9, b[12] = 3;
                        a[12] = 4, a[13] = 4, b[13] = 4, b[14] = 7;
                        a[14] = 4, a[15] = 5, b[15] = 1, b[16] = 4;
                        a[16] = 5, a[17] = 5, b[17] = 6, b[18] = 9;
                        a[18] = 5, a[19] = 6, b[19] = 3, b[20] = 6;
                        a[20] = 6, a[21] = 6, b[21] = 7, b[22] = 1;
                        a[22] = 7, a[23] = 7, b[23] = 4, b[24] = 5;
                        a[24] = 7, a[25] = 7, b[25] = 8, b[26] = 3;
                        a[26] = 8, a[27] = 8, b[27] = 6, b[28] = 6;
                        a[28] = 8, a[29] = 8, b[29] = 7, b[30] = 9;
                        a[30] = 8, a[31] = 9, b[31] = 1, b[32] = 2;
                        a[32] = 9, a[33] = 9, b[33] = 7;
                       
                        i = j = 34;
                        while (j != 100) {
                                a[j] = b[j] = 0;
                                j++;
                        }
                        break;
		case 5:
			                             b[0] = 1;	             
			a[0] = 1, a[1] = 1, b[1] = 2, b[2] = 3;
                        a[2] = 1, a[3] = 1, b[3] = 7, b[4] = 1;
                        a[4] = 2, a[5] = 2, b[5] = 3, b[6] = 4;
                        a[6] = 2, a[7] = 2, b[7] = 5, b[8] = 8;
                        a[8] = 2, a[9] = 3, b[9] = 3, b[10] = 5;
                        a[10] = 3, a[11] = 3, b[11] = 6, b[12] = 1;
                        a[12] = 4, a[13] = 4, b[13] = 4, b[14] = 7;
                        a[14] = 4, a[15] = 4, b[15] = 8, b[16] = 1;
                        a[16] = 5, a[17] = 5, b[17] = 9, b[18] = 2;
                        a[18] = 6, a[19] = 6, b[19] = 3, b[20] = 6;
                        a[20] = 6, a[21] = 6, b[21] = 9, b[22] = 4;
                        a[22] = 7, a[23] = 7, b[23] = 5, b[24] = 7;
                        a[24] = 7, a[25] = 8, b[25] = 2, b[26] = 5;
                        a[26] = 8, a[27] = 8, b[27] = 6, b[28] = 7;
                        a[28] = 8, a[29] = 8, b[29] = 9, b[30] = 3;
                        a[30] = 9, a[31] = 9, b[31] = 7, b[32] = 8;
                        a[32] = 9, a[33] = 9, b[33] = 9;
                      	i = j = 34;
                        while (j != 100) {
                                a[j] = b[j] = 0;
                                j++;
                        }
                        break;
	}
	return i;
}
int checkcomp(){
	int i, j, k = 0, s = 0;
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			if(sudoko.a[i][j] == sudoko.c[i][j])
				k++;
			else if(sudoko.a[i][j] == 0){
				s++;
			}
			else
				printf("Wrong values for position (%d,%d)\t correct value is %d\n", i, j, sudoko.c[i][j]);
		}
	}
	if(k == 81)
		printf("congratulations, sudoko complete\n");
	if(s >= 1)
		printf("please complete sudoko\n");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sudoko.h"
int answer1(){
	int i, j, x = 0, y;
	time_t t;
	int p[10], q[10], r[10];
	srand((unsigned)time(&t));
	while(x == 0){
		x = rand() % 10;
	}
	for(i = 1; i < 4; i++){
		for(j = 1; j < 4; j++){
			sudoko.c[i][j] = x;
			x++;
			if(x > 9)
				x = 1;
		}
	}
	for(i = 1; i < 4; i++){/*copying elements from a 3*3 matrix to  particular array*/
		if(i == 1){/*first row */
			for(j = 1; j < 4; j++){
				p[j] = sudoko.c[i][j];
			}
		}
		else if(i == 2){/*second row*/
			for(j = 1; j < 4; j++){
				q[j] = sudoko.c[i][j];
			}
		}
		else if(i == 3){/*third row*/
			for(j = 1; j < 4; j++){
				r[j] = sudoko.c[i][j];
			}
		}
	}
	for(i = 1; i < 4; i++){/*completing first three rows*/ 
		if(i == 1){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(i == 2){
			y = 1;
			for(j =4; j < 7; j++){
				sudoko.c[i][j] = r[y];
			 	y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(i == 3){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	for(j = 1; j < 4; j++){
		if(j == 1){
			for(i = 1; i < 4; i++){
				p[i] = sudoko.c[i][j];
			}
		}
		else if(j == 2){
			for(i = 1; i < 4; i++){
				q[i] = sudoko.c[i][j];
			}
		}
		else if(j == 3){
			for(i = 1; i < 4; i++){
				r[i] = sudoko.c[i][j];
			}
		}
	}
	for(j = 1; j < 4; j++){
		if(j == 1){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(i =7; i < 10; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(j == 2){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		} 
		else if(j == 3){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = q[y];	
				y++;
			}
		}
	}
	/*now from coloumn 3 to 6*/
	for(j = 4; j < 7; j++){
		if(j == 4){
			for(i = 1; i < 4; i++){
				p[i] = sudoko.c[i][j];
			}
		}
		else if(j == 5){
			for(i = 1; i < 4; i++){
				q[i] = sudoko.c[i][j];
			}
		}
		else if(j == 6){
			for(i = 1; i < 4; i++){
				r[i] = sudoko.c[i][j];
			}
		}
	}
	/*completing first three columns by addding them to main matrix*/
 	for(j = 4; j < 7; j++){
		if(j == 4){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(j == 5){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(j == 6){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	/*for column 7th to 10*/
	for(j = 7; j < 10; j++){
		if(j == 7){
			for(i = 1; i < 4; i++){
				p[i] = sudoko.c[i][j];
			}
		}
		else if(j == 8){
			for(i = 1; i < 4; i++){
				q[i] = sudoko.c[i][j];
			}
		}
		else if(j == 9){
			for(i = 1; i < 4; i++){
				r[i] = sudoko.c[i][j];
			}
		}
	}
	/*completing first three column of matrix*/
	for(j = 7; j < 10; j++){
		if(j == 7){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(j == 8){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(j == 9){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	return 0;
}
int answer2(){
	int i, j, x = 0, y;
	time_t t;
	int p[10], q[10], r[10];
	srand((unsigned)time(&t));
	while(x == 0){
		x = rand() % 10;
	}
	for(j = 1; j < 4; j++){
		for(i = 1; i < 4; i++){
			sudoko.c[i][j] = x;
			x++;
			if(x > 9)
				x = 1;
		}
	}
	for(j = 1; j < 4; j++){
		if(j == 1){
			for(i = 1; i < 4; i++){
				p[i] = sudoko.c[i][j];
			}
		}
		else if(j == 2){
			for(i = 1; i < 4; i++){
				q[i] = sudoko.c[i][j];
			}
		}
		else if(j == 3){
			for(i = 1; i < 4; i++){
				r[i] = sudoko.c[i][j];
			}
		}
	}
	for(j = 1; j < 4; j++){
		if(j == 1){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(j == 2){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(j == 3){
			y = 1;
			for(i = 4; i < 7; i++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(i = 7; i < 10; i++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	for(i = 1; i < 4; i++){
		if(i == 1){
			for(j = 1; j < 4; j++){
				p[j] = sudoko.c[i][j];
			}
		}
		else if(i == 2){
			for(j = 1; j < 4; j++){
				q[j] = sudoko.c[i][j];
			}
		}
		else if(i == 3){
			for(j =1; j < 4; j++){
				r[j] = sudoko.c[i][j];
			}
		}
	}
	for(i = 1; i < 4; i++){
		if(i == 1){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(i == 2){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(i == 3){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	/*column from 3 to 6*/ 
	for(i = 4; i < 7; i++){
		if(i == 4){
			for(j = 1; j < 4; j++){
				p[j] = sudoko.c[i][j];
			}
		}
		else if(i == 5){
			for(j = 1; j < 4; j++){
				q[j] = sudoko.c[i][j];
			}
		}
		else if(i == 6){
			for(j = 1; j < 4; j++){
				r[j] = sudoko.c[i][j];
			}
		}
	}
	for(i = 4; i < 7; i++){
		if(i == 4){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = q[y];	
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(i == 5){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(i == 6){	
			y = 1;	
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	/*column from 7 to 10*/
	for(i = 7; i < 10; i++){
		if(i == 7){
			for(j = 1; j < 4; j++){
				p[j] = sudoko.c[i][j];
			}
		}
		else if(i == 8){
			for(j = 1; j < 4; j++){
				q[j] = sudoko.c[i][j];
			}
		}
		else if(i == 9){
			for(j = 1; j < 4; j++){
				r[j] = sudoko.c[i][j];
			}
		}
	}
	for(i = 7; i < 10; i++){
		if(i == 7){	
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
		}
		else if(i == 8){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = r[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
		}
		else if(i == 9){
			y = 1;
			for(j = 4; j < 7; j++){
				sudoko.c[i][j] = p[y];
				y++;
			}
			y = 1;
			for(j = 7; j < 10; j++){
				sudoko.c[i][j] = q[y];
				y++;
			}
		}
	}
	return 0;
}   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main(void){
	int green[5][5]; // array to track green letters in the all game
	int yellow[5][5]; // array to track yellow letters in the all game
	char user_word[5];
	char chosen_word[5]="blind"; //choose your word from here
	char screen[5][5]={"_____","_____","_____","_____","_____"};
	int i,j,z,game_finish=0,counter=0,game_win=0,counter_letter=0,counter_letter2=0;
	for ( i = 0; i < 5; i++){
		for ( j = 0; j < 5; j++){
			green[i][j] = -1;
			yellow[i][j] = -1; 
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c ",screen[i][j]);
		}
		printf("\n");
	}
	while(counter<5 && game_win==0){
		
		
		game_win=1;
		do{
			printf("type a 5 letter word: ");
			scanf("%s",user_word);
			for(i=0;i<5;i++){
				screen[counter][i]=user_word[i];
			}
		}while(strlen(user_word)!=5);
		printf("\n");
		
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(user_word[i]==chosen_word[j]){
					if(i==j){
						green[counter][i]=0;
					}
				}
			}
		}
			
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(user_word[i]==chosen_word[j]){
					if((i!=j) && (green[counter][i]== -1))
       					 yellow[counter][i]=0;
				}
			}
		}
		system("cls");
		system("");
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(green[i][j]!=-1){
					printf("\x1b[0;32m%c\x1b[0m ",screen[i][j]);
				}
				else if(yellow[i][j]!=-1){
					printf("\x1b[0;33m%c\x1b[0m ",screen[i][j]);
				}
				else{
					printf("%c ",screen[i][j]);
				}
			}
			printf("\n");	
		}
		for(i=0;i<5;i++){
			if(green[counter][i]==-1){
				game_win=0;
			}
		}
		counter++;
		
	}	
}	
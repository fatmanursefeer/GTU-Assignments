/*
** hw8_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw8_lib.h"

/* I COULD NOT DO THIS PART SO I TAKE COMMENT LINE THIS PART.
int is_element(char word, char *words_to_delete[WORDSIZE], int n){
	int ans;
	if(words_to_delete[0] == word) ans = TRUE;
	else{
		ans = is_element(word, &words_to_delete[n][1]);
	}
	return ans;
} 

int ayni_mi(char *str, char *words_to_delete[WORDSIZE]){
	int ans;
	if(!is_element(str[0], words_to_delete);
}

char * birlestir(char *kelime, char *str){
	char buff[20];
	if(kelime[0] == ' ')
		str[0] = '\0';
	else
		spritnf(str, "%c%s", kelime[0], birlestir(buff, &kelime[1]);
	return(str);
}

void delete_words(FILE* infid, FILE* outfid, char* words_to_delete[WORDSIZE],  int number_of_words)
{
	char kelime[500], str[20];
	int i=0, j=0, k, a, b=0;
	fgets(kelime, 500, infid);
	if(i == number_of_words)
		i=0;
	else{
		birlestir(kelime, str);
		k = ayni_mi(str, words_to_delete);
		if(k != 1)
			fprintf(outfid, "%s", str);
}


void clean_file(char* infile, char * outfile, char* words_to_delete[WORDSIZE], int number_of_words)
{
	FILE* infid;
	FILE* outfid;
	infid = fopen(infile, "r+");
	outfid = fopen(outfile, "w+");
	if(infid == NULL || outfid == NULL){
		printf("ERROR FILE CAN NOT OPEN\n");
		exit(1);
	}	
	delete_words(infid, outfid, words_to_delete, number_of_words);
	fclose(infid);
	fclose(outfid);
}
*/

void print_maze(cell_type maze[][8], int i, int j){  /* This recursive function print the current maze */
	if((i < 8) && (j < 8)){  /* Since the maze 8x8 */
		if(j == 7){
			printf("%d ", maze[i][j]);  /* prints */
			j = -1;  /* Because I send the j like j+1 */
			i++;
			printf("\n");
			print_maze(maze, i, j+1);
		}
		else{
			printf("%d ", maze[i][j]);  /* prints */
			print_maze(maze, i, j+1);
		}
	}
}


void maze_current_location(cell_type maze[][8], cell_type player, int *x, int *y, int i, int j){  /* This recursive function finds the location of the player */
	if(maze[i][j] == player){  /* Returns values if finds location */
		*x = i;
		*y = j;
	}
	else{
		if((j < 8) && (i < 8)){  /* Since the maze 8x8 */
			if(j == 7){
				j = -1;  /* Because I send the j like j+1 */
				i++;
			}
			maze_current_location(maze, player, x, y, i, j+1);
		}
	}
}


int maze_move(cell_type maze[][8], cell_type player, move_type move)
{
	int x, y, result;
	maze_current_location(maze, player, &x, &y, 0, 0);  /* I created this function to find out where the player is */
	if(move == move_left){  /* If the move equal left this place works */
		if(y > 0){   /* This condition controls whether the player can go in that direction */
			switch(maze[x][y-1]){
				case cell_free:  /* If the destination is empty, the move is executed and the player's place is updated. */
					maze[x][y] = cell_free;
					maze[x][y-1] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x, y-1);  /* update */
					printf("\nWHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): "); /* Again asked the user to which direction do she wants */
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_wall:  /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
					print_maze(maze, 0, 0);   /* printing current maze */
					printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_target:  /* If the destination is target, the move is executed and the player's place is updated. And the game is finish */
					maze[x][y] = cell_free;
					maze[x][y-1] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x, y-1);
					result = 1;
					break;
			}
		}
		else{  /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
			print_maze(maze, 0, 0);  /* printing current maze */
			printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
			scanf("%u", &move);
			maze_move(maze, player, move);
		}
	}
	else if(move == move_right){  /* If the move equal right this place works */
		if(y < 7){  /* This condition controls whether the player can go in that direction */
			switch(maze[x][y+1]){
				case cell_free:  /* If the destination is empty, the move is executed and the player's place is updated. */
					maze[x][y] = cell_free;
					maze[x][y+1] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x, y+1);  /* update */
					printf("\nWHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");  /* Again asked the user to which direction do she wants */
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
			
				case cell_wall:   /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
					print_maze(maze, 0, 0);   /* printing current maze */
					printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_target:  /* If the destination is target, the move is executed and the player's place is updated. And the game is finish */
					maze[x][y] = cell_free;
					maze[x][y+1] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x, y+1);
					result = 1;
					break;
			}
		}
		else{   /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
			print_maze(maze, 0, 0);  /* printing current maze */
			printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
			scanf("%u", &move);
			maze_move(maze, player, move);
		}
	}
	else if(move == move_up){   /* If the move equal up this place works */
		if(x > 0){  /* This condition controls whether the player can go in that direction */
			switch(maze[x-1][y]){
				case cell_free:   /* If the destination is empty, the move is executed and the player's place is updated. */
					maze[x][y] = cell_free;
					maze[x-1][y] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x-1, y);  /* update */
					printf("\nWHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");  /* Again asked the user to which direction do she wants */
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_wall:  /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_target:  /* If the destination is target, the move is executed and the player's place is updated. And the game is finish */
					maze[x][y] = cell_free;
					maze[x-1][y] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x-1, y);
					result = 1;
					break;
			}
		}
		else{   /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
			print_maze(maze, 0, 0);   /* printing current maze */
			printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
			scanf("%u", &move);
			maze_move(maze, player, move);
		}
	}
	else if(move == move_down){   /* If the move equal down this place works */
		if(x < 7){  /* This condition controls whether the player can go in that direction */
			switch(maze[x+1][y]){
				case cell_free:  /* If the destination is empty, the move is executed and the player's place is updated. */
					maze[x][y] = cell_free;
					maze[x+1][y] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x+1, y);  /* update */
					printf("\nWHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");  /* Again asked the user to which direction do she wants */
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_wall:  /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
					scanf("%u", &move);
					maze_move(maze, player, move);
					break;
				case cell_target:  /* If the destination is target, the move is executed and the player's place is updated. And the game is finish */
					maze[x][y] = cell_free;
					maze[x+1][y] = player;
					print_maze(maze, 0, 0);  /* printing current maze */
					printf("\nCurrent location: (%d,%d)", x+1, y);
					result = 1;
					break;
			}
		}
		else{   /* If the destination is not empty, a warning messaje is written to user and asket again which direction she wants to move */
			print_maze(maze, 0, 0);  /* printing current maze */
			printf("\nYOU CAN NOT MOVE IN THAT DIRECTION. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
			scanf("%u", &move);
			maze_move(maze, player, move);
		}
	}
	else{  /* If the move number is not correct printing an error message. */
		print_maze(maze, 0, 0);  /* printing current maze */
		printf("\nYOU ENTER WRONG NUMBER. WHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN): ");
		scanf("%u", &move);
		maze_move(maze, player, move);
	}
	return result;  /* And the end return the solve or not. */
}

/* I COULD NOT DO THIS PART SO I TAKE COMMENT LINE THIS PART.
void printing_steps(int step[], int buff){
	/* This function prints the towers one by one 
	if(step[buff] == 0){  /* if array value equals to 0 
		printf("                    ");
	}
	else if(step[buff] == 1){  /* if array value equals to 1 
		printf("        *****        \n");
		printf("        * 1 *        \n");	
	}
	else if(step[buff] == 2){  /* if array value equals to 2 
		printf("       *******       \n");
		printf("       *  2  *       \n");
	}
	else if(step[buff] == 3){  /* if array value equals to 3 
		printf("      *********      \n");
		printf("      *   3   *      \n");
	}
	else if(step[buff] == 4){  /* if array value equals to 4 
		printf("     ***********     \n");
		printf("     *    4    *     \n");
	}
	else if(step[buff] == 5){  /* if array value equals to 5 
		printf("    *************    \n");
		printf("    *     5     *    \n");
	}
	else if(step[buff] == 6){  /* if array value equals to 6 
		printf("   ***************   \n");
		printf("   *      6      *   \n");
	}
	else if(step[buff] == 7){  /* if array value equals to 7 
		printf("  *****************  \n");
		printf("  *       7       *  \n");
	}
	else{  /* and the bottom of the towers 
		printf(" ******************* ");
	}	
}

void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n)
{
	int i, j=1;
	/* In addition I create integer arrays and used these values when sending to function. 
    	int s_arr[8] = {0,0,0,0,0,0,0,8};  /* Because number of tower would be max 7 
    	int e_arr[8] = {0,0,0,0,0,0,0,8};
    	int a_arr[8] = {0,0,0,0,0,0,0,8};
    	for(i = 7-n; i<7; i++){  /* I filled the array by the value of n 
    		s_arr[i] = j;
    		j++;
    	}
    	rec_toh(s_arr, e_arr, a_arr, s_arr, e_arr, a_arr, n);  /* Called the recursive function 
    	print_step(s_arr, e_arr, a_arr);  /* Finally prints the final step 
}
*/

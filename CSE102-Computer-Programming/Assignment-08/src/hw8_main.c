/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/


#include <stdio.h>
#include "hw8_lib.h"

void test_clean_file () 
{
	/*
	char words_to_delete[3][20] = {"fatma", "nur", "sefer"};
	char infile = "    ";
	char outfile = "    ";
	int number_of_words = 10;
	clean_file(infile, outfile, words_to_delete[WORDSIZE], number_of_words);
	*/
}


void test_maze_move ()
{
	int result, x, y, player; /* At first I defined the necessary variables. */
	cell_type maze[8][8] = {  /* I creared the maze manually. */
		{cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall},
		{cell_wall, cell_wall, cell_free, cell_free, cell_wall, cell_free, cell_free, cell_wall},
		{cell_wall, cell_free, cell_wall, cell_free, cell_wall, cell_free, cell_wall, cell_wall},
		{cell_wall, cell_free, cell_p1, cell_free, cell_wall, cell_free, cell_target, cell_wall},
		{cell_wall, cell_free, cell_wall, cell_p2, cell_free, cell_wall, cell_free, cell_wall},
		{cell_wall, cell_free, cell_wall, cell_wall, cell_free, cell_wall, cell_free, cell_wall},
		{cell_wall, cell_free, cell_free, cell_free, cell_free, cell_free, cell_free, cell_wall},
		{cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall, cell_wall}
	};
	cell_type cp1 = cell_p1; /* for player 1 */
	cell_type cp2 = cell_p2; /* for player 2 */
	move_type mp1;  /* for player 1 */
	move_type mp2;  /* for player 2 */
	printf("\n--------------MAZE----------------\n");
	printf("\n(0's WALL, 1's FREE, 2 IS TARGET, 3 IS PLAYER1 LOCATION, 4 IS PLAYER2 LOCATION)\n");  /* I wrote down what values represent what. */
	/*I got the inforation from the user which player she wanted to be and in addition I printed the current location of the players. */
	printf("\nWHICH PLAYER DO YOU WANT TO BE? (1 FOR PLAYER1, 2 FOR PLAYER2 (player1 location is: (3,2), player2 location is(4,3))): "); 
	scanf("%d", &player);
	/*Since the function thats prints the maze is in lib.c I could not print the maze, instead I showed the player's location and directions to go. */
	printf("\nWHICH DIRECTION DOU YOU WANT TO MOVE?(0 FOR LEFT, 1 FOR RIGHT, 2 FOR UP, 3 FOR DOWN (if you are player1 you can move left or right, if you are player2 you can move up or right): ");
	scanf("%u", &mp2);
	if(player == 1)
		result = maze_move(maze, cp1, mp1);  /* for player 1 */
	else if(player == 2)
		result = maze_move(maze, cp2, mp2);  /* for player 2 */
	if(result == 1) printf("\nYOU DID NOT SOLVE THE MAZE\n");   /* If the maze not solved */
	else printf("\nYOU SOLVED THE MAZE\n");  /*If the maze solved */
}


void test_towers_of_hanoi ()
{/* 
	int n;  /* number of towers 
	char start_peg, end_peg, aux_peg;
	printf("\n\n-----------------TOWERS OF HANOI----------------\n");
	printf("n: ");
	scanf("%d", &n);
	if((n<1) || (n>7))  /* Prints an error message if the number of towers is not within the excepted range 
		printf("You entered wrong number.");
	else 
		towers_of_hanoi(start_peg, end_peg, aux_peg, n);
	*/
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_clean_file ();
	test_maze_move ();
	test_towers_of_hanoi ();
	return (0);
} /* end main */

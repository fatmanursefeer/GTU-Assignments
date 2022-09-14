#include <stdio.h>
#include <stdlib.h>
#define N 5

void swap_array(int *x, int *y){
/*This function swapping the lements in the array.*/
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void mix_array(int array[N][N]){
/*This function randomly shuffles elements in the array. */
	int i, j, k, l;
	for(i=N-1; i>0; i--){
		for(j=N-1; j>0; j--){
			k = rand() % (i+1);
			l = rand() % (j+1);
			swap_array(&array[i][j], &array[k][l]);
		}
	}
}

void print_array(int array[N][N]){
/*This function prints the current puzzle. */
	int i, j, x, y;
/*I order the stars correctly to make the puzzle look good. */
	y = (N*5)+1;
	printf("\n");
	for(i=0; i<y; i++)
		printf("*");
	printf("\n");
	/*I printed the puzzle use for loops.*/
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			x = array[i][j];
			if(x<10)
				printf("*  %d ", array[i][j]);
			else
				printf("* %d ", array[i][j]);
		}
		printf("*\n");
	}
	for(i=0; i<y; i++)
		printf("*");
	printf("\n");
}


void move_puzzle(int array[N][N], int row, int column, int direction){
/*This funtion moves the desired piece in the desired direction.*/
	int temp=0, temp2=0, i, j, k, l;
/*Using for loops I found the empty place in the array and assign its position to k and l. */
	for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(array[i][j] == 0){
					k = i;
					l = j;
				}
			}
	}
	/*I used the switch-case construct to perform transaction operation.*/
	switch(direction){
		case 1:
			if((row == k) && (column > l)){
				/*I checked if it satisfies the condition and if it does, I performed the desired movement by sliding the elements by one by.*/
				temp = array[row][column];
				array[row][column] = array[k][l];
				column--;
				while(column >= l){
					/*Let the while loop continue until the meet the requirement */
					temp2 = array[row][column];
					array[row][column] = temp;
					temp = temp2;
					column--;
				}
			}
			else
				printf("\nCan not move in the direction you want. \n");
			break;
		case 2:
			if((row == k) && (column < l)){
				/*I checked if it satisfies the condition and if it does, I performed the desired movement by sliding the elements by one by.*/
				temp = array[row][column];
				array[row][column] = array[k][l];
				column++;
				while(column <= l){
					/*Let the while loop continue until the meet the requirement */
					temp2 = array[row][column];
					array[row][column] = temp;
					temp = temp2;
					column++;
				}
			}
			else
				printf("\nCan not move in the direction you want. \n");
			break;
		case 3:
			if((column == l) && (row > k)){
				/*I checked if it satisfies the condition and if it does, I performed the desired movement by sliding the elements by one by.*/
				temp = array[row][column];
				array[row][column] = array[k][l];
				row--;
				while(row >= k){
					/*Let the while loop continue until the meet the requirement */
					temp2 = array[row][column];
					array[row][column] = temp;
					temp = temp2;
					row--;
				}
			}
			else
				printf("\nCan not move in the direction you want. \n");
			break;
		case 4:
			if((column == l) && (row < k)){
				/*I checked if it satisfies the condition and if it does, I performed the desired movement by sliding the elements by one by.*/
				temp = array[row][column];
				array[row][column] = array[k][l];
				row++;
				while(row <= k){
					/*Let the while loop continue until the meet the requirement */
					temp2 = array[row][column];
					array[row][column] = temp;
					temp = temp2;
					row++;
				}
			}
			else
				printf("\nCan not move in the direction you want. \n");
			break;
		default:
			printf("\nYou entered wrong botton.Try again.\n");
			break;
	}
}

int solved_puzzle(int array[N][N]){
/*This function checks if the puzzle has been solved.*/
	int i, j, temp, num = 1;
/*I have assigned the last element in the array to another value so that is not deleted.*/ 
	temp = array[N-1][N-1];
	array[N-1][N-1] = 0; /*I did like that because if the puzzle solves, bottom rigth corner must be equal 0*/
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(num != array[i][j]){
				array[N-1][N-1] = temp;
				return 0; /*If the puzzle not solved function returns 0*/
			}
			num++;
		}
	}
	return 1; /*If the puzzle solved function returns 1*/
}

enum move{left=1, right=2, up=3, down=4};

int main(){
/*I initially defined the size of the 2D array as define in the beginning. And I defined the variables.*/
	int array[N][N];
	int i, j=0, k, l, num=1, sonuc, row, column, x;
	enum move direction;
/*Using the for loop I filled the array. */
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			array[i][j] = num;
			num++;
		}
	}
/*Here I set the last element of the array equal to 0. Because at the first the bottom right corner must be empty.*/ 
	array[i-1][j-1] = 0;
/*I created this function to randomly mix elements in array. */
	mix_array(array); 
	print_array(array); /*This function printing the current array. */
/* I create an infinite loop to contuinue until the user gives up or solves the puzzle. */
	while(1){
		/*I took the values to learn which place user wants to move from.*/
		printf("\nWhich location do you want to move?(If you want to gave up you enter -1 on row.)\nRow: ");
		scanf("%d", &row);
		if(row == -1){
			/*If the user gives up, user entered -1 and the program ends.*/
			printf("You give up. You could not solve the puzzle.\n");
			break;
		}
		printf("\nColumn: ");
		scanf("%d", &column);
		printf("\nWhich direction do you want to move? (1 for left, 2 for right, 3 for up and 4 for down.)\n");
		scanf("%u", &direction);
		move_puzzle(array, row, column, direction); /*This function changes the current puzzle.*/
		print_array(array);
		sonuc = solved_puzzle(array); /*This funtion checked the puzzle solve or not.*/
		if(sonuc == 1){
			printf("\nYou solved the puzzle congratulations!!\n");
			break;
		}	
	}
}

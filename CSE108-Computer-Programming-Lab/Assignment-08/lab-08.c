#include <stdio.h>

typedef struct{
	double mtrx[3][3];
	double determinant;
} matrix;


void determinant_of_matrix(matrix *initial_matrix){
	/*Here I calculated the determinant of the matrix */
	double a, b, c, d, e, f, g;
	a = initial_matrix->mtrx[0][0];
	d = ((initial_matrix->mtrx[1][1])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[1][2]) * (initial_matrix->mtrx[2][1]));
	if(c<0)
		d = d * (-1);
	b = initial_matrix->mtrx[0][1];
	e = ((initial_matrix->mtrx[1][0])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[1][2]) * (initial_matrix->mtrx[2][0]));
	if(e<0)
		e = e * (-1);
	c = initial_matrix->mtrx[0][2];
	f = ((initial_matrix->mtrx[1][0])*(initial_matrix->mtrx[2][1])) - ((initial_matrix->mtrx[1][1]) * (initial_matrix->mtrx[2][0]));
	if(f<0)
		f = f * (-1);
	g =  (a * d) - (b * e) + (c * f);
	if(g<0)
		g = g * (-1);
	initial_matrix->determinant = g;
}

void inverse_matrix(matrix *initial_matrix, matrix inverted_matrix){
	/*Here I calculated the inverse matrix*/
	double d;
	d = 1/(initial_matrix->determinant);
	inverted_matrix.mtrx[0][0] = d * ((initial_matrix->mtrx[1][1])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[1][2]) * (initial_matrix->mtrx[2][1]));
	inverted_matrix.mtrx[0][1] = d * -((initial_matrix->mtrx[1][0])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[1][2]) * (initial_matrix->mtrx[2][0]));
	inverted_matrix.mtrx[0][2] = d * ((initial_matrix->mtrx[1][0])*(initial_matrix->mtrx[2][1])) - ((initial_matrix->mtrx[1][1]) * (initial_matrix->mtrx[2][0]));
	inverted_matrix.mtrx[1][0] = d * -((initial_matrix->mtrx[0][1])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[0][2]) * (initial_matrix->mtrx[2][1]));
	inverted_matrix.mtrx[1][1] = d * ((initial_matrix->mtrx[0][0])*(initial_matrix->mtrx[2][2])) - ((initial_matrix->mtrx[0][2]) * (initial_matrix->mtrx[2][0]));
	inverted_matrix.mtrx[1][2] = d * -((initial_matrix->mtrx[0][0])*(initial_matrix->mtrx[2][1])) - ((initial_matrix->mtrx[0][1]) * (initial_matrix->mtrx[2][0]));
	inverted_matrix.mtrx[2][0] = d * ((initial_matrix->mtrx[0][1])*(initial_matrix->mtrx[1][2])) - ((initial_matrix->mtrx[0][2]) * (initial_matrix->mtrx[2][1]));
	inverted_matrix.mtrx[2][1] = d * ((initial_matrix->mtrx[0][0])*(initial_matrix->mtrx[1][2])) - ((initial_matrix->mtrx[0][2]) * (initial_matrix->mtrx[1][0]));
	inverted_matrix.mtrx[2][2] = d * ((initial_matrix->mtrx[0][0])*(initial_matrix->mtrx[1][1])) - ((initial_matrix->mtrx[0][1]) * (initial_matrix->mtrx[1][0]));
	
}


void print_matrix(matrix initial_matrix){
	/* Here I printed the matrix */
	int i, j;
	printf("\nMATRIX\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			printf("%.4lf\t", initial_matrix.mtrx[i][j]);
		printf("\n");
	}		
}

int main(){
	int i, j;
	/* Here I creat my two struct variable */
	matrix initial_matrix;
	matrix inverted_matrix;
	/*Here I fulled the matrix one by one */
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Enter the %d. row %d. column: ", i, j);
			scanf("%lf", &initial_matrix.mtrx[i][j]);
		}
	}
	print_matrix(initial_matrix); /*I send the struct my matrix to function */
	determinant_of_matrix(&initial_matrix); /*I calculate the determinant of the matrix */
	if(initial_matrix.determinant == 0) /* If determinant equal 0 then the matrix not inversing */
		printf("\nERROR DETERMINANT EQUAL 0 SO YOU CAN NOT FIND INVERSE OF MATRIX\n");
	else{
		inverse_matrix(&initial_matrix, inverted_matrix);
		print_matrix(inverted_matrix);
	}	
}

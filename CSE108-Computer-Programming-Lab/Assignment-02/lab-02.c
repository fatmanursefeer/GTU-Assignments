#include <stdio.h>
#include <math.h>


int addition_for_integer(){
	int val1, val2, val3;
	printf("Please enter the firt integer number: /n");
	scanf("%d", &val1);
	printf("Please enter the second integer number: /n");
	scanf("%d", &val2);
	val3 = val1 + val2;
	printf("Addition of the numbers: %d/n", val3);
	return 0;
}

int multiplication_for_integer(){
	int val1, val2, val3;
	printf("Please enter the firt integer number: /n");
	scanf("%d", &val1);
	printf("Please enter the second integer number: /n");
	scanf("%d", &val2);
	val3 = val1 * val2;
	printf("Multiplacition of the numbers: %d/n" val3);
	return 0;
}

int addition_for_complex(){
	int val1, val2, val3;
	printf("Please enter the firt complex number(real part first): /n");
	scanf("%d", &val1);
	scanf("%d", &val2);
	printf("Please enter the second complex number(real part first): /n");
	scanf("%d", &val3);
	scanf("%d", &val4);
	val5 = val1 + val3;
	val6 = val2 + val4;
	printf("Addition of this numbers: %d + %di/n ", val5, val6);
	return 0;
}

int multiplication_for_complex(){
	double val1, val2, val3;
	printf("Please enter the firt integer number: /n");
	scanf("%lf", &val1);
	printf("Please enter the second integer number: /n");
	scanf("%lf", &val2);
	val3 = val1 * val2;
	return val3;
}

int number_type_integer(){
	int val1;
	printf("Enter the calculation type: /n 1. Addition/n 2. Multipllication/n");
	printf("----------------------------------");
	scanf("%d", &val1);
	if(val1 == 1)
		addition_for_integer();
	else if(val1 == 2)
		multiplication_for_integer();
	else{
		printf("Please enter the correct number./n");
		return 0;
	}
}
		
double number_type_complex(){
	int val1;
	printf("Enter the calculation type: /n 1. Addition/n 2. Multipllication/n");
	printf("----------------------------------");
	scanf("%d", &val1);
	if(val1 == 1){
		addition_for_complex();
		return 0;
	}
	else if(val1 == 2){
		multiplication_for_complex();
		return 0;
	}
	else{
		printf("Please enter the correct number./n");
		return 0;
	}
}

void area_of_rectangle(double a, double b, double c, double d){
	double alan;
	alan = a*b*c*d;
	printf("Area of rectangle: %.2lf", alan);
	return 0;
}

void perimeter_of_rectangle(double a, double b, double c, double d){
	double cevre;
	cevre = a+b+c+d;
	printf("Perimeter of rectangle: %.2lf", cevre);
	return 0;
}

void perimeter_of_triangle(double a, double b, double c){
	double cevre;
	cevre = a+b+c;
	printf("Perimeter of riangle: %.2lf", cevre);
}


void area_of_rectangle(double a, double b, double c){	
	double s, alan;
	s = (a+b+c)/2;
	alan = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("Area of triangle: %.2lf", alan);
	return 0;
}

void perimeter_of_circle(double r){
	double cevre, pi = 3.14;
	cevre = 2 * pi *r;
	printf("Perimeter of circle: %.2lf", cevre);
	return 0;
}

void area_of_circle(double r){
	double alan, pi= 3.14;
	alan = pi*r*r;
	printf("Area of circle: %.2lf", alan);
	return 0;
}

	
void take_size_of_rectangle(){
	double val1, val2, val3, val4;
	printf("Please enter the size of rectangle: ");
	scanf("%lf", &val1);
	scanf("%lf", &val2);
	scanf("%lf", &val3);
	scanf("%lf", &val4);
	area_of_rectangle(double val1, double val2, double val3, double val4);
	perimeter_of_rectangle(double val1, double val2, double val3, double val4);
}

void take_size_of_triangle(){
	double val1, val2, val3;
	printf("Please enter the size of triangle: ");
	scanf("%lf", &val1);
	scanf("%lf", &val2);
	scanf("%lf", &val3);
	perimeter_of_triangle(double val1, double val2, double val3);
	area_of_triangle(double val1, double val2, double val3);
}

void take_size_of_circle(){
	double r;
	printf("Please enter the r of the circle: ");
	scanf("%lf", &r);
	perimeter_of_circle(double r);
	area_of_circle(double r);
}

void fahrenheit_to_kelvin(){
	double temp, kelvin;
	printf("Please enter the temparature: ");
	scanf("%lf", &temp);
	kelvin = ((5/9)*(temp-32)+273.15);
	printf("%.3lf", kelvin);
	return 0;
}

	

void standart_calculater(){
	int val1;
	printf("Enter the number type: /n 1. Integer/n 2. Complex/n");
	printf("----------------------------------");
	scanf("%d", &val1);
	if(val1 == 1)
		number_type_integer();
	else if(val1 == 2)
		number_type_complex();
	else{
		printf("Please enter the correct number./n");
		return 0;
	}
}
		
		
void area_perimeter_calculater(){
	int val1;
	printf("Enter the shape type: /n 1. Rectangle/n 2. Triagle/n 3. Circle/n");
	printf("----------------------------------");
	scanf("%d", val1);
	if(val1 == 1)
		take_size_of_rectangle();
	else if(val1 == 2)
		take_size_of_triangle();
	else if(val1 == 3)
		take_size_of_circle();
	else{
		printf("Please enter the correct number./n");
		return 0;
	}
}

void temperature_calculater(){
	int val1;
	printf("Enter the calculater type: /n 1. Fahrenheit to Kelvin /n 2. Kelvin to Fahrenheit /n");
	if(val1 == 1)
		fahrenheit_to_kelvin();
		



int main(){
	int val;
	printf("Enter the calculater type: /n 1. Standart Calculater/n 2. Area&Perimeter Calculater/n 3.Temperatur Calculater/n");
	printf("----------------------------------");
	scanf("%d", &val);
	if(val == 1)
		standart_calculater();
	else if(val == 2);
		area_perimeter_calculater();
	else if 
		temperature_calculater();
	else{
		printf("Please enter the correct number./n");
		return 0;
	}
		
		
		

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void die(const char * msg);
int isTriangle(double a, double b, double c);
double areaTriangle(double a, double b, double c);

int main() {
	printf("Please enter the three sides of a triangle.\n");
	double a, b, c;
	if (scanf_s("%lf%lf%lf", &a, &b, &c) != 3)  die("Input Failure.");
	if (isTriangle(a, b, c) == 1){
		printf("Area of triangle is %f.\n", areaTriangle(a, b, c));
	exit(EXIT_SUCCESS);
}
	else
		die("It is not a valid triangle.");
} // end main
void die(const char * msg) {
	printf("Fatal error %s\n", msg);
	exit(EXIT_FAILURE);
}
int isTriangle(double a, double b, double c) {
	if (((a + b) > c) && ((b + c) > a) && ((c + a) > b)) return 1;
	else                                                 return 0;
}
double areaTriangle(double a, double b, double c) {
	double s; 
	s = (a + b + c) / 2;
	return(sqrt(s * (s - a) * (s - b) * (s - c)));
}

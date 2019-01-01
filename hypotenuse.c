#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void die(const char * msg);
double hypotenuse(double side0, double side1);

int main()
{
	double side0, side1;
	printf("Please enter two legs of right triangle\n");
	if (scanf_s("%lf%lf", &side0, &side1) != 2)    die("Invalid Input");
	printf("Hypotenuse is %f\n", hypotenuse(side0, side1));
	exit(EXIT_SUCCESS);
}
void die(const char * msg) {
	printf("Fatal error %s\n", msg);
	exit(EXIT_FAILURE);
}
double hypotenuse(double side0, double side1) {
	if (side0 <= 0 || side1 <= 0)   die("Sides have to be greater than 0");
		return(sqrt(side0 * side0 + side1 * side1));
}
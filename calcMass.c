#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define c 299792458

void die(const char * msg);
double mass(double joules);

int main() {
	double joules;
	printf("Please enter the joules of energy.\n");
	if (scanf_s("%lf", &joules) != 1)                die("Invalid Input.");
	printf("Joules of energy: %f\nThat's equivalent to %f kilograms\n", joules, mass(joules));
	exit(EXIT_SUCCESS);
}
void die(const char * msg) {
	printf("Fatal error %s\n", msg);
	exit(EXIT_FAILURE);
}
double mass(double joules) {
	if (joules < 0)   die("Joules can't be negative because that means mass is negative.");
	return ((joules / c)/c); // something spooky was going on here when  had joules/(c*c) but
							 // now it is fixed
}
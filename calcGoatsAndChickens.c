#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void die(const char * msg);
unsigned chickens(unsigned heads, unsigned legs);
unsigned goats(unsigned heads, unsigned legs);

int main() {
	unsigned heads, legs;
	printf("Please enter the total number of heads and legs.\n");
	if (scanf_s("%u%u", &heads, &legs) != 2)   die("Input failure.");
	printf("heads legs %u %u\n", heads, legs); 
	if((legs % 2 != 0) || (legs > 4 * heads) || (legs < 2*heads))
		die("anatomically impossible.");
	// Number of legs can't be odd neither can be greater than 4 times the number of heads
	// because assuming if all of them were goats max legs possible = 4*heads.
	printf("That's %u chickens and %u goats.\n", chickens(heads, legs), goats(heads, legs));
	exit(EXIT_SUCCESS);
}

void die(const char * msg) {
printf("Fatal error %s\n", msg);
exit(EXIT_FAILURE);
}
unsigned chickens(unsigned heads, unsigned legs) {
	return((4 * heads - legs) / 2); // This comes out of solving the two algebra equations
}
unsigned goats(unsigned heads, unsigned legs) {
	return((legs - 2 * heads) / 2);
}
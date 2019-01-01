#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void die(const char * msg);
unsigned pages(unsigned linesPerPage, unsigned totalLines);

int main(){
	printf("Please enter the lines(between 1 and 999) that can be printed on one page "
		   "and total number of lines you want to print.\n");
	unsigned linesPerPage, totalLines;
if (scanf_s("%u%u", &linesPerPage, &totalLines) != 2)   die("Invalid Input.");
if (linesPerPage < 1 || linesPerPage > 999)				die("Too much lines on one page.");
printf("Total pages required %u\n", pages(linesPerPage, totalLines));
exit(EXIT_SUCCESS);
}
void die(const char * msg) {
	printf("Fatal error %s\n", msg);
	exit(EXIT_FAILURE);
}
unsigned pages(unsigned linesPerPage, unsigned totalLines) {
	if (totalLines % linesPerPage == 0)  return totalLines / linesPerPage;
	else								 return (totalLines / linesPerPage + 1);
}
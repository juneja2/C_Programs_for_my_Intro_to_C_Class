
#include <stdio.h>

void outputRange(unsigned lo, unsigned hi); // [lo, hi)
unsigned addRange(unsigned lo, unsigned hi); // [lo, hi)
unsigned factorial(unsigned n); // factorial(4) returns 24
unsigned fib(unsigned n); // fibonacci function of 6 is 8 
int prime(unsigned n); // returns 1 if n is 2, 3, 5, 7, ...
unsigned gcd(unsigned a, unsigned b); // greatest common divisor
void multiplicationTable(unsigned max); // output multiplication table
int main()
{ // This works but check for more data tomorrow
	outputRange(3, 7);

	unsigned a = addRange(3, 7);
	printf("%u\n", a);

	unsigned b = factorial(4);
	printf("%u\n", b);

	unsigned c = fib(4);
	printf("%u\n", c);

	int d = prime(6);
	if (d == 0) printf("%u is not a prime\n", 6);
	else printf("%u is a prime\n", 6);
	
	unsigned e = gcd(300, 110);
	printf("%u\n", e);

	multiplicationTable(12);
    return 0;
}
void outputRange(unsigned lo, unsigned hi) {
	if (lo >= hi);
	else {
		for (unsigned i = lo; i < hi; i++)
			printf("%u\n", i);
	}
}
unsigned addRange(unsigned lo, unsigned hi) {
	unsigned total = 0;
	if (lo >= hi) return 0;
	else {
		for (unsigned i = lo; i < hi; i++)
			total += i;
		return total;
	}
}
unsigned factorial(unsigned n) {
	unsigned facTorial = 1;
	if (n == 0) return facTorial;
	else if (n == 1) return facTorial;
	else {
		for (unsigned i = n; i > 1; --i)
			facTorial *= i;
		return facTorial;
	}
}
unsigned fib(unsigned n) {
	unsigned fib0 = 0;
	unsigned fib1 = 1;
	unsigned fibN = 0;
	if (n == 0) return fib0;
	else if (n == 1) return fib1;
	else {
		for (unsigned i = 2; i <= n; i++) {
			fibN = fib0 + fib1;
			fib0 = fib1;
			fib1 = fibN;
		}
		return fibN;
	}
}
int prime(unsigned n) {
	unsigned maxDivisorPossible = n / 2;
	for (unsigned i = 2; i <= maxDivisorPossible; i++)
		if (n%i == 0) return 0; // returns 0 if n is not prime
	// we check all the possible divisor and see if we get remainder equal to 0 and if it
	// does then we know that it isn't prime hence we immediately return
	return 1; // return 1 if n is prime
}
unsigned gcd(unsigned a, unsigned b) {
	if (a == 0 && b == 0) return 0;
	else if (a != 0 && b == 0) return a;
	else if (a == 0 && b != 0) return b;
	else if (a > b) return(gcd(a%b, b));
	else return (gcd(b%a, a));
}
void multiplicationTable(unsigned max) {
	if (max > 18)
		printf("Too much\n");
	else {
		printf(" *");
		for (unsigned i = 0; i <= max; i++)
			printf("%4u", i);
		printf("\n");
		for (unsigned row = 0; row <= max; row++) {
			printf("%2u", row);
			for (unsigned column = 0; column <= max; column++) {
				printf("%4u", row*column);
			}
			printf("\n");
		}
	}
}
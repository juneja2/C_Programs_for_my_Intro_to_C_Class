#include <stdio.h>
#include <stdlib.h>

unsigned sod(unsigned number);
void sort0(unsigned ar[],unsigned elements);
void sort1(unsigned ar[],unsigned elements);
int compare(const void * ptr0, const void * ptr1);
void show(unsigned ar[], unsigned elements);

int main(){
	unsigned ar[]= {1,11,19,100,300000};
	sort0(ar, 5);
	show(ar, 5);
	printf("\n");
	unsigned arr[] = {200, 1, 10, 11, 302, 1};
	sort1(arr, 6);
	show(arr, 6);

	return 0;
}
void show(unsigned ar[], unsigned elements){
	for(int i = 0; i < elements; i++)
		printf("   %u", ar[i]);
}
unsigned sod(unsigned number){
	int sumOfDigits = 0;
	while(number !=0){
		sumOfDigits += number%10;
		number /= 10;
	}
	return sumOfDigits;
}
void sort0(unsigned ar[], unsigned elements){
	for(int i = 0; i < elements-1; i++)
		for(int j = i+1; j < elements; j++)
			if(sod(ar[i]) > sod(ar[j]) ){
				unsigned temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
}
int compare(const void * ptr0, const void * ptr1){
	unsigned number0 = * (const unsigned * )ptr0;
	unsigned number1 = * (const unsigned * )ptr1;
	return sod(number0) < sod(number1) ? -1 : sod(number0) > sod(number1) ? 1 : 0;
}
void sort1(unsigned ar[],unsigned elements){
	qsort(ar, elements, sizeof(ar[0]), compare);
}
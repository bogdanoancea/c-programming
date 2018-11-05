#include<stdio.h>

int main() {
	unsigned int a, b;
	printf("Introduceti un numar intreg zecimal: ");
	scanf("%d",&a);
	printf("Introduceti un numar intreg hexazecimal: ");
	scanf("%x",&b);
	printf("\n Numarul zecimal:\tBaza 10: %u\tBaza 8: %#o\tBaza 16: %#X", a, a, a);
	printf("\n Numarul hexazecimal:\tBaza 10: %u\tBaza 8: %#o\tBaza 16: %#X", b, b, b);
	return 0;
}

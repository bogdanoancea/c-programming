#include<stdio.h>

union exemplu {
	long int a;
	char* b;
	char* c;
};

int main() {
	union exemplu x;
	printf("Spatiul ocupat de o variabila uniune: %d bytes\n", sizeof(x));
	x.a = 10;
	x.b = "ABCD";
	x.c = "EFG";
 
	printf("%ld\n", x.a);
	printf("%s\n", x.b);
	printf("%s\n", x.c);
	return 0;
}
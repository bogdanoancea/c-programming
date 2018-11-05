#include<stdio.h>

int main() {
	int n;
	float e;
	printf("Introduceti n:");
	scanf("%d", &n);
	e = (float)n / ( n + 1 );
	printf("Valoarea expresiei este: %.12f", e);
	return 0;
}
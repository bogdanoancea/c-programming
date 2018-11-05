#include<stdio.h>

int main() {
 	float x;
	int a, b;
	
	printf("Introduceti x:");
	scanf("%f", &x);
	printf("Introduceti a: ");
	scanf("%d", &a);
	printf("Introduceti b: ");
	scanf("%d", &b);
 
	( x>= a && x < b) ? printf("\nX se afla in intervalul [%d %d)", a, b) : printf("\nX nu se afla in intervalul [%d %d)", a, b);
}

#include<stdio.h>

int main() {
	float a, b, c;
	printf("Dati lungimile laturilor\n");
	printf("a=");
	scanf("%f", &a);
	printf("b=");
	scanf("%f", &b);
	printf("c=");
	scanf("%f", &c);
	
 
	if (a > 0 && b > 0 && c > 0 && a < b + c && b < a + c && c < a + b)
		printf("%4.2f, %4.2f si %4.2f formeaza un triunghi.", a, b, c);
	else
		printf ("%4.2f, %4.2f si %4.2f nu formeaza un triunghi.", a, b, c);
	
	return 0;
}


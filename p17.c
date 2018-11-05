#include<stdio.h>

int main() {
	float a, b, c;
	printf("Dati lungimile laturilor:\n");
	scanf("%f %f %f", &a, &b, &c);
 
	if (a >= 0 && b >= 0 && c >= 0 && a < b + c && b < a + c && c < a + b)
		printf("\t %4.2f, %4.2f si %4.2f formeaza un triunghi.", a, b, c);
	else
		printf ("\t Nu formeaza un triunghi.");
	
	return 0;
}


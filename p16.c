#include<stdio.h>

int main() {
	float a, b, c;
	printf("Dati lungimile laturilor:\n");
	scanf("%f %f %f", &a, &b, &c);
 
	(a >= 0 && b >= 0 && c >= 0 && a < b + c && b < a + c && c < a + b) ? printf("\t %4.2f, %4.2f si %4.2f formeaza triunghi.", a, b, c):printf ("\t Nu formeaza triunghi.");
	return 0;
}


#include <math.h>
#include<stdio.h>

int main() {
	double x, y, z; 
 
	printf("\nIntroduceti numarul: ");
	scanf("%lf", &x);
	printf("\nAti introdus x= %.2lf", x);
 
	printf("\n\nIntroduceti puterea: ");
	scanf("%lf", &y);
	printf("\nAti introdus y= %.2lf", y);
 
	z = pow(x, y);
 
	printf("\n\%.2lf^%.2lf= %.2lf", x, y, z); 
	return 0;
}


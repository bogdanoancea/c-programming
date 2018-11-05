#include <stdio.h>
#include <math.h>

int main (void) {
	int a, b, c;
	float x1, x2, d;
	printf("Introduceti coeficientii ecuatiei.\n");
	printf("\ta="); 
	scanf("%d",&a);
	printf("\tb="); 
	scanf("%d",&b);
	printf("\tc="); 
	scanf("%d",&c);
	
	if( !a ) //a==0
		if( !b )
			if( !c )
				printf("Ecuatia are o infinitate de solutii.");
			else
				printf("Ecuatia nu are nici o solutie.");
		else {
			x1 = -c / (float)b;
			printf("Solutia ecuatiei este: %.2f.", x1);
		}
	else {
		d = b * b - 4 * a * c;
		printf("%f", sqrt(d));
		if(d < 0)
			printf("Ecuatia nu are solutii reale.");
		else {
			x1 = ( -b - sqrt(d)) / ( 2 * a );
			x2 = ( -b + sqrt(d)) / ( 2 * a );
			printf("Solutiile sunt:\n\tx1= %.2f\n", x1);
			printf("\tx2=: %.2f\n", x2);
		}
	}
	return 0;
}


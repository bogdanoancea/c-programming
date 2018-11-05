#include<stdio.h>

int main() {
	double x;
	int y;	/*pentru partea intreaga*/
	double z; 	/*pentru partea zecimala*/
	
	printf("Introduceti x:");
	scanf("%lf", &x);
 
	printf("x= %g\t", x);
	printf("[x]= %d\t", y = x);
	printf("{x}= %f\t", z = x - y);
 
	printf("e=%g\n", 5 * x * y - 3 * z + 15);
	return 0;
}

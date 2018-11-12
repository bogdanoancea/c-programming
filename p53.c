#include<stdio.h>
#include<math.h>

void listf (double (*fp)(double), double min, double max, double pas) { 
	double x, y;
	for(x = min; x <= max; x += pas) {
		y = (*fp)(x);
		printf ("\n%20.10lf %20.10lf", x, y);
	}
}

int main() {
	float min, max, pas;
	printf("Introduceti valoarea minima:");
	scanf("%f", &min);
	printf("Introduceti valoarea maxima:");
	scanf("%f", &max);
	printf("Introduceti pasul:");
	scanf("%f", &pas);
	printf("\nFunctia sin");
	listf(sin, min, max, pas);
	printf("\nFunctia cos");
	listf(cos, min, max, pas);
	printf("\n");
	return 0;
}
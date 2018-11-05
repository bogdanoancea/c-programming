#include<stdio.h>

float media (int x, int y) {
	float ma;
	ma = ( x + y ) / 2.0;
	return ma;
} 

int main () {
	int a, b;
	float m;
	printf("Introduceti a: ");
	scanf("%d", &a);
	printf("Introduceti b: ");
	scanf("%d", &b);
	m = media(a, b);
	printf("Media aritmetica este: %f\n", m);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int suma (int x, int y) {
	int s;
	s = x + y;
	return s;
}

int main() {
	int a, b, c;
	printf("Introduceti a: "); 
	scanf("%d",&a);
	printf("Introduceti b: "); 
	scanf("%d",&b);
	c = suma(a, b);
	printf("Suma este: %d\n", c);
	return 0;
}

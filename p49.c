#include<stdio.h>

void swap(int* a, int* b);

int main() {

	int x;
	int y;
 
	printf("Introduceti x: ");
	scanf("%d", &x); 
	printf("Introduceti y: ");
	scanf("%d", &y);
 
	printf("\nInainte de interschimbare: \n");
	printf("x = %d\ty = %d \n", x, y);
	swap(&x, &y);
	printf("\nDupa de interschimbare: \n");
	printf("x = %d\ty = %d \n", x, y); 
	return 0;
}

void swap(int* a, int* b) {
	int c;
	c = *b;
	*b = *a;
	*a = c;
}
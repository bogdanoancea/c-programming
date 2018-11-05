#include<stdio.h>

int main() {
	int x, y;
	printf("Introduceti x: ");
	scanf("%d", &x);
	printf("Introduceti y: ");
	scanf("%d", &y);
 
	printf("\n Maximul este: %d\n", x > y ? x : y);
	printf("\n Minimul este: %d\n", x < y ? x : y);
	return 0;
}
#include<stdio.h>

int main() {
	int n, s = 0, i;

	printf("n= ");
	scanf("%d", &n);
 
	for(i = 1; i <= n; i++)
		s += i * i;
 
	printf("Suma este egala cu: %d", s);
	return 0;

}
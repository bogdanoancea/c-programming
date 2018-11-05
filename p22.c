#include<stdio.h>

int main() {
 	int i, n, s = 0;
 	printf("Introduceti n:");
 	scanf("%d",&n);
 	for(i = 1; i <= n; i++)
		s += i;   //s=s+i;
	printf("Suma primelor %d numere naturale este: %d\n", n, s);
	return 0;
}

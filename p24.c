#include<stdio.h>

int main() {
	int n, s = 0, i = 1;
	
	printf("Introduceti n:");
	scanf("%d",&n);
 
	do {
		s += i;   //s=s+i;
		i++;
	} while(i <= n );
	printf("Suma primelor %d numere naturale este: %d\n", n, s);
	return 0;
}
#include<stdio.h>

int main() {
	int n, s = 0, i = 1;
	printf("Introduceti n:");
	scanf("%d",&n);
 
	while(i<=n) {
		s += i;   //s=s+i;
		i++;
	}
	printf("Suma primelor %d numere naturale este: %d\n", n, s);
	return 0;
}
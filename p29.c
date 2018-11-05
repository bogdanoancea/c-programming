#include<stdio.h>

int main() {
	int n;
	int s = 0;
	int p = 1;
	int i;

	printf("Introduceti n:");
	scanf("%d", &n);
 
	for(i = 1; i <= n; i++) {
		p = p * i;
		s = s + p;
	}
	printf("Rezutatul este: %d", s);
	return 0;
 } 
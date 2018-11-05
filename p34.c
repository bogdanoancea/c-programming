#include<stdio.h>

int factorial(int n) {
	int i, p = 1;

	for(i = 1; i <= n; i++)
		p *= i;
	
	return p;
}

int main() {
	int m, i, s = 0;
	printf("\nIntroduceti numarul: ");
	scanf("%d", &m);
	for(i = 1; i <= m; i++)
		s += factorial(i);

	printf("\tSuma este: %d", s);
	return 0;
}


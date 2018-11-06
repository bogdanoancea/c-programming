#include<stdio.h>

int produs1(int n) { //cu instructiunea FOR
	int i, p = 1;
	for(i = 1; i <= n; i++)
		p = p * i;
	return p;
}

int produs2(int n)	{ //cu instructiunea WHILE
	int p = 1, i = 1; 
	while(i <= n) {
		p = p * i;
		i++;
	}
	return p;
}

int produs3(int n) { //cu instructiunea DO WHILE
	int p = 1, i = 1; 
	do {
		p = p * i;
		i++;
	} while (i <= n);
	return p;
}

int main() {
	int n; 
	printf("Introduceti n: ");
	scanf("%d", &n);
	printf("\nProdusul calculat cu FOR are valoarea: %d.\n" , produs1(n));
	printf("\nProdusul calculat cu WHILE are valoarea: %d.\n" , produs2(n));
	printf("\nProdusul calculat cu DO WHILE are valoarea: %d.\n" , produs3(n));
	return 0;
}

#include<stdio.h>

int produs1(int n) { //cu instructiunea FOR
	int i, P = 1;
	for(i = 1; i <= n; i++)
		P = P * i;
	return P;
}

int produs2(int n)	{ //cu instructiunea WHILE
	int P = 1, i = 1; 
	while(i <= n) {
		P = P * i;
		i++;
	}
	return P;
}

int produs3(int n) { //cu instructiunea DO WHILE
{
	int P = 1, i = 1; 
	do {
		P = P * i;
		i++;
	} while (i <= n);
	return P;
}

int main() {
	int n; 
	printf("Introduceti n: ");
	scanf("%d", &n);
	printf("\n\tProdusul calculat cu FOR are valoarea: %d.\n" , produs1(n));
	printf("\n\tProdusul calculat cu WHILE are valoarea: %d.\n" , produs2(n));
	printf("\n\tProdusul calculat cu DO WHILE are valoarea: %d.\n" , produs3(n));
	return 0;
}
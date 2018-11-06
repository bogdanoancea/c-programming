#include <stdio.h>

int suma1(int n){	//cu instructiunea FOR 
	int s = 0, i, semn = 1;
	for(i = 1; i <= n; i++) {
		s += semn * i;	//s=s+semn*i
		semn = -semn;
	}
	return s;
}
 
int suma2(int n) {	//cu instructiunea WHILE
	int s = 0, i = 1, semn = 1;
	while ( i <= n ) {
		s += semn * i;	//s=s+semn*i
		semn = -semn;
		i++;
	}
	return s;
}
 
int suma3(int n) {	//cu instructiunea DO WHILE
	int s = 0, i = 1, semn = 1;
	do {
		s += semn * i;	//s=s+semn*i
		semn = -semn;
		i++;
	}
	while (i <= n );
	return s;
}
 
int main() {
	int n;
	printf("Introduceti n:");
	scanf("%d", &n);
 
	printf("\nSuma calculata cu FOR are valoarea: %d" , suma1(n));
	printf("\nSuma calculata cu WHILE are valoarea: %d" , suma2(n));
	printf("\nSuma calculata cu DO WHILE are valoarea: %d" , suma3(n));
	return 0;
}

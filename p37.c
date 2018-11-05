#include<stdio.h>

int main() {
	int n, s = 0;

	printf("n= ");
	scanf("%d", &n);
	
	while (n != 0) {
		s += n % 10;
		n = n / 10;
	}
	printf("Suma cifrelor este: %d", s);
	return 0;
}

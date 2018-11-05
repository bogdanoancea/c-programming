#include<stdio.h>

int main() {
	int n, p = 1;
	printf("Introduceti n:");
	scanf("%d", &n);
	printf("2^%d=%d", n, p = ( p << n ) );
	return 0;
}
 
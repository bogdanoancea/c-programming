#include<stdio.h>

int main() {
	int n, i, p = 1;

	printf("Introduceti n: ");
	scanf("%d", &n);

	for(i = 2; i <= n; i++) {
		if ( ! ( i % 2 ) )	//se mai putea scrie if(i%2==0)
			p *= i;		
	}
 	printf("Produsul este: %d", p);
	 return 0;
}

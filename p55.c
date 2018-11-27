#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i;
	int *a;
 
	printf("n = "); 
	scanf("%d", &n); /* Dimensiunea vectorului */

	a = malloc(n * sizeof(int));

	printf("Introduceti componentele vectorului: \n");

	for (i = 0; i < n; i++) {
		printf("a[%d]=",i);
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) { /* Afisarea vectorului */
		printf("a[%d]= %d\n", i, a[i]);
	}

	free(a); /* Eliberam memoria alocata dinamic */

	return 0;
}
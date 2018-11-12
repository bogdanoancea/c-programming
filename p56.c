#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, i, j;
	int **mat; /* Adresa matricei */

	/* Se citesc dimensiunile matricei */
	printf("introduceti numarul de linii n = ");
	scanf("%d", &n);

	printf("introduceti numarul de coloane m = ");
	scanf("%d", &m);


	/* Se aloca spatiu pentru matrice */
	mat = malloc(n * sizeof(int *));

	for (i = 0; i < n; i++) {
		mat[i] = calloc(m, sizeof(int));
	}

	/*Se seteaza valorile elementelor*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (i == j)
				mat[i][j] = 1;
		}
	}

	/* Afisarea matricei */
	for (i = 0; i < n; i++) {
		for (j = 0;j < m; j++) {
			printf("%6d", mat[i][j]);
		}
		printf("\n");
	}
 
	/* elberarea memoriei */
	for (i = 0; i < n; i++) {
		free(mat[i]);	
	}
	free(mat);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

void citeste(int **mat, int n, int m);
void afiseaza(int **mat, int n, int m);
int** aduna_matrici(int** mat1, int** mat2, int n, int m);

int main () {

	int n, m;
	int i, j;
	int **A, **B, **C;

	printf("Introduceti numarul de linii n = ");
	scanf("%d", &n);

	printf("Introduceti numarul de coloane m = ");
	scanf("%d", &m);
	
	A = (int **) malloc( n * sizeof(int *));
	if(A == NULL) {
		printf("memorie insuficienta\n");
		exit(1);
	}
	
	for(i = 0; i < m; i++) {
		A[i] = malloc( m * sizeof(int));
		if(A[i] == NULL) {
			printf("memorie insuficienta\n");
			exit(1);
		}
	}

	B = (int **) malloc( n * sizeof(int *));
	if(B == NULL) {
		printf("memorie insuficienta\n");
		exit(1);
	}

	for(i = 0; i < m; i++) {
		B[i] = malloc( m * sizeof(int));
		if(B[i] == NULL) {
			printf("memorie insuficienta\n");
			exit(1);
		}
	}

	printf("Introduceti elementele matricei A\n");
	citeste(A, n, m);
	printf("Introduceti elementele matricei B\n");
	citeste(B, n, m);

	printf("\nMatricea A este:\n");
	afiseaza(A, n, m);
	printf("\nMatricea B este:\n");
	afiseaza(B, n, m);

	printf("\nMatricea C=A+B este:\n");	
	C = aduna_matrici(A, B, n, m);
	afiseaza(C, n, m);
	
	return 0;
}

void citeste(int **mat, int n, int m) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			printf("mat[%d][%d] = ", i, j);
			scanf("%d", mat[i] + j); // echivalent scanf("%d", &mat[i][j])
		}
}

void afiseaza(int **mat, int n, int m){
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%8d", mat[i][j]);
		}
		printf("\n");
	}
}

int** aduna_matrici(int** mat1, int** mat2, int n, int m) {
	int** result;
	int i, j;

	result = (int **) malloc( n * sizeof(int *));
	if(result == NULL) {
		printf("memorie insuficienta\n");
		exit(1);
	}
	for(i = 0; i < m; i++) {
		result[i] = malloc( m * sizeof(int));
		if(result[i] == NULL) {
			printf("Memorie insuficienta");
			exit(1);
		}
	}
	for(i = 0; i < n; i++)
		for( j = 0; j < m; j++)
			result[i][j] = mat1[i][j] + mat2[i][j];
		
	return result;
}

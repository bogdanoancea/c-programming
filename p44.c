#include<stdio.h>
#define N 10
#define M 5

int citeste_nr_linii(int nr_max);
int citeste_nr_coloane(int nr_max);
void citeste(int a[][M], int n, int m);
int suma(int a[][M], int n, int m);

int main() { 
	int a[N][M];	
	int m, n;       /* numarul real (la citire) de randuri, respectiv, de coloane, ale matricei */
	int i, j;
	int s;
	
	n = citeste_nr_linii(N);
	m = citeste_nr_coloane(M);
	//introducerea elementelor matricei
	printf("Introduceti elementele matricei: \n");
	citeste(a, n, m);
	s = suma(a, n, m);
	printf("\nSuma elementelor este: %d", s);
	return 0;
}

int citeste_nr_linii(int nr_max) {
	int n;
	
	do {
		printf("\nIntroduceti numarul de linii (<=10):");
		scanf("%d", &n);
	} while (n < 0 || n > nr_max);
	return n;
}

int citeste_nr_coloane(int nr_max) {
	int n;
	
	do {
		printf("\nIntroduceti numarul de coloane (<=5):");
		scanf("%d", &n);
	} while (n < 0 || n > nr_max);
	return n;
}

void citeste(int a[][M], int n, int m) {
	int i, j;
	
	for(i = 0; i < n; i++)
		for(j = 0 ; j < m; j++) {
			printf("Elementul [%d,%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
}

int suma(int a[][M], int n, int m) {
	int s = 0;
	int i, j;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			s += a[i][j];
	return s;
}

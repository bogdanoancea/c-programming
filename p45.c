#include<stdio.h>
#define N 5
#define M 4

void citeste(int a[][M], int n, int m);
void afiseaza(int a[][M], int n, int m);
float media(int a[][M], int n, int m);
int suma_poz(int a[][M], int n, int m);
int suma_neg(int a[][M], int n, int m);
int suma_linie(int a[][M], int n, int m, int i);
int suma_coloana(int a[][M], int n, int m, int j);
void interschimb_linii(int a[][M], int n, int m, int i, int j);
void interschimb_coloane(int a[][M], int n, int m, int i, int j);


int main() { 
	int a[N][M];	
	int m, n;       /* numarul real (la citire) de randuri, respectiv, de coloane, ale matricei */
	int i, j;
	int s;
	//introducerea elementelor matricei
	printf("Introduceti elementele matricei: \n");
	citeste(a, N, M);
	afiseaza(a, N, M);
	printf("\nMedia elementelor matricei este: %f", media(a, N, M));
	printf("\nSuma elementelor pozitive este: %d", suma_poz(a, N, M));
	printf("\nSuma elementelor negative este: %d", suma_neg(a, N, M));
	printf("\nSuma elementelor de pe linia %d este: %d", 3, suma_linie(a, N, M, 3));
	printf("\nSuma elementelor de pe coloana %d este: %d", 1, suma_coloana(a, N, M, 1));
	interschimb_linii(a, N, M, 2, 3);
	printf("\nDupa interschimbarea liniilor matricea este:\n");
	afiseaza(a, N, M);
	interschimb_coloane(a, N, M, 1, 2);
	printf("\nDupa interschimbarea coloanelor matricea este:\n");
	afiseaza(a, N, M);
	return 0;
}

void citeste(int a[][M], int n, int m) {
	int i, j;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			printf("a[%d,%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void afiseaza(int a[][M], int n, int m) {
	int i, j;
	
	printf("\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("a[%d,%d]= %d\t", i, j, a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

float media(int a[][M], int n, int m) {
	int i, j;
	int s = 0;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			s += a[i][j];
	}
	return (float) s / (n * m);
}

int suma_poz(int a[][M], int n, int m) {
	int i, j;
	int sp = 0;
	printf("\n");
	
	for(i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			if(a[i][j] > 0) 
				sp += a[i][j];
	return sp;
}

int suma_neg(int a[][M], int n, int m) {
	int i, j;
	int sn = 0;
	
	for(i = 0; i < n; i++) 
		for (j = 0; j < m; j++)
			if(a[i][j] < 0)
				sn += a[i][j];
	return sn;
}

int suma_linie(int a[][M], int n, int m, int i) {
	int j;
	int s = 0;
	for(j = 0; j < m; j++)
		s += a[i-1][j];
	return s;
}

int suma_coloana(int a[][M], int n, int m, int j) {
	int i;
	int s = 0;
	for(i = 0; i < n; i++)
		s += a[i][j-1];
	return s;
}

void interschimb_linii(int a[][M], int n, int m, int i, int j) {
	int k;
	int t;
	
	for(k = 0; k < m; k++) {
		t = a[j - 1][k];
		a[j - 1][k] = a[i - 1][k];
		a[i - 1][k] = t;
	}
}

void interschimb_coloane(int a[][M], int n, int m, int i, int j) {
	int k;
	int t;
	
	for(k = 0; k < n; k++) {
		t = a[k][j];
		a[k][j - 1] = a[k][i - 1];
		a[k][i - 1] = t;
	}
}

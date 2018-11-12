#include<stdio.h>

void citeste(int a[][4], int n, int m) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			printf("Elem [%d,%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void afiseaza(int a[][4], int n, int m) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

int main() { 
	int a[5][4];
	int i, j;
	citeste(a, 5, 4);
	afiseaza(a, 5, 4);
	return 0;
}

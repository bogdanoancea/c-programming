#include<stdio.h>

#define MAX 30

/* cauta pe x în vectorul v */
int gasit(int *v, int n, int x) {
  int m = 0, i;
  
  for(i = 0; i < n; i++)
     if ( *(v + i) == x)  return i;
  return -1;
}


void citire(int* v, int n) {
	int i;
	
	for(i = 0; i < n; i++) {
		printf("\na[%d]=", i);
		scanf( "%d", v + i  );
	}
}

void afisare(int* v, int n) {
	int j;
	
	printf("Elementele vectorului sunt:"); 
	for(j = 0; j < n; j++)
		printf ("%5d", v[j]);
	printf("\n");
}

int main () { 
	int a[MAX]; /* vectorul initial */
	int b[MAX]; /* vectorul cu elemente distincte */
	int n, m, i, j;
	printf("Numarul de elemente ale vectorului n="); 
	scanf("%d", &n); 
	printf ("Introducere %d numere intregi:\n", n);
	citire(a, n);

	m = 0;
	for(i = 0; i < n; i++)
		if(gasit(b,m,a[i])==-1) 
			b[m++] = a[i];
 
	afisare(b, m);
	return 0; 
}

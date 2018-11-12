#include <stdio.h>
#include <stdlib.h>


void citire(int* x,int n) { //n este dimensiunea reala a sirului
	int i;
	for( i = 0; i < n; i++) {
		printf("\nElementul %d: ", i);
		scanf("%d", &x[i]);
	}
}

void afisare(int* x,int n) {
	if(n > 1)
		afisare(x, n - 1); 
	printf("%d ", x[n - 1]);
}

int suma(int* x, int n) {
	if(n == 1) 
		return x[0]; 
	else 
		return x[n - 1] + suma(x, n - 1);
}

int produs(int* x,int n) {
	if(n == 1) 
		return x[0];
	else 
		return x[n - 1] * produs(x, n - 1);
}

int numar_negative(int* x, int n) {
	if(n == 1) 
		return (x[0] < 0 ? 1 : 0); 
	else 
		return (x[n - 1] < 0 ? 1 : 0) + numar_negative(x, n - 1);
}

int produs_negative(int* x, int n) {
	if(n == 1) 
		return (x[0] < 0 ? x[0] : 1); 
	else 
		return (x[n - 1] < 0 ? x[n - 1] : 1) * produs_negative(x, n - 1);
}

int suma_negative(int* x, int n) {
	if(n == 1) 
		return (x[0] < 0 ? x[0] : 0); 
	else 
		return (x[n - 1] < 0 ? x[n - 1] : 0) + suma_negative(x, n - 1);
}


int numar_pozitive(int* x,int n) {
	if(n==1) 
		return (x[0] > 0 ? 1 : 0); 
	else 
		return (x[n-1] > 0 ? 1 : 0) + numar_pozitive(x,n-1);
}


int produs_pozitive(int* x,int n) {
	if(n == 1) 
		return (x[0] > 0 ? x[0]: 1); 
	else 
		return (x[n-1] > 0 ? x[n-1] : 1) * produs_pozitive(x, n-1);
}

int suma_pozitive(int* x,int n) {
	if(n == 1) 
		return (x[0] > 0 ? x[0] : 0); 
	else 
		return (x[n-1] > 0 ? x[n-1] : 0) + suma_pozitive(x, n-1);

}
int main() {
	int* x; 
	int n; 
 
	
	printf("Introduceti numarul de elemente: ");
	scanf("%d",&n);
	
	x = (int*) malloc(sizeof(int) *n);
	if( x == NULL) {
		puts("Eroare la alocare memoriei!");
		exit(1);
	}
	printf("Introduceti elementele sirului:\n");
	citire(x,n);
 
	printf("Vectorul este: ");
	afisare(x,n);
 
	
	printf("\nSuma elementelor este: %d",suma(x,n)); 
	
	printf("\nProdusul elementelor: %d",produs(x,n));

	printf("\nNumarul elementelor negative: %d",numar_negative(x,n));
	
	printf("\nProdusul elementelor negative: %d", produs_negative(x,n));
	
	printf("\nSuma elementelor negative: %d", suma_negative(x,n));
	
	printf("\nNumarul elementelor pozitive: %d",numar_pozitive(x,n));
	
	printf("\nProdusul elementelor pozitive: %d", produs_pozitive(x,n));
	
	printf("\nSuma elementelor pozitive: %d", suma_pozitive(x,n));

	return 0;
}

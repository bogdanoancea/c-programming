#include<stdio.h>

int main() {
	/* a este o locatie de memorie pentru elemente de 
	tip int pe care am initializat-o cu valoarea 1 */
	int a = 1;
	
	/* b este o variabila pointer spre tipul int, capabila a 
	retine adrese ale altor variabile de tipul specificat */
	int* b;

	/* in adresa b retinem adresa locatiei de memorie 
	(adica a variabilei) a, deci b devine adresa locatiei de memorie a */
	b = &a;
	
	printf("Val a= %d\t Val b= %d\n\n", a, *b);
	printf("Adresa a= %p\t Adresa punctata de b= %p", &a, b);
	
	return 0;
}

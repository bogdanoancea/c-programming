#include<stdio.h>

int main() {
	
	/*a este o locatie de memorie pentru elemente de 
	tip int pe care am initializat-o cu valoarea 1 */
	int a = 1;

	/*b este o locatie de memorie pentru elemente de 
	tip int pe care am initializat-o cu valoarea 1 */
	int b = 55;
 
	/* p este o variabila pointer spre tipul int, 
	adica capabila a retine adrese ale altor variabile de tipul int */
	int *p;

	//initializam pointerul
	/* in p retinem adresa locatiei de memorie (adica a variabilei) b,  
	deci p devine adresa locatiei de memorie b */
	p = &b;

	printf("a= %d\t b= %d\t *p= %d \n\n", a, b, *p);

	/* transferul se face intre valori, valorii retinute la adresa
	b ii atribuim valoarea retinuta in a */
	*p = a;
	
	printf("a= %d\t b= %d\t *p= %d \n\n", a, b, *p);
	return 0;
}


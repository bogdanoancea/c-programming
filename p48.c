#include<stdio.h>


int main() {
	int *a, *b, *c;
	int x;
	int y;
 
	a = &x;	//initializam a
	b = &y;	//initializam b
	
	printf("Introduceti a: ");
	scanf("%d", a); /* atentie la modul in care am scris scanf */
	printf("Introduceti b: ");
	scanf("%d", b);
 
	printf("\nInainte de interschimbare: \n");
	
	printf("\tx= %d\ty= %d \n\n", *a, *b);
	printf("\tAdresa x= %p\tAdresa y= %p\n", a, b);
 
	//interschimbarea
	c = a;
	a = b;
	b = c;
 
	printf("\nDupa interschimbare: \n");
	
	printf("\tx= %d\ty= %d\n\n", *a, *b);
	printf("\tAdresa x= %p\tAdresa y= %p\n", a, b);
	return 0;
}

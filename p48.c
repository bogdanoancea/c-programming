#include<stdio.h>


int main() {
	int *a, *b, *c;
	int x;
	int y;
 
	a = &x;	//initializam a
	b = &y;	//initializam b
	
	printf("Introduceti a: ", a);
	scanf("%d", a); /* atentie la modul in care am scris scanf */
	printf("Introduceti b: ", b);
	scanf("%d", b);
 
	printf("\nInainte de interschimbare: \n");
	
	printf("\ta= %d\tb= %d \n\n", *a, *b);
	printf("\tAdresa a= %p\tAdresa b= %p\n", a, b);
 
	//interschimbarea
	c = a;
	a = b;
	b = c;
 
	printf("\nDupa interschimbare: \n");
	
	printf("\ta= %d\tb= %d\n\n", *a, *b);
	printf("\tAdresa a= %p\tAdresa b= %p\n", a, b);
	return 0;
}

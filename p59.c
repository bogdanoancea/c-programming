#include<stdio.h>

int main() {
	char lin[128]; // linii de maxim 128 car
	int nl = 0;
	
	printf("Introduceti un text:\n");
	while ( gets (lin) != NULL) { // citire linie in lin
		++nl; // incrementeaza numarul de linii
		printf ("%d: %s \n", nl, lin); // scrie numar si continut linie
	}
	return 0;
}
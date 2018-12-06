#include <stdio.h>
#include<string.h>

int main () {
	char linie[128], *cuv; // adresa cuvant in linie
	char *sep = ".,;\t\n "; // sir de caractere separator
	puts("Introduceti o linie de text:");
	gets(linie); // citire linie
	cuv = strtok(linie, sep); // primul cuvant din linie
	puts("Cuvintele introduse sunt:");
	while ( cuv != NULL ) {
		puts(cuv); // scrie cuvant
		cuv = strtok(NULL, sep); // urmatorul cuvant din linie
	}
	return 0;
}
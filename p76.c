#include <stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 1200

int main(int argc, char** argv) {
	FILE* pf;
	int nr_cuv = 0;
	int nr_chars = 0;
	char buf[MAX];
	char* p;
	if(argc != 2) {
		puts("Mod de utilizare: p76.exe nume_fisier");
		exit(1);
	}

	pf = fopen(argv[1], "rt");

	if (pf == NULL) {
		puts("Eroare deschidere fisier");
		exit(1);
	}

	while( fgets(buf, MAX, pf) != NULL) {
		p = strtok(buf, " \n");
		while (p != NULL) {
			nr_cuv++;
			nr_chars += strlen(p);
			//printf("%s",p);
			p = strtok(NULL, " \n");
		}
	}
	printf("Numarul de cuvinte este: %d\n", nr_cuv);
	printf("Numarul de caractere este: %d\n", nr_chars);
	return 0;
}

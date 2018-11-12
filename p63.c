#include<stdio.h>
#include<string.h>

int main() {
	int k = 0;
	char txt[1024]; //sir introdus de utilizator
	char* p;

 	printf("Introduceti un sir de caractere si apoi apasati Enter\n");
	gets(txt); 

	p = strtok(txt, " ");
	while(p != NULL) {
		p = strtok(NULL, " ");
		k++;
	} 
	printf("\nNumarul de cuvinte este: %d",k); 
	return 0;
}

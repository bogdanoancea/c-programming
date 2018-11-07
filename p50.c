#include<stdio.h>

int main() {
	
	int a[] = {1, 2, 3, 4, 5}; //a retine un sir de caractere, in numar de 5
	int* b;
	int i;
	
	b = a;
	for(i = 0; i < 5; i++) {
		printf("%d\t", *b); 
		b++;
	}
 
	b -= 5;
	printf("\nprimul element este: %d\n", *b);
	b += 3;
	printf("\nal patrulea element este: %d",*b);
	return 0;
}

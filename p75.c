#include<stdio.h>
#include<stdlib.h>

 
int main(int argc, char** argv) {
	FILE *fp;

	if(argc != 2) {
		puts("Modul de utilizare: p75.exe nume_fisier");
		exit(1);
	}
	
	fp = fopen(argv[1], "r");	
 
	if(fp == NULL) {		
		printf ("Eroare la deschidere fisier!");
		exit(1);
	 }
 
	 int x, n; 			
	 int sumaImpar = 0;
     int sumaPar = 0;
 
	while( !feof(fp) ) {
		n = fscanf(fp,"%d", &x);
		if(n == 0) {
			printf("n=%d\n", n);
			printf("x=%d\n", x);
			puts("Eroare citire numar!");
			exit(1);
		}
		else 
			if(feof(fp))
				break;
        if(x % 2 == 0)
        	sumaPar = sumaPar + x;
        if(x % 2 != 0)
        	sumaImpar = sumaImpar + x;
	}
	fclose(fp);
	printf("sumaImpar este: %d\n", sumaImpar);
	printf("sumaPar este: %d\n", sumaPar);
}
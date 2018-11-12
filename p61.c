#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LUNG 81 //lungime maxima cuvant
#define NR 15 // numar maxim de cuvinte citite

void citire_cuv( char tab_cuv[][LUNG], int *nr_cuv ) {
	printf( "Se introduc maxim %d cuvinte pe cate un rand separat, terminate cu CTRL/Z:\n", NR );
	while(*nr_cuv < NR && gets ( tab_cuv[*nr_cuv] ) )
		(*nr_cuv)++;
}

void cuv_max( char tab_cuv[][LUNG], int nr_cuv ){
	int i, lung_crt, lung_max = 0;
	char * p_max;
	/* pointerul spre cuvantul maxim */
	/* se poate memora indicele cuvantului de lungime maxima: int i_max;
	sau chiar cuvantul de lungime maxima: char c_max[LUNG]; */
	for(i = 0; i < nr_cuv; i++)
		if ( ( lung_crt = strlen(tab_cuv[i]) ) > lung_max){
			p_max = tab_cuv[i];
			lung_max = lung_crt;
		}
	printf ("Cuvantul de lungime maxima %d este: %s\n", lung_max, p_max);
}
	
void cuv_vocale( char tab_cuv[][LUNG], int nr_cuv ){
	int i;
	puts("Cuvintele ce incep cu vocale:");
	for(i = 0; i < nr_cuv; i++)
		switch(toupper(tab_cuv[i][0])){
			case 'A': 
			case 'E': 
			case 'I': 
			case 'O': 
			case 'U':
			puts(tab_cuv[i]);
		}
}

int main(){
	char tab_cuv[NR][LUNG]; //vectorul de cuvinte
	int nr_cuv = 0; // numarul cuvintelor introduse
	citire_cuv(tab_cuv, &nr_cuv);
	cuv_max(tab_cuv, nr_cuv);
	cuv_vocale(tab_cuv, nr_cuv);
	return 0;
}


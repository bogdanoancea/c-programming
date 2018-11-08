#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define DIM_MAX 50

struct angajat {
	int cod_angajat;
	char* nume;
	char* prenume;
	struct {
		int an;
		int luna;
		int zi;
	} data_angajarii;
	float sal_incadrare;
};

void citeste(struct angajat* p, int dim) {
	int i;
	for(i = 0; i < dim; i++) {
		printf("\nIntroduceti cod angajat:");
		scanf("%d", &p[i].cod_angajat);
		printf("\nIntroduceti nume angajat:");
		scanf("%49s", p[i].nume);
		printf("\nIntroduceti prenume angajat:");
		scanf("%49s", p[i].prenume);
		printf("\nIntroduceti data angajarii:");
		printf("\nAn:" );
		scanf("%d", &p[i].data_angajarii.an);
		printf("\nLuna:" );
		scanf("%d", &p[i].data_angajarii.luna);
		printf("\nZi:" );
		scanf("%d", &p[i].data_angajarii.zi);
		printf("\nIntroduceti salariul:");
		scanf("%f", &p[i].sal_incadrare);
	}
}

void afiseaza(struct angajat* p, int dim) {
	int i;
	for(i = 0; i < dim; i++) {
		printf("\n===========================");
		printf("\nCod angajat:%d", p[i].cod_angajat);
		printf("\nNume angajat:%s", p[i].nume);
		printf("\nPrenume angajat:%s", p[i].prenume);
		printf("\nAnul angajarii:%d", p[i].data_angajarii.an);
		printf("\nLuna angajarii:%d", p[i].data_angajarii.luna);
		printf("\nZiua angajarii:%d", p[i].data_angajarii.zi);
		printf("\nSalariul de incadrare:%f", p[i].sal_incadrare);
	}
	printf("\n");
}

float sal_mediu(struct angajat* p, int dim) {
	int i; 
	float sum = 0;
	for(i = 0; i < dim; i++) {
		sum +=p[i].sal_incadrare;
	}
	return sum/dim;
}


int main() {
	int i, n;
	struct angajat *v;
	
	
	printf("Introduceti numarul de angajati:");
	scanf("%d", &n);
	/* se aloca dinamic memorie */
	v = (struct angajat *) malloc (n * sizeof( struct angajat));
	for(i = 0; i < n; i++) {
		v[i].nume = (char*)malloc(DIM_MAX * sizeof(char));
		v[i].prenume = (char*)malloc(DIM_MAX * sizeof(char));
	}
	
	citeste(v, n);
	printf("Salariul mediu pe angajat este: %f", sal_mediu(v,n));
	afiseaza(v,n);
	
	/* inaintea terminarii programului avem grija sa eliberam memoria alocata dinamic */
	for(i = 0; i < n; i++) {
		free(v[i].nume);
		free(v[i].prenume);
	}
	free(v);
	return 0;
}

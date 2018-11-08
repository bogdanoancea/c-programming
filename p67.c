#include<stdio.h>

typedef struct {//declarare structura 
	char marca[20];
	char model[20];
	char culoare[20];
	int an;
	struct {//definire structura
		char nr_locuri;
		int putere;
	} info; //lista variabile la structura
} automobil;  //nume structura

typedef automobil masini[20];	//tip de date propriu - vector de 20 de automobile

void citire(masini a, int *n) {	//introducere date. Atentie cum este transmis n - numarul de automobile
	int i;
	printf("Dati nr. de automobile (cel mult 20): ");
	scanf("%d",n);
	for(i=0; i < *n; i++) {
		printf("Introduceti datele despre automobilul %d\n", i + 1);
		printf("\tMarca: ");
		scanf("%s", a[i].marca);
		printf("\tModelul: ");
		scanf("%s", a[i].model);
		printf("\tCuloarea: ");
		scanf("%s", a[i].culoare);
		printf("\tAnul fabricatiei: ");
		scanf("%d", &a[i].an);
		printf("\tNumarul de locuri: ");
		scanf("%d", &a[i].info.nr_locuri);
		printf("\tPuterea (in cai putere): ");
		scanf("%d", &a[i].info.putere);
	}
}
 
void afisare(masini a,int n){ //afisare date
	int i;
	 for (i = 0; i < n; i++) {
		printf("Automobil [%d]:\n", i + 1);
		printf("\tMarca:     %s\n", a[i].marca);
		printf("\tModelul:   %s\n", a[i].model);
		printf("\tCuloarea:  %s\n", a[i].culoare);
		printf("\tAnul fabricatiei: %d\n", a[i].an);
		printf("\tNr. locuri: %d\n", a[i].info.nr_locuri);
		printf("\tPuterea:   %d\n\n", a[i].info.putere);
	 }
}

/*afiseaza masinile fabricate intr-un anumit an */
void an(masini a,int n,int p) {
	int i;
	for(i = 0;i < n; i++) {
		 if(a[i].an == p) {
			printf("Automobil [%d]:\n",i + 1);
			printf("\tMarca:     %s\n", a[i].marca);
			printf("\tModelul:   %s\n", a[i].model);
			printf("\tCuloarea:  %s\n", a[i].culoare);
			printf("\tAn fabricatie:  %d\n", a[i].an);
			printf("\tNr. locuri: %d\n", a[i].info.nr_locuri);
			printf("\tPuterea:   %d\n\n", a[i].info.putere);
		 }
	}
}

int main() {
	masini a;
	int n, i, j, p;
	automobil aux;
	citire(a, &n);
	afisare(a, n);
	
	/* afisarea automobilelor cu 4 locuri */
	printf("Afisare automobile cu 4 locuri\n");	
	for(i = 0; i < n; i++) { 
		if(a[i].info.nr_locuri == 4) {
			printf("Automobil [%d]:\n", i + 1);
			printf("\tMarca:     %s\n", a[i].marca);
			printf("\tModelul:   %s\n", a[i].model);
			printf("\tCuloarea:  %s\n", a[i].culoare);
			printf("\tAn fabricatie: %d\n", a[i].an);
			printf("\tNr. locuri: %d\n", a[i].info.nr_locuri);
			printf("\tPuterea:   %d\n\n", a[i].info.putere);
		}
	}

	/* sortare automobile dupa puterea motorului */
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++) {
			if(a[i].info.putere > a[j].info.putere) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	printf("Afisare automobile sortate dupa puterea motorului\n");
	afisare(a,n);
	printf("\n\tDati anul dupa care vor fi afisate masinile: ");
	scanf("%d",&p);
	an(a,n,p);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int nr_matricol;
	char nume[30];
	char prenume[30];
	float media;
} student;

void creare_fisier(char* fn) {
	FILE* f;
	student s;
	f = fopen(fn, "wb");
	if (f == NULL) {
		printf("Eroare la crearea fisierului\n");
		exit(1);
	}
	printf("Introduceti numarul matricol sau -1 pentru terminare:");
	scanf("%d", &s.nr_matricol);
	while (s.nr_matricol != -1) {
		printf("Introduceti numele:");
		scanf("%s", s.nume);
		printf("Introduceti prenumele:");
		scanf("%s", s.prenume);
		printf("Introduceti media:");
		scanf("%f", &s.media);
		fwrite(&s, sizeof(s), 1, f);
		printf("Introduceti numarul matricol sau -1 pentru terminare:");
		scanf("%d", &s.nr_matricol);
	}
	fclose(f);
}

void adaugare_student(char* fn) {
	FILE* f;
	student s;
	f = fopen(fn, "ab");
	if(f == NULL) {
		printf("Nu s-a reusit deschiderea fisierului\n");
		exit(1);
	}
    printf("Introduceti numarul matricol sau -1 pentru terminare:");
	scanf("%d", &s.nr_matricol);
	while (s.nr_matricol != -1) {
		printf("Introduceti numele:");
		scanf("%s", s.nume);
		printf("Introduceti prenumele:");
		scanf("%s", s.prenume);
		printf("Introduceti media:");
		scanf("%f", &s.media);
		fwrite(&s, sizeof(s), 1, f);
		printf("Introduceti numarul matricol sau -1 pentru terminare:");
		scanf("%d", &s.nr_matricol);
	}
	fclose(f);
}

void listare_fisier(char* fn) {
	FILE * f;
	student s;
	int nr_articole;
	f = fopen(fn,"rb");
	if(f == NULL) {
		printf("Nu s-a reusit deschiderea fisierului\n");
		exit(1);
	}
	nr_articole = fread(&s, sizeof(s), 1, f);
	while (nr_articole == 1) {
        printf("\n=============================");
		printf("\nNr matricol: %d", s.nr_matricol);
		printf("\nNume: %s", s.nume);
		printf("\nPrenume: %s", s.prenume);
		printf("\nMedia: %f", s.media);
		nr_articole = fread(&s, sizeof(s), 1, f);
	}
	fclose (f);
}

int main() {
	char nf[64];
	printf("Introduceti numele fisierului unde se vor salva informatiile despre studenti:");
	scanf("%s", nf);
	creare_fisier(nf);
	printf("\nListare studenti\n");
	listare_fisier(nf);
	printf("\nAdaugare noi studenti\n");
	adaugare_student(nf);
	printf("\nListare studenti\n");
	listare_fisier(nf);
	return 0;
}

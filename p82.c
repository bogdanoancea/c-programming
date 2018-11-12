#include<stdio.h>
#include<stdlib.h>
#define MAX 1200

void inversare(FILE* in, FILE* out) {
	char s[MAX];
    char* ret;
	if ( (ret = fgets(s, MAX, in))!= NULL) {
        inversare(in, out);
	}
	if(ret != NULL)
        fputs(s, out);
}

void inversare_linii(char* f_in, char* f_out) {
	FILE *in, *out;

	in = fopen(f_in, "rt");
	if(in == NULL) {
		printf("Nu se poate deschide fisierul %s ", f_in);
		exit(1);
	}
	out = fopen(f_out, "wt");
	if(out == NULL) {
		printf("Nu se poate deschide fisierul %s ", f_out);
		exit(1);
	}
	inversare(in, out);
	fclose(in);
	fclose(out);
}

int main(int argc, char** argv) {
	if(argc != 3) {
		puts("Modul de folosire a programului: p82.exe fisier_intrare fisier_iesire");
		exit(1);
	}
	inversare_linii(argv[1], argv[2]);
	return 0;
}

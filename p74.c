#include <stdio.h>

#define MAX 1200

int main(int argc, char **argv) {
        FILE * pf;
        char buffer [MAX];

        if(argc != 2) {
        	puts("Modul de folosire al programului: p74.exe nume_fisier");
        }
        pf = fopen(argv[1] , "r");
        if (pf == NULL)
        	fprintf(stderr, "Eroare! Nu am putut deschide fisierul %s!\n", argv[1]);
        else {
            while (fgets(buffer, MAX, pf) != NULL) {
            	fputs(buffer, stdout);
            }
            fclose(pf);
        }
        return 0;
}

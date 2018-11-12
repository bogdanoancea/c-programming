#include <stdio.h>
#include <stdlib.h>

#define MAX 1200

int main(int argc, char *argv[]) {
        FILE *dest, *src;
        int i;
        char buffer[MAX];
        
        if(argc < 4) {
        	puts("Mod de utilizare al programului: p73.exe fisier_dest fisier_sursa1 fisier_sursa2 ...");
        	exit(1);
        }
        
        dest = fopen(argv[1], "w");
        if (!dest) 
        	fprintf(stderr, "Eroare! Nu am putut deschide fisierul destinatie!\n");

        for (i = 2; i < argc; ++i) {
                src = fopen(argv[i], "r");
                               
                if (!src) 
                	fprintf(stderr, "Eroare! Nu am putut deschide fisierul sursa (%d)!\n", i);
                
                while (fgets(buffer, MAX, src) != NULL)
                        fputs(buffer, dest);
                fclose(src);
        }

        fclose(dest);
        return 0;
}
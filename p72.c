#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {
	FILE *src, *dest;
	int c;
	if(argc != 3) {
		puts("Mod de utilizare: p72.exe src_file dest_file");
		exit(1);
	}
	src = fopen(argv[1], "r");
	dest = fopen(argv[2], "w");
	if( src == NULL || dest == NULL) {
		printf("Eroare deschidere fisiere\n");
		exit(1);
	}
	while( (c = fgetc(src)) != EOF)
		fputc(c, dest);
	fclose(src); 
	fclose(dest);
	return 0;
}

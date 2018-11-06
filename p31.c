#include<stdio.h>

int main() {
	int c = 0; // numarul de consoane
	int v = 0; // nummarul de vocale
	
	char k;
 
	printf("Introduceti textul dorit: ");
 
	k = getchar(); //citeste un carater

	while ( k != '.' && k != '\n') {
		if ( k != ',' && k != ' ')
			switch (k) {
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U': v++;
						break;
				default: c++;
			}
		k = getchar(); //urmatorul caracter din text 
	}
	printf("\nNumarul de vocale este: %u", v);
	printf("\nNumarul de consoane este: %u", c);
	return 0;
}

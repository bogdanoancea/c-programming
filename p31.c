#include<stdio.h>

int main() {
	int v = 0;
	int c = 0;
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
	printf("Numarul de vocale este: %u\n", v);
	printf("Numarul de consoane este: %u\n", c);
	return 0;
}

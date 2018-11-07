#include<stdio.h>

int main() {
	int v = 0;
	int c = 0;
	char k;
	
	printf("Introduceti textul dorit: ");
	
	do {
		k = getchar();
		if ( k != ',' && k !=  ' ' && k != '\n' && k != '.')
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
	} while (k != '.' && k != '\n');
 
	printf("Numarul de vocale este %u\n", v);
	printf("Numarul de consoane este %u\n", c);
	return 0;
}

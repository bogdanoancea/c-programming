#include <stdio.h>
#include <stdlib.h>

int strlen( char *s){
	int lg = 0;
	while (s[lg] != '\0')
		lg++;
	return lg;
}

int strcmp( char *s1, char *s2){
	int i;
	for(i = 0; s1[i] || s2[i]; i++)
		if (s1[i] < s2[i])
			return -1;
		else
			if (s1[i] > s2[i])
				return 1;
	return 0;
}

char *strcpy( char *d, char *s){
	int i = 0;
	while(s[i]){
		d[i] = s[i];
		i++;
	}
	d[i] = '\0'; // sau d[i]=0;
	return d;
}

char *strcat(char *d, char *s){
	int i = 0, j = 0;
	while(d[i]) 
		i++;
	/* la iesirea din while, i este indicele caracterului cu rol de terminator de sir*/
	while(d[i++] = s[j++]);
	return d;
}

int main() {
	char s1[80];
	char s2[80];
	int cmp;
	
	printf("Introduceti primul sir:");
	gets(s1);
	printf("Introduceti al doilea sir:");
	gets(s2);
	cmp = strcmp(s1,s2);
	if(cmp == 0) 
		printf("\n Cele doua siruri sunt identice");
	else 
		if (cmp > 0 )
			printf("\n Al doilea sir este din pdv lexicografic inaintea primului");
		else
			printf("\n Primul sir este din pdv lexicografic inaintea celui de-al doilea");
		
	printf("\n Lungimea primului sir este: %d", strlen(s1));
	printf("\n Lungimea celui de-al doilea sir este: %d", strlen(s2));

	char *copy = (char*)malloc(strlen(s1));
	copy = strcpy(copy, s1);
	printf("\n Copia primului sir: ");
	puts(copy);
	
	char* concat = (char*) malloc(strlen(s1) + strlen(s2));
	concat[0] = 0;
	concat = strcat(concat, s1);
	concat = strcat(concat, s2);
	printf("\n Cele doua siruri concatenate: ");
	puts(concat);

	return 0;
}
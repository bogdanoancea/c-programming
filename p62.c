#include <stdio.h>
#include <string.h>

#define N 81

int main(void){
	char s1[N], s2[N], s3[N], rez[N];
	char *ps1 = s1, *pos, *r = rez;

	puts("sirul s1:"); 
	gets(s1);
	puts("subsirul s2:"); 
	gets(s2);
	puts("s3:"); 
	gets(s3);
	while ( pos = strstr(ps1, s2) ){
		while(ps1 < pos) 
			*r++ = *ps1++; //copiez în r din s1 pana la pos
		strcpy(r, s3); //copiez în r pe s3
		r += strlen(s3); //sar peste s3 copiat în r
		ps1 += strlen(s2); //sar în s1 peste s2
	}
	strcpy(r, ps1); //adaug ce a mai ramas din s1
	puts("sirul rezultat:");
	puts(rez);
	return 0;
}
#include <stdio.h> 
#include <stdlib.h> 

#define N 5
 
int citire1(int tab[]) { 
	int i = 0;
	
	printf("Introduceti elementele tabloului:\n");
	while(scanf("%d", &tab[i]) != EOF) 
		i++;
	return i;
} 
void tiparire1(int *tab, int n) { 
	int i;
	
	printf("Elementele tabloului:\n");
	for(i = 0; i < n; i++)
		printf("%d ", tab[i]);
	printf("\n"); 
}

int citire2(int tab[]) { 
	int *pi;
	
	pi = tab;
	printf("Introduceti elementele tabloului:\n");
	while(scanf("%d", pi) != EOF) 
		pi++;
	return pi - tab;
}

void tiparire2(int tab[], int n) { 
	int *pi;
	
	printf("Elementele tabloului:\n");
	for (pi = tab; pi < tab + n; pi++)
		printf("%d ", *pi);
	printf("\n");
}

int main() {
	int tab1[N], tab2[N], n, m;
	
	n = citire1(tab1); 
	tiparire1(tab1,n); 
	m = citire2(tab2); 
	tiparire2(tab2,m); 
	return 0;
}
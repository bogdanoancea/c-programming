#include<stdio.h>

int main() {
	int a[20];	/*am declarat un vector de maxim 20 de elememnte de tipul int cu numele a */
 
	/* introducem numarul de elemente din vector */
	int n;
	int i;
	printf("Dati nr de elemente (<=20): ");
	scanf("%d", &n);
 
	//introducem elementele
	printf("Introduceti elementele vectorului\n");
	for(i = 0; i < n; i++) {
		printf("\t a[%d]= ", i + 1);
		scanf("%d", &a[i]);
	}
 
	/* afisam elementele vectorului */
	printf("Elementele vectorului sunt: ");
	for(i = 0; i < n; i++)
		printf("%d \t", a[i]);
	
	printf("\n");
	return 0;
}


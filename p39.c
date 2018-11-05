#include<stdio.h>

int main() {
	int a[20];	/*am declarat un sir de max 20 de elem. de tipul int cu numele a */
 
	/* introducem numarul de elemente din sir */
	int n;
	int i;
	printf("Dati nr de elemente din sir (<=20): ");
	scanf("%d", &n);
 
	//introducem elementele din sir
	printf("Introduceti elementele vectorului\n");
	for(i = 0; i < n; i++) {
		printf("\t a[%d]= ", i + 1);
		scanf("%d", &a[i]);
	}
 
	/* afisam elementele vectorului */
	printf("Elementele sirului sunt: ");
	for(i = 0; i < n; i++)
		printf("%d \t", a[i]);
	
	return 0;
}


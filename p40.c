#include<stdio.h>

void citire(int a[], int n) {
	int j;
	
	printf("\nIntroduceti elementele sirului:\n");
	for(j = 0; j < n; j++) {
		printf("\t a[%d]=", j);
		scanf("%d", &a[j]);
	}
}

void afisare(int a[], int n) {
	int i;
	printf("\nElementele sirului sunt: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
}

int main() {
	int a[20], n;
	printf("Introduceti numarul de elemente (<20):");
	scanf("%d", &n);
	
	citire(a[], n);
	afisare(a[], n);
	return 0;
}
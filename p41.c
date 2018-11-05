#include<stdio.h>


/* functia de citire a numarului de eleemente */
int nr_elem(int n_max);

/* functia de afisare a elementelor vectorului */
void afisare(int a[], int n);

/* functia de afisare a elementelor vectorului */
void citire(int a[], int n);

/* functia care calculeaza suma elementelor vectorului */
int suma(int a[], int n);

/* functia care calculeaza produsul elementelor vectorului */
int produs(int a[], int n);

/* functia care calculeaza media elementelor vectorului */
float media(int a[], int n);

/* functia care calculeaza numarul elementelor negative ale vectorului */
int nr_neg(int a[], int n);

/* functia care calculeaza numarul elementelor pozitive vectorului */
int nr_poz(int a[], int n);

/* functia care calculeaza numarul elementelor egale cu zero vectorului */
int nr_zero(int a[], int n);

/* functia care calculeaza elementul minim al vectorului */
int min(int a[], int n);

/* functia care calculeaza elementlul maxim al vectorului */
int max(int a[], int n);

/* functia care calculeaza suma elementelor pozitive ale vectorului */
int suma_poz(int a[], int n);

/* functia care calculeaza suma elementelor negative ale vectorului */
int suma_neg(int a[], int n);

/* functia care cauta un element in vector */
int cauta(int a[], int n, int el);

#define NMAX 20

int main() {
	int v[20];
	int n;
	int pos;
	int nr;
	n = nr_elem(NMAX);
	
	citire(v, n);
	afisare(v,n);
	
	printf("\nSuma elementelor este: %d\n", suma(v, n));
	printf("\nProdusul elementelor este: %d\n", produs(v, n));
	printf("\nMedia elementelor este: %f\n", media(v, n));
	printf("\nElementul minim este: %d\n", min(v, n));
	printf("\nElementul maxim este: %d\n", max(v, n));
	printf("\nSuma elementelor pozitive este: %d\n", suma_poz(v, n));
	printf("\nSuma elementelor negative este: %d\n", suma_neg(v, n));
	printf("\nIntroduceti un numar:");
	scanf("%d", &nr);
	pos = cautare(v, n, nr);	
	if(pos == -1)
		printf("\nNumarul %d nu a fost gasit in vector", nr);
	else
		printf("\nNumarul % se afla pe pozitia %d", nr, pos);
	
	return 0;
}

int nr_elem(int n_max) {
	int result;
	do {
		printf("introduceti numarul de elemente ale vectorului (<=20): ");
		scanf("%d", &result);
	} while(result >=20 || result <= 0);
	return result;
}

void afisare(int a[], int n) {
	int i;
	printf("\nSirul este: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void citire(int a[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("\t a[%d]=", i);
		scanf("%d", &a[i]);
	}
}

int suma(int a[], int n) {
	int s = 0;
	int i;

	for(i = 0; i < n; i++)
		s += a[i]; /* sau s=s+a[i]; */
	return s;
}

int produs(int a[], int n) {
	int p = 1;
	int i;

	for(i = 0; i < n; i++)
		p *= a[i];
	return p;
}

float media(int a[], int n) {
	return (float) suma(a, n) / n;
}

int nr_neg(int a[], int n) {
	int neg = 0;
	int i;

	for(i = 0; i < n; i++)
		if( a[i] < 0 )
			neg++;
	return neg;
}

int nr_poz(int a[], int n) {
	int poz = 0;
	int i;

	for(i = 0; i < n; i++)
		if( a[i] > 0 )
			poz++;
	return poz;
}

int nr_zero(int a[], int n) {
	int zero = 0;
	int i;

	for(i = 0; i < n; i++)
		if(a[i] == 0)
			zero++;
	return zero;
}

int min(int a[], int n) {
	int min;
	int i;
	min = a[0];
	for(i = 1;i < n; i++)
		if( a[i] < min )
			min = a[i];
	return min;
}

int max(int a[], int n) {
	int max;
	int i;
	max = a[0];
	for(i = 1;i < n; i++)
		if( a[i] > max )
			max = a[i];
	return max;
}

int suma_neg(int a[], int n)  {
	int i;
	int suma_n = 0;
	for(i = 0; i < n; i++) {
		if( a[i] < 0 )
			suma_n += a[i];
	}
	return suma_n;
}

int suma_poz(int a[], int n)  {
	int i;
	int suma_p = 0;
	for(i = 0; i < n; i++) {
		if( a[i] > 0 )
			suma_p += a[i];
	}
	return suma_p;
}

int cautare(int a[], int n, int elem) {
	int i;
	for(i = 0; i < n; i++)
		if( a[i] == elem)
			return i;
	return -1;	
}

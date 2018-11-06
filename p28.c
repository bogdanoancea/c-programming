#include<stdio.h>
#include<math.h>

float produs1(int n) {	//cu instructiunea FOR
	float p = 1;
	int i;
	for(i = 1; i <= n; i++) {
		if (!(i%2)) //se mai putea scrie if(i%2==0)
			p = p * (1 / (float)i);
		else 
			p = p * i;	//pt impar
	}
	return p;
}

float produs2(int n) { //cu instructiunea WHILE
	float p = 1;
	int i = 1; 
	while(i <= n) {
		if (! (i % 2) ) //se mai putea scrie if(i%2==0)
			p = p * (1 / (float)i);
		else 
			p = p * i;	//pt impar
		i++;
	}
	return p;
}

float produs3(int n) { //cu instructiunea WHILE
	float p = 1;
	int i = 1;
	
	do {
		if ( ! ( i % 2 ) ) //se mai putea scrie if(i%2==0)
			p = p * (1 / (float)i);
		else 
			p = p * i;	//pt impar
		i++;
	} while ( i<= n );
	return p;
}


int main() {
	int n;
	printf("Introduceti n: ");
	scanf("%d", &n);
 
	printf("\nProdusul cu FOR este: %.5f\n", produs1(n));
	printf("\nProdusul cu WHILE este: %.5f\n", produs2(n));
	printf("\nProdusul cu DO WHILE este: %.5f\n", produs3(n));
	return 0;
}

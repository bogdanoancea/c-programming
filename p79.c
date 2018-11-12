#include<stdio.h>

void afisare(int* v, int n) {
	printf("%d\n", v[n - 1]);
	if( n >= 2) 
		afisare(v, n - 1);
}


int main(){
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	afisare(a, 10);
	return 0;
}

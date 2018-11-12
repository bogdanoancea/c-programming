#include <stdio.h>
#include <stdlib.h>

int fact_r(int n) {
	if(n == 1 || n == 0)
		return 1;
	return n * fact_r(n - 1);
}
int fact_i(int n) {
	int i, r;
	r = 1;
	for( i = 1; i <= n; i++)
		r = r * i;
	return r;
}


int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    printf("Factorialul calculat recursiv: %d\n", fact_r(n));
    printf("Factorialul calculat iterativ: %d\n", fact_i(n));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int fib_i(int n) {
	int f1 = 1, f2 = 1, fn = 1, i;
	if(n == 0 || n == 1)
		return 1;
	for(i = 2; i <= n; i++) {
		fn = f1 + f2;
		f2 = f1;
		f1 = fn;
	}
	return fn;
}

int fib_r(int n) {
	if( n == 0 || n == 1)
		return 1;
	return fib_r(n - 2) + fib_r(n - 1);
}


int main() {
    int n, i;
    printf("n=");
    scanf("%d", &n);
    printf("Sirul Fibonacci calculat recursiv:\n");
    for(i = 0; i <= n; i++)
        printf("%6d", fib_r(i));

    printf("\nSirul Fibonacci calculat iterativ:\n");
    for(i = 0; i <= n; i++)
        printf("%6d", fib_i(i));
    return 0;
}

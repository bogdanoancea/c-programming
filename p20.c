#include<stdio.h>

int main() {
 
	int x;
	printf("Introduceti x:");
	scanf("%d", &x);
 
	if(x == 0)
		printf("F(x)=2");
	else
		if( x < 0 )
			printf("F(x)=%d", 3 * x * x + 7 * x - 10);
		else
			printf("F(x)=%d", 4 * x * x);
 
	return 0;
}


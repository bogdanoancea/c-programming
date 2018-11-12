#include <stdio.h>

unsigned int cmmdc(unsigned int a, unsigned int b) {
	if(a == b) 
		return a;
	else
		if(a > b) 
			return cmmdc(a - b, b);
		else 
			return cmmdc(a, b - a);
}
void main() {
	unsigned int x, y;
	printf("Introduceti x: ");
	scanf("%u", &x);
	printf("Introduceti y: ");
	scanf("%u", &y);
 
	if( x == 0 || y == 0)	//daca x=0 sau y=0
		printf("cmmdc(%u,%u) = 1\n", x, y);
	else
		printf("cmmdc(%u,%u) = %u\n", x, y, cmmdc(x, y));
}

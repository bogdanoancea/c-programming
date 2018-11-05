#include<stdio.h>

int main() {
	unsigned int a = 5;
	const int b = 7;
	printf("%d <sau pe biti> %d este %d\n", a, b, a|b);
	printf("%d <si pe biti> %d este %d\n", a, b, a&b);
	printf("%d <sau exclusiv pe biti> %d este %d\n", a, b, a^b);
	printf("5 <complementat pe biti> este %u variabila fiind pe %u octeti\n", ~a, sizeof(a));
	return 0;
}

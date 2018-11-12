#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {
	int i, sum = 0;

	if (argc != 3) {
		printf("Nu ati specificat numerele!\n");
		exit(1);
	}
	printf("Suma este : ");
	sum = atoi(argv[1]) + atoi(argv[2]);
 	printf("%d\n", sum);
	return 0;
 
}
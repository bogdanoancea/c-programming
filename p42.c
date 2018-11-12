#include<stdio.h>

int main() {
	int a[][4]={
			{2,-9,0,9},
			{7,11,-8,4},
			{2,2,-20,1},
			{12,7,90,-9},
			{2,4,5,7}
			}; 
	int i,j;
	
	/*operatia de afisare a matricei  */
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 4; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	return 0;
}

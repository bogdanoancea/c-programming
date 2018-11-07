#include<stdio.h>

int main(int argc, char * argv[]) { // sau : char** argv
	int i;
	for(i = 0; i < argc; i++) // argv[0] este chiar numele programului
		printf ("%s ", argv[i]);
	return 0;
}
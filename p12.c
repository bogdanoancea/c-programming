#include<stdio.h>


int main() {
	int val = 1;
 
	printf("Utilizarea operatorului in forma postfixata %d\n", val++);
	printf("Utilizarea dupa incrementare %d\n", val);
	
	printf("Utilizarea operatorului in forma prefixata %d\n", ++val);
	printf("utilizarea dupa incrementare %d\n", val);
	
	printf("Utilizarea operatorului in forma postfixata %d\n", val--);
	printf("Utilizarea dupa decrementare %d\n", val);
	
	printf("Utilizarea operatorului in forma prefixata %d\n", --val);
	printf("Utilizarea dupa decrementare %d\n", val);
	return 0;
}


#include<stdio.h>

int main() {
	int a, b;
	char x;
	printf("Introduceti a: ");
	scanf("%d", &a);
	printf("Introduceti b: ");
	scanf("%d", &b);
	
	
	printf("Introduceti operatia dorita (+ - * /): ");
    scanf("%c", &x);
 	switch(x) {
		case '+': printf("a+b= %d", a + b); 
				  break;
		case '-': printf("a-b= %d", a - b); 
		          break;
		case '/': printf("a/b=%.2f",a /(float)b); 
		          break;
		case '*': printf("a*b= %d", a * b); 
		          break;
		default: printf("Operatie necunoscuta");
	}
	return 0;
}

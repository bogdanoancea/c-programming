#include<stdio.h>
#include<string.h>

int pos(char* s1, char* s2);

int main() {
	char* sir1 = "Acesta este un exemplu de lucru cu pointeri";
	char* sir2 = "pointeri";
	char* sir3 = "double";
	int res;
	
	res = pos(sir1, sir2);
	if(res != -1)
		printf("%s se gaseste in: %s pe pozitia %d\n", sir2, sir1, res);
	else
		printf("%s nu se gaseste in: %s\n", sir2, sir1);
	
	res = pos(sir1, sir3);
	if(res != -1)
		printf("%s se gaseste in: %s pe pozitia %d\n", sir3, sir1, res);
	else
		printf("%s nu se gaseste in: %s\n", sir3, sir1);
	
	return 0;
}

int pos( char* s1, char * s2) {
	char * p = strstr(s1, s2); //p va fi adresa la care se găseşte s2 in s1
	if (p) 
		return p - s1;
	else 
		return -1;
}


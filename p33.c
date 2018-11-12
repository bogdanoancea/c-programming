#include<stdio.h>

int main() {
	char litera;
	for(litera = 'A'; litera <= 'Z'; litera++) {
		if(litera == 'M') 
			break;
		printf("%c", litera);
	}
}
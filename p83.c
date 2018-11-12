#include <stdio.h>
#include "p83.h"


extern int i;

void afisare() {
    printf("i = %d\n", i);
}

int main() {
    afisare();
    return 0;
}
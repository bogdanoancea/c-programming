#include <stdio.h>

/*Variabilă locală, iniţializată cu 1 la fiecare apel al lui f1*/
void f1() {
   int x = 1;
   x = x + 15;
   printf("In interiorul lui f1, x = %d\n", x);

}

void f2() {
    static int y = 10;    /*Variabilă locală statică, iniţializată cu 10 la primul apel al lui f2; valoarea ei este reţinută pe parcursul apelurilor lui f2*/
    y = y + 15;
    printf("In interiorul lui f2, y = %d\n", y);
}

void f3() {
    static int nr_apeluri=0;
    nr_apeluri++;
    printf("funcţia f() este apelata pentru a %d-a oara\n", nr_apeluri); 
}

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        f1();
        f2();
        f3();
    }
    return 0; 
} 
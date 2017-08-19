#include "base.h"
#include <cstdio>

int main(){
    printf("-------------------------\n");
    Base * p = new Derived;
    printf("-------------------------\n");
    p -> fun();
    printf("-------------------------\n");
    delete p;
    p = 0;

    printf("-------------------------\n");
    printf("sizeof virtual base = %lu\n", sizeof(Base));
    printf("sizeof Derived = %lu\n", sizeof(Derived));
    printf("sizeof C= %lu\n", sizeof(C));
    printf("test base\n");
    printf("-------------------------\n");
    Derived dr;
    printf("-------------------------\n");
}

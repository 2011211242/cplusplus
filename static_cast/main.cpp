#include <cstdio>
#include <climits>

volatile const int a = 1;
using namespace std;

int main(){
    int *p = (int *)&a;
    *p = 5;

    printf("%d\n", a);
    printf("%d\n", *p);
}

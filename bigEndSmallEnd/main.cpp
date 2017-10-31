#include <cstdio>
using namespace std;

union node {
    int a;
    char b[4];
    float c;
};

struct ref{
    unsigned char a;
    unsigned char b;
};

int main(){
    ref a;
    int b;
    printf("%lu\n", &a);
    printf("%lu\n", &b);
}

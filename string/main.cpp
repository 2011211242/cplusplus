#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    char  str[] = "Hello world";
    char * str1 = (char *)"hello world";

    printf("sizeof = %lu\n", sizeof(str));
    printf("strlen = %lu\n", strlen(str));
    printf("str = %s\n", str);

    printf("______________________________\n");

    printf("sizeof = %lu\n", sizeof(str1));
    printf("strlen = %lu\n", strlen(str1));
    printf("str = %s\n", str1);
}

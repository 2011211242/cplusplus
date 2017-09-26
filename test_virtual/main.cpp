#include <cstdio>
using namespace std;

class A{
public:
    virtual void func(){
        printf("Hello A\n");
    }
};

class B:public A{
public:
    virtual void func(){
        printf("Hello A\n");
    }
};

int main(){
    A * ptr = NULL;
    ptr -> func();
}

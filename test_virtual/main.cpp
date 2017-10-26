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
        printf("Hello B\n");
    }
};

int main(){
    A * ptr = new B;//NULL;
    ptr -> func();
}


#include <cstdio>
using namespace std;

class A{
public:
    A(){printf("A constructor\n");}
    void hello(){printf("hello\n");}
    virtual ~A(){printf("A deconstructor\n");}
};

class B{
public:
    B(){printf("B constructor\n");}
    virtual ~B(){printf("B deconstructor\n");}
};

class base{
public:
    void test(){
        printf("base test function\n");
    }

    base(){
        printf("Base constructor\n");
    }

    virtual ~base(){
        printf("Base destructor\n");
    }
};

class derived: public base{
public:
    A a;
    B b;
    void test(){
        printf("derived test function\n");
    }

    derived(){
        a.hello();
        printf("derived constructor\n");
    }

    virtual ~derived(){
        printf("derived destructor\n");
    }
};

/*
class base{
public:
    virtual ~base(){
        printf("Base destructor\n");
    }
};

class derived: public base{
public:
    virtual ~derived(){
        printf("derived destructor\n");
    }
};
*/

int main(){
    base * dr = new derived;
    dr -> test();
    delete dr;
}


#ifndef BASE
#define BASE
#include <cstdio>
using namespace std;

class Base{
public:
    Base(){printf("constructor of virtual Base\n");};
    virtual ~Base(){printf("destructor of virtual Base\n");}
    virtual void fun() = 0;
private:
    int a;
};

class Derived:public Base{
public:
   void fun(){printf("this is fun\n");} 
   ~Derived(){printf("destructor of Derived\n");}
   Derived(){printf("constructor of Derived\n");}
};

class C{
};
#endif

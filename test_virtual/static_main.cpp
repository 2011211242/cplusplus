#include <iostream>
using namespace std;
class A{
public:
    static void func(){
        cout << "Hello World" << endl;
    }
};

int main(){
    A::func();
}

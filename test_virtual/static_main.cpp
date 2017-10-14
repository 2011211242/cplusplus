#include <iostream>
using namespace std;
class A{
public:
    void func(){
        cout << "Hello World" << endl;
    }
};

int main(){

    A::func();
}

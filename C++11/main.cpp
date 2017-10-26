#include <cstdio>
using namespace std;

class Person{
public:
    int val;
    Person(){
        printf("constructor of Person\n");
        val = 0;
    }

    Person(const Person &a){
        printf("copy constructor of Person\n");
        val = 0;
    }

    ~Person(){
        printf("deconstructor of Person\n");
    }
};

Person get(){
    printf("get\n");
    Person p;
    return p;
}

constexpr int n = 5;
char arr[n];

int main(){
    Person p = get();

    p.val ++;
    printf("%d\n", p.val);
    printf("end\n");
}

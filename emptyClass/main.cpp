#include <cstdio>
using namespace std;

class Empty{
public:
    Empty(){printf("constructor of Empty\n");}
    Empty(const Empty& rhs){printf("constructor of copy\n");};
    ~Empty(){printf("deconstructor of Empty\n");}

    Empty& operator = (const Empty &rhs){printf("constructor of equal\n");}
    Empty* operator &() {printf("constructor of point\n");}
    const Empty* operator &() const{printf("constructor of const point\n");}
private:
    int c;
};

int main(){
    Empty f;
    const Empty a;
    printf("Empty a----------------------\n");
    const Empty* c;
    printf("Empty *c----------------------\n");
    Empty b;
    printf("Empty b----------------------\n");
    Empty *d;
    printf("Empty *d----------------------\n");

    b = a;
    printf("b = a----------------------\n");
    c = &a;
    printf("c = &a----------------------\n");
    d = &b;
    printf("d = &b----------------------\n");
    Empty e(a);
    printf("Empty e(a)----------------------\n");
    f = b;
    printf("f = b----------------------\n");
    Empty h = b;
    printf("h = b----------------------\n");
}

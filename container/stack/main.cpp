#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

class A{
public:
    A(){
        printf("construct\n");
        ptr = new int[10];
        for(int i = 0; i < 10; i++){
            ptr[i] = i;
        }
    }

    A(const A & a){
        printf("copy construct\n");
        this -> ptr = new int[10];
        memcpy(this -> ptr, a.ptr, 10 * sizeof(int));
    }

    A& operator = (const A a)
    {
        if(this == &a)
        {
            return *this;
        }
        memcpy(this -> ptr, a.ptr, sizeof(int) * 10);
        return *this;
    }

    ~A(){
        printf("destructor\n");
        if(this -> ptr != NULL){
            delete [] ptr;

            printf("destructed\n");
            this -> ptr = NULL;
        } 
    }

    void print(){
        for(int i = 0; i < 10; i++){
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }

private:
    int * ptr;
};

template <class T> class Stack{
public:
    Stack(): ptr(NULL), e(-1), _cap(0) {}
    Stack(const Stack &a): ptr(NULL), e(a.e), _cap(a._cap){
        if(this -> e > 0){
            this -> ptr = new T*[_cap];
            memcpy(this -> ptr, a.ptr, e * sizeof(T*));
        }
    }

    Stack<T>& operator =(const Stack<T> &a){
        if(this == &a){
            return *this;
        }

        this->ptr = (T **)realloc(this-> ptr, a._cap * sizeof(T*));
        memcpy(this-> ptr, a.ptr, this -> _cap * sizeof(T*));
        this -> e = a.e;
        for(int i = 0; i <= e; i++){
            this -> ptr[i] = new T(*a.ptr[i]);
        }

        return *this;
    }

    ~Stack(){
        for(int i = 0; i <= e; i++){
            ptr[i] -> ~T();
        }
        delete [] ptr;
        e = -1;
        _cap = 0;
    }

    void push(const T &a){
        if(_cap == 0){
            ptr = new T*[1];
            _cap = 1;
        }
        else{
            if(e + 1 >= _cap){
                _cap *= 2;
                ptr = (T**)realloc(ptr, _cap);
                memset(ptr + e + 1, 0, _cap * sizeof(T));
            }
        }

        ptr[++e] = new T(a);
    }

    T top(){
        if(e > 0) return *ptr[e];
    }

    void pop(){
        if(e >= 0)
            ptr[e--] -> ~T();
    }

private:
    T ** ptr;
    int e, _cap;
};

int main(){
    A a1;
    stack<A> sta;
    stack<A> stb;

    sta.push(a1);
    sta.push(a1);

    stb = sta;
}

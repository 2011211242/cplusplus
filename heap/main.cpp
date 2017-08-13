#include <cstdio>
#include "heap.h"
#include <vector>
using namespace std;

struct node {
    int x,y;
};

bool operator < (const node &a, const node &b){
    return a.x > b.x;
}

int main(){
    vector<node> ary = {
        {7, 4},
        {5, 1}
    };
    heap<int> hp;
    node tmp = max(ary[0], ary[1]);
    printf("x = %d, y=%d\n", tmp.x, tmp.y);
}


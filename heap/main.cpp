#include <cstdio>
#include "heap.h"
#include <vector>
#include <stack>
using namespace std;

struct node {
    int x,y;
};


bool operator < (const node &a, const node &b){
    return a.x > b.x;
}

int main(){
    vector<node> ary = {
        {2, 5},
        {3, 4},
        {1, 6},

        {5, 2},
        {6, 1},
        {4, 3},
 
    };

    heap<node> hp;

    for(node item:ary){
        hp.push(item);
    }

    vector<node> top_k = hp.top_k(4);
    for(node item : top_k){
        printf("x = %d, y=%d\n", item.x, item.y);
    }

    printf("---------------------------------------\n");
    top_k = hp.top_k(8);
    for(node item : top_k){
        printf("x = %d, y=%d\n", item.x, item.y);
    }

    printf("---------------------------------------\n");
    top_k = hp.sort();
    for(node item : top_k){
        printf("x = %d, y=%d\n", item.x, item.y);
    }

    printf("---------------------------------------\n");
    printf("---------------------------------------\n");
    printf("---------------------------------------\n");
    
    while(!hp.empty())
    {
        top_k = hp.sort();

        printf("---------------------------------------\n");
        for(node item : top_k){
            printf("x = %d, y=%d\n", item.x, item.y);
        }
        hp.pop();
    }
}


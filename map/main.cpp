#include <cstdio>
#include <vector>
using namespace std;

struct node{
    int val;
    unsigned int dist;
    vector<unsigned int> next;
    node():val(0), dist(0){}
};

int main(){
    int n;
    scanf("%d", &n);
    vector<node> mp(n);

    node tmp;
    for(int i = 0; i < n; i++){
    }
}

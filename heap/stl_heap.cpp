#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(vector<int>hehe){
    for(int i = 0; i != hehe.size(); i++)cout<<hehe[i]<<" ";
    cout<<endl;
}

int main()
{
    int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
    vector<int> ivec(ia, ia+9);

    make_heap(ivec.begin(), ivec.end());
    cout<<"make heap"<<endl;
    show(ivec);

    ivec.push_back(7);
    push_heap(ivec.begin(), ivec.end());
    cout<<"push heap"<<endl;
    show(ivec);
    
    pop_heap(ivec.begin(), ivec.end());
    cout<<"pop heap"<<endl;
    show(ivec);

    cout<<ivec.back()<<endl;
    ivec.pop_back();
    cout<<"pop back"<<endl;
    show(ivec);

    sort_heap(ivec.begin(), ivec.end());
    cout<<"sort heap"<<endl;
    show(ivec);
    return 0;
}


#include <vector>
#include <iostream>
using namespace std;

void func(vector<int> dp){
    cout << dp.capacity() << endl;
    //printf("%lu\n", dp.capacity());
}

int main(){
    vector<int> dp;
    dp.resize(10);

    cout << dp.capacity() << endl;
    func(dp);
}


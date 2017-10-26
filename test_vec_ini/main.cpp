#include <vector>
using namespace std;

const int n = 1000000;
int main()
{

    vector<int> vec;
    vec.resize(n, 1);
    for(int i =0; i < n; i++){
        vec[i] = i;
    }

    vec.resize(n, 0);
}

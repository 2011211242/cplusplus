#include <iostream>
#include <vector>
using namespace std;

int main(){
    int s = 10;
    int k = 4;
    vector<vector<int>>  dp(k + 1, vector<int>(s + 1, 0));
    vector<int> num = {1, 2, 3, 4, 7, 8};

    dp[0][0] = 1;
    for(int i = 0; i < num.size(); i++){
        for(int j = k; j > 0; j--){
            for(int s_k = s; s_k >= num[i]; s_k --){
                dp[j][s_k] += dp[j - 1][s_k - num[i]];
            }
        }
    }

    printf("%d\n", dp[k][s]);
}



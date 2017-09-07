#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void quick_sort(vector<int> &num, int s, int e){
    if(s < e){
        int left = s;
        int right = e;
        int pivot = num[s];

        while(s < e){
            while(s < e && num[e] >= pivot) e--;
            num[s] = num[e];

            while(s < e && num[s] <= pivot) s++;
            num[e] = num[s];
        }
        num[s] = pivot;

        quick_sort(num, left, s - 1);
        quick_sort(num, s + 1, right);
    }
}

void printf(const vector<int>& num){
    for(int i = 0; i < num.size(); i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}

int main(){
    vector<bool> flag(10, false);
    vector<int> num;

    srand(time(NULL));
    int cnt = 0;
    while(cnt < 10){
        int idx = rand() % 10;

        if(flag[idx] == false)
        {
            num.push_back(idx);
            cnt++;
            flag[idx] = true;
        }
    }

    printf(num);
    quick_sort(num, 0, 9);
    printf(num);
}


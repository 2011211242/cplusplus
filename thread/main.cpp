#include <cstdio>
#include <queue>
#include <thread>
#include <mutex>
using namespace std;

mutex Lock;
mutex full;
mutex empty;
bool fin = false;
int count = 100;

queue<int> Q;

void task(){
    while(true){
        printf("Lock\n");
        Lock.lock();
        if(Q.empty()){
            empty.lock();
        }

        if(fin) {
            empty.unlock();
            return;
        }

        int tmp = Q.front();
        Q.pop();
        full.unlock();

        printf("uLock\n");
        Lock.unlock();

        printf("%d\n", tmp);

        if(tmp <= count){
            Lock.lock();
            printf("Lock\n");
            if(Q.size() == count){
                full.lock();
            }
            Q.push(tmp * 2 + 1);
            empty.unlock();

            if(Q.size() == count){
                full.lock();
            }
            Q.push(tmp * 2 + 2);
            empty.unlock();
            printf("uLock\n");
            Lock.unlock();
        }
    }
}

int main(){
    vector<thread> threads;
    Q.push(0);

    /*
    for(int i = 0; i < 10; i++){
        Lock.unlock();
    }
    */

    Lock.lock();
    Lock.lock();
    Lock.lock();
    Lock.lock();

    printf("locked\n");

    /*
    for(int i = 0; i < 4; i++){
        threads.push_back(thread(task));
    }

    for(int i = 0; i < 4; i++){
        threads[i].join();
    }
    */
}

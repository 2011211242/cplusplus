#include <cstdio>
#include <queue>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <algorithm>
#include <condition_variable>
using namespace std;

mutex mtx;

int producing;
int consuming;

mutex producing_mtx;
mutex consuming_mtx;

condition_variable not_full;
condition_variable not_empty;

bool fin = false;
int _count = 0;
int max_count = 0;

queue<int> Q;


void task(int th_id){
    bool ready_to_exit = false;
    while(true){
        int idx;
        //printf("thread_id=%d while\n", th_id);
        {
            //unique_lock<mutex> lock(producing_mtx);
            //printf("thread_id=%d producing_mtx\n", th_id);
            unique_lock<mutex> lock1(mtx);
            _count++;
            max_count = max(_count, max_count);
            //printf("thread_id=%d mtx\n", th_id);

            if(Q.size() == 0 && producing == 0){
                ready_to_exit = true;
            }
            else{
                while(Q.empty()){
                    printf("empty\n");
                    not_empty.wait(lock1);
                }
                idx = Q.front();
                Q.pop();
                not_full.notify_all();
            }

            //lock1.unlock();
            //lock.unlock();
            _count--;
            if(ready_to_exit) break;
        }

        for(int i = 0; i < 1000000; i++);
        printf("thread_id=%d, idx = %d, max_count = %d\n", th_id, idx, max_count);

        {
            unique_lock<mutex> lock2(mtx);
            _count++;
            max_count = max(_count, max_count);
            producing++;
            //unique_lock<mutex> lock3(mtx);

            if(idx * 2 + 2 < 1000)
            {
                Q.push(idx * 2);
                Q.push(idx * 2 + 1);
            }

            producing --;
            _count--;

            not_empty.notify_all();
            //lock3.unlock();
            //lock2.unlock();
        }
    }
}

int main(){
    vector<thread> threads;
    Q.push(1);

    /*
       for(int i = 0; i < 10; i++){
       Lock.unlock();
       }
       */


    //printf("locked\n");

    int thread_num = 8;
    for(int i = 0; i < thread_num; i++){
        threads.push_back(thread(task, i));
        usleep(1000);
    }

    for(int i = 0; i < thread_num; i++){
        threads[i].join();
    }
}

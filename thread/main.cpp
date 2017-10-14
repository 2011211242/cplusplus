#include <cstdio>
#include <queue>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <algorithm>
#include <condition_variable>
using namespace std;

mutex mtx;

int consuming = 0;
int waiting = 0;

int thread_num = 8;
mutex consuming_mtx;
mutex producing_mtx;
mutex mtx_;

condition_variable not_full;
condition_variable not_empty;

bool fin = false;
int _count = 0;
int max_count = 0;

queue<int> Q;
bool ready_to_exit = false;

void task(int th_id){
    while(true){
        int idx;
        //printf("thread_id=%d while\n", th_id);
        {
            //unique_lock<mutex> lock(producing_mtx);
            //printf("thread_id=%d producing_mtx\n", th_id);
            consuming_mtx.lock();
            consuming++; 
            consuming_mtx.unlock();


            consuming_mtx.lock();
            consuming --; 
            consuming_mtx.unlock();

            mtx_.lock();
            _count++;
            max_count = max(_count, max_count);
            printf("thread_id=%d mtx max_count=%d, max_waiting = %d\n", th_id, max_count, waiting);

            unique_lock<mutex> lock1(mtx);

            if(Q.size() == 0 && consuming == thread_num - 1){
                ready_to_exit = true;
                printf("%d ready to exit\n", th_id);
            }
            else{
                while(Q.empty()){
                    printf("%d empty\n", th_id);
                    waiting++;
                    not_empty.wait(lock1);
                    printf("%d get ridd empty\n", th_id);
                }
                printf("%d\n", th_id);
                idx = Q.front();
                Q.pop();

                not_full.notify_all();
            }

            //lock1.unlock();
            //lock.unlock();
            _count--;
            if(ready_to_exit) break;
            mtx_.unlock();

        }

        for(int i = 0; i < 1000000; i++);
        printf("thread_id=%d, idx = %d, max_count = %d\n", th_id, idx, max_count);

        producing_mtx.lock();
        _count ++;
        max_count = max(_count, max_count);

        if(idx * 2 + 2 < 1000)
        {
            Q.push(idx * 2);
            not_empty.notify_all();
            Q.push(idx * 2 + 1);
            not_empty.notify_all();
            printf("not_empty.notified\n");
        }
        _count --;
        producing_mtx.unlock();
    }
}

int main(){
    vector<thread> threads;
    Q.push(1);

    for(int i = 0; i < thread_num; i++){
        threads.push_back(thread(task, i));
    }

    for(int i = 0; i < thread_num; i++){
        threads[i].join();
    }
}

#include <mutex>
#include <unistd.h>
#include <thread>
#include <ctime>
using std::mutex;
using std::thread;

class SingletonStatic
{
private:
    static SingletonStatic* m_instance;
    SingletonStatic(){ val = 0;}
    int val;
    mutex mtx;
public:
    void add(int id)
    { 
        int t = rand() % 1000;
        usleep(t); 
        mtx.lock(); 
        printf("thread %d locked\n", id);
        this->val++; 
        printf("thread %d val = %d\n", id, this->val);
        printf("thread %d unlock\n\n", id);
        mtx.unlock();
        //usleep(1); 
    }

    static SingletonStatic* getInstance()
    {
        return m_instance;
    }
};

//外部初始化 before invoke main
SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;

void task(int id){
    printf("thread id = %d\n", id);
    sleep(1);
    SingletonStatic * instance = SingletonStatic::getInstance();
    for(int i = 0; i < 10; i++){
        instance->add(id);
    }
}

int main(){
    srand(time(NULL));

    thread t1(task, 0);
    thread t2(task, 1);
    thread t3(task, 2);
    thread t4(task, 3);
    thread t5(task, 4);
    thread t6(task, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}

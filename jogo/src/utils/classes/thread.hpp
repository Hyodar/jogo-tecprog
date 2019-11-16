#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <pthread.h>
using namespace std;

class Thread{

private:
    pthread_t threadID;
    pthread_attr_t tAttribute;
    //static pthread_mutex_t mutex;

    static void* runThread(void* pThread);
    virtual void run();

public:
    Thread();
    virtual ~Thread();
    void start();
    void join();
    void yield();
    //void lock();
    //void unlock();

};

#endif //THREAD_HPP_

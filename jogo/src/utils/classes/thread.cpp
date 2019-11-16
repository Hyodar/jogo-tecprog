
// Libraries
// ---------------------------------------------------------------------------
#include <iostream>

// Class header
// ---------------------
#include "thread.hpp"

// Internal libraries
// ----------------------


// Methods
// ---------------------------------------------------------------------------

Thread::Thread(){
    //noop;
}

// ---------------------------------------------------------------------------

Thread::~Thread(){
    //noop
}

// ---------------------------------------------------------------------------

void Thread::run(){

}

// ---------------------------------------------------------------------------

void Thread::start(){
    int status = pthread_attr_init( &tAttribute );

    status = pthread_attr_setscope( &tAttribute, PTHREAD_SCOPE_SYSTEM );
    if(status) std::cout << "Error" << std::endl;

    status = pthread_create( &threadID, &tAttribute, Thread::runThread, (void*)this);
    if(status) std::cout << "Error" << std::endl;

    status = pthread_attr_destroy( &tAttribute );
    if(status) std::cout << "Error" << std::endl;

}

// ---------------------------------------------------------------------------

void Thread::yield(){
    sched_yield();
}

// ---------------------------------------------------------------------------

void Thread::join(){
    pthread_join( threadID, NULL );
}

// ---------------------------------------------------------------------------

void* Thread::runThread(void* pThread){
    Thread* sThread = static_cast<Thread*>( pThread );

    if ( nullptr == sThread ) std::cout << "thread falhou." <<std::endl;

    else sThread->run();
}

// ---------------------------------------------------------------------------

/*void Thread::lock(){
    pthread_mutex_init( &(Thread::mutex), NULL );
    pthread_mutex_lock( &(Thread::mutex) );
}*/

// ---------------------------------------------------------------------------

/*void Thread::unlock(){
    pthread_mutex_unlock( &(Thread::mutex) );
}*/

#include <pthread.h> 
#include<iostream> 
using namespace std; 


//thread function that prints its id 
void *printid(void*threadid)
{
    int id = *((int*)threadid); 
    cout<<"hello from the thread: "<<id<<endl; 
    delete(int*) threadid; 
    return nullptr; 
}

int main()
{
    const int numThreads =5; 
    pthread_t *tid = new pthread_t[numThreads]; 

    //create threads 
    for (int i =0; i< numThreads; i++)
    {
        int *idptr = new int(i); 
        if (pthread_create(&tid[i] , nullptr, printid, (void*) idptr)!=0)
        {
            cerr <<"error creating thread: " <<i<<endl; 
            delete idptr; 
            return 1; 
        }
        
    }

    for (int i=0; i< numThreads; i++)
    {
        pthread_join (tid[i], nullptr); 

    }

    cout<<"all threads have been finished. " <<endl; 

    delete []tid; 
    return 0; 

    












    return 0; 
}
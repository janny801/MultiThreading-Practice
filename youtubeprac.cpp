
//https://www.youtube.com/watch?v=C5NhMVqq90k

#include <pthread.h>
#include<iostream> 
using namespace std; 
#include <string> 
#include <algorithm> 


void *funcA(void*arg)
{
    while (true)
    {
        cout<<"A"<<endl; 
    }
    return nullptr; 
}
void *funcB(void*arg)
{
    while (true)
    {
        cout<<"B"<<endl; 
    }
    return nullptr; 
}


int main(int argc, char** argv)
{
    pthread_t threadA; 
    pthread_t threadB; 

    pthread_create(&threadA, nullptr, &funcA, /*argument that is passed here will be passed to the function : n this case we are only passing nullptr to funcA*/nullptr);
    pthread_create(&threadB, nullptr, &funcB, nullptr); 


    string input = ""; 
    while (input!="quit")
    {
        getline(cin, input); 

    }


    return 0; 
}
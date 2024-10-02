#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>

struct arguments
{
	int value;
	std::string binCode;
};

// Write the child thread function here
void *dec2bin(void *void_ptr)
{
    arguments *ptr= (arguments*) void_ptr; 
    int value =ptr-> value; //deref pointer and get access to the value . now we have the value we can transform it into binary 
    
    ptr-> binCode =""; //make sure it is equal to an empty string 
    do
    {
        int digit = value%2; 
        ptr-> binCode = std::to_string(digit)+ptr->binCode; //find out what this does 
        value = value / 2; 
    }
    while (value>0); 
    return nullptr; 
}
//child thread function 

int main()
{
    std::vector<arguments> arg; //vector of arguments 
    arguments tempHolder;
    tempHolder.binCode = "";
	while (std::cin >> tempHolder.value) 
    {
        arg.push_back(tempHolder);
    }
    int nValues = arg.size();
 	pthread_t *tid = new pthread_t[nValues];
        
	for(int i=0;i<nValues;i++)
	{
        
		if(pthread_create(&tid[i], nullptr, dec2bin, (void*)&arg.at(i)) != 0) //find out what this does (arg.at(i)) is a single struct of arguments
		{
			std::cerr << "Error creating thread" << std::endl;
			return 1;

		}		
	}
	
	// Wait for the other threads to finish.
    // Call pthread_join here
    
    
    for(int i=0; i< nValues;i++)
    {
        pthread_join(tid[i],nullptr);
    }

    
    for (int i = 0; i < nValues; i++)
    {
        std::cout << arg[i].value << " base 10 is equal to " << arg[i].binCode << std::endl;
    }
    if (tid!=nullptr)
        delete[] tid;
    return 0;
}
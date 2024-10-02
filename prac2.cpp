#include <pthread.h>
#include <iostream>
#include <vector>

// Thread function to print the input value
void* printValue(void* void_ptr)
{
    int* value_ptr = (int*) void_ptr;
    std::cout << "The value that you entered: " << *value_ptr << std::endl;
    return nullptr;
}

int main()
{
    std::vector<int> values; // Vector to store input values
    int tempValue;

    // Read input values and store them in the vector
    std::cout << "Enter numbers (end with non-number): ";
    while (std::cin >> tempValue)
    {
        values.push_back(tempValue);
    }

    int nValues = values.size();
    pthread_t* tid = new pthread_t[nValues];

    // Create threads to process each input value
    for (int i = 0; i < nValues; i++)
    {
        // Pass the address of the value in the vector to the thread
        if (pthread_create(&tid[i], nullptr, printValue, (void*)&values[i]) != 0)
        {
            std::cerr << "Error creating thread" << std::endl;
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < nValues; i++)
    {
        pthread_join(tid[i], nullptr);
    }

    std::cout << "All threads have finished." << std::endl;

    delete[] tid;
    return 0;
}

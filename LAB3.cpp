#include <iostream>
#include <omp.h> // Include the OpenMP header
using namespace std;

unsigned int factorial(unsigned int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num = 5;
    
    // Parallel region
    #pragma omp parallel
    {
        // This section is executed by a single thread only
        #pragma omp single
        {
            cout << "Factorial of " << num << " is " << factorial(num) << endl;
        }
        
        // This section is executed in a mutually exclusive manner by multiple threads
        #pragma omp critical
        {
            cout << "Thread " << omp_get_thread_num() << " completed." << endl;
        }
    }
    
    return 0;
}


 
        
    
    


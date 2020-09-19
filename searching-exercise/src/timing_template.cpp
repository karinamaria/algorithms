/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <fstream>

#include "searching.cpp"

#define inicio 100000000
#define incremento 18000000

void bSearchIterative(int array[]){
    std::ofstream fileSearch("../pics/bSearchIterative.txt", std::ios::app);

    auto last = inicio;
    for (size_t i{0}; i<50; ++i){
         //================================================================================
        auto start = std::chrono::steady_clock::now();
       
        last = (i==0) ? last : last+incremento;
        sa::bsearch(array, &array[last],-1);
       
        //================================================================================
        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = end - start;
       
        fileSearch << &array[last] - array << " "<< std::chrono::duration <double, std::milli> (diff).count()<< std::endl;
    }
    last = inicio;
    fileSearch.close();
}

void bSearchRecursive(int array[]){
    std::ofstream fileSearch("../pics/bSearchRecursive.txt", std::ios::app);

    auto last = inicio;
    for (size_t i{0}; i<50; ++i){
         //================================================================================
        auto start = std::chrono::steady_clock::now();
       
        last = (i==0) ? last : last+incremento;
        sa::bsearchrecursive(array, &array[last],-1);
       
        //================================================================================
        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = end - start;
       
        fileSearch << &array[last] - array << " "<< std::chrono::duration <double, std::milli> (diff).count()<< std::endl;
    }
    last = inicio;
    fileSearch.close();
}

int main( void )
{
 
    int *array = new int[1000000000];//10⁹

    for(int i{0}; i<1000000000; ++i){
        array[i] = i;
    }

    bSearchIterative(array);
    bSearchRecursive(array);

    delete [] array;
    return EXIT_SUCCESS;
}


#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

#include <random>

#include "../include/sorting.h"

using namespace sa;

typedef void (*fuctions_sorting) (value_type*, value_type*);

void print( value_type *first, value_type *last ){
    std::ostringstream oss;
    std::copy( first, last, std::ostream_iterator< value_type > ( oss, " " ) );
    std::cout << oss.str() << std::endl;
}

void ordenar(value_type *first, value_type *last, fuctions_sorting function ){
    function(first, last);
    print(first, last);
}
/**
void run_insertion_sort(value_type *first, value_type *last){
	std::cout << "Insertion sort" << std::endl;
	insertionsort(first, last);
	print(first, last);
}

void run_bubble_sort(value_type *first, value_type *last){
	std::cout << "Bubble sort" << std::endl;
	bubblesort(first, last);
	print(first, last);
}

void run_selection_sort(value_type *first, value_type *last){
	std::cout << "Selection sort" << std::endl;
	selectionsort(first, last);
	print(first, last);
}

void run_sheel_sort(value_type *first, value_type *last){
	std::cout << "Shell sort" << std::endl;
	shellsort(first, last);
	print(first, last);
}

void run_quick_sort(value_type *first, value_type *last){
	std::cout << "Quick sort" << std::endl;
	quicksort(first, last);
	print(first, last);
}**/

int main(){
	fuctions_sorting functions[]{insertionsort, bubblesort, selectionsort,
								shellsort, quicksort};
	value_type A[]{1006,23,45,293,12,43,1};
	std :: random_device rd ; 
    std :: mt19937 g ( rd ( ) ) ;
	std :: shuffle ( std::begin(A), std::end(A), 25 ) ;
 	
    print(std::begin(A), std::end(A));
    std::cout << "-------------------------" << std::endl;
	//run_insertion_sort(std::begin(A), std::end(A));
	//run_bubble_sort(std::begin(A), std::end(A));
	//run_selection_sort(std::begin(A), std::end(A));
	for(auto i=0; i<5; i++){
		ordenar(std::begin(A), std::end(A), functions[i]);
	}
	//run_sheel_sort(std::begin(A), std::end(A));
	return 0;
}
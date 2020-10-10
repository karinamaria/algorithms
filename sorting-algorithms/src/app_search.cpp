
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "../include/sorting.h"

using namespace sa;

typedef void (*fuctions_sorting) (value_type *first, value_type *last);

void print( value_type *first, value_type *last ){
    std::ostringstream oss;
    std::copy( first, last, std::ostream_iterator< value_type > ( oss, " " ) );
    std::cout << oss.str() << std::endl;
}

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

int main(){
	fuctions_sorting functions[]{run_insertion_sort, run_bubble_sort, run_selection_sort};
	value_type A[]{1006,23,45,293,12,43,1,49};

	//run_insertion_sort(std::begin(A), std::end(A));
	//run_bubble_sort(std::begin(A), std::end(A));
	//run_selection_sort(std::begin(A), std::end(A));
	for(auto i=0; i<3; i++){
		functions[i](std::begin(A), std::end(A));
	}
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "../include/sorting.h"

using namespace sa;

std::string print( value_type *first, value_type *last ){
    std::ostringstream oss;
    std::copy( first, last, std::ostream_iterator< value_type > ( oss, " " ) );
    return oss.str();
}

void run_insertion_sort(value_type *first, value_type *last){
	insertionsort(first, last);
	std::cout << print(first, last) << std::endl;
}

void run_bubble_sort(value_type *first, value_type *last){
	bubblesort(first, last);
	std::cout << print(first, last) << std::endl;
}

int main(){
	value_type A[]{23,45,293,12,43,1,49};

	//run_insertion_sort(std::begin(A), std::end(A));
	run_bubble_sort(std::begin(A), std::end(A));
	return 0;
}
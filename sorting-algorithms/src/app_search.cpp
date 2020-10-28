
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

int main(){
	fuctions_sorting functions[]{insertionsort, bubblesort, selectionsort,
								shellsort, quicksort};
	value_type A[]{1006,23,45,293,12,43,1};
	std :: random_device rd ; 
    std :: mt19937 g ( rd ( ) ) ;
	std :: shuffle ( std::begin(A), std::end(A), 25 ) ;
 	
    print(std::begin(A), std::end(A));
    std::cout << "-------------------------" << std::endl;
	
	for(auto i=0; i<5; i++){
		ordenar(std::begin(A), std::end(A), functions[i]);
	}
	return 0;
}
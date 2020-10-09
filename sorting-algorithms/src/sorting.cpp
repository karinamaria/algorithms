#include <iostream>

#include "../include/sorting.h"

namespace sa {
	void printArray(value_type *first, value_type *last){
		std::cout << "\nArray [ ";
		while(first != last){
			std::cout << *first++ << " ";
		}
		std::cout << "]\n";
	}

	/*!
	 *  It's a function that compare two integers
	 *  \param a the first integer of comparison
	 *  \param b the second integer of comparison
 	*/
	bool comp( const value_type & a, const value_type & b ){
		return ( a < b );
	}

	/*!
	 *  Performs a **insertion sort** in range `[first;last)`
	 *  \param first Iterator to the first element in range.
	 *  \param last Iterator to past the last element in range.
 	*/
	void insertionsort( value_type * first, value_type * last){
		auto *it{first+1};//store the second element of range `[first;last)`. 
		while(it < last){
			for(auto i=it; i>first && (*i < *(i-1)); i--){
				if(comp(*i, *(i-1))){
					std::swap(*i, *(i-1));
				}
			}
			it++;
		}
	}

	/*!
	 *  Performs a **bubble sort** in range `[first;last)`
	 *  \param first Iterator to the first element in range.
	 *  \param last Iterator to past the last element in range.
 	*/
	void bubblesort( value_type * first, value_type * last){
		auto it{last};
	
		while(it > first){
			for(auto i=first; i<it-1; i++){
				if(!comp(*i, *(i+1))){
					std::swap(*i, *(i+1));
				}

			}
			it -= 1;
		}
	}
}
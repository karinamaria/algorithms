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
		for(auto i=first+1; i < last; i++){
			for(auto j=i; j>first && (*j < *(j-1)); j--){
				if(comp(*j, *(j-1))){
					std::swap(*j, *(j-1));
				}
			}
		}
		/**auto *it{first+1};//store the second element of range `[first;last)`. 
		while(it < last){
			for(auto i=it; i>first && (*i < *(i-1)); i--){
				if(comp(*i, *(i-1))){
					std::swap(*i, *(i-1));
				}
			}
			it++;
		}**/
	}

	/*!
	 *  Performs a **bubble sort** in range `[first;last)`
	 *  \param first Iterator to the first element in range.
	 *  \param last Iterator to past the last element in range.
 	*/
	void bubblesort( value_type * first, value_type * last){
		//auto it{last};//store the last element because after each iteration
		 			  //the last elements are sorted
		for(auto i=last; i > first+1; i--){
			for(auto j=first; j<i-1; j++){
				if(comp(*(j+1), *j)){
					std::swap(*j, *(j+1));
				}

			}
		}
		/*while(it > first+1){
			for(auto i=first; i<it-1; i++){
				if(!comp(*i, *(i+1))){
					std::swap(*i, *(i+1));
				}

			}
			it -= 1;
		}*/
	}

	/*!
	 *  Performs a **selection sort** in range `[first;last)`
	 *  \param first Iterator to the first element in range.
	 *  \param last Iterator to past the last element in range.
 	*/
	void selectionsort( value_type * first, value_type * last){
		auto smaller{first};
		for(auto i=first; i<last-1; i++){
			smaller = i;
			for(auto j=i+1; j<last; j++){
				if(comp(*j,*smaller)){
					smaller=j;
				}
			}
			if(smaller != i){
				std::swap(*smaller, *i);
			}
		}
	}

	/*!
	 *  Performs a **shell sort** in range `[first;last)`
	 *  \param first Iterator to the first element in range.
	 *  \param last Iterator to past the last element in range.
 	*/
	void shellsort( value_type * first, value_type * last){
		auto size = std::distance(first, last)/2; // index of element of middle
		for(auto i=size; i >= 1; i/=2){
			for(auto j=first; j+i < last; j++){// (j+i) is the next element of comparison
				if(comp(*(j+i), *j)){
					std::swap(*(j), *(j+i));
				}
			}
		}
	}
}
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
	 *  \return true if a < b, false otherwise.
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
			for(auto j=first; j+i < last; j++){// (j+i) is the next element of comparison with j
				if(comp(*(j+i), *j)){
					std::swap(*(j), *(j+i));
				}
			}
		}
	}

	/*!
	* Partition reorders the elements in the range [first;last) in such a way that
	* all elements **less** than the pivot appear before the pivot, and all elements
	* equal or greater than the pivot appear after the pivot.
	*
	* @param first The first element in the range we want to reorder.
	* @param last Past-the-last element in the range we want to reorder.
	* @param pivot Location of the pivot element we need to partition the array with.
	* @return An iterator to the new pivot location within the range.
	*/
	value_type * partition( value_type *first, value_type *last, value_type *pivot){
	    auto slow{first-1}, fast{first};
	    while(fast != pivot){
	        if(comp(*fast,*pivot)){//fast < pivot [first, slow)
	            slow = slow+1;  
	            std::swap(*fast, *slow);   
	        }
	        fast++;
	        
	    }
	    std::swap(*pivot, *(slow+1));

	    return slow;
	}

	/*!
	* Quick Sort is a recursive function that makes use of the `partition` function 
	* to divide the interval [first, last) into two regions: the elements smaller than 
	* the pivot and the elements greater than or equal to the pivot. Each of these regions 
	* is ordered by recursive calls to the `partition` function.
	*
	* @param first The first element in the range we want to order.
	* @param last Past-the-last element in the range we want to order.
	*/
	void quicksort( value_type *first, value_type *last){
	   value_type n = last-first;
	   
	   if(n > 1){
	   		auto pivot = partition(first, last, last-1);
	   		quicksort(first, pivot+1);//left
	        quicksort(pivot+1, last);//right
	   }
	}
}                     
/*
 */

#include <iostream>
#include "../include/searching.h"

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        while(first != last and *first != value){
            first++;
	    }
	    return first;
    }

    /*!
     * Performs a **binary search iterative** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
        value_type step, *mid;
        value_type count = last-first;
        while(count != 0){
            step = count/2;
            mid = first+ step;
            if(*mid == value){
                return mid;
            }else if(*mid < value) {
                first = mid+1;
                count = count - (step+1);
            }
            else
                count = step;
        }
        return first;
    }

     /*!
     * Performs a **binary search recursive** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearchrecursive( value_type * first, value_type * last, value_type value )
    {
        value_type *middle = first+(last-first)/2;
        
		if((last - first) == 0){
			return first;
		}
		if(*middle == value){
			return middle;
		}
		if(*middle > value){				
			return bsearchrecursive(first, middle, value);
		}
		return bsearchrecursive(middle+1, last, value);
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        value_type step, *mid;
        value_type count = last-first;
        while(count != 0){
            step = count/2;
            mid = first+ step;
            if(*mid >= value) 
                count = step;
            else{
                first = mid+1;
                count = count - (step+1);
            }
        }
        return first;
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        value_type step, *mid;
        value_type count = last-first;
        while(count != 0){
            step = count/2;
            mid = first+ step;
            if(!(value<*mid)){
                first = mid+1;
                count = count - (step+1); 
            }else
                count = step;
        }
        return first;
    }
}


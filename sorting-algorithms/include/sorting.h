/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + insertion sort
 *  + selection sort
 *  + bubble sort
 *  + shell sort
 *  + quick sort
 *  + merge sort
 *  + radix sort
 *
 * \author Karina
 * \date October, 5st.
 */
#ifndef SEARCHING_H
#define SEARCHING_H

#include <algorithm>

/// Sorting Algorithms Namespace
namespace sa {

    /// just an alias for an integer type.
    using value_type = unsigned int;

    void printArray(value_type *first, value_type *last);

    bool compare_ints( const value_type & a, const value_type & b );

    /// insertion sort.
    void insertionsort( value_type * first, value_type * last);

    /// selection sort.
    void selectionsort( value_type * first, value_type * last);

    // bubble sort.
    void bubblesort( value_type * first, value_type * last);

    /// shell sort.
    void shellsort( value_type * first, value_type * last);

    /// quick sort.
    void quicksort( value_type * first, value_type * last);

    /// merge sort.
    void mergesort( value_type * first, value_type * last);

    /// merge sort.
    void radixsort( value_type * first, value_type * last);
}

#endif // SORTING_H

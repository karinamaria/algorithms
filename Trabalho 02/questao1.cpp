/**Local minimum in an array. Write a function that, given an array a[] of n distinct
integers, finds and returns the location a local minimum. A local minimum in an array
is an element a[i] such that both a[i] < a[i-1] and a[i] < a[i+1] (assuming
the neighbor entry is inside the array). Note that an element that does not have one
(or both) of its two neighbors can still be a local minimum. Your program should use
∼ 2 lg(n) compares in the worst case **/

#include <iostream>
#include <stdlib.h>
#include <time.h>

void printArray(int *first, int *last){
	std::cout << "\nArray [ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]\n";
}

int* run_q01(int *first, int *last){
    printArray(first, last);
	int n = std::distance(first, last);
	if(n == 0){//array vazio
		return nullptr;
	}
	if(n == 2){
		if(*first < *(last-1)){
			return first;
		}
		return last-1;
	}
	int m = n/2;//centro
	if(*(first+m) < *(first+(m-1)) && *(first+m) < *(first+(m+1))){
		return first+m;
	}
	if(*(first+(m-1)) < *(first+(m+1))){
		last = first+m;
	}else{
		first = last-m;
	}
	return run_q01(first, last);

}

int main(){
    srand(time(NULL));
	size_t numeroElementos = rand() % 10;

    int array[numeroElementos];
    size_t array_sz{sizeof(array)/sizeof(array[0])};

    for(size_t i=0; i<numeroElementos; i++){
		array[i]=(rand() % 101);
	}

    int *result = run_q01(array, &array[array_sz]);

	if(result == nullptr){
		std::cout << "\n:::::::: ARRAY VAZIO OU NADA FOI ENCONTRADO ::::::::" << std::endl;
	}else{
		std::cout << "\n-------- INDICE: " << std::distance(array, result) << " --------" << std::endl;
		std::cout << "\n-------- RESULTADO: " << *result << " --------" << std::endl;
	}
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <tuple>

/**

https://www.geeksforgeeks.org/find-repeating-element-sorted-array-size-n/
https://algotree.org/algorithms/binary_search/search_number_in_a_rotated_sorted_array/
https://algotree.org/algorithms/binary_search/duplicates/
https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
https://gist.github.com/them0nk/2495155
https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

**/

#define SIZE 2

void printArray(int *first, int *last){
	std::cout << "\nArray [ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]\n";
}

void printArray(int A[], int inicio, int fim){
	std::cout << "A [ ";
	for ( int i {0} ; i < (fim-inicio) ; ++ i ){
		std::cout << A[i] << " ";
	}
	std::cout << "]\n";
}

void printMatriz(const int (&A) [SIZE][SIZE]){
	for (const auto & row : A){
		std::cout << "[";
			for(auto col{0}; col < SIZE; ++col){
				std::cout << (col > 0? ", " : " ") << row[col];
			}
		std::cout << "]\n";
	}
}

void imprimirResultado(int *array, int *result){
	if(result == nullptr){
		std::cout << "\n:::::::: ARRAY VAZIO OU NADA FOI ENCONTRADO ::::::::" << std::endl;
	}else{
		std::cout << "\n-------- INDICE: " << std::distance(array, result) << " --------" << std::endl;
		std::cout << "\n-------- RESULTADO: " << *result << " --------" << std::endl;
	}
}

int* run_q02(int *first, int *last){
	return nullptr;
}

int* run_q04(int *first, int *last, int value ){
	printArray(first, last);
	int step, *mid;
	int count = last-first;
	while(count != 0){
	   	step = count/2;
        mid = first + step;
        if(*mid >= value) 
            count = step;
        else{
            first = mid+1;
            count -= (step+1);
        }
    }
    return first;
}

int* run_q07(int array[], int inicio, int fim){
	printArray(array, inicio, fim);
	int i;
	
	while(inicio < fim){
		i = (inicio + fim)/2;
		if(array[i] == i){
			return &array[i];
		}
		if(array[i] > i){
			fim=i;
		}else{
			inicio=i+1;
		}
	}
	return nullptr;
}

//recebe o array A
std::tuple<bool, int, int> run_q11(int A[], size_t array_sz, int value){
	for(size_t i=0; i<array_sz; i++){
         for (size_t j=i; j<array_sz; j++){
            if(i!=j && (A[i]+A[j]) == value){
               return std::make_tuple(true, i, j);
            }
         }
      }

	return std::make_tuple(false, -1, -1);
}

void q11(){
	bool existSoma = false;

	size_t numeroElementos = 5;
	int A[numeroElementos]{0,1,1,2,4};
	int B[numeroElementos]{3,5,8,9,10};

	std::cout << "-------- ARRAY A --------\n";
	printArray(A, &A[sizeof(A)/sizeof(A[0])]);
	std::cout << "-------- ARRAY B --------\n";
	printArray(B, &B[sizeof(B)/sizeof(B[0])]);

	for(size_t i=0; i<numeroElementos || existSoma; i++){
		auto tupla = run_q11(A, sizeof(A)/sizeof(A[0]), B[i]);
		existSoma = std::get<0>(tupla);
		if(existSoma){
			std::cout	<< "-------- SOMA ENCONTRADA --------\nOs elementos de indice " << std::get<1>(tupla) << " e " << std::get<2>(tupla)
						<< " do vetor A resultam no elemento de indice " << i << " do vetor B\n";
		}
	}
}

void q04(){
	size_t numeroElementos = 5;

	int array[numeroElementos]{0,1,1,2,4};

	size_t array_sz{sizeof(array)/sizeof(array[0])};

	int *result = run_q04(array, &array[array_sz],1);
	
	if(result == &array[array_sz]){
		std::cout << "-------- A CHAVE NAO FOI ENCONTRADA --------\n";
	}else{
		std::cout << "\n-------- INDICE: " << std::distance(array, result) << " --------" << std::endl;
		std::cout << "\n-------- RESULTADO: " << *result << " --------" << std::endl;
	}
}


int * bsearchrecursive( int *first, int *last, int value )
    {
		int *middle = first+(last-first)/2;
       	std::cout << "target: "<< value <<" last - first: "<< last-first<< std::endl;
       	std::cout << "first: "<< *first <<" last: "<< *last<< std::endl;
        
		if((last - first) == 0 ){
			std::cout << "oi" << std::endl;
			return first;
		}

		if(*middle == value){
			std::cout << "middle: "<< *middle << std::endl;
			return middle;
		}
		if(*middle > value){				
			return bsearchrecursive(first, middle, value);
		}if(*middle < value){
			return bsearchrecursive(middle+1, last, value);
		}
		
		return first;
		
    }


int main(){
	srand(time(NULL));
	size_t numeroElementos = 5;
	//size_t numeroElementos = rand() % 10;

	int array[numeroElementos]{0,1,1,2,4};
	
	/**int matriz[][SIZE]
	{
		{10, 18, 27},
		{41, 50, 45},
		{38, 21, 12},
	};**/
	size_t array_sz{sizeof(array)/sizeof(array[0])};

	/*for(size_t i=0; i<numeroElementos; i++){
		array[i]=(rand() % 101);
	}*/
    
   	int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    printArray( std::begin(A), std::end(A) );
    for ( const auto & e : A )
        {
            auto result = bsearchrecursive( std::begin(A), std::end(A), e );
            ( result == std::end(A) ) ?
            std::cout << "Search failed!\n" :
            std::cout << "Located target "<< e <<" element at position " << std::distance( std::begin(A), result ) << std::endl;
        }
	//imprimirResultado(run_q01(array, &array[array_sz]));
	//imprimirResultado(array, run_q07(array, 0, array_sz));
	//q04();
	//q11();
	//printMatriz(matriz);
	return 0;
}
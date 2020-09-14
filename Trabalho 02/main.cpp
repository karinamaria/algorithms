#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#define SIZE 3

void printArray(int *first, int *last){
	std::cout << "\nArray [ ";
	while(first != last){
		std::cout << *first++ << " ";
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

void imprimirResultado(int *result){
	if(result == nullptr){
		std::cout << "\n:::::::: ARRAY VAZIO ::::::::" << std::endl;
	}else{
		std::cout << "\n-------- RESULTADO: " << *result << " --------" << std::endl;
	}
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

int* run_q02(int *first, int *last){
	return nullptr;
}

int main(){
	srand(time(NULL));
	size_t numeroElementos = rand() % 10;

	int array[numeroElementos];
	int matriz[][SIZE]
	{
		{10, 18, 27},
		{41, 50, 45},
		{38, 21, 12},
	};
	size_t array_sz{sizeof(array)/sizeof(array[0])};

	for(size_t i=0; i<numeroElementos; i++){
		array[i]=(rand() % 101);
	}
	

	//imprimirResultado(run_q01(array, &array[array_sz]));
	printMatriz(matriz);
	return 0;
}
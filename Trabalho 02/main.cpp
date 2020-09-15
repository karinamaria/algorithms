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

void imprimirResultado(int *result){
	if(result == nullptr){
		std::cout << "\n:::::::: ARRAY VAZIO OU NADA FOI ENCONTRADO ::::::::" << std::endl;
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

int main(){
	srand(time(NULL));
	size_t numeroElementos = 5;
	//size_t numeroElementos = rand() % 10;

	int array[numeroElementos]{0,2,9,11,16};
	
	int matriz[][SIZE]
	{
		{10, 18, 27},
		{41, 50, 45},
		{38, 21, 12},
	};
	size_t array_sz{sizeof(array)/sizeof(array[0])};

	/*for(size_t i=0; i<numeroElementos; i++){
		array[i]=(rand() % 101);
	}*/
	

	//imprimirResultado(run_q01(array, &array[array_sz]));
	imprimirResultado(run_q07(array, 0, array_sz));
	//printMatriz(matriz);
	return 0;
}
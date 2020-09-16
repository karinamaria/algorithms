/**Identity. Given an array a of N distinct integers (positive or negative) in ascending order.
Write a function that receives an array and finds an index i such that a[i] = i if
such an index exists.**/
#include <iostream>

void printArray(int A[], int inicio, int fim){
	std::cout << "A [ ";
	for ( int i {0} ; i < (fim-inicio) ; ++ i ){
		std::cout << A[i] << " ";
	}
	std::cout << "]\n";
}

int* run_q07(int array[], int inicio, int fim){
	printArray(array, inicio, fim);
	int i;
	
	while(inicio < fim){
		i = (inicio + fim)/2;
        std::cout << "i: " << i << std::endl;
        std::cout << "array[i]: " << array[i] << std::endl;
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
    int array[]{-2,0,1,3,5};
    size_t array_sz{sizeof(array)/sizeof(array[0])};

    int *result = run_q07(array, 0, array_sz);

    if(result == nullptr){
		std::cout << ":::::::: ARRAY VAZIO OU NADA FOI ENCONTRADO ::::::::" << std::endl;
	}else{
		std::cout << "-------- O INDICE: " << std::distance(array, result) << " POSSUI O NUMERO: " << *result<<
        " --------" << std::endl;
		
	}

    return 0; 
}
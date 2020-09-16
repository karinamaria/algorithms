/**Binary search with duplicates. Modify binary search function so that it 
always returns the smallest index of a key of an item matching the search key.**/

#include <iostream>

void printArray(int *first, int *last){
	std::cout << "\nArray [ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]\n";
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

int main(){
    size_t numeroElementos = 5;

	int array[numeroElementos]{0,1,1,4,5};
    int chave{1};

	size_t array_sz{sizeof(array)/sizeof(array[0])};

	int *result = run_q04(array, &array[array_sz],chave);
	
    std::cout << "PROCURANDO O NUMERO "<< chave << std::endl;
	if(result == &array[array_sz]){
		std::cout << "-------- A CHAVE NAO FOI ENCONTRADA --------\n";
	}else{
		std::cout << "-------- NUMERO ENCONTRADO NO INDICE: " << std::distance(array, result) << " --------" << std::endl;
	}
}
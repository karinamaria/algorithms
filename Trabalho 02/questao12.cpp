/**Sum of two. Given two arrays A and B of at most N integers each, write a function
that receives these arrays and determines whether the sum of any two distinct integers
in A equals an integer in B. The function should return the three indices, two from
A and one from B, for which the sum is true. In case there are no such indexes, your
function should return three invalid locations (see the last paragraph in Section 2).**/

#include <iostream>
#include <tuple>

void printArray(int *first, int *last){
	std::cout << "\nArray [ ";
	while(first != last){
		std::cout << *first++ << " ";
	}
	std::cout << "]\n";
}

std::tuple<bool, int, int> run_q12(int A[], size_t array_sz, int value){
    
	for(size_t i=0; i<array_sz; i++){
         for (size_t j=i; j<array_sz; j++){
            if((A[i]+A[j]) == value && i!=j ){
               return std::make_tuple(true, i, j);
            }
         }
      }

	return std::make_tuple(false, -1, -1);
}

std::tuple<bool, int, int, int> q12(int *A, int B[], size_t a_sz, size_t b_sz){
	bool existSoma = false;
    std::cout << "A: " << a_sz << " B: " << b_sz << std::endl;
	std::cout << "-------- ARRAY A --------\n";
	printArray(A, &A[a_sz]);
	std::cout << "-------- ARRAY B --------\n";
	printArray(B, &B[b_sz]);

	for(size_t i=0; i<(b_sz) || existSoma; i++){
		auto tupla = run_q12(A, a_sz, B[i]);
		existSoma = std::get<0>(tupla);
		if(existSoma){
            return std::make_tuple(true, std::get<1>(tupla), std::get<2>(tupla), i);
		}
	}
    return std::make_tuple(false, -1, -1, -1);
}

int main(){
    bool existSoma = false;

	size_t numeroElementos = 5;
	int A[numeroElementos]{0,1,1,2,4};
	int B[numeroElementos]{3,5,8,9,10};

    auto tupla = q12(A,B, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]));
    existSoma =  std::get<0>(tupla);
    if(existSoma){
        std::cout	<< "-------- SOMA ENCONTRADA --------\nOs elementos de indice " << std::get<1>(tupla) << " e " << std::get<2>(tupla)
					<< " do vetor A resultam no elemento de indice " << std::get<3>(tupla) << " do vetor B\n";
	}



    return 0;
}
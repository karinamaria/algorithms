/**
Find a duplicate. Given an array of N elements in which each element is an integer
between 1 and N , write function to determine if there are any duplicates. Your algorithm
should run in linear time and use O(1) extra space
**/

#include <iostream>

int main(){
	int n=7, absoluto;
	int A[]{6,3,1,4,5,2,7};
	bool duplicata = false;

	std::cout << "----- PROCURANDO DUPLICATAS ---- " << std::endl;
	for(int i{0}; i<n; ++i){
		absoluto = (A[i] < 0) ? -1*A[i] :  A[i];
		if(A[absoluto] < 0){
			duplicata=true;
			std::cout << absoluto << " "; 	
		}
		else{
    		A[absoluto] = -A[absoluto]; 
		}
	}
	if(!duplicata){
		std::cout << "NENHUMA DUPLICADA ENCONTRADA" << std::endl;
	}
	return 0;
}
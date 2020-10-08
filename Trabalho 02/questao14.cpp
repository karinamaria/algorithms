#include <iostream>

int* lower_bound(int *first, int *last, int value ){
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

int* upper_bound(int *first, int *last, int value ){
    int count = last-first;
    while(count != 0){
        int step = count/2;
        int *mid = first+ step;
        if(!(value<*mid)){
            first = mid+1;
            count = count - (step+1); 
        }else{
            count = step;
        }
    }
    return first;
}


int main(){
    int A[]{0,2,3,5,5}, *lower, *upper;
    size_t a_sz{sizeof(A)/sizeof(A[0])};
    bool existeDuplicata = false;

   
    for(int i=0; i<int(a_sz); i++){
        lower = lower_bound(A, &A[a_sz], A[i]); 
        upper =  upper_bound(A, &A[a_sz], A[i]);
      
        if(upper-lower > 1){
            existeDuplicata=true;
            std::cout << "Duplicata encontrada com o valor: " << A[i] << std::endl;
            break;
        } 
    }

    if(!existeDuplicata){
        std::cout << "Nenhuma duplicata encontrada" << std::endl;
    }

    return 0;
}
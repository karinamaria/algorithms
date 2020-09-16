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
    int A[]{0,1,1,2,4};
    size_t a_sz{sizeof(A)/sizeof(A[0])};
    int *lower, *upper;

    for(size_t i{0}; i < a_sz; i++){
        
    }

    return 0;
}
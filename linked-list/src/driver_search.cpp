#include <iostream>
#include <list>

#include "list.h"

int main(){
	sc::list<int> seq { 1, 2, 3, 4, 5 };

    // removing a segment from the beginning.
    auto past_last = seq.erase( seq.begin(), std::next(seq.begin(),3) );
    std::cout << "begin: " << *(seq.begin()) << std::endl;
    std::cout << "seq.begin() == past_last :" << (seq.begin() == past_last) << std::endl;
	for(auto itr = seq.begin(); itr != seq.end(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
	return 0;
}
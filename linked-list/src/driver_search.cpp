#include <iostream>
#include <list>

#include "list.h"

int main(){
	sc::list<int> seq{ 1, 2, 3, 4, 5 };
    sc::list<int> seq2(10);
	//std::list<int> seq1 { 1, 2, 3, 4, 5 };
	//sc::list<int> a{ 1, 2, 3, 4, 5 };;
	// a.insert(a.begin(), 1);
	
	// a.insert(a.begin(), 5);
	
	//a.insert( std::next( a.begin(), 1 ), 9)
	//a.insert(a.begin(), seq1.begin(), seq1.end());
	// seq1.insert( seq1.begin(), source.begin(), source.end() );
	// std::cout << "Size: " << seq1.size() << std::endl;
	for(auto itr = seq2.begin(); itr != seq2.end(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
	return 0;
}
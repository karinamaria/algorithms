#include <iostream>

#include "list.h"

int main(){
	sc::list<int> a;
	a.insert(a.begin(), 5);
	
	a.insert(a.begin(), 1);
	
	a.insert( a.end(), 3 );
	std::cout << "Size: " << a.size() << std::endl;
	for(auto itr = a.begin(); itr != a.end(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
	return 0;
}
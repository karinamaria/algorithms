#include <iostream>

#include "list.h"

int main(){
	sc::list<int> a;
	a.push_front(5);
	
	a.push_front(1);
	
	a.push_back(3);
	std::cout << "Size: " << a.size() << std::endl;
	for(auto itr = a.begin(); itr != a.end(); ++itr){
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
	return 0;
}
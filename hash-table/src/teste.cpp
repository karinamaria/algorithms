#include <iostream>
#include <functional>
#include <tuple>
#include <cassert>

#include "../include/hashtbl.h"
#include "../include/account.h"

using namespace MyHashTable;

int main(){
	Account acct("Alex Bastos", 1, 1668, 54321, 1500.f);
	Account acct2("Alex Bastos", 1, 1668, 54321, 1500.f);
    Account myAccounts[] =
    {
        {"Alex Bastos", 1, 1668, 54321, 1500.f},
        {"Aline Souza", 1, 1668, 45794, 530.f},
        {"Cristiano Ronaldo", 13, 557, 87629, 150000.f},
        {"Jose Lima", 18, 331, 1231, 850.f},
        {"Saulo Cunha", 116, 666, 1, 5490.f},
        {"Lima Junior", 12, 123, 5671, 150.f},
        {"Carlito Pardo", 28, 506, 9816, 50.f},
        {"Januario Medeiros", 17, 324, 7777, 4850.f}
    };
    std::cout << ">>> Lista de Contas: " << std::endl;	

    for( auto & e : myAccounts )
        std::cout << e << std::endl;
    std::cout << std::endl;
    // Cria uma tabela de dispersao com capacidade p 23 elementos
    HashTbl< Account::AcctKey, Account, KeyHash, KeyEqual > contas( 4 );

    contas.insert( acct.getKey(), acct );
    HashTbl< Account::AcctKey, Account, KeyHash, KeyEqual > testes;
    testes = contas;
    testes.print();
    std::cout << ">>> Inserindo \"" << acct.m_name << "\"\n";
    std::cout << ">>> Insercao \n" << testes.at(acct.getKey()) << std::endl;
    
	return 0;
}
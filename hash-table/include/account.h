/*!
 * @file account.h
 * @brief Definição da struct Account.
 * @date 30 de novembro de 2020
 * @author Karina Maria
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <functional>
#include <tuple>

/// Representa uma conta
struct Account{

	std::string m_name; //!< client name.
	int m_bank_code;    //!< id do banco.
	int m_branch_code;  //!< id da agencia.
	int m_number;       //!< número da conta.
	float m_balance;    //!< saldo da conta.

    /// Apelido para chave da conta
    using AcctKey = std::tuple< std::string, int, int, int >;

    /// Construtor básico
    Account( std::string = "<empty>", int = 0, int = 0, int = 0, float = 0.f );
		     
	/// Retorna a chave da conta.
	AcctKey getKey(void) const;
	
	/// Extrator de fluxo das informações da conta.
	friend std::ostream &operator<< ( std::ostream & _os, const Account & _acct );
};

/// Comparar duas contas;
bool operator==( const Account & a, const Account & b );

/// Functor que gera um número hash para uma determinada conta.
struct KeyHash{
    std::size_t operator()( const Account::AcctKey & ) const;
};


// Functor que testa se duas chaves são iguais
struct KeyEqual{
	bool operator()( const Account::AcctKey & , const Account::AcctKey & ) const;
};

#endif

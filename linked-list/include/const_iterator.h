#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H

#include "node.h"

class const_iterator {
	public :
		//======================================================================
        //== Método Especial.
        //----------------------------------------------------------------------
		/// Construtor Padrão
		const_iterator( ) : current{ nullptr } { /**/ }

		//======================================================================
        //== Sobrecarga de operadores.
        //----------------------------------------------------------------------
		
		/// Retorna uma referência ao objeto localizado na posição apontada pelo iterador
		const Object&   operator*( ) const { 
			return current->data; 
		}
		/// Avança o iterador em uma posição (pré-incremento).
		const_iterator& operator++( ) { 
			current=current->next; 
			return *this; 
		}
		/// Avança o iterador em uma posição (pós-incremento).
		const_iterator  operator++( int ) { 
			const_iterator other{*this};  
			current=current->next;
			return other;
		}
		/// Decresce o iterador em uma posição (pré-decremento).
		const_iterator& operator--( ) { 
			current=current->prev; 
			return *this;
		}
		/// Decresce o iterador em uma posição (pós-decremento).
		const_iterator  operator--( int ) {
			const_iterator other{*this};
			current=current->prev;
			return other;
		}
		/// Verifica se dois iteradores são iguais.
		bool operator== ( const const_iterator & rhs ) const { 
			return current == rhs.current; 
		}
		/// Verifica se dois iteradores são diferentes.
		bool operator!= ( const const_iterator & rhs ) const {
			return current != rhs.current;
		}
	
	protected :
		Node *current; //<! Nó `current`
		const_iterator( Node* p ) : current( p ); //<! Construtor protected
		friend class list<Object>; //<! Indicativo que `list` é classe friend
};

#endif
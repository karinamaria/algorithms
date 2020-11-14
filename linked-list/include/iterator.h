#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include "const_iterator.h"

class iterator : public const_iterator {
	public :
		//======================================================================
        //== Método Especial.
        //----------------------------------------------------------------------
		/// Construtor Padrão
		iterator( ) : const_iterator( ) { /* Empty */ }

		//======================================================================
        //== Sobrecarga de operadores.
        //----------------------------------------------------------------------

		/// Retorna uma referência constante ao objeto localizado na posição apontada pelo iterador
		const Object & operator*( ) const { return current->data; }
		/// Retorna uma referência ao objeto localizado na posição apontada pelo iterador
		Object& operator*( ) { return  current->data};
		/// Avança o iterador em uma posição (pré-incremento).
		iterator& operator++( ){
			current=current->next; 
			return *this; 
		}
		/// Avança o iterador em uma posição (pós-incremento).
		iterator  operator++( int ){
			const_iterator other{*this};  
			current=current->next;
			return other;
		}
		/// Decresce o iterador em uma posição (pré-decremento).
		iterator& operator--( ){
			current=current->prev; 
			return *this;
		}
		/// Decresce o iterador em uma posição (pós-decremento).
		iterator  operator--( int ){
			const_iterator other{*this};
			current=current->prev;
			return other;
		}

	protected :
		iterator( Node *p ) : const_iterator( p ); //<! Construtor protected
		friend class list<Object>; //<! Indicativo que `list` é classe friend
};

#endif
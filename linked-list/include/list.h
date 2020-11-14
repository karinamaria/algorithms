#ifndef LIST_H
#define LIST_H

#include "node.h"
#include "iterator.h"
#include "const_iterator.h"

/*!
 * @file list.h
 * @brief Definição da classe list.
 * @date 12 de novembro de 2020
 * @author Karina Maria
 */
namespace sc {

    template < typename T >
    class list {
        public:
            // Apelidos para os tipos
            using size_type = unsigned long; //!< O tipo do tamanho.
        
        public:
            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------
            /// Construtor padrão que cria uma lista vazia.
            list( ){

            }
            /// Constrói a lista com a contagem de instâncias inseridas por padrão de T.
            explicit list( size_type count ){

            }
            /// Constrói a lista com o conteúdo do intervalo [first, last)
            template< typename InputIt >
            list( InputIt first, InputIt last ){

            }
            /// Construtor  de cópia
            list( const list& other ){

            }
            /// Construtor que recebe uma lista inicializadora.
            list( std::initializer_list<T> ilist ){
                
            }
            /// Destrutor da lista
            ~list( ){
                //chamar método clear
                delete m_head; 
                delete m_tail;
            }
            /// Atribui cópia dos elementos de uma lista a outra
            list& operator=( const list& other ){

            }
            /// Atribui os elementos de uma lista inicializadora a lista
            list& operator=( std::initializer_list<T> ilist ){

            }

            //======================================================================
            //== Métodos Iteradores
            //----------------------------------------------------------------------
            
            /// Iterador para o ínicio da lista
            iterator begin( ) {
                if(size != 0){
                    return iterator(&m_head->next);
                } 
            }
            /// Iterador constante para o ínicio do final.
            const_iterator cbegin( ) const{
                 if(size != 0){
                    return const_iterator(&m_head->next);
                } 
            }
            /// Iterador para o final da lista
            iterator end( ){
                return iterator(&m_tail);
            }
            /// Iterador constante para o final da lista
            const_iterator cend( ) const{
                return const_iterator(&m_tail);
            }
        private:
            //== Membro da classe
            size_type m_size; //!< Quantidade de elementos na list.
            Node *m_head; //!< Nó cabeçalho da list.
            Node *m_tail; //!< Nó cauda da list.
    };
}

#endif
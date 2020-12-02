/*!
 * @file hashtbl.h
 * @brief Definição da hash table.
 * @date 30 de novembro de 2020
 * @author Karina Maria
 */

#ifndef _HASHTBL_H_
#define _HASHTBL_H_

#include <iostream>
#include <forward_list> // forward_list

using namespace std;

namespace MyHashTable {

    template<class KeyType, class DataType>
    class HashEntry{
        public:

            KeyType m_key;  // Armazena a chave associada a informacao
            DataType m_data;// A informacao.

            HashEntry( KeyType kt_, DataType dt_ ) : m_key(kt_), m_data(dt_)
            {/*Empty*/}
    };

    template < typename KeyType ,
               typename DataType ,
               typename KeyHash = std::hash < KeyType >,
               typename KeyEqual = std::equal_to < KeyType > >
    class HashTbl{
        public:
            // Aliases
            using entry_type = HashEntry<KeyType,DataType>;
            using list_type = std::forward_list< entry_type >;
            using size_type = std::size_t;

            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------
            explicit HashTbl( int TableSz_ = DEFAULT_SIZE ){
                m_size = next_prime(TableSz_);
                m_count = 0;
                m_data_table = new list_type(m_size);

            }
            HashTbl( const HashTbl& );
            HashTbl( const std::initializer_list< entry_type > & );
            HashTbl& operator=( const HashTbl& );
            HashTbl& operator=( const std::initializer_list< entry_type > & );
            virtual ~HashTbl();

            //======================================================================
            //== Métodos modificadores
            //----------------------------------------------------------------------
            bool insert( const KeyType &, const DataType &  );
            bool retrieve( const KeyType &, DataType & ) const;
            bool erase( const KeyType & );
            void clear();

            //======================================================================
            //== Métodos de capacidade
            //----------------------------------------------------------------------
            
            ///Retorna ^true` se a tabela de dispersão estiver vazia, ou `false` caso contrário.
            bool empty() const { return m_count==0; }
            inline size_type size() const { return m_count; }

            //======================================================================
            //== Métodos de acesso
            //----------------------------------------------------------------------
            DataType& at( const KeyType& );
            DataType& operator[]( const KeyType& );
            size_type count( const KeyType& ) const;
            void print();
            friend std::ostream & operator<<( std::ostream & os_, const HashTbl & ht_ ){
                // TODO
                return os_;
            }
            //======================================================================
            //== Métodos para buscar próximo número primo
            //----------------------------------------------------------------------
            /// Retorna `true`, se o nº eh primo. Caso contrário, retorna `false`
            bool is_prime(unsigned int n){
                if(n == 1) { return false; }

                for(int i=2; i<n; i++){
                    if(n%i == 0){ 
                        return false;//existe mais de dois divisores
                    }
                }
                return true;//apenas dois divisores
            }
            /// Retorna o primeiro nº primeiro maior ou igual a `n`
            unsigned int next_prime(unsigned int n){
                while(!is_prime(n)){
                    n++;
                }
                return n;
            }

      
        private:
            //=== Métodos privados
            void rehash();        //!< Change Hash table size if load factor >1.0
            
        private:
            //=== Membros privados
            unsigned int m_size;  //!< Tamanho da tabela.
            unsigned int m_count; //!< Numero de elementos na tabela. 
            std::forward_list< entry_type > *m_data_table; //!< Tabela de listas para entradas de tabela.
            // std::unique_ptr< std::forward_list< entry_type > [] > m_data_table;
            static const short DEFAULT_SIZE = 11;
    };

} // MyHashTable
#include "hashtbl.inl"
#endif












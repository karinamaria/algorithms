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
            /// Construtor Padrão
            explicit HashTbl( int TableSz_ = DEFAULT_SIZE ){
                m_size = next_prime(TableSz_);
                m_count = 0;
                m_data_table = new list_type[m_size];

            }
            /// Construtor  de cópia
            HashTbl( const HashTbl& other){
                clear();
                m_size = other.m_size;
                m_data_table = new list_type[m_size];

                for(unsigned int i = 0; i <= other.m_size; i++){
                    for(auto it=other.m_data_table[i].begin(); it!=other.m_data_table[i].end(); it++){
                        insert(it->m_key, it->m_data);
                    }
                }
                
            }
            /// Construtor que recebe uma lista inicializadora.
            HashTbl( const std::initializer_list< entry_type > & ilist){
                clear();
                m_size = ilist.m_size;
                m_data_table = new list_type[m_size];

                for(unsigned int i=0; i <= ilist.m_size; i++){
                    for(auto it=ilist.m_data_table[i].begin; it!=ilist.m_data_table[i].end(); it++){
                        insert(it->m_key, it->m_data);
                    }
                }

            }
            /// Atribui cópia dos elementos de uma lista a outra
            HashTbl& operator=( const HashTbl& other){
                clear();
                for(unsigned int i = 0; i <= other.m_size; i++){
                    for(auto it=other.m_data_table[i].begin(); it!=other.m_data_table[i].end(); it++){
                        insert(it->m_key, it->m_data);
                    }
                }
                return *this;
            }
            /// Atribui os elementos de uma lista inicializadora a lista
            HashTbl& operator=( const std::initializer_list< entry_type > & ilist){
                clear();
                for(unsigned int i=0; i <= ilist.m_size; i++){
                    for(auto it=ilist.m_data_table[i].begin; it!=ilist.m_data_table[i].end(); it++){
                        insert(it->m_key, it->m_data);
                    }
                }
                return *this;
            }
            virtual ~HashTbl(){
                clear();
                delete [] m_data_table;
            }

            //======================================================================
            //== Métodos modificadores
            //----------------------------------------------------------------------
            
            //! Insere na tabela a informação contida em `d_` e associada a uma chave `k_`
            /*!
             * @param k_ referência ao tipo da chave
             * @param d_ referência ao tipo de dado a ser armazenado
             * @return `true` se o dado está sendo inserindo a primeira vez e `false`, caso contrário
             */
            bool insert( const KeyType & k_, const DataType & d_){
                // calcular fator de carga
                auto loadFactor = (m_count / m_size);
                if( loadFactor >= 1.0){ /* chamar rehash() */}

                KeyHash hashFunc;
                KeyEqual equalFunc;
                entry_type new_entry (k_, d_);//criar nova entrada p/ tabela
                
                auto end = hashFunc(k_)%m_size;
                if(!m_data_table[end].empty()){
                    for(auto i=m_data_table[end].begin(); i != m_data_table[end].end(); i++){
                        if(equalFunc(i->m_key, new_entry.m_key)){
                            i->m_data = new_entry.m_data;
                            return false;
                        }
                    }
                }

                //Não existe nenhum elemento no indice ou nenhum elemento corresponde a chave `k_`
                m_count++;
                m_data_table[end].push_front(new_entry);

                return true;
            }
            //! Recupera em `d_` a informação associada a chave `k_`
            /*!
             * @param k_ referência ao tipo da chave
             * @param d_ referência ao tipo de dado a ser armazenado
             * @return `true` se a chave for encontrada e `false`, caso contrário
             */
            bool retrieve( const KeyType & k_, DataType & d_) const{
                KeyHash hashFunc;
                KeyEqual equalFunc;

                auto end = hashFunc(k_)%m_size;

                for(auto it=m_data_table[end].begin(); it != m_data_table[end].end(); it++){
                    if(equalFunc(k_, it->m_key)){
                        d_=it->m_data;
                        return true;
                    }
                }
                return false;
            }

            //! Remove um item de tabela identificado por sua chave `k_`
            /*!
             * @param k_ referência ao tipo da chave
             * @return `true` se a chave for encontrada e `false`, caso contrário
             */
            bool erase( const KeyType & k_){
                KeyHash hashFunc;
                KeyEqual equalFunc;

                auto end = hashFunc(k_)%m_size;

                for(auto i=m_data_table[end].begin; i!= m_data_table[end]; i++){
                    if(equalFunc(i->m_key, k_)){
                        m_data_table[end].remove(i);
                        m_count--;
                        return true;
                    }
                }
                return false;

            }
            /// Limpa toda a memória associada às listas de colisão da tabela
            void clear(){
                for(size_type i=0; i<m_size; i++){
                    m_data_table[i].clear();
                }
                
                m_count=0;
            }

            //======================================================================
            //== Métodos de capacidade
            //----------------------------------------------------------------------
            
            /// Retorna `true` se a tabela de dispersão estiver vazia, ou `false` caso contrário.
            bool empty() const { return m_count==0; }
            /// Retorna a quantidade de elemento atualmente armazenados na tabela.
            inline size_type size() const { return m_count; }

            //======================================================================
            //== Métodos de acesso
            //----------------------------------------------------------------------
            /// Retorna uma referência para o dado associado a chave `k_` fornecida.
            DataType& at( const KeyType& k_ ){
                KeyHash hashFunc;
                KeyEqual equalFunc;
                
                auto end = hashFunc(k_)%m_size;

                for(auto i=m_data_table[end].begin(); i != m_data_table[end].end(); i++){
                    if(equalFunc(i->m_key, k_)){
                        return i->m_data;
                    }
                }
                throw std::out_of_range("A chave não foi encontrada");
            }
            /**!
            *Retorna uma referência para o dado associado a chave k_ fornecida, se
             existir. Se a chave não estiver na tabela, o método realizar a inserção e retorna a referência
             para o dado recém inserido na tabela.
            **/
            DataType& operator[]( const KeyType& k_){
                KeyHash hashFunc;
                KeyEqual equalFunc;
                
                auto end = hashFunc(k_)%m_size;

                for(auto i=m_data_table[end].begin(); i != m_data_table[end].end(); i++){
                    if(equalFunc(i->m_key, k_)){
                        return i->m_data;
                    }
                }
                DataType d_;
                insert(k_, d_);

                return d_;
            }
            ///Retorna a qnt de elementos da tabela que estão na lista de colisão associada a chave k_
            size_type count( const KeyType& k_) const{
                size_type count = 0;

                KeyHash hashFunc;
                KeyEqual equalFunc;
                
                auto end = hashFunc(k_)%m_size;

                for(auto i=m_data_table[end].begin(); i != m_data_table[end].end(); i++){
                    count++;
                }
                return count;
            }

            /// Imprimir as informações da conta
            void print(){
                for(size_type i=0; i< m_size; i++){
                   std::cout << "\n[" << i << "]->";
                    if(m_data_table[i].empty()){
                        std::cout << "'Empty'";
                    }
                    for(auto it=m_data_table[i].begin(); it!= m_data_table[i].end(); it++){
                        std::cout << "\n" << it->m_data << "";
                    }
                }
                std::cout << "\n";
            }

            ///Gerar uma representação textual da tabela e seus elementos.
            friend std::ostream & operator<<( std::ostream & os_, const HashTbl & ht_ ){
                for(size_type i=0; i<ht_.m_size; i++){
                    os_ << "\n[" << i << "]->";
                    if(ht_.m_data_table[i].empty()){
                        std::cout << "'Empty'";
                    }
                    for(auto it=ht_.m_data_table[i].cbegin(); it!= ht_.m_data_table[i].cend(); it++){
                        os_ << "\n" << it->m_data;
                    }
                }
                os_ << "\n";
                return os_;
            }
            //======================================================================
            //== Métodos para buscar próximo número primo
            //----------------------------------------------------------------------
            /// Retorna `true`, se o nº eh primo. Caso contrário, retorna `false`
            bool is_prime(unsigned int n){
                if(n <= 1) { return false; }

                for(unsigned int i=2; i<n; i++){
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
            list_type *m_data_table; //!< Tabela de listas para entradas de tabela.
            //std::unique_ptr< std::forward_list< entry_type > [] > m_data_table;
            static const short DEFAULT_SIZE = 11;
    };

} // MyHashTable

#endif
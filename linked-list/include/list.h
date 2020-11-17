#ifndef LIST_H
#define LIST_H

/*!
 * @file list.h
 * @brief Definição da classe list.
 * @date 12 de novembro de 2020
 * @author Karina Maria
 */
namespace sc {

    template < typename T >
    class list {
        private:
            /*!
             * @brief Definição da struct `Node`
             */
            struct Node {
                T data;     //<! Campo de dados
                Node *prev; //<! Ponteiro para o nó anterior na lista.
                Node *next; //<! Ponteiro para o próximo nó na lista.
                // <! Construtor básico.
                Node( const T& d = T( ), Node* p = nullptr, Node* n = nullptr )
                : data( d ), prev( p ), next( n ) { /* Vazio */ }
            };

        public:
            using size_type = unsigned long; //!< Apelido para o tipo do tamanho.
            
            /*!
             * @brief Definição da classe `const_iterator`
             */
            class const_iterator {
                public :
                    //======================================================================
                    //== Método Especial.
                    //----------------------------------------------------------------------
                    /// Construtor Padrão
                    const_iterator( ) : current{ nullptr }{ /* Empty */ };

                    //======================================================================
                    //== Sobrecarga de operadores.
                    //----------------------------------------------------------------------
                    
                    /// Retorna uma referência ao objeto localizado na posição apontada pelo iterador
                    const T&   operator*( ) const{ return current->data; }
                    /// Avança o iterador em uma posição (pré-incremento).
                    const_iterator& operator++( ){ current=current->next; return *this; }
                    /// Avança o iterador em uma posição (pós-incremento).
                    const_iterator  operator++( int ){ const_iterator other{*this}; current=current->next; return other; }
                    /// Decresce o iterador em uma posição (pré-decremento).
                    const_iterator& operator--( ){ current=current->prev; return *this; }
                    /// Decresce o iterador em uma posição (pós-decremento).
                    const_iterator  operator--( int ){ const_iterator other{*this}; current=current->prev; return other; }
                    /// Verifica se dois iteradores são iguais.
                    bool operator== ( const const_iterator & rhs ) const{ return current == rhs.current; }
                    /// Verifica se dois iteradores são diferentes.
                    bool operator!= ( const const_iterator & rhs ) const{ return current != rhs.current; }
                
                    protected :
                        Node *current; //<! Nó `current`
                        const_iterator( Node* p ) : current( p ){/* Empty */}; //<! Construtor protected
                        friend class list<T>; //<! Indicativo que `list` é classe friend
            };
            /*!
             * @brief Definição da classe `iterator`
             */
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
                    const T& operator*( ) const{ return this->current->data; }
                    /// Retorna uma referência ao objeto localizado na posição apontada pelo iterador
                    T& operator*( ){ return  this->current->data; }
                    /// Avança o iterador em uma posição (pré-incremento).
                    iterator& operator++( ){ this->current=this->current->next; return *this; }
                    /// Avança o iterador em uma posição (pós-incremento).
                    iterator  operator++( int ){ iterator other{*this};  this->current=this->current->next; return other;}
                    /// Decresce o iterador em uma posição (pré-decremento).
                    iterator& operator--( ){ this->current=this->current->prev; return *this; }
                    /// Decresce o iterador em uma posição (pós-decremento).
                    iterator  operator--( int ){ iterator other{*this}; this->current=this->current->prev; return other;}

                    protected :
                        iterator( Node *p ) : const_iterator(p){ /* Empty */ }; //<! Construtor protected
                        friend class list<T>; //<! Indicativo que `list` é classe friend
            };
        
        
        public:
            //======================================================================
            //== Métodos Especiais
            //----------------------------------------------------------------------
            /// Construtor padrão que cria uma lista vazia.
            list( ){
                m_head = new Node;
                m_tail = new Node;
                m_head->next = m_tail;
                m_tail->prev = m_head;
                m_size = 0;
            }
            /// Constrói a lista com a contagem de instâncias inseridas por padrão de T.
            explicit list( size_type count ) : m_size{count}{

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
                clear();
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
            
            /// Retorna um iterador para o ínicio da lista
            iterator begin( ) {
                return iterator(m_head->next);
                
            }
            /// Retorna um iterador constante para o ínicio do final.
            const_iterator cbegin( ) const{
                return const_iterator(m_head->next);
                
            }
            /// Retorna um iterador para o final da lista
            iterator end( ){
                return iterator(m_tail);
            }
            /// Retorna um iterador constante para o final da lista
            const_iterator cend( ) const{
                return const_iterator(m_tail);
            }

            //======================================================================
            //== Métodos de capacidade
            //----------------------------------------------------------------------
            
            /// Retorna a quantidade de elementos da lista
            size_type size( ) const{ return m_size; }
            /// Retorna se a lista está vazia
            bool empty( ) const{ return m_size == 0; }


            //======================================================================
            //== Métodos modificadores
            //----------------------------------------------------------------------
            /// Remove todos os elementos do vetor
            void clear( ){
                while(!empty()){
                    pop_front();
                }
            }
            /// Adiciona `value` no inicio da lista
            void push_front( const T & value ){
                insert(begin(), value);
            }
            /// Adiciona `value` no fim da lista
            void push_back( const T & value ){
                insert(end(), value);
            }
            /// Remove o elemento do final da lista;
            void pop_back(){
                erase(--end());
            }
            /// Remove o elemento do início da lista;
            void pop_front(){
                erase(begin());
            }
            /// Retorna um objeto para o fim da lista
            const T& back() const{
                return *(--end());
            }
            /// Retorna um objeto para o inicio da lista
            const T& front() const{
                return *(begin());
            }
            //======================================================================
            //== Métodos modificadores com Iteradores
            //----------------------------------------------------------------------
            
            //! Adiciona o `value` antes da posição para que o iterador `pos` aponta
            /*!
             * @param pos iterador
             * @param value valor a ser inserindo
             * @return um iterador para a posição do item inserido.
             */
            iterator insert( iterator pos, const T & value ){
                Node* novo = new Node{ value };

                ++m_size;

                if(pos == end()){
                    novo->next = m_tail;
                    novo->prev = m_tail->prev;
                    (novo->next)->prev = novo;
                    (novo->prev)->next = novo;
                }
                else{
                    Node *temp = pos.current;
                    novo->next = temp;
                    (temp->prev)->next = novo;
                    novo->prev = temp->prev;
                    temp->prev = novo;
                }
                
                return iterator(novo);
            }

            const_iterator insert( const_iterator pos, const T & value ){
                Node* novo = new Node{ value };

                ++m_size;

                if(pos == end()){
                    novo->next = m_tail;
                    novo->prev = m_tail->prev;
                    (novo->next)->prev = novo;
                    (novo->prev)->next = novo;
                }
                else{
                    Node *temp = pos.current;
                    novo->next = temp;
                    (temp->prev)->next = novo;
                    novo->prev = temp->prev;
                    temp->prev = novo;
                }
                
                return const_iterator(novo);
            }

            template < typename InItr>
            /// Adiciona os elementos do intervalo `[first, last)` antes de `pos`
            iterator insert( iterator pos, InItr first, InItr last ){

            }
            iterator insert( const_iterator pos, std::initializer_list<T> ilist ){

            }

            //! Remove o nó para o qual o iterador `pos` aponta
            /*!
             * @param pos iterador
             * @return um iterador para o elemento depois de `pos`
             */
            iterator erase( iterator pos ){
                Node *temp = pos.current;
                (temp->prev)->next = temp->next;
                (temp->next)->prev = temp->prev;
                delete temp;
                --m_size;

                return pos++;
            }
            iterator erase( iterator first, iterator last ){

            }
            void assign( size_type count, const T& value ){

            }
            template < typename InItr>
            void assign( InItr first, InItr last ){

            }
            void assign( std::initializer_list<T> ilist ){

            }
        private:
            //== Membro da classe
            size_type m_size; //!< Quantidade de elementos na list.
            Node *m_head; //!< Nó cabeçalho da list.
            Node *m_tail; //!< Nó cauda da list.
    };
}

#endif
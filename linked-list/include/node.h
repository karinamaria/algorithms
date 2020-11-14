#ifndef NODE_H
#define NODE_H

/*!
 * @file node.h
 * @brief Definição da struct node.
 * @date 12 de novembro de 2020
 * @author Karina Maria
 */

template < typename T >
struct Node {
    T data;     //<! Campo de dados
    Node *prev; //<! Ponteiro para o nó anterior na lista.
    Node *next; //<! Ponteiro para o próximo nó na lista.
    // <! Construtor básico.
    Node( const T& d = T( ), Node* p = nullptr, Node* n = nullptr )
	: data( d ), prev( p ), next( n ) { /* Vazio */ }
};

#endif
/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Implementar os métodos da classe Node

*/

#ifndef NODE_CPP
#define NODE_CPP

// Arquivo de cabeçalho
#include "node.h"

using namespace std;

template <class elementType>
elementType Node<elementType>::getData()
{
  return data;
}

template <class elementType>
Node<elementType> *Node<elementType>::getNext()
{
  return next;
}

template <class elementType>
Node<elementType> *Node<elementType>::getPrev()
{
  return prev;
}

template <class elementType>
void Node<elementType>::setData(const elementType *dataReceived)
{
  data = *dataReceived;
}

template <class elementType>
void Node<elementType>::setPrev(Node<elementType> *node)
{
  prev = node;
}

template <class elementType>
void Node<elementType>::setNext(Node<elementType> *node)
{
  next = node;
}

#endif

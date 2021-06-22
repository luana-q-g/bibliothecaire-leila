/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Arquivo de cabeçalho da classe BaseList

*/

#ifndef BASELIST_H
#define BASELIST_H

// Bibliotecas
#include <iostream>
#include <string>

#include "node/node.h"
#include "node/node.cpp"

using namespace std;

template <class elementType>
class BaseList
{
private:
  Node<elementType> *header;
  Node<elementType> *current;

public:
  BaseList();
  //~BaseList();

  // Getters
  Node<elementType> *getHeader();
  Node<elementType> *getCurrent();

  // Setters
  void setCurrent(Node<elementType> *node);

  // Operações primitivas da lista básica

  // Retorna por referência o ponteiro para o elemento com o dado valor na lista
  bool isInList(elementType *element, Node<elementType> **nodeRef);

  // Insere o elemento dado no próximo elemento a partir do dado nó
  bool insertNode(Node<elementType> *nodeRef, elementType *element);

  // Remove o elemento apontado pelo dado ponteiro
  bool removeNode(Node<elementType> *nodeRef);

  // Retorna o por referência valor armazenado no dado nó
  bool getData(Node<elementType> *node, elementType *element);

  // Retorna se a lista está vazia ou não
  bool empty();

  // Retorna se a lista está cheia ou não
  bool full();

  // Retorna o valor do primeiro elemento da lista
  bool getFirst(elementType *element);

  // Retorna o valor do próximo elemento da lista
  bool getNext(elementType *element);
};

#endif

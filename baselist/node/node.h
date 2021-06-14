/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Arquivo de cabeçalho da classe Node.

A classe node representa cada nó de uma lista encadeada
duplamente encadeada.

*/

#ifndef NODE_H
#define NODE_H

// Bibliotecas
#include <iostream>
#include <string>

using namespace std;

template <class elementType>
class Node
{
private:
  elementType data;
  Node<elementType> *next;
  Node<elementType> *prev;

public:
  elementType getData();

  Node<elementType> *getNext();
  Node<elementType> *getPrev();

  void setData(const elementType *data);
  void setNext(Node<elementType> *node);
  void setPrev(Node<elementType> *node);
};

#endif

/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/05/2021
Data de Atualização: 21/05/2021

Objetivos: Implementar os métodos da classe BaseList

*/

#ifndef BASELIST_CPP
#define BASELIST_CPP

// Arquivo de cabeçalho
#include "baselist.h"
#include <cstddef>

using namespace std;

template <class elementType> BaseList<elementType>::BaseList() {
  header = new Node<elementType>;

  header->setNext(header);
  header->setPrev(header);

  setCurrent(header);
};

// template <class elementType> BaseList<elementType>::~BaseList() {
//   getFirst(NULL);

//   // Delete all nodes (except header)
//   while (getNext(NULL) && current != header) {
//     delete current->getPrev();
//   }

//   // Delete header node
//   delete header;
// };

template <class elementType>
Node<elementType> *BaseList<elementType>::getHeader() {
  return header;
}

template <class elementType>
Node<elementType> *BaseList<elementType>::getCurrent() {
  return current;
}

template <class elementType>
void BaseList<elementType>::setCurrent(Node<elementType> *node) {
  if (node != NULL) {
    current = node;
  }
}

// Retorna por referência o ponteiro para o elemento com o dado valor na lista
template <class elementType>
bool BaseList<elementType>::isInList(elementType *element,
                                     Node<elementType> **nodeRef) {
  // Caso a lista esteja vazia certamente o elemento não está nela
  if (empty()) {
    return false;
  }

  // Elemento para armazenar os valores retornados da lista
  elementType *elementAux = new elementType;

  // Variável de controle
  bool found = false;

  // Atribuindo o valor do elemento buscado no nó header para
  // servir como condição de parada para o loop
  header->setData(element);

  // Obtendo o valor do primeiro elemento e posicionando o ponteiro
  // current para a primeira posicao da lista
  getFirst(elementAux);

  do {
    // Caso o elemento seja encontrado pelo valor
    if (*elementAux == *element) {
      found = true;
    }
  } while (!found && getNext(elementAux));

  // Caso tenha sido encontrado apenas no nó header o
  // elemento não está de fato na lista
  if (current == header) {
    found = false;
  } else {
    // Retornando o ponteiro para o nó atual por referência
    if (nodeRef != NULL) {
      // Atribuindo ao valor do ponteiro passado por referência
      // o endereço do elemento encontrado
      *nodeRef = current;
    }
  }

  return found;
}

// Insere o elemento dado no próximo elemento a partir do dado nó
template <class elementType>
bool BaseList<elementType>::insertNode(Node<elementType> *nodeRef,
                                       elementType *element) {
  if (full() || nodeRef == NULL) {
    return false;
  }

  // Criando um novo nó para o elemento a ser adicionado
  Node<elementType> *newNode = new Node<elementType>;
  newNode->setData(element);

  // Inserindo o elemento a partir do dado nó
  newNode->setPrev(nodeRef);
  newNode->setNext(nodeRef->getNext());

  nodeRef->getNext()->setPrev(newNode);
  nodeRef->setNext(newNode);

  return true;
}

// Remove o elemento apontado pelo dado ponteiro
template <class elementType>
bool BaseList<elementType>::removeNode(Node<elementType> *nodeRef) {
  if (empty() || nodeRef == NULL || nodeRef == header) {
    return false;
  }

  // Caso o ponteiro a ser removido seja o current da lista
  if (nodeRef == current) {
    setCurrent(current->getNext());
  }

  nodeRef->getPrev()->setNext(nodeRef->getNext());
  nodeRef->getNext()->setPrev(nodeRef->getPrev());

  // Liberando o espaço alocado pelo elemento
  delete nodeRef;

  return 1;
}

// Retorna o por referência valor armazenado no dado nó
template <class elementType>
bool BaseList<elementType>::getData(Node<elementType> *node,
                                    elementType *element) {
  if (node != NULL) {
    *element = node->getData();
    return true;
  } else {
    return false;
  }
}

// Retorna se a lista está vazia ou não
template <class elementType> bool BaseList<elementType>::empty() {
  return (header->getNext() == header);
}

// Retorna se a lista está cheia ou não
template <class elementType> bool BaseList<elementType>::full() {
  return false;
}

// Retorna o valor do primeiro elemento da lista
template <class elementType>
bool BaseList<elementType>::getFirst(elementType *element) {
  if (empty()) {
    return false;
  }

  // Movendo o current para o primeiro elemento da lista
  setCurrent(header->getNext());

  // Retornando o valor do elemento por referência
  if (element != NULL) {
    *element = current->getData();
  }

  return true;
}

// Retorna o valor do próximo elemento da lista
template <class elementType>
bool BaseList<elementType>::getNext(elementType *element) {
  // Caso a lista esteja vazia ou tenha chego ao final da lista
  if (empty()) {
    return false;
  }

  // Avançando o ponteiro current
  setCurrent(current->getNext());

  // Retornando o valor do elemento por referência
  if (element != NULL) {
    *element = current->getData();
  }

  return true;
}

#endif

/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Implementar os métodos da classe lista

*/


#ifndef LISTA_CPP
#define LISTA_CPP

// Arquivo de cabeçalho
#include "lista.h"

using namespace std;

template <class elementType>
Lista<elementType>::Lista(string _categoria) : categoria(_categoria) {}

template <class elementType>
bool Lista<elementType>::podeInserir(elementType &element, Node<elementType> *nodeRef)
{
  if (element.getCategoria() == categoria)
  {

    // TODO: Lógica de ordenação da lista
    return true;
  }

  return false;
}

template <class elementType>
bool Lista<elementType>::inserir(elementType &element, Node<elementType> *nodeRef)
{
  if (podeInserir(element, nodeRef))
    return (BaseList<elementType>::insertNode(nodeRef, element));
}

/*
template <class elementType>
bool Lista<elementType>::remover(elementType &element)
{
}
*/

#endif

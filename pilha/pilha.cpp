/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Implementar os métodos da classe pilha

*/


#ifndef PILHA_CPP
#define PILHA_CPP

// Arquivo de cabeçalho
#include "pilha.h"

using namespace std;

template <class elementType>
void Pilha<elementType>::inserir(elementType &element)
{
  BaseList<elementType>::insertNode(BaseList<elementType>::getHeader(), element);
}

template <class elementType>
elementType Pilha<elementType>::remover()
{
  Node<elementType> noRemovido;

  noRemovido.setData(BaseList<elementType>::getHeader()->getNext()->getData());

  BaseList<elementType>::removeNode(BaseList<elementType>::getHeader()->getNext());

  return noRemovido;
}

#endif

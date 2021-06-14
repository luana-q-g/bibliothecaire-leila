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
  /*std::for_each(data.begin(), data.end(), [](char & c) {
        c = ::tolower(c);
    });*/
  if (element.getCategoria() == categoria)
  {
    cout << "Teste";
    // TODO: Lógica de ordenação da lista
    return true;
  }

  return false;
}

template <class elementType>
bool Lista<elementType>::inserir(elementType &element, int posicao)
{
  Node<elementType> *nodeRef = getElemento(posicao);

  if (podeInserir(element, nodeRef))
    return (BaseList<elementType>::insertNode(nodeRef, &element));

  return false;
}

template <class elementType>
Node<elementType> *Lista<elementType>::getElemento(int posicao)
{
  // Inicializando o ponteiro no começo da lista
  BaseList<elementType>::getFirst(NULL);

  // Percorrendo a lista até chegar na posição desejada
  for (int i = 1; i < posicao; i++)
  {
    BaseList<elementType>::getNext(NULL);
  }

  // Retornando o elemento atual após percorrer a lista
  return BaseList<elementType>::getCurrent();
}

template <class elementType>
void Lista<elementType>::imprimir()
{
  if (BaseList<elementType>::empty())
  {
    cout << "A fila está vazia!" << endl;
    return;
  }

  // Elemento auxiliar
  elementType *elementAux = new elementType;

  BaseList<elementType>::getFirst(elementAux);

  Node<elementType> *current = new Node<elementType>;
  Node<elementType> *header = BaseList<elementType>::getHeader();

  // Exibindo todos os elementos
  do
  {
    current = BaseList<elementType>::getCurrent();
    cout << *elementAux << endl;
  } while (BaseList<elementType>::getNext(elementAux) &&
           (current != header));

  cout << endl;
}

#endif

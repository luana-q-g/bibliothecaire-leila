/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Arquivo de cabeçalho da classe lista

*/

#ifndef LISTA_H
#define LISTA_H

// Bibliotecas
#include <iostream>
#include <string>

#include "../baselist/baselist.h"
#include "../baselist/baselist.cpp"

using namespace std;

template <class elementType>
class Lista : public BaseList<elementType>
{
private:
  wstring categoria;

  // Retorna se o dado elemento pode ou não ser inserido na dada posição da lista
  bool podeInserir(elementType &element, Node<elementType> *nodeRef);

  // Retorna um ponteiro para o nó do elemento com base na sua posição de ocorrência na lista
  Node<elementType> *getElemento(int posicao);

public:
  Lista(wstring categoria = L"");
  wstring getCategoria();
  bool inserir(elementType &element, int posicao);
  bool remover(elementType &element);
  void imprimir();
};

#endif

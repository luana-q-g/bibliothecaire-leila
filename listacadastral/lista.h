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
  string categoria;
  bool podeInserir(elementType &element, Node<elementType> *nodeRef);

public:
  Lista(string categoria = "");
  bool inserir(elementType &element, Node<elementType> *nodeRef);
  bool remover(elementType &element);
};

#endif

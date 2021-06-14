/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Arquivo de cabeçalho da classe pilha

*/

#ifndef PILHA_H
#define PILHA_H

// Bibliotecas
#include <iostream>
#include <string>

#include "../baselist/baselist.h"
#include "../baselist/baselist.cpp"

using namespace std;

template <class elementType>
class Pilha : public BaseList<elementType>
{
public:
  void inserir(elementType &element);
  elementType remover();
};

#endif

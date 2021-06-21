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

#include "../baselist/baselist.cpp"
#include "../baselist/baselist.h"

using namespace std;

template <class elementType> class Pilha : public BaseList<elementType> {
private:
  int tam_pilha;

public:
  Pilha();
  Pilha(int _tam_pilha, elementType *lista_fixa);

  void inserir(elementType &element);
  elementType remover();
};

#endif

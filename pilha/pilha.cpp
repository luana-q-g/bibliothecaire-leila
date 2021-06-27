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
Pilha<elementType>::Pilha(): tam_pilha(0){}

template <class elementType>
Pilha<elementType>::Pilha(int tam_pilha, elementType *lista_fixa){
  srand(time(NULL)); // randomize seed
  int indices[tam_pilha];

  for (int i = 0; i < tam_pilha; i++)
  {
    bool tem_num = true;
    int num_aleatorio;

    while (tem_num)
    {
      num_aleatorio = rand() % 36;

      tem_num = false;

      for (int i = 0; i < tam_pilha; i++)
      {
        if (indices[i] == num_aleatorio)
        {
          tem_num = true;
        }
      }
    }

    indices[i] = num_aleatorio;
  }

  for (int i = 0; i < tam_pilha; i++)
  {
    this->inserir(lista_fixa[indices[i]]);
  }
}

template <class elementType>
void Pilha<elementType>::inserir(elementType &element)
{
  BaseList<elementType>::insertNode(BaseList<elementType>::getHeader(), &element);
}

template <class elementType>
elementType Pilha<elementType>::remover()
{
  Node<elementType> noRemovido;
  elementType dataRemovido = BaseList<elementType>::getHeader()->getNext()->getData();

  noRemovido.setData(&dataRemovido);

  BaseList<elementType>::removeNode(BaseList<elementType>::getHeader()->getNext());

  return noRemovido.getData();
}

#endif

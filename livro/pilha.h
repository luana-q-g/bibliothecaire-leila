#ifndef PILHA_H
#define PILHA_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "baselist.h" // Inclua a base de onde `BaseList` vem

template <class elementType>
class Pilha : public BaseList<elementType> {
private:
    int tam_pilha;

public:
    Pilha();
    Pilha(int tam_pilha, const std::vector<elementType>& lista_fixa);
    void inserir(elementType& element); // Removemos o const
    elementType remover();
};

// Implementações dos métodos
template <class elementType>
Pilha<elementType>::Pilha() : tam_pilha(0) {}

template <class elementType>
Pilha<elementType>::Pilha(int tam_pilha, const std::vector<elementType>& lista_fixa) {
    srand(time(NULL)); // Randomize seed
    std::vector<int> indices(tam_pilha);

    for (int i = 0; i < tam_pilha; i++) {
        bool tem_num = true;
        int num_aleatorio;

        while (tem_num) {
            num_aleatorio = rand() % lista_fixa.size();

            tem_num = false;

            for (int j = 0; j < i; j++) {
                if (indices[j] == num_aleatorio) {
                    tem_num = true;
                }
            }
        }

        indices[i] = num_aleatorio;
    }

    for (int i = 0; i < tam_pilha; i++) {
        this->inserir(const_cast<elementType&>(lista_fixa[indices[i]]));
    }
}

template <class elementType>
void Pilha<elementType>::inserir(elementType& element) {
    BaseList<elementType>::insertNode(BaseList<elementType>::getHeader(), &element);
}

template <class elementType>
elementType Pilha<elementType>::remover() {
    Node<elementType> noRemovido;
    elementType dataRemovido = BaseList<elementType>::getHeader()->getNext()->getData();

    noRemovido.setData(&dataRemovido);

    BaseList<elementType>::removeNode(BaseList<elementType>::getHeader()->getNext());

    return noRemovido.getData();
}

#endif

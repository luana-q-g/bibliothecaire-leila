#include <stdexcept>
#include <locale> // Necessário para configurar o locale
#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include <string>
#include <random>
#include <unordered_set>
#include <ctime>
#include <pqxx/pqxx>

#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "baselist/baselist.h"
#include "database/connection.h"

using namespace std;
using namespace sf;

#ifndef ACOESLIVRO_H
#define ACOESLIVRO_H

Color getColorFromString(const string& colorName);
wstring converteString(const pqxx::field& field);
Pilha<Livro> geraPilhaLivros(DatabaseConnection db, int tamanho);
vector<Lista<Livro>> geraListaLivrosCategorias(DatabaseConnection db);

template <class elementType>
Lista<elementType>* buscarListaPorCategoria(vector<Lista<elementType>>& listas, const wstring& categoria) {
    for (auto& lista : listas) {
        if (lista.getCategoria() == categoria) {
            return &lista; // Retorna o ponteiro para a lista encontrada
        }
    }
    return nullptr; // Retorna nullptr se nenhuma lista com a categoria for encontrada
}

Livro getLivroAleatorio(DatabaseConnection db);

#endif
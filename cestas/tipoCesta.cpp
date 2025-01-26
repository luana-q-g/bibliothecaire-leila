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
#include "cesta.h"
#include "acoesLivro.h"

#include "database/connection.h"

#ifndef TIPOCESTA_H
#define TIPOCESTA_H

using namespace std;
using namespace sf;


class tipoCesta {
private:
    std::vector<Cesta> cestas;

    sf::Texture textura;

public:
    tipoCesta(DatabaseConnection db) {

        if (!textura.loadFromFile("./interface/assets/imagens/cesta.png"));
        int basey = 540;

        result res = db.showQuery("SELECT nome, cor FROM Categoria;");

        vector<int> posicoes = {20, 130, 240, 350, 460, 570, 680, 790, 810};
        int i = 0;
        for (const auto& row : res) {
            cout << posicoes[i] << endl;
            wstring categ = converteString(row[0]);
            string cor = row[1].as<string>();
            Color cor_code = getColorFromString(cor);
            cout << cor << endl;
            cestas.emplace_back(categ, sf::Vector2f(posicoes[i],basey), textura, cor_code);
            i++;
        }
    }

std::vector<Cesta> getCesta() const {
        return cestas; // Retorna todos os livros
    }

void printCestaJogo(const std::vector<Cesta>& cestas) {
    std::wcout << L"Lista de cestas:" << std::endl;
    for (const auto& cesta : cestas) {
        std::wcout << L"Categoria: " << cesta.getCategoria() << std::endl;
        std::wcout << L"Posição: (" << cesta.getShape().getPosition().x 
                   << L", " << cesta.getShape().getPosition().y << L")" << std::endl;
        std::wcout << L"----" << std::endl;
    }
}

std::vector<Cesta> escolherCestasJogo(const std::vector<Cesta>& cestas){
    std::vector<Cesta> cestaEscolhidas;
    srand(static_cast<unsigned>(time(nullptr))); 
    float xInicial = 50.0f;
    float yInicial = 540.0f;
    float incrementoX = 110.0f;


    for (int i=0; i<7; i++){
        int indice = rand() % (cestas.size());

        const Cesta& cestaOriginal = cestas[indice]; 
        Cesta novaCesta = cestaOriginal;
    
        novaCesta.setPosition(sf::Vector2f(xInicial + i * incrementoX, yInicial));

        // Adiciona a nova cesta ao vetor de cestas escolhidas
        cestaEscolhidas.push_back(novaCesta);
    }  
    
    return cestaEscolhidas;
}
    

};

#endif
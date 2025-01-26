#include <vector>
#include <ctime>
#include <stdexcept>
#include "cesta.h"
#include <locale> // Necessário para configurar o locale
#include <iostream>

#ifndef TIPOCESTA_H
#define TIPOCESTA_H



class tipoCesta {
private:
    std::vector<Cesta> cestas;

    sf::Texture textura;


    // Retorna uma cor baseada na categoria
    sf::Color obterCorPorCategoria(const std::wstring& categoria) {
        if (categoria == L"Letras") return sf::Color::Blue;
        if (categoria == L"Filosofia") return sf::Color::Green;
        if (categoria == L"Geografia") return sf::Color::Yellow;
        if (categoria == L"História") return sf::Color::Red;
        if (categoria == L"Matemática") return sf::Color::Cyan;
        if (categoria == L"Psicologia") return sf::Color::Magenta;
        if (categoria == L"Informática") return sf::Color::Black;
        if (categoria == L"Química") return sf::Color::White; // Laranja
        if (categoria == L"Arte") return sf::Color(128, 0, 128);    // Roxo
    }

public:
    tipoCesta() {

        if (!textura.loadFromFile("./interface/assets/imagens/cesta.png"));
        int basey = 540;

        cestas.emplace_back(L"Letras",sf::Vector2f(20,basey), textura, obterCorPorCategoria(L"Letras"));
        
        cestas.emplace_back(L"Filosofia",sf::Vector2f(130,basey), textura, obterCorPorCategoria(L"Filosofia"));

        cestas.emplace_back(L"Geografia",sf::Vector2f(240,basey), textura, obterCorPorCategoria(L"Geografia"));

        cestas.emplace_back(L"História",sf::Vector2f(350,basey), textura, obterCorPorCategoria(L"História"));

        cestas.emplace_back(L"Matemática",sf::Vector2f(460,basey), textura, obterCorPorCategoria(L"Matemática"));

        cestas.emplace_back(L"Psicologia",sf::Vector2f(570,basey), textura, obterCorPorCategoria(L"Psicologia"));

        cestas.emplace_back(L"Informática",sf::Vector2f(680,basey), textura, obterCorPorCategoria(L"Informática"));

        cestas.emplace_back(L"Quimica",sf::Vector2f(790,basey), textura, obterCorPorCategoria(L"Quimica"));

        cestas.emplace_back(L"Arte",sf::Vector2f(900,basey), textura, obterCorPorCategoria(L"Arte"));



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
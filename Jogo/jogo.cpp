#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "baselist/baselist.h"
#include <SFML/System/Vector2.hpp>
#include "cestas/tipoCesta.cpp"
#include "cestas/cesta.h"
#include "jogo.h"
#include <thread>
#include <chrono>

int Jogo::getPontuacao(){
        return pontuacao;
}

void Jogo::setPontuacao(int novaPontuacao) {
    pontuacao = novaPontuacao;
}

void Jogo::verificarLivroNaCesta(const Livro& livro,  std::vector<Cesta>& cestas, Jogo& jogo1, float& queda,int& pontosconsec) {
    for (Cesta& cesta : cestas) {
        // Verifica colisão com a cesta
        sf::Vector2f livroCenter = livro.getShape().getPosition() + (livro.getShape().getSize() / 2.0f);
        sf::Vector2f cestaCenter = cesta.getShape().getPosition() + (cesta.getShape().getSize() / 2.0f);

// Calculando a distância entre os centros
        float distanciaX = std::abs(livroCenter.x - cestaCenter.x);
        float distanciaY = std::abs(livroCenter.y - cestaCenter.y);

// Verificar se os centros estão dentro de uma interseção
        if (distanciaX < livro.getShape().getSize().x / 2.0f &&
            distanciaY < livro.getShape().getSize().y / 2.0f) {
            // Verifica se a categoria e cor são iguais
            if (livro.getCategoria() == cesta.getCategoria() &&
                livro.getShape().getFillColor() == cesta.getShape().getFillColor()) {
                jogo1.setPontuacao(jogo1.getPontuacao() + 1);
                pontosconsec++;
                std::wcout << L"SCORE" << std::endl;
                std::wcout << L"Velocidade atual: " << queda << std::endl;

                if (jogo1.getPontuacao() >= 5 && pontosconsec == 2){
                    queda -= 0.4f;
                    std::wcout << L"Velocidade reduzida! Velocidade atual: " << queda << std::endl;
                    pontosconsec = 0;

                }
                else if (jogo1.getPontuacao() >= 20 && pontosconsec == 2){
                    queda -= 1.0f;
                    if (queda == 0.0f)
                    {
                        queda = 0.5f;
                    }
                    std::wcout << L"Velocidade reduzida 20! Velocidade atual: " << queda << std::endl;
                    pontosconsec = 0;
                }
            } 
            else {
                std::wcout << L"Livro caiu na cesta errada." << std::endl;
                std::wcout << L"Velocidade atual: " << queda << std::endl;
                pontosconsec = 0;

            }
         // Sai do loop, pois o livro só pode interagir com uma cesta
        }
    }   
}



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
    int x;
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
                std::wcout << L"Velocidade atual: " << pontosconsec << std::endl;

                if (pontosconsec == 2 && jogo1.getPontuacao() > 10){
                    x = jogo1.getPontuacao() / 10;
                    queda = queda - (0.4f * x);
                    if (queda <= 0){
                        queda = 0.5f;
                    }
                    std::wcout << L"Velocidade reduzida! Velocidade atual: " << queda << std::endl;
                    pontosconsec = 0;

                }
            } 
            else {
                std::wcout << L"Livro caiu na cesta errada." << std::endl;
                std::wcout << L"Velocidade atual: " << queda << std::endl;
                pontosconsec = 0;

                jogo1.setPontuacao(0);
                queda = 0.5f;
                break;
                exit;

            }
         // Sai do loop, pois o livro só pode interagir com uma cesta
        }

    }  

}

void Jogo::desenharNomeLivro(sf::RenderWindow& window, Livro& livroAtual, sf::Font& fonte) {
    sf::Text text;
    text.setFont(fonte);
    text.setString(
        L"Book's Name: \n" +
        livroAtual.getNome() +
        L" " +  
        livroAtual.getAutor() +
        L" em " +
        std::to_wstring(livroAtual.getAnoLancamento()));
    text.setCharacterSize(20);
    text.setFillColor(livroAtual.getCor());
    text.setStyle(sf::Text::Bold);
    text.setPosition(0,200);
    window.draw(text);
}




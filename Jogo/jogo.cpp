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

int Jogo::getPontuacao() const {
        return pontuacao;
}

void Jogo::setPontuacao(int novaPontuacao) {
    pontuacao = novaPontuacao;
}

void Jogo::verificarLivroNaCesta(const Livro& livro, const std::vector<Cesta>& cestas) {
    Jogo jogo1;
    for (const Cesta& cesta : cestas) {
        // Verifica colisão com a cesta
        sf::FloatRect livroBounds = livro.getShape().getGlobalBounds();
        sf::FloatRect cestaBounds = cesta.getShape().getGlobalBounds();

        if (livroBounds.intersects(cestaBounds)) {
            // Verifica se a categoria e cor são iguais
            if (livro.getCategoria() == cesta.getCategoria() &&
                livro.getShape().getFillColor() == cesta.getShape().getFillColor()) {
                jogo1.setPontuacao(jogo1.getPontuacao() + 1);
                std::wcout << L"Ponto ganho! Pontuação atual: " << jogo1.getPontuacao() << std::endl;
            } else {
                std::wcout << L"Livro caiu na cesta errada." << std::endl;
            }
            break; // Sai do loop, pois o livro só pode interagir com uma cesta
        }
    }
}



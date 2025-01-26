#ifndef BOTAOIMAGEM_H
#define BOTAOIMAGEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class BotaoImagem {
private:
    sf::Sprite sprite;      // Sprite que usa a textura como base
    sf::Texture textura;    // Textura carregada para o sprite
    sf::Shader shader;
    sf::Text texto;         // Texto sobre o botão
    sf::Font fonte;         // Fonte do texto
    sf::Color corAtual;     // cor botao

public:
    // Construtor
    BotaoImagem(const std::string& caminhoImagem, const sf::Font& font, const std::string& textoStr, sf::Vector2f tamanho);

    // Define a posição do botão
    void setPosicao(float x, float y);

    // Define a cor do filtro
    void setCorFiltro(const sf::Color& cor);

    // Define o texto
    void setTexto(const std::string& novoTexto);

    // Desenha o botão
    void desenhar(sf::RenderWindow& janela);

    // Verifica se o botão foi clicado
    bool foiClicado(const sf::Vector2i& posicaoMouse);
};

#endif
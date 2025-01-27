#include "cesta.h"
#include <iostream>

// Construtor completo
Cesta::Cesta(std::wstring categoria, sf::Vector2f posicao, sf::Texture& textura, sf::Color cor)
    : categoria(categoria), posicao(posicao), textura(&textura), cor(cor) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f)); // Define largura e altura do retângulo
    shape.setPosition(posicao);
    shape.setFillColor(cor);
    shape.setTexture(&textura);
}


// Método para obter o shape
sf::RectangleShape Cesta::getShape(){
    return shape;
}

const sf::RectangleShape& Cesta::getShape() const {
    return shape;
}
// Método para obter a categoria
std::wstring Cesta::getCategoria() const {
    return categoria;
}

// Método para definir a cor
void Cesta::setCor(sf::Color novaCor) {
    cor = novaCor;
    shape.setFillColor(cor);
}

// Método para definir a categoria
void Cesta::setCategoria(std::wstring novaCategoria) {
    categoria = novaCategoria;
}

// Método para definir a textura
void Cesta::setTextura(sf::Texture& novaTextura) {
    textura = &novaTextura;
    shape.setTexture(textura);
}

// Implementação de setPosition
void Cesta::setPosition(const sf::Vector2f& novaPosicao) {
    posicao = novaPosicao;         // Atualiza a posição interna
    shape.setPosition(posicao);    // Atualiza a posição do shape gráfico
}

void Cesta::desenharCestasComCategorias(sf::RenderWindow& window, const std::vector<Cesta>& cestas, sf::Font& fonte) {
    for (const auto& cesta : cestas) {
        // Suba a posição da cesta
        sf::RectangleShape shape = cesta.getShape();
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - 40); // Suba 50 pixels
        window.draw(shape);

        // Adicionar o texto da categoria
        sf::Text textoCategoria;
        textoCategoria.setFont(fonte);
        textoCategoria.setString(std::wstring(cesta.getCategoria()));
        textoCategoria.setCharacterSize(15); // Tamanho do texto
        textoCategoria.setFillColor(sf::Color::Black);
        if (cesta.getCategoria() == L"Art" ){
            textoCategoria.setPosition(shape.getPosition().x + (shape.getSize().x / 2) - 5 , shape.getPosition().y + shape.getSize().y + 5);
        }
        else if (cesta.getCategoria()==L"Chimie"){
            textoCategoria.setPosition(shape.getPosition().x + (shape.getSize().x / 2) - 10, shape.getPosition().y + shape.getSize().y + 5);
        }

        else if (cesta.getCategoria() == L"Mathematiques"){
            textoCategoria.setString(std::wstring(L"Math"));
            textoCategoria.setPosition(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + shape.getSize().y + 5);
        }
        else
        {
        // Posicione o texto logo abaixo da cesta
            textoCategoria.setPosition(shape.getPosition().x + (shape.getSize().x / 2) - 50, shape.getPosition().y + shape.getSize().y + 5);
        // Desenhe o texto na janela
        }
        window.draw(textoCategoria);

    }
}





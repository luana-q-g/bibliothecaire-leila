#include "cesta.h"

// Construtor completo
Cesta::Cesta(std::wstring categoria, sf::Vector2f posicao, sf::Texture& textura, sf::Color cor)
    : categoria(categoria), posicao(posicao), textura(&textura), cor(cor) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f)); // Define largura e altura do retângulo
    shape.setPosition(posicao);
    shape.setFillColor(cor);
    shape.setTexture(&textura);
}


// Método para obter o shape
sf::RectangleShape Cesta::getShape() const {
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

void Cesta::setPosition(const sf::Vector2f& novaPosicao) {
    posicao = novaPosicao; // Atualiza a posição interna
    shape.setPosition(posicao); // Atualiza a posição gráfica (SFML)
}

sf::Vector2f Cesta::getPosition() const {
    return shape.getPosition(); // Retorna a posição gráfica (SFML)
}




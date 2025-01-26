#ifndef CESTA_H
#define CESTA_H

// Bibliotecas necessárias
#include <SFML/Graphics.hpp>
#include <string>

class Cesta {
private:
    sf::RectangleShape shape;    // Representação gráfica da cesta
    sf::Vector2f posicao;        // Posição da cesta
    std::wstring categoria;      // Categoria da cesta
    sf::Texture* textura;        // Ponteiro para a textura (compartilhada externamente)
    sf::Color cor;               // Cor da cesta

public:
    // Construtor padrão
    Cesta()
        : categoria(L""), shape(sf::Vector2f(0.0f, 0.0f)), posicao(sf::Vector2f(0, 0)), textura(nullptr), cor(sf::Color::White) {
        shape.setPosition(posicao);
        shape.setFillColor(cor);
    }

    // Construtor completo
    Cesta(std::wstring categoria, sf::Vector2f _posicao, sf::Texture& _textura, sf::Color _cor);

    // Getters
    sf::RectangleShape getShape();
    const sf::RectangleShape& getShape() const; // Para objetos const
    std::wstring getCategoria() const;
    sf::Vector2f getPosition() const;
    // Setters
    void setCor(sf::Color novaCor);
    void setCategoria(std::wstring novaCategoria);
    void setTextura(sf::Texture& novaTextura);
    void setPosition(const sf::Vector2f& novaPosicao);
};

#endif // CESTA_H

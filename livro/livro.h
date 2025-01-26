#ifndef LIVRO_H
#define LIVRO_H

// Bibliotecas
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include <SFML/Main.hpp>

using namespace std;

class Livro {
private:
    wstring nome;
    wstring autor;
    wstring categoria;
    int ano_lancamento;
    wstring editora; 

    sf::RectangleShape shape; // Representação gráfica do livro
    sf::Vector2f posicao;
    sf::Texture texturaLivro;      // Textura gráfica do livro
           // Caminho para a textura
    float velocidadeQueda; 
    sf::Color cor;   // Velocidade de queda

public:
    Livro()
        : nome(L""), autor(L""), categoria(L""), ano_lancamento(0), editora(L""), 
        posicao(sf::Vector2f(0, 0)), shape(sf::Vector2f(50, 100)), cor(sf::Color::White) {
    }
      
    // Construtor com argumentos
    Livro(wstring _nome, wstring _autor, wstring _categoria,
      int _anoLancamento, wstring _editora, sf::Vector2f _posicao,const wstring& caminhoImagem, sf::Color _cor);

    // Getters
    wstring getNome() const;
    wstring getAutor() const;
    wstring getCategoria() const;
    int getAnoLancamento() const;
    wstring getEditora() const;
    sf::RectangleShape getShape() const;
    sf::Texture getTextura() const; // Adiciona o membro de textura

    // Setters
    void setNome(wstring _nome);
    void setAutor(wstring _autor);
    void setCategoria(wstring _categoria);
    void setAnoLancamento(int _ano_lancamento);
    void setEditora(wstring _editora);
    
    void setCor(sf::Color _cor) {
        cor = _cor;
        shape.setFillColor(cor);
    }

    // Métodos de movimento
    void mover(sf::RenderWindow& window);
    void cair();

    // Métodos auxiliares
    void setTextura(const sf::Texture& textura);
    void setVelocidadeQueda(float velocidade);


    // Sobrecarga de operadores
    bool operator>(const Livro& livro) const;
    bool operator<(const Livro& livro) const;
    bool operator==(const Livro& livro) const;

    // Sobrecarga de operador de saída
    friend ostream& operator<<(ostream& output, const Livro& l1);
};

#endif

/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Arquivo de cabeçalho da classe livro

*/

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
    std::wstring nome;
    std::wstring autor;
    std::wstring categoria;
    int ano_lancamento;
    std::wstring editora; 

    sf::RectangleShape shape; // Representação gráfica do livro
    sf::Vector2f posicao;   
    std::wstring texturaCaminho; 
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
    Livro(std::wstring _nome, std::wstring _autor, std::wstring _categoria,
      int _anoLancamento, std::wstring _editora, sf::Vector2f _posicao,const std::wstring& caminhoImagem, sf::Color _cor);




    // Getters
    std::wstring getNome() const;
    std::wstring getAutor() const;
    std::wstring getCategoria() const;
    int getAnoLancamento() const;
    std::wstring getEditora() const;
    sf::RectangleShape getShape() const;
    std::wstring getTexturaCaminho() const;
    sf::Texture textura; // Adiciona o membro de textura






    // Setters
    void setNome(std::wstring _nome);
    void setAutor(std::wstring _autor);
    void setCategoria(std::wstring _categoria);
    void setAnoLancamento(int _ano_lancamento);
    void setEditora(std::wstring _editora);
    void setTexturaCaminho(const std::wstring& novoCaminho);

    

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
    friend std::ostream& operator<<(std::ostream& output, const Livro& l1);
};

#endif

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
#include "livro.h"

#ifndef LIVRO_CPP
#define LIVRO_CPP

using namespace std;

// Construtor
// Construtor com parâmetros
Livro::Livro(std::wstring _nome, std::wstring _autor, std::wstring _categoria,
             int _anoLancamento, std::wstring _editora, sf::Vector2f _posicao,
             const std::wstring& caminhoImagem, sf::Color _cor)
    : nome(_nome), autor(_autor), categoria(_categoria), ano_lancamento(_anoLancamento),
      editora(_editora), posicao(_posicao), shape(sf::Vector2f(50, 100)), 
      cor(_cor), texturaCaminho(caminhoImagem) {
    shape.setPosition(posicao);
    shape.setFillColor(cor);

    // Carregando a textura, se o caminho for válido
    if (!caminhoImagem.empty()) {
        if (!texturaLivro.loadFromFile("./interface/assets/imagens/livro.png")) {
            std::wcerr << L"Erro ao carregar a textura do arquivo: " << caminhoImagem << std::endl;
        } else {
            shape.setTexture(&texturaLivro); // Aplica a textura ao retângulo
        }
    }
}

// Getters
std::wstring Livro::getNome() const { return nome; }
std::wstring Livro::getAutor() const { return autor; }
std::wstring Livro::getCategoria() const { return categoria; }
int Livro::getAnoLancamento() const { return ano_lancamento; }
std::wstring Livro::getEditora() const { return editora; }
sf::RectangleShape Livro::getShape() const { return shape; }
std::wstring Livro::getTexturaCaminho() const {return texturaCaminho; }

// Setters
void Livro::setNome(std::wstring _nome) { nome = _nome; }
void Livro::setAutor(std::wstring _autor) { autor = _autor; }
void Livro::setCategoria(std::wstring _categoria) { categoria = _categoria; }
void Livro::setAnoLancamento(int _ano_lancamento) { ano_lancamento = _ano_lancamento; }
void Livro::setEditora(std::wstring _editora) { editora = _editora; }

// Métodos de movimento
void Livro::mover(sf::RenderWindow& window) {
    // Verificar se tecla esquerda está pressionada
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (posicao.x > 0) { // Limite esquerdo da janela
            posicao.x -= velocidadeQueda + 1.0f; // Move para a esquerda
            shape.setPosition(posicao);
        }
    }

    // Verificar se tecla direita está pressionada
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (posicao.x + shape.getSize().x < window.getSize().x) { // Limite direito da janela
            posicao.x += velocidadeQueda + 1.0f; // Move para a direita
            shape.setPosition(posicao);
        }
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        posicao.y = 490.0f;
        shape.setPosition(posicao);

    }
    


}


void Livro::cair() {
    posicao.y += velocidadeQueda;
    shape.setPosition(posicao);
}

void Livro::setTextura(const sf::Texture& textura) {
    shape.setTexture(&textura);
}

void Livro::setVelocidadeQueda(float velocidade) {
    velocidadeQueda = velocidade;
}

void Livro::setTexturaCaminho(const std::wstring& novoCaminho) {
    texturaCaminho = novoCaminho;
}

// Sobrecarga de operadores
bool Livro::operator>(const Livro& livro) const {
    return (nome > livro.nome) && (ano_lancamento > livro.ano_lancamento);
}

bool Livro::operator<(const Livro& livro) const {
    return (nome < livro.nome) && (ano_lancamento < livro.ano_lancamento);
}

bool Livro::operator==(const Livro& livro) const {
    return (ano_lancamento == livro.ano_lancamento) && (autor == livro.autor) &&
           (categoria == livro.categoria) && (editora == livro.editora);
}

std::wostream& operator<<(std::wostream& output, const Livro& l1) {
    output << "Nome: " << l1.getNome() << ", Autor: " << l1.getAutor() << "\n"
           << "Ano de lançamento: " << l1.getAnoLancamento()
           << ", Editora: " << l1.getEditora() << std::endl;
    return output;
}

// Define a posição do livro

#endif


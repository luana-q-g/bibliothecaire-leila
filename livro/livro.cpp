#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Main.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include "livro.h"

#ifndef LIVRO_CPP
#define LIVRO_CPP

using namespace std;

// Construtor com parâmetros

Livro::Livro()
    : nome(L""), autor(L""), categoria(L""), ano_lancamento(0), editora(L""),
      posicao(sf::Vector2f(390, 0)), shape(sf::Vector2f(50, 100)), cor(sf::Color::White) {
    shape.setPosition(posicao);
    shape.setFillColor(cor);
}

Livro::Livro(std::wstring _nome, std::wstring _autor, std::wstring _categoria,
             int _anoLancamento, std::wstring _editora, sf::Vector2f _posicao,
             const std::wstring& caminhoImagem, sf::Color _cor)
    : nome(_nome), autor(_autor), categoria(_categoria), ano_lancamento(_anoLancamento),
      editora(_editora), posicao(_posicao), shape(sf::Vector2f(50, 100)), 
      cor(_cor) {
    shape.setPosition(posicao);
    shape.setFillColor(cor);

    // Carregar textura, se fornecida
    if (!caminhoImagem.empty()) {
        if (!texturaLivro.loadFromFile(std::string(caminhoImagem.begin(), caminhoImagem.end()))) {
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
sf::Texture Livro::getTextura() const { return texturaLivro; }
sf::Color Livro::getCor() const {return cor;}

// Setters
void Livro::setNome(std::wstring _nome) { nome = _nome; }
void Livro::setAutor(std::wstring _autor) { autor = _autor; }
void Livro::setCategoria(std::wstring _categoria) { categoria = _categoria; }
void Livro::setAnoLancamento(int _ano_lancamento) { ano_lancamento = _ano_lancamento; }
void Livro::setEditora(std::wstring _editora) { editora = _editora; }

// Métodos de movimento
void Livro::mover(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (posicao.x > 0) { // Limite esquerdo
            posicao.x -= 1.5 * velocidadeQueda; // Move para a esquerda
            shape.setPosition(posicao);
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (posicao.x + shape.getSize().x < window.getSize().x) { // Limite direito
            posicao.x += 1.5 * velocidadeQueda; // Move para a direita
            shape.setPosition(posicao);
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posicao.y = window.getSize().y - window.getSize().y/3; // Alinha o eixo Y
        shape.setPosition(posicao);
    }
}

void Livro::cair() {
    posicao.y += velocidadeQueda;
    shape.setPosition(posicao);

}

void Livro::setTextura(const std::string& caminhoTextura) {
    if (!texture) {
        // Inicializa o ponteiro compartilhado para a textura
        texture = std::make_shared<sf::Texture>();
    }

    // Tenta carregar a textura
    if (!texture->loadFromFile(caminhoTextura)) {
        std::cerr << "Erro ao carregar a textura: " << caminhoTextura << std::endl;
    } else {
        // Aplica a textura ao retângulo
        shape.setTexture(texture.get(), true); // Ajusta automaticamente a textura ao tamanho do shape
    }
}

void Livro::setVelocidadeQueda(float velocidade) {
    velocidadeQueda = velocidade;
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
    output << L"Nome: " << l1.getNome() << L", Autor: " << l1.getAutor() << L"\n"
           << L"Ano de lançamento: " << l1.getAnoLancamento()
           << L", Editora: " << l1.getEditora() << std::endl;
    return output;
}

#endif

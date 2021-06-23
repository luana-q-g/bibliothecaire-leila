/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Implementar os métodos da classe livro

*/

#ifndef LIVRO_CPP
#define LIVRO_PP

// Arquivo de cabeçalho
#include "livro.h"

using namespace std;

Livro::Livro(wstring _nome, wstring _autor, wstring _categoria,
             int _ano_lancamento, wstring _editora)
    : shape(sf::Vector2f(200.f, 400.f)) {
  nome = _nome;
  autor = _autor;
  categoria = _categoria;
  ano_lancamento = _ano_lancamento;
  editora = _editora;

  // Carregando a textura do livro
  sf::Texture texture;

  // if (!texture.loadFromImage(_imagem)) {
  //   cout << "Erro ao carregar imagem do livro" << endl;
  // } else {
  //   cout << "Textura carregada com sucesso!"<< endl;
  //   shape.setTexture(&texture);
  // }

  // shape.setFillColor(sf::Color::Red);
}

wstring Livro::getNome() const { return nome; }

wstring Livro::getAutor() const { return autor; }

wstring Livro::getCategoria() const { return categoria; }

int Livro::getAnoLancamento() const { return ano_lancamento; }

wstring Livro::getEditora() const { return editora; }

sf::RectangleShape Livro::getShape() const { return shape; }

void Livro::setNome(wstring _nome) { nome = _nome; }

void Livro::setAutor(wstring _autor) { autor = _autor; }

void Livro::setCategoria(wstring _categoria) { categoria = _categoria; }

void Livro::setAnoLancamento(int _ano_lancamento) {
  ano_lancamento = _ano_lancamento;
}

void Livro::setEditora(wstring _editora) { editora = _editora; }

// Operator overloading
bool Livro::operator>(const Livro &livro) {
  return (nome > livro.nome) && (ano_lancamento > livro.ano_lancamento);
}

bool Livro::operator<(const Livro &livro) {
  return (nome < livro.nome) && (ano_lancamento < livro.ano_lancamento);
}

bool Livro::operator==(const Livro &livro) {
  return (ano_lancamento == livro.ano_lancamento) && (autor == livro.autor) &&
         (categoria == livro.categoria) && (editora == livro.editora);
}

ostream &operator<<(ostream &output, const Livro &l1) {
  output << "Nome: " << l1.nome << ", Autor: " << l1.autor << endl
         << "Ano de lançamento: " << l1.ano_lancamento
         << ", Editora: " << l1.editora << endl;

  return output;
}
#endif


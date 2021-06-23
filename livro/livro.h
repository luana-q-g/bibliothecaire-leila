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
  wstring nome;
  wstring autor;
  wstring categoria;
  int ano_lancamento;
  wstring editora;
  sf::RectangleShape shape;

public:
  Livro(wstring _nome = L"", wstring _autor = L"", wstring _categoria = L"",
        int _ano_lancamento = 0, wstring _editora = L"");

  wstring getNome() const;
  wstring getAutor() const;
  wstring getCategoria() const;
  int getAnoLancamento() const;
  wstring getEditora() const;
  sf::RectangleShape getShape() const;

  void setNome(wstring _nome = L"");
  void setAutor(wstring _autor = L"");
  void setCategoria(wstring _categoria = L"");
  void setAnoLancamento(int _ano_lancamento = 0);
  void setEditora(wstring _editora = L"");

  // Operator overloading
  bool operator>(const Livro &livro);
  bool operator<(const Livro &livro);
  bool operator==(const Livro &livro);

  friend ostream &operator<<(ostream &output, const Livro &);
};

#endif

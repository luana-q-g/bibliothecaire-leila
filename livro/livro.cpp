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

Livro::Livro(string _nome, string _autor, string _categoria, int _ano_lancamento, string _editora)
    : nome(_nome), autor(_autor), categoria(_categoria), ano_lancamento(_ano_lancamento), editora(_editora) {}

string Livro::getNome() const
{
  return nome;
}

string Livro::getAutor() const
{
  return autor;
}

string Livro::getCategoria() const
{
  return categoria;
}

int Livro::getAnoLancamento() const
{
  return ano_lancamento;
}

string Livro::getEditora() const
{
  return editora;
}

void Livro::setNome(string _nome)
{
  nome = _nome;
}

void Livro::setAutor(string _autor)
{
  autor = _autor;
}

void Livro::setCategoria(string _categoria)
{
  categoria = _categoria;
}

void Livro::setAnoLancamento(int _ano_lancamento)
{
  ano_lancamento = _ano_lancamento;
}

void Livro::setEditora(string _editora)
{
  editora = _editora;
}

// Operator overloading
bool Livro::operator>(const Livro &livro)
{
  return (nome > livro.nome) && (ano_lancamento > livro.ano_lancamento);
}

bool Livro::operator<(const Livro &livro)
{
  return (nome < livro.nome) && (ano_lancamento < livro.ano_lancamento);
}

bool Livro::operator==(const Livro &livro)
{
  return (ano_lancamento == livro.ano_lancamento) && (autor == livro.autor) && (categoria == livro.categoria) && (editora == livro.editora);
}

ostream &operator<<(ostream &output, const Livro &l1)
{
  output << "Nome: " << l1.nome << ", Autor: " << l1.autor << endl
         << "Ano de lançamento: " << l1.ano_lancamento << ", Editora: " << l1.editora << endl;

  return output;
}
#endif

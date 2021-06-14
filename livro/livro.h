/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Arquivo de cabeçalho da classe livro

*/

#ifndef LIVRO_H
#define LIVRO_H

// Bibliotecas
#include <iostream>
#include <string>

using namespace std;

class Livro
{
private:
  string nome;
  string autor;
  string categoria;
  int ano_lancamento;
  string editora;

public:
  Livro(string _nome = "", string _autor = "", string _categoria = "", int _ano_lancamento = 0, string _editora = "");

  string getNome() const;
  string getAutor() const;
  string getCategoria() const;
  int getAnoLancamento() const;
  string getEditora() const;

  void setNome(string _nome = "");
  void setAutor(string _autor = "");
  void setCategoria(string _categoria = "");
  void setAnoLancamento(int _ano_lancamento = 0);
  void setEditora(string _editora = "");

  // Operator overloading
  bool operator>(const Livro &livro);
  bool operator<(const Livro &livro);
  bool operator==(const Livro &livro);
};

#endif

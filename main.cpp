/*

Autor(es):
  Luís Augusto Simas do Nascimento - 790828
  Pedro Klesse - 790746
  Luana Garcia
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Trabalho de AED1

*/

// Bibliotecas
#include <iostream>
#include <string>

#include "livro/livro.h"
#include "listacadastral/lista.h"
#include "listacadastral/lista.cpp"
#include "pilha/pilha.h"

using namespace std;

// Função principal
int main(int argc, char *argv[])
{
  // Lista pra cada categoria
  Lista<Livro> lista("Filosofia");

  Livro letras_l1("Libras: conhecimento além dos sinais", "Maria Cristina da Cunha", "Letras", 2011, "Pearson");
  Livro letras_l2("Comunicação e linguagem", "Thelma de Carvalho Guimarães", "Letras", 2012, "Pearson");
  Livro letras_l3("Teoria da Literatura I", "Pedro Paulo da Silva", "Letras", 2009, "Pearson");
  Livro letras_l4("Língua latina", "Charlene Martins Miotti", "Letras", 2010, "Pearson");
  Livro filosofia_l5("Introdução à Filosofia", "João Mattar", "Filosofia", 2010, "Pearson");
  Livro filosofia_l6("Ética", "Maria Thereza Pompa Antunes", "Filosofia", 2012, "Pearson");
  Livro filosofia_l7("Correntes modernas de filosofia", "José Ferraz Neto", "Filosofia", 2013, "Pearson");
  Livro filosofia_l8("Genealogia da Moral", "Friedrich Nietzsche", "Filosofia", 1887, "Vozes");
  Livro geografia_l9("Hidrologia", "Diego Barreto de Oliveira", "Geografia", 2015, "Pearson");
  Livro geografia_l10("Espaço Geográfico: ensino e representação", "Rosangela Doin de Almeida", "Geografia", 1989, "Contexto");
  Livro geografia_l11("Pensamento geográfico brasileiro", "Ruy Moreira", "Geografia", 2008, "Contexto");
  Livro geografia_l12("Globalização e espaço geográfico", "Eustáquio de Sene", "Geografia", 2004, "Contexto");
  Livro historia_l13("No Tempo das Especiarias: o império da pimenta e do açúcar", "Fábio Pestana", "História", 2006, "Contexto");
  Livro historia_l14("Dicionário de Datas da História do Brasil", "Circe Bittencour", "História", 2007, "Contexto");
  Livro historia_l15("História do Café", "Ana Luiza Martins", "História", 2008, "Contexto");
  Livro historia_l16("As Primeiras Civilizações", "Jaime Pinsky", "História", 2011, "Contexto");
  Livro matematica_l17("Geometria Analítica: Um Tratamento Vetorial", "Ivan de Camargo", "Matemática", 2005, "Pearson");
  Livro matematica_l18("Matemática financeira", "André Wakamatsu", "Matemática", 2018, "Pearson");
  Livro matematica_l19("Métodos numéricos em equações diferenciais", "Marina Vargas", "Matemática", 2021, "Intersaberes");
  Livro matematica_l20("Geometrias Não Euclidianas", "Nelson Pereira", "Matemática", 2020, "Intersaberes");
  Livro psicologia_l21("Teorias da Personalidade: da teoria clássica à pesquisa moderna", "Howard S. Friedman", "Psicologia", 2003, "Pearson");
  Livro psicologia_l22("Introdução à Psicologia", "Charles G. Morris", "Psicologia", 2004, "Pearson");
  Livro psicologia_l23("A Psicanálise nas Tramas da Cidade", "Bernardo Tanis", "Psicologia", 2009, "Pearson");
  Livro psicologia_l24("Burnout: quando o trabalho ameaça o bem-estar do trabalhador", "Ana Maria Benevides Pereira", "Psicologia", 2014, "Pearson");

  // Pilha com os livros
  // TODO: preencher ela aleatoriamente
  Pilha<Livro> pilha;

  int op = 0;
  string categoria;

  // TODO: resolver como a gente vai colocar as posições
  int posicao = 0;

  /*
  while (op != 3)
  {
    cout << "Opções: " << endl;
    cout << "[1] Inserir livro." << endl;
    cout << "[2] Listar livros." << endl;
    cout << "[3] Sair." << endl;
    cout << "Opção: ";
    cin >> op;

    switch (op)
    {
    case 1:
    {
      cout << "Em qual categoria? ";
      cin >> categoria;
      cout << "Inserir logo após qual livro? ";
      cin >> posicao;

      // TODO: selecionar a lista certa pra inserir com base na categoria

      if (queue.push(newElement))
      {
        cout << "Livro inserido com sucesso!" << endl;
      }
      else
      {
        cout << "Não é possível inserir o livro nessa posição!" << endl;
      }

      delete newElement;

      break;
    }
    case 2:
    {
      if (queue.pop(removedElement))
      {
        cout << removedElement->getNome() << " retirado com sucesso!" << endl;
      }
      else
      {
        cout << "Erro ao retirar pessoa" << endl;
      }

      delete removedElement;

      break;
    }
    case 3:
    {
      cout << "Saindo..." << endl;
      break;
    }
    default:
      cout << "Opção inválida" << endl;
      ;
    }

    cout << endl;
  }

  */
  return 0;
}

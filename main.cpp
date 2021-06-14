/*

Autor(es):
  Luís Augusto Simas do Nascimento - 790828
  Pedro Klesse - 790746
  Luana de Queiroz Garcia - 740953
Data de Criação: 14/06/2021
Data de Atualização: 14/06/2021

Objetivos: Trabalho de AED1

*/

// Bibliotecas
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "livro/livro.h"
#include "listacadastral/lista.h"
#include "listacadastral/lista.cpp"
#include "pilha/pilha.h"
#include "pilha/pilha.cpp"

using namespace std;

// Função principal
int main(int argc, char *argv[])
{

  setlocale(LC_ALL, "Portuguese");

  // Lista pra cada categoria
  Lista<Livro> lista_letras("Letras");
  Lista<Livro> lista_filosofia("Filosofia");
  Lista<Livro> lista_geografia("Geografia");
  Lista<Livro> lista_historia("História");
  Lista<Livro> lista_matematica("Matemática");
  Lista<Livro> lista_psicologia("Psicologia");
  Lista<Livro> lista_informatica("Informática");
  Lista<Livro> lista_quimica("Química");
  Lista<Livro> lista_arte("Arte");

  //Vetor que armazena todas as listas(estantes)
  Lista<Livro> listas[9] = {
      lista_letras,
      lista_filosofia,
      lista_geografia,
      lista_historia,
      lista_matematica,
      lista_psicologia,
      lista_informatica,
      lista_quimica,
      lista_arte};

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
  Livro informatica_l25("Aprenda Programação Orientada a Objetos em 21 dias", "Anthony Sintes", "Informática", 2002, "Pearson");
  Livro informatica_l26("Treinamento em Linguagem C++: módulo 1", "Victorine Viviane Mizrahi", "Informática", 1996, "Pearson");
  Livro informatica_l27("Manual Completo do Linux: guia do administrador", "Evi Nemeth", "Informática", 2004, "Pearson");
  Livro informatica_l28("Compiladores: princípios, técnicas e ferramentas", "Alfred V. Alho", "Informática", 2007, "Pearson");
  Livro quimica_l29("Química Orgânica", "Bianca Sandrino", "Química", 2020, "Intersaberes");
  Livro quimica_l30("Química Quântica: Origens e Aplicações", "Liziane Barbara Bugalski", "Química", 2019, "Intersaberes");
  Livro quimica_l31("Manual de Ar Comprimido e Gases", "John P. Rollins", "Química", 2003, "Pearson");
  Livro quimica_l32("Estudos de eletroquímica: reações químicas e energia", "Ana Luiza Lorenzen", "Química", 2017, "Intersaberes");
  Livro arte_l33("Estética e história da arte", "Humberta Gomes Machado Porto", "Arte", 2016, "Pearson");
  Livro arte_l34("História do cinema mundial", "Fernando Mascarello", "Arte", 2014, "Papirus");
  Livro arte_l35("Beethoven: as muitas faces de um gênio", "João Mauricio Galindo", "Arte", 2019, "Contexto");
  Livro arte_l36("O cinema de Quentin Tarantino", "Mauro Baptista", "Arte", 2018, "Papirus");

  Livro lista_fixa[] = {
      letras_l1, letras_l2, letras_l3, letras_l4, filosofia_l5, filosofia_l6, filosofia_l7, filosofia_l8,
      geografia_l9, geografia_l10, geografia_l11, geografia_l12, historia_l13, historia_l14, historia_l15,
      historia_l16, matematica_l17, matematica_l18, matematica_l19, matematica_l20, psicologia_l21, psicologia_l22,
      psicologia_l23, psicologia_l24, informatica_l25, informatica_l26, informatica_l27, informatica_l28,
      quimica_l29, quimica_l30, quimica_l31, quimica_l32, arte_l33, arte_l34, arte_l35, arte_l36}; // Pilha com os livros

  srand(time(NULL)); // randomize seed
  // TODO: preencher ela aleatoriamente
  Pilha<Livro> pilha;
  int tam_pilha = 10;
  int indices[tam_pilha];

  for (int i = 0; i < tam_pilha; i++)
  {
    bool tem_num = true;
    int num_aleatorio;

    while (tem_num)
    {
      num_aleatorio = rand() % 36;

      tem_num = false;

      for (int i = 0; i < tam_pilha; i++)
      {
        if (indices[i] == num_aleatorio)
        {
          tem_num = true;
        }
      }
    }

    indices[i] = num_aleatorio;
  }

  for (int i = 0; i < tam_pilha; i++)
  {
    pilha.inserir(lista_fixa[indices[i]]);
  }

  int op = 0;
  int categoria;

  // TODO: resolver como a gente vai colocar as posições
  int posicao = 0;

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
      cout << "Categorias: " << endl;
      cout << "[0] Letras" << endl;
      cout << "[1] Filosofia" << endl;
      cout << "[2] Geografia" << endl;
      cout << "[3] Historia" << endl;
      cout << "[4] Matematica" << endl;
      cout << "[5] Psicologia" << endl;
      cout << "[6] Informatica" << endl;
      cout << "[7] Quimica" << endl;
      cout << "[8] Arte" << endl;

      cout << "Em qual categoria? ";
      cin >> categoria;

      if (categoria > 8 || categoria < 0)
      {
        cout << "Categoria inválida!" << endl;
      }
      else
      {
        listas[categoria].imprimir();

        cout << "Inserir logo após qual livro? ";
        cin >> posicao;

        Livro livro = pilha.remover();

        if (listas[categoria].inserir(livro, posicao))
        {
          cout << "Livro inserido com sucesso!" << endl;
        }
        else
        {
          // Caso não seja possível inserir o livro, retornamos ele para a pilha
          pilha.inserir(livro);
          cout << "Não é possível inserir o livro nessa posição!" << endl;
        }
      }
      break;
    }
    //Listar todos os livros
    case 2:
    {
      cout << "Livros na pilha:" << endl;

      Pilha<Livro> pilhaAux;
      Livro livroAux;

      while (!pilha.empty())
      {
        livroAux = pilha.remover();
        cout << livroAux << endl;
        pilhaAux.inserir(livroAux);
      }

      // Devolvendo os elementos para a stack principal
      while (!pilhaAux.empty())
      {
        livroAux = pilhaAux.remover();
        pilha.inserir(livroAux);
      }
      break;
    }
    case 3:
    {
      cout << "Saindo..." << endl;
      break;
    }
    default:
      cout << "Opção inválida" << endl;
    }
    cout << endl;
  }

  return 0;
}

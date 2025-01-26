#include <stdexcept>
#include <locale> // Necessário para configurar o locale
#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include <string>
#include <random>
#include <unordered_set>
#include <ctime>
#include <pqxx/pqxx>

#include "acoesLivro.h"

#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "baselist/baselist.h"
#include "database/connection.h"

using namespace std;
using namespace sf;

Color getColorFromString(const string& colorName) {
    // Mapa para associar strings a cores predefinidas do SFML
    static const map<string, sf::Color> colorMap = {
        {"Red", sf::Color::Red},
        {"Green", sf::Color::Green},
        {"Blue", sf::Color::Blue},
        {"Yellow", sf::Color::Yellow},
        {"Cyan", sf::Color::Cyan},
        {"Magenta", sf::Color::Magenta},
        {"White", sf::Color::White},
        {"Black", sf::Color::Black},
        {"Orange", sf::Color(255, 140, 0)},
        {"Purple", sf::Color(128, 0, 128)},
        {"Transparent", sf::Color::Transparent}
    };

    // Procura pela string no mapa
    auto it = colorMap.find(colorName);
    if (it != colorMap.end()) {
        return it->second; // Retorna a cor correspondente
    } else {
        // Se a string não for encontrada, retorna uma cor padrão (exemplo: preto)
        cerr << "Cor desconhecida: " << colorName << endl;
        return sf::Color::Black;
    }
}

wstring converteString(const pqxx::field& field){
  // Primeiro, obtenha a string como string
  string str = field.as<string>();
  
  // Agora converta para wstring
  wstring_convert<codecvt_utf8<wchar_t>> conv;
  wstring wstr = conv.from_bytes(str);
  return wstr;
}

vector<Lista<Livro>> geraListaLivrosCategorias(DatabaseConnection db){
  result res = db.showQuery("SELECT nome FROM Categoria;");

  vector<Lista<Livro>> listas;
  for (const auto& row : res) {
    for (const auto& field : row) {
      wstring categ = converteString(field);
      Lista<Livro> lista_categoria(categ);
      listas.push_back(lista_categoria);
    }
  }

  return listas;
}

Pilha<Livro> geraPilhaLivros(DatabaseConnection db, int tamanho){
  Pilha<Livro> pilha = Pilha<Livro>();
  
  result res = db.showQuery("SELECT COUNT(*) FROM Livro;");
  int num_livros = res[0][0].as<int>();

  // configure random numbers
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(1, num_livros);

  // generate random numbers not repeated
  string id_livros;
  string random_number;
  unordered_set<int> unique_numbers; // Conjunto para armazenar números únicos

  for (int i = 0; i < tamanho; ++i) {
      int num;
      do {
          num = distr(gen); // Gera um número aleatório
      } while (unique_numbers.find(num) != unique_numbers.end()); // Gera novamente se já existir

      unique_numbers.insert(num); // Adiciona o número ao conjunto
      random_number = to_string(num);

      // Constrói a string com os números separados por vírgulas
      id_livros = id_livros != "" ? id_livros + ", " + random_number : random_number;
  }

  cout << id_livros << endl;

  res = db.showQuery("SELECT l.nome, l.autor, l.nome_categoria, l.ano_lancamento, l.editora, c.cor " \
  "FROM Livro l JOIN Categoria c ON l.nome_categoria = c.nome WHERE id in ("+id_livros+");");

  wstring caminhoTextura = L"./interface/assets/imagens/livro.png";

  for (const auto& row : res) {
    Livro l;
    l.setNome(converteString(row[0]));
    l.setAutor(converteString(row[1]));
    l.setCategoria(converteString(row[2]));
    l.setAnoLancamento(row[3].as<int>());
    l.setEditora(converteString(row[4]));
    string cor = row[5].as<string>();
    l.setCor(getColorFromString(cor));

    // Adicionar livro na pilha
    pilha.inserir(l);
  }

  return pilha;
}

// Retorna um livro aleatório
Livro getLivroAleatorio(DatabaseConnection db) {
    result res = db.showQuery("SELECT COUNT(*) FROM Livro;");
    int num_livros = res[0][0].as<int>();

    // configure random numbers
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, num_livros);

    int random_number = distr(gen);

    res = db.showQuery("SELECT l.nome, l.autor, l.nome_categoria, l.ano_lancamento, l.editora, c.cor " \
    "FROM Livro l JOIN Categoria c ON l.nome_categoria = c.nome WHERE l.id = "+to_string(random_number)+";");

    string caminhoTextura = "./interface/assets/imagens/livro.png";

    Livro l;
    for (const auto& row : res) {
        l.setNome(converteString(row[0]));
        l.setAutor(converteString(row[1]));
        l.setCategoria(converteString(row[2]));
        l.setAnoLancamento(row[3].as<int>());
        l.setEditora(converteString(row[4]));
        string cor = row[5].as<string>();
        l.setCor(getColorFromString(cor));

        sf::Texture texturaLivro;
        // Carrega a textura para o livro no índice
        if (!texturaLivro.loadFromFile(caminhoTextura)) {
            wcerr << L"Erro ao carregar a textura do livro de id " << random_number << endl;

            // Retorna um objeto padrão em caso de erro
            return Livro();
        }

        // Configura a textura do shape usando um método público
        l.setTextura(texturaLivro);

    }

    // Retorna o livro selecionado
    return l;
}
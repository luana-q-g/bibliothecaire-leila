#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <locale>
#include <codecvt>
#include <string>
#include <random>
#include <unordered_set>
#include <ctime>
#include <pqxx/pqxx>

#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "livro/acoesLivro.h"
#include "baselist/baselist.h"
#include <SFML/System/Vector2.hpp>
#include "cestas/tipoCesta.cpp"
#include "cestas/cesta.h"
#include "Jogo/jogo.h"
#include "database/connection.h"

#include "buttonimg/BotaoImagem.h"

using namespace std;
using namespace sf;

// Prototipagem das funções
void executarJogoAntigo(sf::RenderWindow &window, bool &modoLivrosCaindo, DatabaseConnection db);
void executarLivrosCaindo(sf::RenderWindow &window, DatabaseConnection db);

int main(int argc, char *argv[])
{
  try
  {
    DatabaseConnection db;

    setlocale(LC_ALL, "C.utf8");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bibliotecária Leila - Dois Modos");
    window.setFramerateLimit(60);

    // Variável de controle para alternar entre os dois modos
    bool modoLivrosCaindo = false;

    // Loop principal
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
      }

      executarJogoAntigo(window, modoLivrosCaindo, db);
      // executarLivrosCaindo(window, db);
      // // Alternar entre os dois modos de jogo
      // if (!modoLivrosCaindo) {
      //    executarJogoAntigo(window, modoLivrosCaindo, db);
      // } else {

      //  modoLivrosCaindo = false;
      // }
    }

    db.disconnect();
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
  }

  return 0;
}

void setBackground(string path_img, Sprite & bg, Texture & bgTexture, RenderWindow &window){
  if (!bgTexture.loadFromFile(path_img)) {
    cout << "Erro: não foi possível carregar a imagem de background" << endl;
  }
  else {
    // resized background
    sf::Vector2u TextureSize = bgTexture.getSize(); // Get size of texture.
    sf::Vector2u WindowSize = window.getSize();     // Get size of window.

    float ScaleX = (float)WindowSize.x / TextureSize.x;
    float ScaleY = (float)WindowSize.y / TextureSize.y; // Calculate scale.

    bg.setColor(sf::Color::White); // Removing old color (must be white, not transparent)
    bg.setScale(ScaleX, ScaleY);   // Set scale.
    bg.setTexture(bgTexture, true);
  }
}

void setTextureItens(string path_img, Sprite & s, Texture & st){
    if (!st.loadFromFile(path_img)) {
        cout << "Não carregou a imagem\n"
            << endl;
    }
    else {
        s.setTexture(st);
    }
}

void executarJogoAntigo(sf::RenderWindow &window, bool &modoLivrosCaindo, DatabaseConnection db) {
    static bool comecoDoJogo = true;
    static bool finalDoJogo = false;

    // Vetor que armazena todas as listas(estantes)
    vector<Lista<Livro>> listas = geraListaLivrosCategorias(db);

    int tamanho = 5;
    Pilha<Livro> pilha = geraPilhaLivros(db, tamanho);

    // Dimensões da tela
    const float windowWidth = 800.0f;
    const float windowHeight = 600.0f;

    // Dimensões do livro
    const float bookWidth = 50.0f;
    const float bookHeight = 100.0f;

    window.create(sf::VideoMode(626 * 2, 375 * 2), "Bibliotecária Leila");

    sf::Texture bgTexture;
    sf::Texture girlTexture;
    sf::Texture dialogoTexture;
    sf::Texture logoTexture;
    sf::Sprite background;
    sf::Sprite girl;
    sf::Sprite dialogo;
    sf::Sprite logo;

    
    int contadorScore = 0;
    int errouMais;

    srand(time(0));

    sf::Clock clock;
    float timer = 0, delay = 1.5;

    sf::Font font;
    sf::Text text;
    sf::Text errorText;

    Livro livroAtual = pilha.remover();

    // background inicio
    setBackground("./interface/assets/imagens/background_menu.jpg", background, bgTexture, window);

    setTextureItens("./interface/assets/imagens/logo.png", logo, logoTexture);
    logo.setPosition((window.getSize().x / 2) - (logo.getGlobalBounds().width / 2), 0);
    

    Button botao_iniciar("iniciar", 200, 65);

    sf::FloatRect boundsBase = logo.getGlobalBounds();
    sf::FloatRect boundsSprite = botao_iniciar.getGlobalBounds();

    botao_iniciar.setPosition((window.getSize().x / 2) - (botao_iniciar.getGlobalBounds().width / 2),
        (boundsBase.top + boundsBase.height + window.getSize().y*0.1));


  BotaoImagem botao("./interface/assets/imagens/botaoImg.png", font, "Iniciar", Vector2f(112.0f, 56.0f));
  botao.setPosicao(300.0f, 250.0f);
  botao.setCorFiltro(sf::Color(0, 0, 255, 100));

  while (window.isOpen()) {
    Event event;
    Button buttonPressed;

    // timer mensagem de erro
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    if (timer > delay)
    {
      timer = 0;
      errorText.setString(L" ");
    }

    // While there are pending events
    while (window.pollEvent(event)) {
      // Check the element type
      switch (event.type) {

        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == 0) {
                errorText.setString(L" ");

                if (comecoDoJogo) {

                    if (botao_iniciar.click_outros(sf::Mouse::getPosition(window))) {
                        // Carregando a imagem do background
                        setBackground("./interface/assets/imagens/background.jpg", background, bgTexture, window);
                        cout << "oi caralhooo" << endl;
                        comecoDoJogo = false;
                    }
                }
            }
            break;
        case sf::Event::MouseButtonReleased:
          
          break;
        default:
          break;
      }
    }

    if (comecoDoJogo) {
      window.clear();
      window.draw(background);
      window.draw(logo);
      window.draw(botao_iniciar);
      botao.desenhar(window);
      window.display();
    }
  }
}
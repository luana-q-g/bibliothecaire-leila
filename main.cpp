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
#include <chrono>
#include <thread>

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
int executarLivrosCaindo(sf::RenderWindow &window, DatabaseConnection db);

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

  // Loading interface buttons
  Button botao_historia("historia", buscarListaPorCategoria(listas, L"Histoire"));
  Button botao_psicologia("psicologia", buscarListaPorCategoria(listas, L"Psychologie"));
  Button botao_letras("letras", buscarListaPorCategoria(listas, L"Litterature"));
  Button botao_filosofia("filosofia", buscarListaPorCategoria(listas, L"Philosophie"));
  Button botao_geografia("geografia", buscarListaPorCategoria(listas, L"Geographie"));
  Button botao_matematica("matematica", buscarListaPorCategoria(listas, L"Mathematiques"));
  Button botao_informatica("informatica", buscarListaPorCategoria(listas, L"Informatique"));
  Button botao_quimica("quimica", buscarListaPorCategoria(listas, L"Chimie"));
  Button botao_arte("artes", buscarListaPorCategoria(listas, L"Art"));
  Button botao_sair("sair", 145, 56);
  Button botao_jogo1("jogo1", 200, 65);
  Button botao_jogo2("jogo2", 200, 65);

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


  if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria.png"))
  {
    cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
  }
  else
  {
    girl.setTexture(girlTexture);
    girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
  }

  if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo.png"))
  {
    cout << "Erro: não foi possível carregar a imagem do dialogo" << endl;
  }
  else
  {
    dialogo.setTexture(dialogoTexture);
    dialogo.setPosition(girl.getGlobalBounds().width - 150,
                        (window.getSize().y - dialogo.getGlobalBounds().height -
                         girl.getGlobalBounds().height) +
                            50);
  }

  setTextureItens("./interface/assets/imagens/logo.png", logo, logoTexture);
  logo.setPosition((window.getSize().x / 2) - (logo.getGlobalBounds().width / 2), 0);

  if (!font.loadFromFile("./interface/assets/fonts/Roboto-Bold.ttf"))
  {
    cout << "Erro: não foi possível carregar a fonte";
  }
  else
  {
    text.setFont(font);
    text.setString(
        L"Hmmm, on a ici le livre\n" +
        livroAtual.getNome() +
        L"\n écrit par " +
        livroAtual.getAutor() +
        L" en " +
        to_wstring(livroAtual.getAnoLancamento()));

    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(dialogo.getPosition().x + 40, dialogo.getPosition().y + 100);

    errorText.setFont(font);
    errorText.setString(L" ");
    errorText.setCharacterSize(24);
    errorText.setFillColor(sf::Color::Black);
    errorText.setStyle(sf::Text::Bold);
    errorText.setPosition(dialogo.getPosition().x + 180, dialogo.getPosition().y + 200);
  }

  // BotaoImagem botao("./interface/assets/imagens/botaoImg.png", font, "Clique Aqui", sf::Vector2f(112.0f, 56.0f));
  // botao.setPosicao(300.0f, 250.0f);
  // botao.setCorFiltro(sf::Color(0, 0, 255, 100));
  


  // Posicionando os botoes
  botao_historia.setPosition(girl.getPosition().x + girl.getGlobalBounds().width + (window.getSize().x / 6), window.getSize().y - 140);
  botao_psicologia.setPosition(botao_historia.getPosition().x + botao_historia.getGlobalBounds().width + 50, botao_historia.getPosition().y);
  botao_letras.setPosition(botao_psicologia.getPosition().x + botao_psicologia.getGlobalBounds().width + 50, botao_historia.getPosition().y);
  botao_filosofia.setPosition(botao_letras.getPosition().x + botao_letras.getGlobalBounds().width + 50, botao_historia.getPosition().y);
  botao_geografia.setPosition(botao_historia.getPosition().x - 80, botao_historia.getPosition().y + 65);
  botao_matematica.setPosition(botao_geografia.getPosition().x + botao_geografia.getGlobalBounds().width + 50, botao_historia.getPosition().y + 65);
  botao_informatica.setPosition(botao_matematica.getPosition().x + botao_matematica.getGlobalBounds().width + 50, botao_historia.getPosition().y + 65);
  botao_quimica.setPosition(botao_informatica.getPosition().x + botao_informatica.getGlobalBounds().width + 50, botao_historia.getPosition().y + 65);
  botao_arte.setPosition(botao_quimica.getPosition().x + botao_quimica.getGlobalBounds().width + 50, botao_historia.getPosition().y + 65);
  botao_sair.setPosition((window.getSize().x / 2) - (botao_sair.getGlobalBounds().width) + 200, window.getSize().y - 140);

  // botao_jogo1.setPosition(girl.getPosition().x - 2*botao_jogo1.getGlobalBounds().width ,
  //   (boundsBase.top + boundsBase.height + window.getSize().y*0.1));
                  
  // botao_jogo2.setPosition((window.getSize().x *3 / 4) - (botao_jogo2.getGlobalBounds().width / 2),
  //     (boundsBase.top + boundsBase.height + window.getSize().y*0.1));

  botao_sair.setPosition(window.getSize().x - botao_sair.getGlobalBounds().width - 10.0f, 10.0f);
  
  sf::FloatRect boundsBase = logo.getGlobalBounds();

  botao_jogo1.setPosition((window.getSize().x / 3) - (botao_jogo1.getGlobalBounds().width / 2),
      (boundsBase.top + boundsBase.height + window.getSize().y*0.1));
    
  botao_jogo2.setPosition((window.getSize().x * 2 / 3) - (botao_jogo2.getGlobalBounds().width / 2),
      (boundsBase.top + boundsBase.height + window.getSize().y*0.1));

  

  // Posicionando menina e dialogo
  girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
  dialogo.setPosition(girl.getGlobalBounds().width - 150,
                      (window.getSize().y - dialogo.getGlobalBounds().height -
                       girl.getGlobalBounds().height) +
                          50);

  while (window.isOpen()){
    sf::Event event;
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
        // sf::Event::Closed is triggered whenever the user wants to close
        // the window via any method provided by the window manager
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::MouseButtonPressed:
          if (event.mouseButton.button == 0)
          {
            errorText.setString(L" ");

            if (comecoDoJogo) {

              if (botao_jogo1.click_outros(sf::Mouse::getPosition(window))) {
                // Carregando a imagem do background
                setBackground("./interface/assets/imagens/background.jpg", background, bgTexture, window);

                comecoDoJogo = false;
              }
              if (botao_jogo2.click_outros(sf::Mouse::getPosition(window))) {
                // Carregando a imagem do background
                setBackground("./interface/assets/imagens/background.jpg", background, bgTexture, window);

                int pontuacao = executarLivrosCaindo(window, db);

                comecoDoJogo = false;
                finalDoJogo = true;

                // Mudar lado da bibliotecária
                // dialogo.move(sf::Vector2f(50, 0));

                girl.setPosition(window.getSize().x / 2 - girl.getGlobalBounds().width / 2, window.getSize().y - girl.getGlobalBounds().height);
                dialogo.setPosition(girl.getPosition().x - girl.getGlobalBounds().width - 100,
                                    (window.getSize().y - dialogo.getGlobalBounds().height -
                                    girl.getGlobalBounds().height) +
                                        45);

                // Texto do final
                if (pontuacao <= 0){
                  pontuacao = 0;
                }
                int basePontuacao = 10;
                
                text.setPosition(dialogo.getPosition().x + 50, dialogo.getPosition().y + 100);                

                if (pontuacao == 0)
                  text.setString(L"Oh non!\n Vous n'avez rien obtenu de bon!");
                else if (pontuacao > 0 && pontuacao <= basePontuacao / 2)
                  text.setString(L"Vous pouvez faire plus que cela ! \n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
                else if (pontuacao >= ((basePontuacao / 2) + 1) && pontuacao < basePontuacao)
                  text.setString(L"  Vous vous êtes bien débrouillé,\n mais vous pouvez faire mieux.!\n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
                else if (pontuacao >= basePontuacao)
                  text.setString(L"Vous vous êtes très bien débrouillé !\n Félicitations!\n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
              }
            }
            else if (finalDoJogo) {
                if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria.png"))
                {
                  cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
                }
                else
                {
                  girl.setTexture(girlTexture);
                  girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
                }

                if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo.png"))
                {
                  cout << "Erro: não foi possível carregar a imagem do dialogo" << endl;
                }
                else
                {
                  dialogo.setTexture(dialogoTexture);
                  dialogo.setPosition(girl.getGlobalBounds().width - 150,
                                      (window.getSize().y - dialogo.getGlobalBounds().height -
                                      girl.getGlobalBounds().height) +
                                          50);
                }

                // Reposicionando texto
                text.setPosition(dialogo.getPosition().x + 40, dialogo.getPosition().y + 100);
                errorText.setPosition(dialogo.getPosition().x + 180, dialogo.getPosition().y + 200);

                // Reposicionando a menina e dialogo
                girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
                dialogo.setPosition(girl.getGlobalBounds().width - 150,
                  (window.getSize().y - dialogo.getGlobalBounds().height -
                  girl.getGlobalBounds().height) +
                      50);

              // JOGAR NOVAMENTE
              if (botao_jogo1.click_outros(sf::Mouse::getPosition(window))) {
                comecoDoJogo = false;
                finalDoJogo = false;

                // Resetando os elementos da pilha
                pilha = geraPilhaLivros(db, tamanho);

                // Resetando a pontuacao do jogador
                contadorScore = 0;

                // Reposicionando tudo na tela. Que deus tenha piedade da minha alma
                // pelo que vou fazer a seguir.

                livroAtual = pilha.remover();

                
                // Atualizando a mensagem de dialogo para o proximo livro
                text.setString(
                  L"Hmmm, on a ici le livre\n" +
                  livroAtual.getNome() +
                  L"\n écrit par " +
                  livroAtual.getAutor() +
                  L" en " +
                  to_wstring(livroAtual.getAnoLancamento()));

                
              }
              else if (botao_jogo2.click_outros(sf::Mouse::getPosition(window))){
                int pontuacao = executarLivrosCaindo(window, db);

                if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria-fim.png"))
                {
                  cout << "Erro: não foi possível carregar as imagens do fim" << endl;
                }
                else
                {
                  if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo-fim.png"))
                  {
                    cout << "Erro: não foi possível carregar as imagens do fim" << endl;
                  }
                  else
                  {
                    finalDoJogo = true;

                    // Mudar lado da bibliotecária
                    // dialogo.move(sf::Vector2f(50, 0));

                    girl.setPosition(window.getSize().x / 2 - girl.getGlobalBounds().width / 2, window.getSize().y - girl.getGlobalBounds().height);
                    dialogo.setPosition(girl.getPosition().x - girl.getGlobalBounds().width - 100,
                                        (window.getSize().y - dialogo.getGlobalBounds().height -
                                        girl.getGlobalBounds().height) +
                                            45);

                    // Texto do final
                    if (pontuacao <= 0){
                      pontuacao = 0;
                    }

                    text.setPosition(dialogo.getPosition().x + 50, dialogo.getPosition().y + 100);

                    if (pontuacao == 0)
                      text.setString(L"Oh non!\n Vous n'avez rien obtenu de bon!");
                    else if (pontuacao > 0 && pontuacao <= tamanho / 2)
                      text.setString(L"Vous pouvez faire plus que cela ! \n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
                    else if (pontuacao >= ((tamanho / 2) + 1) && pontuacao < tamanho)
                      text.setString(L"  Vous vous êtes bien débrouillé,\n mais vous pouvez faire mieux.!\n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
                    else if (pontuacao == tamanho)
                      text.setString(L"Vous vous êtes très bien débrouillé !\n Félicitations!\n Vous avez marqué des " + to_wstring(pontuacao) + L" points");
                  }
                }
                break;
              }
              // FIM
              else if (botao_sair.click_outros(sf::Mouse::getPosition(window)))
              {
                window.close();
                break;
              }
            }
            else if ((botao_historia.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_psicologia.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_letras.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_filosofia.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_geografia.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_matematica.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_informatica.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_quimica.click(sf::Mouse::getPosition(window), livroAtual) == 1) || (botao_arte.click(sf::Mouse::getPosition(window), livroAtual) == 1))
            {

              errouMais = 0;
              contadorScore++;

              if (!pilha.empty())
              {
                livroAtual = pilha.remover();
                text.setString(
                  L"Hmmm, on a ici le livre\n" +
                  livroAtual.getNome() +
                  L"\n écrit par " +
                  livroAtual.getAutor() +
                  L" en " +
                  to_wstring(livroAtual.getAnoLancamento()));
              }
              else
              { // SE O JOGO ACABAR
                if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria-fim.png"))
                {
                  cout << "Erro: não foi possível carregar as imagens do fim" << endl;
                }
                else
                {
                  if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo-fim.png"))
                  {
                    cout << "Erro: não foi possível carregar as imagens do fim" << endl;
                  }
                  else
                  {
                    finalDoJogo = true;

                    // Mudar lado da bibliotecária
                    // dialogo.move(sf::Vector2f(50, 0));

                    girl.setPosition(window.getSize().x / 2 - girl.getGlobalBounds().width / 2, window.getSize().y - girl.getGlobalBounds().height);
                    dialogo.setPosition(girl.getPosition().x - girl.getGlobalBounds().width - 100,
                                        (window.getSize().y - dialogo.getGlobalBounds().height -
                                        girl.getGlobalBounds().height) +
                                            45);

                    // Texto do final
                    if (contadorScore <= 0)
                    {
                      contadorScore = 0;
                    }

                    text.setPosition(dialogo.getPosition().x + 50, dialogo.getPosition().y + 100);

                    if (contadorScore == 0)
                      text.setString(L"Oh non!\n Vous n'avez rien obtenu de bon!");
                    else if (contadorScore > 0 && contadorScore <= tamanho / 2)
                      text.setString(L"Vous pouvez faire plus que cela ! \n Vous avez marqué des " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" points");
                    else if (contadorScore >= ((tamanho / 2) + 1) && contadorScore < tamanho)
                      text.setString(L"  Vous vous êtes bien débrouillé,\n mais vous pouvez faire mieux.!\n Vous avez marqué des " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" points");
                    else if (contadorScore == tamanho)
                      text.setString(L"Vous vous êtes très bien débrouillé !\n Félicitations!\n Vous avez marqué des " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" points");
                  }
                }
              }
            }
            else if ((botao_historia.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_psicologia.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_letras.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_filosofia.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_geografia.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_matematica.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_informatica.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_quimica.click(sf::Mouse::getPosition(window), livroAtual) == 0) || (botao_arte.click(sf::Mouse::getPosition(window), livroAtual) == 0))
            {

              if (!(errouMais > 0))
                contadorScore--;

              errouMais++;

              errorText.setString(L"Essa não é a categoria certa para o livro!\n Tente novamente!");

              // Mostrando novamente as informações do livro
              text.setString(
                L"Hmmm, on a ici le livre\n" +
                livroAtual.getNome() +
                L"\n écrit par " +
                livroAtual.getAutor() +
                L" en " +
                to_wstring(livroAtual.getAnoLancamento()));

              timer = 0;
            }
          }
          break;
        case sf::Event::MouseButtonReleased:
          botao_historia.release();
          botao_psicologia.release();
          botao_letras.release();
          botao_filosofia.release();
          botao_geografia.release();
          botao_matematica.release();
          botao_informatica.release();
          botao_quimica.release();
          botao_arte.release();
          botao_sair.release();
          botao_jogo1.release();
          botao_jogo2.release();
          break;
        default:
          break;
      }
    }

    if (comecoDoJogo) {
      window.clear();
      window.draw(background);
      window.draw(logo);
      window.draw(botao_jogo1);
      window.draw(botao_jogo2);
      // botao.desenhar(window);
      window.display();
    }
    else if (finalDoJogo) {
      window.clear();
      window.draw(background);
      window.draw(girl);
      window.draw(dialogo);
      window.draw(text);
      window.draw(botao_sair);
      window.draw(botao_jogo1);
      window.draw(botao_jogo2);
      window.display();
    }
    else
    {
      window.clear();
      window.draw(background);
      window.draw(girl);
      window.draw(dialogo);
      window.draw(text);
      window.draw(errorText);
      window.draw(botao_historia);
      window.draw(botao_psicologia);
      window.draw(botao_letras);
      window.draw(botao_filosofia);
      window.draw(botao_geografia);
      window.draw(botao_matematica);
      window.draw(botao_informatica);
      window.draw(botao_quimica);
      window.draw(botao_arte);
      window.display();
    }
  }
}

int executarLivrosCaindo(sf::RenderWindow& window, DatabaseConnection db) {
  sf::Sprite background;
  sf::Texture bgTexture;
  sf::Clock clock;
  Jogo jogo;
  tipoCesta cestita(db);
  int pontos = 0;
  Cesta c;

  Livro livroCair = getLivroAleatorio(db);
  float fallSpeed = 0.2f; // Velocidade de queda (pixels por segundo)
  livroCair.setVelocidadeQueda(fallSpeed);

  std::vector<Cesta> todasCestas = cestita.getCesta();
  std::vector<Cesta> cestaJogo = cestita.escolherCestasJogo(window, todasCestas);

  // Carregar a fonte
  sf::Font fonte;
  if (!fonte.loadFromFile("./interface/assets/fonts/Roboto-Medium.ttf")) 
  {
      std::cerr << "Erro ao carregar a fonte!" << std::endl;
  }

  // Configurar o texto
  sf::Text textoPontuacao;
  textoPontuacao.setFont(fonte);
  textoPontuacao.setCharacterSize(30.0f);
  textoPontuacao.setFillColor(sf::Color::White);
  textoPontuacao.setPosition(10.f, 10.f);
  cestita.printCestaJogo(cestita.getCesta());

  std::wcout << L"Posicao: " << livroCair.getShape().getPosition().y << std::endl;
  // Configurar velocidade de queda no objeto Livro
  background.setColor(sf::Color::Black);

  bool bookLanded = false;
  bool showBookInfo = true;
  sf::Clock infoClock;

  while (window.isOpen()) {
    sf::Event event;

  
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

      if (showBookInfo) {
            // Exibir a tela preta com o nome do livro
        window.clear(sf::Color(210, 180, 140)); 
        jogo.desenharNomeLivro(window, livroCair, fonte);
        window.display();

        // Exibir por 3 segundos antes de continuar
        if (infoClock.getElapsedTime().asSeconds() >= 3.f) {
            showBookInfo = false;
            infoClock.restart();
            livroCair.setVelocidadeQueda(fallSpeed); // Configura a velocidade novamente
            bookLanded = false;
        }
        continue;
    }
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
      cestaJogo = cestita.escolherCestasJogo(window, todasCestas);
    }
    

    setBackground("./interface/assets/imagens/background.jpg", background, bgTexture, window);

    textoPontuacao.setString("Score: "  + std::to_string(jogo.getPontuacao()));

    // Atualizar o tempo
    float deltaTime = clock.restart().asSeconds();

    int game_continue = 1;

    if (!bookLanded)  {
      // Usar a função mover e cair do Livro
      livroCair.mover(window);
      livroCair.cair();
      //std::wcout << L"Posicao: " << livroCair.getShape().getPosition().y + livroCair.getShape().getSize().y << std::endl;
      // Verificar se o livro tocou o chão
      if (livroCair.getShape().getPosition().y + livroCair.getShape().getSize().y >= (cestaJogo[0].getShape().getPosition().y + cestaJogo[0].getShape().getSize().y)){
          game_continue = jogo.verificarLivroNaCesta(livroCair, cestaJogo, jogo, fallSpeed, pontos);
          bookLanded = true; // Parar o movimento
          livroCair.getShape().setPosition(livroCair.getShape().getPosition().x, window.getSize().y - livroCair.getShape().getSize().y);// Ajustar no chão
          showBookInfo = true;
          infoClock.restart();
          livroCair = getLivroAleatorio(db); // Novo livro
          fallSpeed +=0.05f;
          livroCair.setVelocidadeQueda(fallSpeed);

          if (!game_continue){
            return jogo.getPontuacao();
          }
      }

    }

  // Renderizar o livro e elementos do jogo
    if (!showBookInfo) {
      window.draw(background);
      window.draw(textoPontuacao);
      window.draw(livroCair.getShape());
      c.desenharCestasComCategorias(window, cestaJogo, fonte);
      window.display();

    }
  }
}

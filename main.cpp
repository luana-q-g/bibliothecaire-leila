#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "livro/pilha.h"
#include "button/button.h"
#include "livro/tipoLivro.cpp"
#include "baselist/baselist.h"
#include <SFML/System/Vector2.hpp>
#include "cestas/tipoCesta.cpp"
#include "cestas/cesta.h"
#include "Jogo/jogo.h"




// Prototipagem das funções
void executarJogoAntigo(sf::RenderWindow& window, bool& modoLivrosCaindo);
void executarLivrosCaindo(sf::RenderWindow& window);

int main(int argc, char* argv[]) {
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

        executarLivrosCaindo(window);
        // Alternar entre os dois modos de jogo
        //if (!modoLivrosCaindo) {
        //    executarJogoAntigo(window, modoLivrosCaindo);
        //} else {
            
          //  modoLivrosCaindo = false;
        //}
    }

    return 0;
}

void executarJogoAntigo(sf::RenderWindow& window, bool& modoLivrosCaindo) {
    static bool comecoDoJogo = true;
    static bool finalDoJogo = false;
     // Lista pra cada categoria
  Lista<Livro> lista_letras(L"Letras");
  Lista<Livro> lista_filosofia(L"Filosofia");
  Lista<Livro> lista_geografia(L"Geografia");
  Lista<Livro> lista_historia(L"História");
  Lista<Livro> lista_matematica(L"Matemática");
  Lista<Livro> lista_psicologia(L"Psicologia");
  Lista<Livro> lista_informatica(L"Informática");
  Lista<Livro> lista_quimica(L"Química");
  Lista<Livro> lista_arte(L"Arte");

  // Vetor que armazena todas as listas(estantes)
  Lista<Livro> listas[9] = {
      lista_letras,      lista_filosofia,  lista_geografia,
      lista_historia,    lista_matematica, lista_psicologia,
      lista_informatica, lista_quimica,    lista_arte};



// Dimensões da tela
  const float windowWidth = 800.0f;
  const float windowHeight = 600.0f;

  // Dimensões do livro
  const float bookWidth = 50.0f;
  const float bookHeight = 100.0f;

  tipoLivro livrito;

  std::vector<Livro> lista_fixa = livrito.getLivros();

  int tamanho = 5;
  Pilha<Livro> pilha = Pilha<Livro>(tamanho, lista_fixa);

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
  Button botao_historia("historia", lista_historia);
  Button botao_psicologia("psicologia", lista_psicologia);
  Button botao_letras("letras", lista_letras);
  Button botao_filosofia("filosofia", lista_filosofia);
  Button botao_geografia("geografia", lista_geografia);
  Button botao_matematica("matematica", lista_matematica);
  Button botao_informatica("informatica", lista_informatica);
  Button botao_quimica("quimica", lista_quimica);
  Button botao_arte("artes", lista_arte);
  Button botao_jogarNovamente("jogar_novamente", 268, 56);
  Button botao_sair("sair", 145, 56);
  Button botao_iniciar("iniciar", 200, 65);



  int contadorScore = 0;
  int errouMais;

  srand(time(0));

  sf::Clock clock;
  float timer = 0, delay = 1.5;

  sf::Font font;
  sf::Text text;
  sf::Text errorText;
  Livro livroAtual = pilha.remover();

  // Iniciando o background com a cor preta
  background.setColor(sf::Color::Black);

  if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria.png")) {
    cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
  } else {
    girl.setTexture(girlTexture);
    girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
  }

  if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo.png")) {
    cout << "Erro: não foi possível carregar a imagem do dialogo" << endl;
  } else {
    dialogo.setTexture(dialogoTexture);
    dialogo.setPosition(girl.getGlobalBounds().width - 150,
                        (window.getSize().y - dialogo.getGlobalBounds().height -
                         girl.getGlobalBounds().height) + 50);
  }

  if (!logoTexture.loadFromFile("./interface/assets/imagens/logo.png")){
                cout << "Não carregou a imagem\n" << endl;
  } else {
    logo.setTexture(logoTexture);
    logo.setPosition(((window.getSize().x) / 2) - (logo.getGlobalBounds().width / 2), ((window.getSize().y) / 2) - (logo.getGlobalBounds().height / 2));
  }

  if (!font.loadFromFile("./interface/assets/fonts/Roboto-Bold.ttf")) {
    cout << "Erro: não foi possível carregar a fonte";
  } else {
    text.setFont(font);
    text.setString(
      L"Hmmm, temos aqui o livro\n" +
      livroAtual.getNome() +
      L"\n escrito por " +
      livroAtual.getAutor() +
      L" em " +
      to_wstring(livroAtual.getAnoLancamento())
    );

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
  botao_jogarNovamente.setPosition(window.getSize().x/2 - (girl.getGlobalBounds().width)*1.5, window.getSize().y - 140);
  botao_sair.setPosition((window.getSize().x / 2) - (botao_sair.getGlobalBounds().width) + 200, window.getSize().y - 140);
  botao_iniciar.setPosition((window.getSize().x / 2) - (botao_iniciar.getGlobalBounds().width / 2), (logo.getPosition().y + (logo.getGlobalBounds().height * 0.3)));

  // Posicionando menina e dialogo
  girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
  dialogo.setPosition(girl.getGlobalBounds().width - 150,
                      (window.getSize().y - dialogo.getGlobalBounds().height -
                       girl.getGlobalBounds().height) + 50);

  while (window.isOpen()) {
    sf::Event event;
    Button buttonPressed;

    //timer mensagem de erro
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer+=time;

    if(timer > delay) {
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
        if (event.mouseButton.button == 0){
          errorText.setString(L" ");

          if(comecoDoJogo){

            if(botao_iniciar.click_outros(sf::Mouse::getPosition(window))){
              // Carregando a imagem do background
              if (!bgTexture.loadFromFile("./interface/assets/imagens/background.jpg")) {
                cout << "Erro: não foi possível carregar a imagem de background" << endl;
              } else {
                // resized background
                sf::Vector2u TextureSize = bgTexture.getSize(); // Get size of texture.
                sf::Vector2u WindowSize = window.getSize();     // Get size of window.

                float ScaleX = (float)WindowSize.x / TextureSize.x;
                float ScaleY = (float)WindowSize.y / TextureSize.y; // Calculate scale.

                background.setColor(sf::Color::White); // Removing old color (must be white, not transparent)
                background.setScale(ScaleX, ScaleY); // Set scale.
                background.setTexture(bgTexture, true);
              }

              comecoDoJogo = false;
            }
          }
          else if(finalDoJogo){
            //JOGAR NOVAMENTE
            if(botao_jogarNovamente.click_outros(sf::Mouse::getPosition(window))){
              comecoDoJogo = false;
              finalDoJogo = false;

              // Resetando os elementos da pilha
              pilha =  Pilha<Livro>(tamanho, lista_fixa);

              // Resetando a pontuacao do jogador
              contadorScore = 0;

              // Reposicionando tudo na tela. Que deus tenha piedade da minha alma
              // pelo que vou fazer a seguir.

              livroAtual = pilha.remover();

              if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria.png")) {
                cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
              } else {
                girl.setTexture(girlTexture);
                girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
              }

              if (!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo.png")) {
                cout << "Erro: não foi possível carregar a imagem do dialogo" << endl;
              } else {
                dialogo.setTexture(dialogoTexture);
                dialogo.setPosition(girl.getGlobalBounds().width - 150,
                                    (window.getSize().y - dialogo.getGlobalBounds().height -
                                     girl.getGlobalBounds().height) + 50);
              }

              // Reposicionando texto
              text.setPosition(dialogo.getPosition().x + 40, dialogo.getPosition().y + 100);
              errorText.setPosition(dialogo.getPosition().x + 180, dialogo.getPosition().y + 200);

              // Atualizando a mensagem de dialogo para o proximo livro
              text.setString(
                L"Hmmm, temos aqui o livro\n" +
                livroAtual.getNome() +
                L"\n escrito por " +
                livroAtual.getAutor() +
                L" em " +
                to_wstring(livroAtual.getAnoLancamento())
              );

              // Reposicionando a menina e dialogo
              girl.setPosition(0, window.getSize().y - girl.getGlobalBounds().height);
              dialogo.setPosition(girl.getGlobalBounds().width - 150,
                                  (window.getSize().y - dialogo.getGlobalBounds().height -
                                   girl.getGlobalBounds().height) + 50);
            }
            //FIM
            else if(botao_sair.click_outros(sf::Mouse::getPosition(window))){
              modoLivrosCaindo = true;
              return;
            }
          }
          else if((botao_historia.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_psicologia.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_letras.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_filosofia.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_geografia.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_matematica.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_informatica.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_quimica.click(sf::Mouse::getPosition(window), livroAtual) == 1)
              || (botao_arte.click(sf::Mouse::getPosition(window), livroAtual) == 1)){

            errouMais = 0;
            contadorScore++;

            if(!pilha.empty()){
              livroAtual = pilha.remover();
              text.setString(
                L"Hmmm, temos aqui o livro\n" +
                livroAtual.getNome() +
                L"\n escrito por " +
                livroAtual.getAutor() +
                L" em " +
                to_wstring(livroAtual.getAnoLancamento())
              );
            }else{ //SE O JOGO ACABAR
              if (!girlTexture.loadFromFile("./interface/assets/imagens/bibliotecaria-fim.png")) {
                  cout << "Erro: não foi possível carregar as imagens do fim" << endl;
              }else{
                if(!dialogoTexture.loadFromFile("./interface/assets/imagens/dialogo-fim.png")){
                  cout << "Erro: não foi possível carregar as imagens do fim" << endl;
                }
                else{
                  finalDoJogo = true;

                  //Mudar lado da bibliotecária
                  //dialogo.move(sf::Vector2f(50, 0));

                  girl.setPosition(window.getSize().x/2 - girl.getGlobalBounds().width/2, window.getSize().y - girl.getGlobalBounds().height);
                  dialogo.setPosition(girl.getPosition().x - girl.getGlobalBounds().width - 100,
                        (window.getSize().y - dialogo.getGlobalBounds().height -
                         girl.getGlobalBounds().height) + 45);

                  //Texto do final
                  if (contadorScore <= 0 ){
                    contadorScore = 0;
                  }

                  text.setPosition(dialogo.getPosition().x + 50, dialogo.getPosition().y + 100);

                  if (contadorScore == 0)
                      text.setString(L"Aah não!\n Você não acertou nenhuma!");
                  else if (contadorScore > 0 && contadorScore <= tamanho / 2)
                      text.setString(L"Você pode fazer mais do que isso!\n Você acertou " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" pontos");
                  else if(contadorScore >= ((tamanho / 2) + 1)  && contadorScore < tamanho)
                      text.setString(L"  Você foi muito bem,\nporém pode ser melhor!\n Você acertou " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" pontos");
                  else if(contadorScore == tamanho)
                      text.setString(L"Você gabaritou, parabéns!\n Você acertou " + to_wstring(contadorScore) + L"/" + to_wstring(tamanho) + L" pontos");

                }
              }
            }
          } else if((botao_historia.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_psicologia.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_letras.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_filosofia.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_geografia.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_matematica.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_informatica.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_quimica.click(sf::Mouse::getPosition(window), livroAtual) == 0)
              || (botao_arte.click(sf::Mouse::getPosition(window), livroAtual) == 0)){

            if (!(errouMais > 0))
              contadorScore--;

            errouMais++;

            errorText.setString(L"Essa não é a categoria certa para o livro!\n Tente novamente!");

            // Mostrando novamente as informações do livro
            text.setString(
              L"Hmmm, temos aqui o livro\n" +
              livroAtual.getNome() +
              L"\n escrito por " +
              livroAtual.getAutor() +
              L" em " +
              to_wstring(livroAtual.getAnoLancamento())
            );

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
          botao_jogarNovamente.release();
          botao_iniciar.release();
        break;
      default:
        break;
      }
    }

    if (comecoDoJogo){
      window.clear();
      window.draw(background);
      window.draw(logo);
      window.draw(botao_iniciar);
      window.display();
    }
    else if (finalDoJogo) {
      window.clear();
      window.draw(background);
      window.draw(girl);
      window.draw(dialogo);
      window.draw(text);
      window.draw(botao_sair);
      window.draw(botao_jogarNovamente);
      window.display();
    }
    else{
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

void executarLivrosCaindo(sf::RenderWindow& window) 
{
    sf::Sprite background;

    // Configuração do tempo
    sf::Clock clock;
    float fallSpeed = 0.5f; // Velocidade de queda (pixels por segundo)

    // Criar um livro para cair
   tipoLivro livrito;
   Livro livroCair = livrito.getLivroAleatorio();
   Jogo jogo;
   tipoCesta cestita;

   std::vector<Cesta> todasCestas = cestita.getCesta();


   std::vector<Cesta> cestaJogo = cestita.escolherCestasJogo(todasCestas);




   cestita.printCestaJogo(cestita.getCesta());
   std::wcout << L"Posicao: " << livroCair.getShape().getPosition().y << std::endl;
    // Configurar velocidade de queda no objeto Livro
    livroCair.setVelocidadeQueda(fallSpeed);




    bool bookLanded = false;
    while (window.isOpen()) {
      sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)
            window.close();
        }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            cestaJogo = cestita.escolherCestasJogo(todasCestas);
    }


      // Atualizar o tempo
      float deltaTime = clock.restart().asSeconds();

      if (!bookLanded) {
          // Usar a função mover e cair do Livro
          livroCair.mover(window);
          livroCair.cair();
          std::wcout << L"Posicao: " << livroCair.getShape().getPosition().y + livroCair.getShape().getSize().y << std::endl;


          jogo.verificarLivroNaCesta(livroCair,cestaJogo);

          // Verificar se o livro tocou o chão
          if (livroCair.getShape().getPosition().y + livroCair.getShape().getSize().y >= window.getSize().y) 
          {

              bookLanded = true; // Parar o movimento
              livroCair.getShape().setPosition(
                  livroCair.getShape().getPosition().x, 
                  window.getSize().y - livroCair.getShape().getSize().y);// Ajustar no chão
          }
      }
    

      // Renderizar o livro
      window.clear(sf::Color::White);
      window.draw(livroCair.getShape());
      for (const auto& cesta : cestaJogo) {
        window.draw(cesta.getShape());
        }
       window.display();

      
      // Finalizar o jogo (simples)
      if (bookLanded) {
          sf::sleep(sf::seconds(2)); // Pausa de 2 segundos antes de sair
          break; // Sai da função e retorna
      }
    }
    
}
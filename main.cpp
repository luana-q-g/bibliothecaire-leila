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
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "listacadastral/lista.cpp"
#include "listacadastral/lista.h"
#include "livro/livro.h"
#include "pilha/pilha.cpp"
#include "pilha/pilha.h"

#include "button/button.h"

using namespace std;

// Função principal
int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese");

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

  Livro letras_l1(L"Libras: conhecimento além dos sinais", L"Maria Cristina da Cunha", L"Letras", 2011, L"Pearson");
  Livro letras_l2(L"Comunicação e linguagem", L"Thelma de Carvalho Guimarães", L"Letras", 2012, L"Pearson");
  Livro letras_l3(L"Teoria da Literatura I", L"Pedro Paulo da Silva", L"Letras", 2009, L"Pearson");
  Livro letras_l4(L"Língua latina", L"Charlene Martins Miotti", L"Letras", 2010, L"Pearson");
  Livro filosofia_l5(L"Introdução à Filosofia", L"João Mattar", L"Filosofia", 2010, L"Pearson");
  Livro filosofia_l6(L"Ética", L"Maria Thereza Pompa Antunes", L"Filosofia", 2012, L"Pearson");
  Livro filosofia_l7(L"Correntes modernas de filosofia", L"José Ferraz Neto", L"Filosofia", 2013, L"Pearson");
  Livro filosofia_l8(L"Genealogia da Moral", L"Friedrich Nietzsche", L"Filosofia", 1887, L"Vozes");
  Livro geografia_l9(L"Hidrologia", L"Diego Barreto de Oliveira", L"Geografia", 2015, L"Pearson");
  Livro geografia_l10(L"Espaço Geográfico: ensino e representação", L"Rosangela Doin de Almeida", L"Geografia", 1989, L"Contexto");
  Livro geografia_l11(L"Pensamento geográfico brasileiro", L"Ruy Moreira", L"Geografia", 2008, L"Contexto");
  Livro geografia_l12(L"Globalização e espaço geográfico", L"Eustáquio de Sene", L"Geografia", 2004, L"Contexto");
  Livro historia_l13(L"No Tempo das Especiarias: o império da pimenta e do açúcar", L"Fábio Pestana", L"História", 2006, L"Contexto");
  Livro historia_l14(L"Dicionário de Datas da História do Brasil", L"Circe Bittencour", L"História", 2007, L"Contexto");
  Livro historia_l15(L"História do Café", L"Ana Luiza Martins", L"História", 2008, L"Contexto");
  Livro historia_l16(L"As Primeiras Civilizações", L"Jaime Pinsky", L"História", 2011, L"Contexto");
  Livro matematica_l17(L"Geometria Analítica: Um Tratamento Vetorial", L"Ivan de Camargo", L"Matemática", 2005, L"Pearson");
  Livro matematica_l18(L"Matemática financeira", L"André Wakamatsu", L"Matemática", 2018, L"Pearson");
  Livro matematica_l19(L"Métodos numéricos em equações diferenciais", L"Marina Vargas", L"Matemática", 2021, L"Intersaberes");
  Livro matematica_l20(L"Geometrias Não Euclidianas", L"Nelson Pereira", L"Matemática", 2020, L"Intersaberes");
  Livro psicologia_l21(L"Teorias da Personalidade", L"Howard S. Friedman", L"Psicologia", 2003, L"Pearson");
  Livro psicologia_l22(L"Introdução à Psicologia", L"Charles G. Morris", L"Psicologia", 2004, L"Pearson");
  Livro psicologia_l23(L"A Psicanálise nas Tramas da Cidade", L"Bernardo Tanis", L"Psicologia", 2009, L"Pearson");
  Livro psicologia_l24(L"Burnout: quando o trabalho ameaça o bem-estar do trabalhador", L"Ana Maria Benevides Pereira", L"Psicologia", 2014, L"Pearson");
  Livro informatica_l25(L"Aprenda Programação Orientada a Objetos em 21 dias", L"Anthony Sintes", L"Informática", 2002, L"Pearson");
  Livro informatica_l26(L"Treinamento em Linguagem C++: módulo 1", L"Victorine Viviane Mizrahi", L"Informática", 1996, L"Pearson");
  Livro informatica_l27(L"Manual Completo do Linux: guia do administrador", L"Evi Nemeth", L"Informática", 2004, L"Pearson");
  Livro informatica_l28(L"Compiladores: princípios, técnicas e ferramentas", L"Alfred V. Alho", L"Informática", 2007, L"Pearson");
  Livro quimica_l29(L"Química Orgânica", L"Bianca Sandrino", L"Química", 2020, L"Intersaberes");
  Livro quimica_l30(L"Química Quântica: Origens e Aplicações", L"Liziane Barbara Bugalski", L"Química", 2019, L"Intersaberes");
  Livro quimica_l31(L"Manual de Ar Comprimido e Gases", L"John P. Rollins", L"Química", 2003, L"Pearson");
  Livro quimica_l32(L"Estudos de eletroquímica: reações químicas e energia", L"Ana Luiza Lorenzen", L"Química", 2017, L"Intersaberes");
  Livro arte_l33(L"Estética e história da arte", L"Humberta Gomes Machado Porto", L"Arte", 2016, L"Pearson");
  Livro arte_l34(L"História do cinema mundial", L"Fernando Mascarello", L"Arte", 2014, L"Papirus");
  Livro arte_l35(L"Beethoven: as muitas faces de um gênio", L"João Mauricio Galindo", L"Arte", 2019, L"Contexto");
  Livro arte_l36(L"O cinema de Quentin Tarantino", L"Mauro Baptista", L"Arte", 2018, L"Papirus");

  Livro lista_fixa[] = {
      letras_l1,       letras_l2,       letras_l3,
      letras_l4,       filosofia_l5,    filosofia_l6,
      filosofia_l7,    filosofia_l8,    geografia_l9,
      geografia_l10,   geografia_l11,   geografia_l12,
      historia_l13,    historia_l14,    historia_l15,
      historia_l16,    matematica_l17,  matematica_l18,
      matematica_l19,  matematica_l20,  psicologia_l21,
      psicologia_l22,  psicologia_l23,  psicologia_l24,
      informatica_l25, informatica_l26, informatica_l27,
      informatica_l28, quimica_l29,     quimica_l30,
      quimica_l31,     quimica_l32,     arte_l33,
      arte_l34,        arte_l35,        arte_l36}; // Pilha com os livros

  int tamanho = 5;
  Pilha<Livro> *pilha = new Pilha<Livro>(tamanho, lista_fixa);

  sf::RenderWindow window(sf::VideoMode(626 * 2, 375 * 2),
                          "Bibliotecária Leila");
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

  bool comecoDoJogo = true;
  bool finalDoJogo = false; // Condição para entrar no final do jogo

  int contadorScore = 0;
  int errouMais;

  srand(time(0));

  sf::Clock clock;
  float timer = 0, delay = 1.5;

  sf::Font font;
  sf::Text text;
  sf::Text errorText;
  Livro livroAtual = pilha->remover();

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
  botao_jogarNovamente.setPosition(window.getSize().x/2 - (girl.getGlobalBounds().width)*1.7, window.getSize().y - 140);
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
              delete pilha;
              pilha = new Pilha<Livro>(tamanho, lista_fixa);

              // Resetando a pontuacao do jogador
              contadorScore = 0;

              // Reposicionando tudo na tela. Que deus tenha piedade da minha alma
              // pelo que vou fazer a seguir.

              livroAtual = pilha->remover();

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
              window.close();
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

            if(!pilha->empty()){
              livroAtual = pilha->remover();
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
                         girl.getGlobalBounds().height) + 25);

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

  return 0;
}

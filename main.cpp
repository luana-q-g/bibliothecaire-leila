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
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
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
#include "utils/utils.h"

using namespace std;

// Função principal
int main(int argc, char *argv[]) {
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

  // Vetor que armazena todas as listas(estantes)
  Lista<Livro> listas[9] = {
      lista_letras,      lista_filosofia,  lista_geografia,
      lista_historia,    lista_matematica, lista_psicologia,
      lista_informatica, lista_quimica,    lista_arte};

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

  Pilha<Livro> pilha(10, lista_fixa);

  sf::RenderWindow window(sf::VideoMode(626 * 2, 375 * 2),
                          "Bibliotecária Leila");
  sf::Texture bgTexture;
  sf::Texture girlTexture;
  sf::Texture dialogoTexture;
  sf::Texture botaoHistoriaTexture;
  sf::Texture botaoHistoriaClicadoTexture;
  sf::Sprite background;
  sf::Sprite girl;
  sf::Sprite dialogo;
  sf::Sprite botao_historia;
  sf::Sprite botao_historia_clicado;

  if (!bgTexture.loadFromFile("./interface/assets/imagens/background.jpg")) {
    cout << "Erro: não foi possível carregar a imagem de background" << endl;
  } else {
    // resized background
    sf::Vector2u TextureSize = bgTexture.getSize(); // Get size of texture.
    sf::Vector2u WindowSize = window.getSize();     // Get size of window.

    float ScaleX = (float)WindowSize.x / TextureSize.x;
    float ScaleY = (float)WindowSize.y / TextureSize.y; // Calculate scale.

    background.setScale(ScaleX, ScaleY); // Set scale.
    background.setTexture(bgTexture, true);
  }

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
                        girl.getGlobalBounds().height - 350);
  }

  sf::Font font;
  sf::Text text;

  if (!font.loadFromFile("./interface/assets/Roboto-Bold.ttf")) {
    cout << "Erro: não foi possível carregar a fonte";
  } else {
    text.setFont(font);
    text.setString("Bem-vindo!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(dialogo.getPosition().x + 200, dialogo.getPosition().y +
    100);
  }

  if(!botaoHistoriaTexture.loadFromFile("./interface/assets/imagens/botoes/botoes_historia.png")){
    cout << "Erro: não foi possível carregar a imagem da bela moça" << endl;
  }else{
    botao_historia.setTexture(botaoHistoriaTexture);
    botao_historia.setPosition(400, 600);
  }

  while (window.isOpen()) {
    sf::Event event;
    bool isClicked;

    // While there are pending events
    while (window.pollEvent(event)) {

      // Check the element type
      switch (event.type) {
      // sf::Event::Closed is triggered whenever the user wants to close
      // the window via any method provided by the window manager
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        cout << "Key pressed was: " << event.key.code << endl;
        break;
      case sf::Event::MouseMoved:
        if (isClicked) {
          // Simple set position
          // circle.setPosition(event.mouseMove.x, event.mouseMove.y);

          // Set position centering the object
          // circle.setPosition(
          //     (event.mouseMove.x - (circle.getGlobalBounds().width / 2)),
          //     (event.mouseMove.y - (circle.getGlobalBounds().height / 2)));

          // Checking colision with rectangle
          // if(circle.getGlobalBounds().intersects(rectangleBounding)){
          //   cout << "Inside the rectangle!" << endl;
          // }else{
          //   cout << "Outside the rectangle!" << endl;
          // }
        }
        break;
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == 0)
          isClicked = true;
        break;
      case sf::Event::MouseButtonReleased:
        // Checking if the object was "droped" on a specifc spot
        // if (circle.getGlobalBounds().intersects(rectangleBounding)) {
        //   //cout << "Inside the rectangle!" << endl;
        //   circle.setPosition(rectangle.getPosition().x,
        //                      rectangle.getPosition().y);
        // } else {
        //   centerShape(circle, window);
        //   //cout << "Outside the rectangle!" << endl;
        // }

        isClicked = false;
        break;
      default:
        break;
      }
    }

    window.clear();
    window.draw(background);
    window.draw(girl);
    window.draw(dialogo);
    window.draw(text);
    window.draw(botao_historia);
    //window.draw(letras_l1.getShape());
    window.display();
  }

  return 0;
}

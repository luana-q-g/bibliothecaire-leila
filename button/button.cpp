/*

  Autor(es): Luís Augusto Simas do Nascimento
  Data de Criação: 23/06/2021
  Data de Atualização: 23/06/2021

  Objetivos: Implementar a classe button

*/

#include <iostream>
#include <string>
#include "button.h"

using namespace std;

Button::Button() : sf::RectangleShape(sf::Vector2f(112,56)){
  clicked = false;
}

Button::Button(string tipo, int w, int h) : sf::RectangleShape(sf::Vector2f(w, h)){
  if(!textureIdle.loadFromFile("./interface/assets/imagens/botoes/botoes_" + tipo + ".png")
  || !textureClicked.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_" + tipo + ".png")){
    cout << "Erro: não foi possível carregar a imagem do botão " + tipo << endl;
  }else{
    nome = tipo;
    clicked = false;
    setTexture(&textureIdle);
  }
}


Button::Button(string tipo, Lista<Livro> _lista) : sf::RectangleShape(sf::Vector2f(112,56)){
  if(!textureIdle.loadFromFile("./interface/assets/imagens/botoes/botoes_" + tipo + ".png")
  || !textureClicked.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_" + tipo + ".png")){
    cout << "Erro: não foi possível carregar a imagem do botão " + tipo << endl;
  }else{
    lista = _lista;
    nome = tipo;
    clicked = false;
    setTexture(&textureIdle);
  }
}

bool Button::click(const sf::Vector2i point, Livro livro){
  if(sf::RectangleShape::getGlobalBounds().contains((float) point.x, (float) point.y)){
    if(!clicked){
      setTexture(&textureClicked);
      clicked = true;
      return lista.inserir(livro, 0);
    }
  }

  return false;
}

bool Button::click_outros(const sf::Vector2i point){
  if(sf::RectangleShape::getGlobalBounds().contains((float) point.x, (float) point.y)){
    if(!clicked){
      setTexture(&textureClicked);
      clicked = true;
      return true;
    }
  }
  return false;
}

void Button::release(){
  if(clicked){
    clicked = false;
    setTexture(&textureIdle);
  }
}

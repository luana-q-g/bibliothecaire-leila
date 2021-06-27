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

Button::Button() : sf::RectangleShape(sf::Vector2f(112,56)){}

Button::Button(string tipo, int w, int h) : sf::RectangleShape(sf::Vector2f(w, h)){
  if(!textureIdle.loadFromFile("./interface/assets/imagens/botoes/botoes_" + tipo + ".png")
  || !textureClicked.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_" + tipo + ".png")){
    cout << "Erro: não foi possível carregar a imagem do botão " + tipo << endl;
  }else{
    nome = tipo;
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
    setTexture(&textureIdle);
  }
}

int Button::click(const sf::Vector2i point, Livro livro){
  if(sf::RectangleShape::getGlobalBounds().contains((float) point.x, (float) point.y)){
    setTexture(&textureClicked);
    return lista.inserir(livro, 0) ? 1 : 0;
  }

  // Return -1 if there was no click
  return -1;
}

bool Button::click_outros(const sf::Vector2i point){
  if(sf::RectangleShape::getGlobalBounds().contains((float) point.x, (float) point.y)){
    setTexture(&textureClicked);
    return true;
  }

  return false;
}

void Button::release(){
  setTexture(&textureIdle);
}

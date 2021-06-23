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

Button::Button(string tipo) : sf::RectangleShape(sf::Vector2f(112,56)){
  if(!textureIdle.loadFromFile("./interface/assets/imagens/botoes/botoes_" + tipo + ".png")
  || !textureClicked.loadFromFile("./interface/assets/imagens/botoes_clicados/botoes_clicados_" + tipo + ".png")){
    cout << "Erro: não foi possível carregar a imagem do botão " + tipo << endl;
  }else{
    nome = tipo;
    setTexture(&textureIdle);
  }
}

void Button::click(const sf::Vector2i point){
  if(sf::RectangleShape::getGlobalBounds().contains((float) point.x, (float) point.y)){
    cout << "Clicou em " << nome << "!" <<endl;
  }
}

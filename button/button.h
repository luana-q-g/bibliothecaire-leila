/*

  Autor(es): Luís Augusto Simas do Nascimento
  Data de Criação: 23/06/2021
  Data de Atualização: 23/06/2021

  Objetivos: Arquivo de cabeçalho da classe button

*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <string>

using namespace std;

class Button : public sf::RectangleShape {
private:
    string nome;
  bool clicked;
  bool active;
  sf::Texture textureClicked;
  sf::Texture textureIdle;

public:
  Button(string tipo);
  void click(const sf::Vector2i point);
};

#endif

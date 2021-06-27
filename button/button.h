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
#include "../listacadastral/lista.h"
#include "../listacadastral/lista.cpp"
#include "../livro/livro.h"

using namespace std;

class Button : public sf::RectangleShape {
private:
  string nome;
  bool clicked;
  bool active;
  sf::Texture textureClicked;
  sf::Texture textureIdle;
  Lista<Livro> lista;

public:
  Button();
  Button(string tipo, Lista<Livro> _lista);
  Button(string tipo, int = 112, int = 56);
  bool click(const sf::Vector2i point, Livro livro);
  bool click_outros(const sf::Vector2i point);
  void release();
};

#endif

/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/06/2021
Data de Atualização: 21/06/2021

Objetivos: Arquivo de implementação para utilidades de interface

*/

#include "interfaceUtils.h"

void centerShape(sf::Shape &shape, sf::RenderWindow &window) {
  shape.setPosition(window.getSize().x / 2.f - shape.getGlobalBounds().width,
                    window.getSize().y / 2.f- shape.getGlobalBounds().height);
}

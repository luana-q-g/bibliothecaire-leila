/*

Autor(es): Luís Augusto Simas do Nascimento
Data de Criação: 21/06/2021
Data de Atualização: 21/06/2021

Objetivos: Arquivo de cabeçalho para utilidades de interface

*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>


void initInterface(sf::Window &window);
void centerShape(sf::Shape &shape, sf::RenderWindow &window);

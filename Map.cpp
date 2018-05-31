#include "Map.h"

Map::Map(float width, float height)
{
	// mapa
	rect[0].setSize(sf::Vector2f(width, height));
	rect[0].setPosition(0, 60);
	rect[0].setFillColor(sf::Color::Green);
	int x = 60, y = 0;

	//droga
	rect[1].setSize(sf::Vector2f(1160, 60));
	rect[1].setPosition(0, 120);
	rect[1].setFillColor(sf::Color::White);

	for (int i = 2; i < 5; i++)
	{
		rect[i].setSize(sf::Vector2f(1100, 60));
		rect[i].setPosition(x, 240 + y * 120);
		rect[i].setFillColor(sf::Color::White);
		y++;
	}

	//polaczenia
	for (int i = 5; i < 10; i++)
	{
		rect[i].setSize(sf::Vector2f(60, 60));
		rect[i].setFillColor(sf::Color::White);
	}
	rect[5].setPosition(1100, 180);
	rect[6].setPosition(60, 300);
	rect[7].setPosition(1100, 420);
	rect[8].setPosition(60, 540);

	//baza
	rect[9].setSize(sf::Vector2f(60, 60));
	rect[9].setPosition(60, 600);
	rect[9].setFillColor(sf::Color::Red);
}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < NumberOfItems; i++)
		window.draw(rect[i]);
}
#pragma once
#include  "SFML/Graphics.hpp"

#define NumberOfItems 10
class Map
{
	friend class Game;
private:
	sf::RectangleShape rect[NumberOfItems];
public:

	Map(float width, float height);
	~Map();

	void draw(sf::RenderWindow &window);
};


#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

#define NumberOfItem 3

class Stats
{
private:
	std::ostringstream ss;
	
	sf::Font font;
	sf::Text stats[NumberOfItem];
	sf::Text stats2[NumberOfItem];

	int baseHealth1 = 10;
	int wave1 = 1;
	int gold1 = 20;
public:
	Stats(float width, float height);
	~Stats();

	void draw(sf::RenderWindow &window);
	void check(); // ustawienie statystyk

	// pobranie statystyk
	void zycie(int hp);
	void waves(int wave);
	void gold(int golds);
	void goldPlus(int golds);
	int goldTo();
};
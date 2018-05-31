#pragma once
#include  "SFML/Graphics.hpp"

#define NumberOfItems 2
class Menu // tworzy okno opcji
{
private:
	int SelectedOptionIndex;
	sf::Font font;
	sf::Text menu[NumberOfItems];
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MenuPlay();
	void MenuExit();
	int SelectedIndex();
};


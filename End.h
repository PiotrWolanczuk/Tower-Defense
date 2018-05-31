#pragma once
#include  "SFML/Graphics.hpp"

class End
{
private:
	sf::Font font;
	sf::Text end;
public:
	End();
	~End();

	void loose();
	void win();
};


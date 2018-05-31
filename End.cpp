#include "End.h"

End::End()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//error---------------------------------
	}
	end.setFont(font);
	end.setFillColor(sf::Color::Yellow);
	end.setPosition(sf::Vector2f(260, 260));
	end.setCharacterSize(24);
	end.setStyle(sf::Text::Bold);
}
End::~End()
{
}
void End::loose()
{
	end.setString("Przegrales!");
	sf::RenderWindow window(sf::VideoMode(600, 600), "Koniec gry");
	while (window.isOpen())
	{
		sf::Event wydarzenie;
		while (window.pollEvent(wydarzenie))
		{
			if(wydarzenie.type == sf::Event::Closed)
				window.close();
			if(sf::Event::KeyPressed == sf::Keyboard::Escape)
				window.close();
		}	
		window.draw(end);
		window.display();
	}
	
}
void End::win()
{
	end.setString("Wygrales gre! Gratulacje!");
	sf::RenderWindow window(sf::VideoMode(600, 600), "Koniec gry");
	while (window.isOpen())
	{
		sf::Event wydarzenie;
		while (window.pollEvent(wydarzenie))
		{
			if (wydarzenie.type == sf::Event::Closed)
				window.close();
			if (sf::Event::KeyPressed == sf::Keyboard::Escape)
				window.close();
		}
		window.draw(end);
		window.display();
	}
}
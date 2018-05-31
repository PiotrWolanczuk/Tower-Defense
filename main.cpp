#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Tutorial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Tower Defense - opcje");
	Tutorial tutorial;
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())// glowna petla aplikacji
	{
		sf::Event wydarzenie;
		while (window.pollEvent(wydarzenie))
		{
			switch (wydarzenie.type)
			{
			case sf::Event::KeyReleased:
				switch (wydarzenie.key.code)
				{
				case sf::Keyboard::Escape:
				{
					window.close();
				}break;
				case sf::Keyboard::Up: // podswietlenie "Play"
					menu.MenuPlay();
					break;

				case sf::Keyboard::Down: // podswietlenie "Exit"
					menu.MenuExit();
					break;
				case sf::Keyboard::Return: // Exit = wylaczenie aplikacji
					if (menu.SelectedIndex() == 1)
					{
						window.close();
					}
					else if (menu.SelectedIndex() == 0) // play = wlaczenie gry
					{
						window.close();
						tutorial.beginning();
						break;
					}
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		menu.draw(window);
		window.display();
	}
	return 0;
}

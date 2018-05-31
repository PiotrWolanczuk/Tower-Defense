#include "Menu.h"
#include <math.h>


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//error---------------------------------
	}
	for (int i = 0; i < NumberOfItems; i++)
	{
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f(width / 2, height / 4 * (i + 1)));
		menu[i].setCharacterSize(24);
		menu[i].setStyle(sf::Text::Bold);
	}

	menu[0].setFillColor(sf::Color::Yellow);
	menu[0].setString("Play");
	menu[1].setString("Exit");

	SelectedOptionIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < NumberOfItems; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MenuPlay() // podsweitlanie "Play"
{
	if (SelectedOptionIndex == 1)
	{
		menu[SelectedOptionIndex].setFillColor(sf::Color::White);
		SelectedOptionIndex--;
		menu[SelectedOptionIndex].setFillColor(sf::Color::Yellow);
	}
}
void Menu::MenuExit()// podsweitlanie "Exit"
{
	if (SelectedOptionIndex == 0)
	{
		menu[SelectedOptionIndex].setFillColor(sf::Color::White);
		SelectedOptionIndex++;
		menu[SelectedOptionIndex].setFillColor(sf::Color::Yellow);
	}
}
int Menu::SelectedIndex()
{
	return SelectedOptionIndex;
}
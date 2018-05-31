#include "Stats.h"

Stats::Stats(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//error---------------------------------
	}
	for (int i = 0; i < NumberOfItem; i++)
	{
		stats[i].setFont(font);
		stats[i].setFillColor(sf::Color::Black);
		stats[i].setPosition(sf::Vector2f(width / 10 * (2 * i + 1), height / 60));
		stats[i].setCharacterSize(24);
		stats[i].setStyle(sf::Text::Bold);
	}
	stats[0].setString("Zloto");
	stats[1].setString("Zycie");
	stats[2].setString("Runda");
	for (int i = 0; i < NumberOfItem; i++)
	{
		stats2[i].setFont(font);
		stats2[i].setFillColor(sf::Color::Black);
		stats2[i].setPosition(sf::Vector2f(stats[i].getPosition().x + 100, stats[i].getPosition().y));
		stats2[i].setCharacterSize(24);
		stats2[i].setStyle(sf::Text::Bold);
	}
	stats2[0].setString("20");
}

Stats::~Stats()
{
}
void Stats::draw(sf::RenderWindow &window)
{
	check();
	for (int i = 0; i < NumberOfItem; i++)
	{
		window.draw(stats[i]);
		window.draw(stats2[i]);
	}
}
void Stats::check()
{
	ss.str("");
	ss << gold1;
	std::string gold = ss.str();
	stats2[0].setString(gold);

	ss.str("");
	ss << baseHealth1;
	std::string hp = ss.str();
	stats2[1].setString(hp);

	ss.str("");
	ss << wave1;
	std::string wave = ss.str();
	stats2[2].setString(wave);
}
void Stats::zycie(int hp)
{
	baseHealth1 = hp;
}
void Stats::waves(int wave)
{
	wave1 = wave;
}
void Stats::gold(int gold) // odjecie pieniedzy za postawienie wiezy
{
	gold1 =  gold1 + gold;
}
void Stats::goldPlus(int gold) // dodanie pieniedzy za zabicie wroga
{
	gold1 = gold1 + gold;
}
int Stats::goldTo() // "kupienie wiezy" przy nacisnieciu 1
{
	return gold1;
}
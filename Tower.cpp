#include "Tower.h"

Tower::Tower(Enemy *pointer2, Bullet *pointer)
{
	tower.setFillColor(sf::Color::Blue);
	tower.setRadius(radiusTower);
	tower.setOutlineThickness(radius);
	tower.setOutlineColor(sf::Color::Transparent);

	range.setRadius(radiusRange);
	range.setFillColor(sf::Color::Transparent);
	range.setOutlineThickness(1);
	range.setOutlineColor(sf::Color::Yellow);

	enemy2 = pointer2;
	bullet = pointer;
}
Tower::~Tower()
{
}
void Tower::draw(sf::RenderWindow &window)
{
	window.draw(tower);
	window.draw(range);
}
void Tower::move(float x, float y)
{
	tower.setPosition(x, y);
	range.setPosition(x - radiusRange + radiusTower, y - radiusRange + radiusTower);
	towerX = x;
	towerY = y;
}
void Tower::stay(float X, float Y)
{
	towers.push_back(tower);
	tower.setPosition(sf::Vector2f(X, Y));
}
void Tower::drawAtPoint(sf::RenderWindow &window)
{
	wektor();
	int counter = 0;
	while (counter < towers.size())
	{
		window.draw(towers[counter]);
		shoot(counter);
		counter++;
	}
}
bool Tower::checkColl(float PosX, float PosY)
{
	int counter = 0;
	while (counter < towers.size())
	{
		if (towers[counter].getPosition().x == PosX  && towers[counter].getPosition().y == PosY)
			rightPlace = false;
		counter++;
	}
	if (rightPlace)
		return true;
	else
	{
		rightPlace = true;
		return false;
	}
}
void Tower::shoot(int j)
{
	int counter2 = 0;
	while (counter2 < enemiesTower.size())
	{
		if (enemiesTower[counter2].getGlobalBounds().intersects(towers[j].getGlobalBounds()))
		{
			if (clock.getElapsedTime().asSeconds() >= 0.5f)
			{
				location = sf::Vector2f(towers[j].getPosition().x + radiusTower, towers[j].getPosition().y + radiusTower);
				enemyPos = sf::Vector2f(enemiesTower[counter2].getPosition().x, enemiesTower[counter2].getPosition().y);

				target = enemyPos - location;
				targetFin = target / sqrt(pow(target.x, 2) + pow(target.y, 2));
				Speed = targetFin * bullet->speed;
				bullet->SpeedTo(Speed, location);
				bullet->setBullet();

				clock.restart();
			}
		}
		counter2++;
	}
}
void Tower::wektor()
{
	enemiesTower = enemy2->wektor();
}
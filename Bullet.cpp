#include "Bullet.h"
Bullet::Bullet(Stats *pointer, Enemy *pointer2)
{
	this->bullet.setRadius(5);
	this->bullet.setFillColor(sf::Color::Black);
	this->speed = 7.f;
	statystyka = pointer;
	enemy2 = pointer2;
}
Bullet::~Bullet()
{
}
void Bullet::drawBullet(sf::RenderWindow &window)
{
	for (int l = 0; l < bullets.size(); l++)
	{
		window.draw(bullets[l]);
	}
}
void Bullet::movementBullet()
{
	for (int l = 0; l < bullets.size(); l++)
	{
		bullets[l].move(Speed);
		if (bullets[l].getPosition().x > 1200 || bullets[l].getPosition().y > 600
			|| bullets[l].getPosition().x < 0 || bullets[l].getPosition().y < 0)
			bullets.erase(bullets.begin() + l);
		else
		{
			wektor();
			wektor2();
			for (int k = 0; k < enemiesBullet.size(); k++)
			{
				if (bullets[l].getGlobalBounds().intersects(enemiesBullet[k].getGlobalBounds()))
				{
					bullets.erase(bullets.begin() + l);
					enemy2->Radius(takeHP, k);
					break;
				}
			}
		}
	}
}
void Bullet::SpeedTo(sf::Vector2f a, sf::Vector2f l)
{
	Speed = a;
	location = l;
}
void Bullet::setBullet()
{
	bullet.setPosition(location);
	bullets.push_back(bullet);
}
void Bullet::wektor()
{
	enemiesBullet = enemy2->wektor();
}
void Bullet::wektor2()
{
	enemiesHPBullet = enemy2->wektor2();
}
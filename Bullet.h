#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <math.h>

#include "Stats.h"
#include "Enemy.h"

class Bullet
{
private:
	Enemy *enemy2;
	Stats *statystyka;

	sf::Clock clock;
	sf::CircleShape bullet;
	std::vector<sf::CircleShape> bullets;
	sf::Vector2f location,Speed; // do obliczania gdzie ma strzelic wieza

	std::vector<Enemy> enemies;
	std::vector<sf::CircleShape> enemiesBullet; // wrogowie
	std::vector<sf::RectangleShape> enemiesHPBullet; // zycie wrogow

	int takeHP = 8;//zabieranie zycia
	int maxHP = 30;
	
public:
	float speed = 7.f; // predkosc pocisku

	Bullet(Stats *pointer, Enemy *pointer2);
	~Bullet();

	void SpeedTo(sf::Vector2f a, sf::Vector2f l);
	void setBullet();
	void drawBullet(sf::RenderWindow &window); // rysowanie pociskow
	void movementBullet(); // poruszanie pociskami
	void wektor();
	void wektor2();
};


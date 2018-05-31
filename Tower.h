#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

class Tower
{
private:
	Bullet *bullet;
	Enemy *enemy2;
	sf::CircleShape range;
	sf::CircleShape tower;

	std::vector<sf::CircleShape> towers;
	std::vector<sf::CircleShape> enemiesTower;
	
	sf::Clock clock;
	sf::Vector2f target, location, targetFin, Speed, enemyPos; // do obliczania gdzie ma strzelic wieza

	float radius = 65; // do rysowania zasiegu
	float radiusTower = 30; // wielkosc wiezy
	float radiusRange = 95; // do interakcji
	float towerX;//polozenie wiezy
	float towerY;

	bool rightPlace = true; // stawianie wiezy we wlasciwym miejscu
public:
	Tower(Enemy *pointer2, Bullet *pointer);
	~Tower();

	void draw(sf::RenderWindow &window); // rysowanie wiezy
	void move(float x, float y); // przemieszczanie wiezy
	void stay(float X, float Y); // zatrzymanie wiezy w danym miejscu
	void drawAtPoint(sf::RenderWindow &window); // rysowanie na stale
	void shoot(int j);
	void wektor();

	bool checkColl(float X, float Y);
};
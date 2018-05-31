#pragma once
#include <SFML\Graphics.hpp>
#include "Map.h"
#include "Stats.h"
#include "End.h"
#include "Enemy.h"
#include "Tower.h"
#include "Bullet.h"

class Game
{
private:
	float towerPosX;
	float towerPosY;
	Enemy *enemy;
	Stats *stat;
	Tower *tower;
	Bullet *bullet;
	End *end;

	int endOfGame;

	bool towerDraw = false; // do stawiania wiezy w danym miejscu
	bool rightPlace; // do stawiania wiezy w prawidlowym miejscu
	float size = 60; // do przesuwania wiezy
	
	sf::Vector2f middle; // do interakcji drogi z wieza
public:
	Game();
	~Game();

	void playGame();
};


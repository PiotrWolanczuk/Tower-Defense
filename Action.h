#pragma once
#include <SFML\Graphics.hpp>

#include "Bullet.h"
#include "End.h"
#include "Enemy.h"
#include "Stats.h"
#include "Tower.h"

#include <vector>
#include <iostream>
#include <math.h>

class Bullet;
class Enemy;
class Tower;

class Action
{
	friend class Stats;
	friend class Game;
private:
	Bullet bullet;
	Enemy enemy2;
	Tower tower;
	Stats *statystyka;
	End *end;

	//sf::Clock clock;

	//std::vector<Tower> towers; // wieze
	//std::vector<Bullet> bullets; // amunicja
	//std::vector<Enemy> enemies; // wrogowie
	
	//sf::Vector2f target, location, targetFin, Speed, enemyPos; // do obliczania gdzie ma strzelic wieza

	// statystyki
	//int baseHP = 10; // zycie bazy
	//int counter;
	//int counter2;
	//int maxSpawn = 5;// do fali
	//int spawnCounter = 0;

	//int takeHP = 15;//zabieranie zycia

	/*bool isWave1 = true; // fale
	bool isWave2 = false;
	bool isWave3 = false;
	bool isWave4 = false;
	bool go = true;
	int whichWave = 2;
	float time = 0.6f;
	float waveTime = 1.0f;*/

	//bool rightPlace = true; // stawianie wiezy we wlasciwym miejscu
public:
	Action(Stats *pointer);
	~Action();

	/*void draw(sf::RenderWindow &window); // rysowanie wiezy
	void move(float x, float y); // przemieszczanie wiezy
	void stay(float X, float Y); // zatrzymanie wiezy w danym miejscu
	void drawAtPoint(sf::RenderWindow &window); // rysowanie na stale
	bool checkColl(float X, float Y);*/

	//strzelanie
	/*void shoot(int j);
	void drawBullet(sf::RenderWindow &window); // rysowanie pociskow
	void movementBullet(); // poruszanie pociskami*/

	//wrogowie
	/*void drawEnemy(sf::RenderWindow &window); // rysowanie wrogow
	void wave();// ustalenie ile jest przeciwnikow w fali
	void movement(); // poruszanie przeciwnikow

	void check(); // sprawdzanie czy przeciwnik doszedl do bazy*/
	//int endOfGame(); // zakonczenie gry
};

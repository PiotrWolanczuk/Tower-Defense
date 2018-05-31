#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

#include "Stats.h"
class Enemy
{
	friend class Bullet;
private:
	Stats *statystyka;

	sf::CircleShape enemy2;
	sf::RectangleShape healthBar;
	sf::Clock clock;

	std::vector<sf::CircleShape> enemies; // wrogowie
	std::vector<sf::RectangleShape> enemiesHP; // zycie

	int maxhp = 30; // zycie przeciwnika
	int maxSpawn = 5;// do fali
	int spawnCounter = 0;
	int baseHP = 10; // zycie bazy
	int counter;
	int counter2;
	int max = 0;
	int radius = 15;
	int hp;

	float enemyXPos; // do pozycji
	float enemyYPos;
	float speed; // predkosc

	bool isWave1 = true; // fale
	bool isWave2 = false;
	bool isWave3 = false;
	bool isWave4 = false;
	bool go = true;
	int whichWave = 2; // do wpisywania ktora fala
	float time = 1.5f; // do czasu dla pierwszej fali
	float waveTime = 15.0f; // do czasu pomiedzy falami
public:
	Enemy(Stats *pointer);
	~Enemy();

	void drawEnemy(sf::RenderWindow &window); // rysowanie wrogow
	void wave();// ustalenie ile jest przeciwnikow w fali
	void movement(); // poruszanie przeciwnikow

	void check(); // sprawdzanie czy przeciwnik doszedl do bazy
	std::vector<sf::CircleShape> wektor();
	std::vector<sf::RectangleShape> wektor2();
	void Radius(int i, int k);
	int endOfGame(); // zakonczenie gry
};


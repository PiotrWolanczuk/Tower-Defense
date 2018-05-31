#include "Enemy.h"

Enemy::Enemy(Stats *pointer)
{
	enemy2.setRadius(radius);
	enemy2.setFillColor(sf::Color::Red);
	enemyXPos = 0;
	enemyYPos = 135;
	speed = 1.f;
	enemy2.setPosition(enemyXPos, enemyYPos);

	statystyka = pointer;

	healthBar.setFillColor(sf::Color::Green);
	healthBar.setSize(sf::Vector2f(maxhp, 3));
	healthBar.setPosition(enemyXPos, enemyYPos - 2);
}

Enemy::~Enemy()
{
}
void Enemy::wave()
{
	if (isWave1)
	{
		if (clock.getElapsedTime().asSeconds() >= time)
		{
			clock.restart();
			if (spawnCounter < maxSpawn)
			{
				enemies.push_back(enemy2);
				enemiesHP.push_back(healthBar);
				spawnCounter++;
			}
			if (spawnCounter == maxSpawn)
			{
				isWave1 = false;
				isWave2 = true;
				maxSpawn = 2 * spawnCounter;
				spawnCounter = 0;
			}
		}
	}
	else if (isWave2)
	{
		if (go)
		{
			if ((clock.getElapsedTime().asSeconds() >= waveTime))
			{
				clock.restart();
				go = false;
				statystyka->waves(whichWave);
			}
		}
		else if (clock.getElapsedTime().asSeconds() >= time)
		{
			clock.restart();
			if (spawnCounter < maxSpawn)
			{
				enemies.push_back(enemy2);
				enemiesHP.push_back(healthBar);
				spawnCounter++;
			}
			if (spawnCounter == maxSpawn)
			{
				isWave2 = false;
				isWave3 = true;
				go = true;
				maxSpawn = 2 * spawnCounter;
				spawnCounter = 0;
				whichWave++;
			}
		}
	}
	else if (isWave3)
	{
		if (go)
		{
			if ((clock.getElapsedTime().asSeconds() >= waveTime))
			{
				clock.restart();
				go = false;
				statystyka->waves(whichWave);
			}
		}
		else if (clock.getElapsedTime().asSeconds() >= time)
		{
			clock.restart();
			if (spawnCounter < maxSpawn)
			{
				enemies.push_back(enemy2);
				enemiesHP.push_back(healthBar);
				spawnCounter++;
			}
			if (spawnCounter == maxSpawn)
			{
				isWave3 = false;
				isWave4 = true;
				go = true;
				maxSpawn = 1.5*spawnCounter;
				spawnCounter = 0;
				whichWave++;
			}
		}
	}
	else  if (isWave4)
	{
		if (go)
		{
			if ((clock.getElapsedTime().asSeconds() >= waveTime))
			{
				clock.restart();
				go = false;
				statystyka->waves(whichWave);
			}
		}
		else if (clock.getElapsedTime().asSeconds() >= time)
		{
			clock.restart();
			if (spawnCounter < maxSpawn)
			{
				enemies.push_back(enemy2);
				enemiesHP.push_back(healthBar);
				spawnCounter++;
			}
			if (spawnCounter == maxSpawn)
			{
				isWave4 = false;
				spawnCounter = 0;
				whichWave++;
			}
		}
	}
}
void Enemy::drawEnemy(sf::RenderWindow &window)
{
	counter = 0;
	while (counter < enemies.size())
	{
		window.draw(enemies[counter]);
		window.draw(enemiesHP[counter]);
		counter++;
	}
}
void Enemy::movement()
{
	check();
	int counter = 0;
	while (counter < enemies.size())
	{
		if ((enemies[counter].getPosition().x <= 1115) && (enemies[counter].getPosition().y <= 135)) // 1
		{
			enemies[counter].move(speed, 0);
			enemiesHP[counter].move(speed, 0);
		}
		else if ((enemies[counter].getPosition().x >= 1115) && (enemies[counter].getPosition().y <= 255)) // 2
		{
			enemies[counter].move(0, speed);
			enemiesHP[counter].move(0, speed);
		}
		else if ((enemies[counter].getPosition().x >= 75) && (enemies[counter].getPosition().y >= 255) && (enemies[counter].getPosition().y <= 260)) // 3
		{
			enemies[counter].move(-speed, 0);
			enemiesHP[counter].move(-speed, 0);
		}
		else if ((enemies[counter].getPosition().x <= 75) && (enemies[counter].getPosition().y <= 375)) // 4
		{
			enemies[counter].move(0, speed);
			enemiesHP[counter].move(0, speed);
		}
		else if ((enemies[counter].getPosition().x <= 1115) && (enemies[counter].getPosition().y <= 475.2) && (enemies[counter].getPosition().y >= 375)) //  5
		{
			enemies[counter].move(speed, 0);
			enemiesHP[counter].move(speed, 0);
		}
		else if ((enemies[counter].getPosition().x >= 1115) && (enemies[counter].getPosition().y <= 495))// 6 
		{
			enemies[counter].move(0, speed);
			enemiesHP[counter].move(0, speed);
		}
		else if ((enemies[counter].getPosition().x >= 75) && (enemies[counter].getPosition().y >= 495)) // 7
		{
			enemies[counter].move(-speed, 0);
			enemiesHP[counter].move(-speed, 0);
		}
		else if ((enemies[counter].getPosition().x <= 75) && (enemies[counter].getPosition().y <= 645) && (enemies[counter].getPosition().y >= 495)) // "baza"
		{
			enemies[counter].move(0, speed);
			enemiesHP[counter].move(0, speed);
		}
		counter++;
	}
}
void Enemy::check()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getPosition().y >= 600)
		{
			if (baseHP > 0)
				baseHP--;
			else
				baseHP = 0;
			enemies.erase(enemies.begin() + i);
			enemiesHP.erase(enemiesHP.begin() + i);
		}
	}
	statystyka->zycie(baseHP);
}
int Enemy::endOfGame()
{
	if (baseHP == 0)
		return 1;
	else if (isWave1 == false && isWave2 == false && isWave3 == false && isWave4 == false && enemies.size() == 0)
		return 2;
	else
		return 3;
}
std::vector<sf::CircleShape> Enemy::wektor()
{
	return enemies;
}
std::vector<sf::RectangleShape> Enemy::wektor2()
{
	return enemiesHP;
}
void Enemy::Radius(int i, int k)
{
	hp = enemiesHP[k].getSize().x;
	enemiesHP[k].setSize(sf::Vector2f(hp - i, 3));
	if (hp - i <= 0)
	{
		enemies.erase(enemies.begin() + k);
		enemiesHP.erase(enemiesHP.begin() + k);
		statystyka->goldPlus(4);
	}
}
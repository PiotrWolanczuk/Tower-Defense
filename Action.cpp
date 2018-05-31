#include "Action.h"

/*Action::Action(Stats *pointer)
{
	statystyka = pointer;
}*/

Action::~Action()
{
}/*
void Action::draw(sf::RenderWindow &window)
{
	window.draw(tower.tower);
	window.draw(tower.range);
}
void Action::move(float x, float y)
{
	tower.tower.setPosition(x, y);
	tower.range.setPosition(x - tower.radiusRange + tower.radiusTower, y -tower.radiusRange + tower.radiusTower);
	tower.towerX = x;
	tower.towerY = y;
}
void Action::stay(float X, float Y)
{
	towers.push_back(Tower(tower));
	tower.tower.setPosition(sf::Vector2f(X, Y));
}
void Action::drawAtPoint(sf::RenderWindow &window)
{
	int counter = 0;
	while (counter < towers.size())
	{	
		window.draw(towers[counter].tower);
		shoot(counter);
		counter++;
	}
}
bool Action::checkColl(float PosX, float PosY)
{
	int counter = 0;
	while (counter < towers.size())
	{
		if (towers[counter].tower.getPosition().x == PosX  && towers[counter].tower.getPosition().y == PosY)
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
void Action::drawBullet(sf::RenderWindow &window)
{
	for (int l = 0; l < bullets.size(); l++)
	{
		window.draw(bullets[l].bullet);
	}
}
void Action::movementBullet() // ruch i sprawdzanie kolizji
{
	for (int l = 0; l < bullets.size(); l++)
	{
		bullets[l].bullet.move(Speed);
		if (bullets[l].bullet.getPosition().x > 1200 || bullets[l].bullet.getPosition().y > 600
			|| bullets[l].bullet.getPosition().x < 0 || bullets[l].bullet.getPosition().y < 0)
			bullets.erase(bullets.begin() + l);
		else
		{
			for (int k = 0; k < enemies.size(); k++)
			{
				if (bullets[l].bullet.getGlobalBounds().intersects(enemies[k].enemy2.getGlobalBounds()))
				{
					bullets.erase(bullets.begin() + l);
					enemies[k].hp = enemies[k].hp - takeHP;
					enemies[k].healthBar.setSize(sf::Vector2f(enemies[k].hp, 3));
					if (enemies[k].hp == 0)
					{
						enemies.erase(enemies.begin() + k);
						statystyka->goldPlus(4);
					}
					break;
				}
			}
		}
	}
}
void Action::shoot(int j)
{
	int counter2 = 0;
	while (counter2 < enemies.size())
	{
		if (enemies[counter2].enemy2.getGlobalBounds().intersects(towers[j].tower.getGlobalBounds()))
		{
			if (clock.getElapsedTime().asSeconds() >= 0.5f)
			{
				location = sf::Vector2f(towers[j].tower.getPosition().x + tower.radiusTower, towers[j].tower.getPosition().y + tower.radiusTower);
				enemyPos = sf::Vector2f(enemies[counter2].enemy2.getPosition().x, enemies[counter2].enemy2.getPosition().y);

				target = enemyPos - location;
				targetFin = target / sqrt(pow(target.x, 2) + pow(target.y, 2));
				Speed = targetFin * bullet.speed;
				bullet.bullet.setPosition(location);

				bullets.push_back(Bullet(bullet));
				clock.restart();
			}
		}
		counter2++;
	}
}
// wrogowie

void Action::wave()
{
	if (isWave1)
	{
		if (clock.getElapsedTime().asSeconds() >= time)
		{
			clock.restart();
			if (spawnCounter < maxSpawn)
			{
				enemies.push_back(Enemy(enemy2));
				spawnCounter++;
				std::cout << spawnCounter << std::endl;
			}
			if (spawnCounter == maxSpawn)
			{
				std::cout << " Koniec Fala 1" << std::endl;
				isWave1 = false;
				isWave2 = true;
				maxSpawn = 2*spawnCounter;
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
				enemies.push_back(Enemy(enemy2));
				spawnCounter++;
				std::cout << spawnCounter << std::endl;
			}
			if (spawnCounter == maxSpawn)
			{
				std::cout << " Koniec Fala 2" << std::endl;
				isWave2 = false;
				isWave3 = true;
				go = true;
				maxSpawn = 2* spawnCounter;
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
				enemies.push_back(Enemy(enemy2));
				spawnCounter++;
				std::cout << spawnCounter << std::endl;
			}
			if (spawnCounter == maxSpawn)
			{
				std::cout << "Koniec Fala 3" << std::endl;
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
				enemies.push_back(Enemy(enemy2));
				spawnCounter++;
				std::cout << spawnCounter << std::endl;
			}
			if (spawnCounter == maxSpawn)
			{
				std::cout << "Koniec Fala 4" << std::endl;
				isWave4 = false;
				spawnCounter = 0;
				whichWave++;
			}
		}
	}
}
void Action::drawEnemy(sf::RenderWindow &window)
{
	counter = 0;
	while (counter < enemies.size())
	{
		window.draw(enemies[counter].enemy2);
		window.draw(enemies[counter].healthBar);
		counter++;
	}
}
void Action::movement()
{
	check();
	int counter = 0;
	while (counter < enemies.size())
	{
		if ((enemies[counter].enemy2.getPosition().x <= 1115) && (enemies[counter].enemy2.getPosition().y <= 135)) // 1
		{
			enemies[counter].enemy2.move(enemy2.speed, 0);
			enemies[counter].healthBar.move(enemy2.speed, 0);
		}
		else if ((enemies[counter].enemy2.getPosition().x >= 1115) && (enemies[counter].enemy2.getPosition().y <= 255)) // 2
		{
			enemies[counter].enemy2.move(0, enemy2.speed);
			enemies[counter].healthBar.move(0, enemy2.speed);
		}
		else if ((enemies[counter].enemy2.getPosition().x >= 75) && (enemies[counter].enemy2.getPosition().y >= 255) && (enemies[counter].enemy2.getPosition().y <= 260)) // 3
		{
			enemies[counter].enemy2.move(-enemy2.speed, 0);
			enemies[counter].healthBar.move(-enemy2.speed, 0);
		}
		else if ((enemies[counter].enemy2.getPosition().x <= 75) && (enemies[counter].enemy2.getPosition().y <= 375)) // 4
		{
			enemies[counter].enemy2.move(0, enemy2.speed);
			enemies[counter].healthBar.move(0, enemy2.speed);
		}
		else if ((enemies[counter].enemy2.getPosition().x <= 1115) && (enemies[counter].enemy2.getPosition().y <= 475.2) && (enemies[counter].enemy2.getPosition().y >= 375)) //  5
		{
			enemies[counter].enemy2.move(enemy2.speed, 0);
			enemies[counter].healthBar.move(enemy2.speed, 0);
		}
		else if ((enemies[counter].enemy2.getPosition().x >= 1115) && (enemies[counter].enemy2.getPosition().y <= 495))// 6 
		{
			enemies[counter].enemy2.move(0, enemy2.speed);
			enemies[counter].healthBar.move(0, enemy2.speed);
		}
		else if ((enemies[counter].enemy2.getPosition().x >= 75) && (enemies[counter].enemy2.getPosition().y >= 495)) // 7
		{
			enemies[counter].enemy2.move(-enemy2.speed, 0);
			enemies[counter].healthBar.move(-enemy2.speed, 0);
		}
		else if ((enemies[counter].enemy2.getPosition().x <= 75) && (enemies[counter].enemy2.getPosition().y <= 645) && (enemies[counter].enemy2.getPosition().y >= 495)) // "baza"
		{
			enemies[counter].enemy2.move(0, enemy2.speed);
			enemies[counter].healthBar.move(0, enemy2.speed);
		}
		counter++;
	}
}
void Action::check()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].enemy2.getPosition().y >= 600)
		{
			if (baseHP > 0)
			{
				baseHP--;
			}
			else
				baseHP = 0;
			enemies.erase(enemies.begin() + i);
		}
	}
	statystyka->zycie(baseHP);
}
int Action::endOfGame()
{
	if (baseHP == 0)
		return 1;
	else if (isWave1 == false && isWave2 == false && isWave3 == false && isWave4 == false && enemies.size() == 0)
		return 2;
	else
		return 3;
}*/

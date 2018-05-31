#include "Game.h"

Game::Game()
{
	stat = new Stats(1200, 660);
	enemy = new Enemy(stat);
	bullet = new Bullet(stat, enemy);
	tower = new Tower(enemy, bullet);
	end = new End();
}
Game::~Game()
{
}

void Game::playGame()
{
	sf::RenderWindow okno(sf::VideoMode(1200, 660), "Tower Defense"); // okno gry	
	okno.setFramerateLimit(100);
	Map map(okno.getSize().x, okno.getSize().y);

	sf::Event wydarzenieGry;
	sf::Clock clock;

	while (okno.isOpen())// glowna petla gry
	{
		while (okno.pollEvent(wydarzenieGry))
		{
			if (sf::Event::KeyPressed && wydarzenieGry.key.code == sf::Keyboard::Num1 && stat->goldTo() >= 5)// wstawianie wiezy
			{
				towerDraw = true;
				towerPosX = 60;
				towerPosY = 60;
				tower->move(towerPosX, towerPosY);
			}
			switch (wydarzenieGry.type)
			{
			case sf::Event::Closed:
			{
				okno.close();
			}break;

			case sf::Event::KeyPressed:
				switch (wydarzenieGry.key.code)
				{
				case sf::Keyboard::Escape:
				{
					okno.close();
				}break;
				case sf::Keyboard::Up: // poruszanie wieza
				{
					towerPosY = (towerPosY - size >= 60) ? towerPosY - size : towerPosY;
					tower->move(towerPosX, towerPosY);
				}break;
				case sf::Keyboard::Down:
				{
					towerPosY = (towerPosY + size < 660) ? towerPosY + size : towerPosY;
					tower->move(towerPosX, towerPosY);
				}break;
				case sf::Keyboard::Left:
				{
					towerPosX = (towerPosX - size >= 0) ? towerPosX - size : towerPosX;
					tower->move(towerPosX, towerPosY);
				}break;
				case sf::Keyboard::Right:
				{
					towerPosX = (towerPosX + size < 1160) ? towerPosX + size : towerPosX;
					tower->move(towerPosX, towerPosY);
				}break;
				case sf::Keyboard::RControl:// stawanie wiezy
				{
					if (towerPosY >= 60)
					{
						if (towerPosY == 60
							|| (towerPosY == 180 && towerPosX < 1040)
							|| (towerPosX == 0 && towerPosY >= 240)
							|| (towerPosX >= 120 && towerPosY == 300)
							|| (towerPosX >= 60 && towerPosX < 1040 && towerPosY == 420)
							|| (towerPosX >= 120 && towerPosY == 540))
						{
							rightPlace = tower->checkColl(towerPosX, towerPosY);
							if (rightPlace)
							{
								tower->stay(towerPosX, towerPosY);
								stat->gold(-5);// ile kosztuje wieza
								towerDraw = false;
								rightPlace = false;
							}
						}
					}
				}break;

				}break;
			}
		}	

		//rysowanie
		okno.clear(sf::Color::White);
		map.draw(okno);
		stat->draw(okno);

		//akcja
		tower->drawAtPoint(okno);
		enemy->wave();
		enemy->drawEnemy(okno);
		bullet->movementBullet();
		bullet->drawBullet(okno);
		
		if (towerDraw)// rysowanie wiezy po nacisnieciu 1
			tower->draw(okno);

		enemy->check();
		// sprawdzanie warunkow zakonczenia gry
		endOfGame = enemy->endOfGame();
		if (endOfGame == 1)
		{
			end->loose();
			okno.close();
		}
		else if (endOfGame == 2)
		{
			end->win();
			okno.close();		
		}

		okno.display();

		//poruszanie
		enemy->movement();
	}
}

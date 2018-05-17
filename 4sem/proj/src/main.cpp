#include "player.h"
#include "Entity.h"
#include "map.h"
#include <SFML/Graphics.hpp>
#include "view.h"
#include <iostream>
#include "menu.h"
#include <cstdio>
#include "bullet.h"
#include <vector>

#define EXIT 0
#define RESTART 1
#define START 2
#define BULLETS_AMOUNT 5
#define START_X 150
#define START_Y 250

const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 

using namespace sf;

int StartGame(int Mode, RenderWindow& window)
{
	Image playerImage;
	playerImage.loadFromFile("images/tank1.png");

	Image bulletImage;
	bulletImage.loadFromFile("images/bullet.png");

//////////////////////////////ПЕРЕПИЛИТЬ////////////////////////////////////////////////////
	String mapPlan[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s                                  0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                0                     0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};
////////////////////////////////////////////////////////////////////////////////////////////

	view.reset(FloatRect(0, 0, 640, 480));
	
	if(Mode == START)
		switch(menu(window, view))
		{
			case 0: 
				/* СИСТЕМА СОХРАНЕНИЙ*/ break;					//ДОПИЛИТЬ
			case 1: 
				window.close(); return EXIT; break;
			case 2: 
				break;
			default: 
				break;
		}

	map mapa("map.png", mapPlan);

	Player test(playerImage, playerImage, START_X, START_Y, 66, 72, "Player1", "Cannon1");

	Clock clock;

	std::vector<Bullet> bullets;
	for (int i = 0; i < BULLETS_AMOUNT; i++) {
		bullets.push_back(Bullet(bulletImage, START_X, START_Y));
	} 

	int bulletsActive = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Event event;
		while (window.pollEvent(event))
		{
			if(event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; }
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			switch (menu(window, view))
			{
				case 1: 
					window.close(); return EXIT; break;
				case 2: 
					return RESTART; 
					break;
				default: 
					break;
			}
		}
	

		window.clear(Color::Red);
		
		

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		Vector2f direction = Vector2f(mousePosition.x, mousePosition.y) - Vector2f(test.get_x(), test.get_y());

		/*if (Mouse::isButtonPressed(Mouse::Left)) {
			if (bulletsActive < bullets.size()) {
				bullets[bulletsActive].activate();
				bullets[bulletsActive].setTimer(time);
				bullets[bulletsActive].setPosition (test.get_x(), test.get_y());
				bullets[bulletsActive].setDirection (direction);
			}
		}
		for (auto& it : bullets) {
			if (it.isActive()) {
				it.update(time, mapa);
				it.draw(window);
			}
		}*/

		mapa.print(window); 
		test.draw(window);

		window.display();

		test.update(time, mapa, window);

		view = get_xy_for_view(test.get_x(), test.get_y());
		window.setView(view);
	}
	return 0;
}

void GameRunning (int Mode, RenderWindow& window)
{
	switch(int newMode = StartGame(Mode, window))
	{
		case EXIT: 
			break;
		case RESTART: 
			GameRunning(newMode, window); break;
		case START: 
			GameRunning(newMode, window); break;
		default: 
			break;
	}
}

int main()
{
	RenderWindow window(VideoMode(800, 640), "My_First_Game(DONT_JUDGE_SEVERELY)", Style::Fullscreen);
	GameRunning(START, window);
	return 0;
}

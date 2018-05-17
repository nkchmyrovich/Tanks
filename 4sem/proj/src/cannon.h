#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "map.h"

using namespace sf;

class Cannon :public Entity
{
protected:
	int FireRate;
	void interactionWithMap(map& mapa);
	void Rotation(RenderWindow& window);
public:
	Cannon(Image &image, float X, float Y,int W,int H,String Name);

	void update(float time, map& mapa);
	void update(float x, float y, bool isAlive, RenderWindow& window);
	void Shooting();
	//void change_FireRate(int frnew);

};

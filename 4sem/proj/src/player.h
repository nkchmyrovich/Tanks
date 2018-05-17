#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "cannon.h"

using namespace sf;

class Player :public Entity
{
protected:
	enum { left, right, up, down, leftUp, rightUp, leftDown, rightDown, stay } state;
	bool isCannon;

	void control();
	void interactionWithMap(map& mapa);
	Cannon cannon;

public:
	Player(Image &bodyImage, Image &cannonImage, float X, float Y,int W,int H,String PlayerName, String CannonName);

	void draw(RenderWindow& window);
	void update(float time, map& mapa, RenderWindow& window);
};

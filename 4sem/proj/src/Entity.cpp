#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>

using namespace sf;





Entity::Entity(Image &image, float X, float Y, int W, int H, String Name) :
	x (X),
	y (Y),
	w (W),
	h (H),
	name (Name),
	moveTimer (0),
	speed (0),
	health (START_HEALTH),
	isAlive (true),
	isMove (false)
{
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
}

void Entity::draw(RenderWindow& window)
{
	window.draw(sprite);
}

float Entity::get_x()
{
	return x;
}

float Entity::get_y()
{
	return y;
}

void Entity::change_x(float xnew)
{
	x = xnew;
}

void Entity::change_y(float ynew)
{
	y = ynew;
}
	
float Entity::get_dx()
{
	return dx;
}

float Entity::get_dy()
{
	return dy;
} 

float Entity::get_h()
{
	return h;
}

float Entity::get_w()
{
	return w;
} 


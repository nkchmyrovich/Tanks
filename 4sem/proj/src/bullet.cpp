#include "bullet.h"
#include <cmath>

const String bulletString = "BULLET";

Bullet::Bullet (Image &image, float X, float Y) :
	Entity (image, X, Y, WIDTH, LENGTH, bulletString)
	{}

Bullet::~Bullet () {}

void Bullet::update (float time, map& mapa) {
	Vector2f velocity = (float)SPEED * direction / sqrt(direction.x * direction.x + direction.y * direction.y);
	x += velocity.x * (time - moveTimer);
	y += velocity.y * (time - moveTimer);
	sprite.setPosition(x, y);
}

void Bullet::interactionWithMap (map& mapa) {
	for (int i = y / 32; i < (y + h) / 32; i++)
	for (int j = x / 32; j < (x + w) / 32; j++)
	{
		if (mapa.get_ij(i, j) == '0')
		{
			isAlive = false;
			isMove = false;
		}
	}
}

void Bullet::setDirection (Vector2f& direction_) {
	direction = direction_;
}

void Bullet::activate () {
	isAlive = true;
	isMove = true;
}

bool Bullet::isActive () {
	return isAlive;
}

void Bullet::setTimer (float time_) {
	moveTimer = time_;
}

void Bullet::setPosition (float x_, float y_) {
	x = x_;
	y = y_;
	sprite.setPosition(x, y);
}
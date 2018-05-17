#include <hero.h>

hero::hero(float x, float y, sf::Texture es_texture, int health):
	x(x),
	y(y),
	health(health)
{
	look.setTexture(es_texture);
	look_setPosition(x, y);
}

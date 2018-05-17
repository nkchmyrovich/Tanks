#pragma once
#include <SFML\Graphics.hpp>

class hero : public essence
{
protected:
	int health;	

public:
	hero(float x, float y, sf::Sprite look, int health);

	void move(sf::Time time);
	bool in_border(const sf::Window& window) const;
}

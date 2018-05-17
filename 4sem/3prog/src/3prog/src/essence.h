#pragma once
#include <Graphics.hpp>
#include <map.h>

using namespace sf;

class essence
{
protected:
	float x, m, y, xo, yo, w, h, dm, dy, speed;//координаты, размеры, ускорения, скорость
	int dir;//напрвление движения
	String File;//файл с расширением
	Image image;
	Texture texture;
	Sprite look;
public:
	essence();
	essence(float M, float Y, float Xo, float Yo, float W, float H, String F);

	void move(float time);
	void draw(RenderWindow& window);

	float get_x();
	float get_y();
	void change_x(float xnew);
	void change_y(float ynew);
	
	float get_dm();
	float get_dy(); 

	float get_h();
	float get_w();

	//void update(float time);
	
	void interactionWithMap(map& mapa);

};

#include <essence.h>
#include <Graphics.hpp>
#include <iostream>

using namespace sf;

essence::essence():
	x(0),
	y(0),
	xo(0),
	yo(0),
	w(0),
	h(0),
	File("")
{
	image.loadFromFile("images/sprite.png");
	image.createMaskFromColor(Color(0, 0, 0));

	texture.loadFromImage(image);

	look.setTexture(texture);
	look.setTextureRect(IntRect(xo,yo,w,h));
	look.setPosition(x, y);

	dir = 0;
	speed = 0;
}
	

essence::essence(float M, float Y, float Xo, float Yo, float W, float H, String F):
	x(M),
	y(Y),
	xo(Xo),
	yo(Yo),
	w(W),
	h(H),
	File(F)
{
	speed = 0.1;
	image.loadFromFile("images/" + File);
		//std::cout << "Image created" << "\n";
	image.createMaskFromColor(Color(0, 0, 0));

	texture.loadFromImage(image);
		//std::cout << "Texture created" << "\n";

	look.setTexture(texture);
	look.setTextureRect(IntRect(xo,yo,w,h));
	look.setPosition(x, y);

	dir = 0;
	speed = 0;
}

void essence::draw(RenderWindow& window)
{
	window.draw(look);
}

void essence::move(float time)
{
	if(Keyboard::isKeyPressed(Keyboard::Left)) { dir = 1; speed = 0.1; look.setTextureRect(IntRect(27, 216, 138, 132)); }
	if(Keyboard::isKeyPressed(Keyboard::Right)) { dir = 0; speed = 0.1; look.setTextureRect(IntRect(237, 27, 138, 129)); }
	if(Keyboard::isKeyPressed(Keyboard::Up)) { dir = 3; speed = 0.1; look.setTextureRect(IntRect(51, 21, 132, 138)); }
	if(Keyboard::isKeyPressed(Keyboard::Down)) { dir = 2; speed = 0.1; look.setTextureRect(IntRect(234, 216, 132, 138)); }

	//std::cout << speed << " " << dir << " " << time << "\n";

	switch(dir)
	{
	case 0: dm = speed; dy = 0; break;
	case 1: dm = -speed; dy = 0; break;
	case 2: dm = 0; dy = speed; break;
	case 3: dm = 0; dy = -speed; break;
	}

	x += dm * time;
	y += dy * time;

	speed = 0;
	
	look.setPosition(x, y);
}

/*void essence::update(float time)
{
	switch(dir)
	{
	case 0: dm = speed; dy = 0; break;
	case 1: dm = -speed; dy = 0; break;
	case 2: dm = 0; dy = speed; break;
	case 3: dm = 0; dy = -speed; break;
	}

	x += dm * time;
	y += dy * time;

	speed = 0;
	
	look.setPosition(x, y);
} */	

float essence::get_x()
{
	return x;
}

float essence::get_y()
{
	return y;
}

void essence::change_x(float xnew)
{
	x = xnew;
}

void essence::change_y(float ynew)
{
	y = ynew;
}
	
float essence::get_dm()
{
	return dm;
}

float essence::get_dy()
{
	return dy;
} 

float essence::get_h()
{
	return h;
}

float essence::get_w()
{
	return w;
} 
void essence::interactionWithMap(map& mapa)//ф-ция взаимодействия с картой
{
 
	for (int i = y / 32; i < (y + h) / 32; i++)
	for (int j = x / 32; j<(x + w) / 32; j++)
	{
		if (mapa.get_ij(i, j) == '0')
		{
			if (dy>0)
			{
				y = i * 32 - h;
			}
			if (dy<0)
			{
				y = i * 32 + 32;
			}
			if (dm>0)
			{
				x = j * 32 - w;
			}
			if (dm < 0)
			{
				x = j * 32 + 32;
			}
		}
 
		if (mapa.get_ij(i, j) == 's') 
		{ 
			x = 300; y = 300;
			mapa.change_ij(i, j, ' ');
		}
	}
}














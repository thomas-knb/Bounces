#include "shape.h"


void Shape::update(float dx = 0, float dy = 1 ,float dt = 0.01)
{    
	_vx += dx;
	_vy += dy;
	_x += _vx * dt;
	_y += _vy * dt;
}

void Shape::update(bool move)
{
	if (move) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			update(-1,1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			update(1,1);
	}
	else
		update(0,1);
}


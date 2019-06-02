#include "simu.h"


Simu::Simu()
{
	_nbShapes = 1;
	_shapes = new Shape*[10];
	_shapes[0] = new Ball(150, 250, 15, 0, 0);
}

Simu::Simu(int type, float x, float y, float radius, float vx, float vy)
{
	_nbShapes = 1;
	_shapes = new Shape*[10];
	if (type == 1)
		_shapes[0] = new Ball(x, y, radius, vx, vy);
	else if (type == 2)
		_shapes[0] = new Cube(x, y, radius, vx, vy);
}

Simu& Simu::operator+=(const Shape& shape)
{
	if (shape.getType() == 1)
		this->_shapes[_nbShapes] = new Ball(shape.getPositionX(), shape.getPositionY(), shape.getRadius(), shape.getSpeedX(), shape.getSpeedY());
	else if (shape.getType() == 2)
		this->_shapes[_nbShapes] = new Cube(shape.getPositionX(), shape.getPositionY(), shape.getRadius(), shape.getSpeedX(), shape.getSpeedY());
	this->_nbShapes++;
	return *this;
}


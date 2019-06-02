#ifndef WALL_HH_
#define WALL_HH_

#include "screen.h"
#include "shape.h"


class Wall
{
	public:
		Wall():_x(0), _y(490), _w(500), _h(10){}
		Wall(float x, float y, float w, float h):_x(x), _y(y), _w(w), _h(h){}
		void draw(Screen& s){s.rect(_x, _y, _w, _h, 0x0000FFFF);}
		void computeSpeed(Shape& shape);
	protected:
		float _x, _y, _w, _h;

};

#endif


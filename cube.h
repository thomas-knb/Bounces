#ifndef CUBE_H_
#define CUBE_H_

#include "shape.h"


class Cube: public Shape
{
	public:
		Cube():Shape(0, 0, 0, 0, 0){};
		Cube(float x, float y, float radius, float vx, float vy):Shape(x, y, radius, vx, vy){};
		void draw(Screen& s){s.rect(_x-_radius, _y-_radius, 2*_radius, 2*_radius, 0xAAAAAAFF);}

};

#endif


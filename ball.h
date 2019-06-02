#ifndef BALL_H_
#define BALL_H_

#include "shape.h"


class Ball: public Shape
{
	public:
		Ball():Shape(0, 0, 0, 0, 0){};
		Ball(float x, float y, float radius, float vx, float vy):Shape(x, y, radius, vx, vy){};
		void draw(Screen& s){s.disc(_x, _y, _radius, 0xFFFFFFFF);}

};

#endif


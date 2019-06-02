#ifndef BALL_H_
#define BALL_H_

#include "shape.h"


class Ball: public Shape
{
	public:
		Ball():Shape(150, 250, 15, 0, 0, 1){};
		Ball(float x, float y, float radius, float vx, float vy):Shape(x, y, radius, vx, vy, 1){};
		void draw(Screen& s){s.disc(_x, _y, _radius, 0xFFFFFFFF);}

};

#endif


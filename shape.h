#ifndef SHAPE_H_
#define SHAPE_H_

#include "screen.h"


class Shape
{
	public:
		Shape():_x(0), _y(0), _radius(0), _vx(0), _vy(0){};
		Shape(float x, float y, float radius, float vx, float vy):_x(x), _y(y), _radius(radius), _vx(vx), _vy(vy){};
		virtual void draw(Screen& s){s.disc(_x, _y, _radius, 0xFFFFFFFF);}
		void setSpeed(float vx, float vy){ _vx = vx; _vy = vy;}
		float getSpeedX() const {return _vx;}
		float getSpeedY() const {return _vy;}
		void setPosition(float x, float y){ _x = x; _y = y;}
		float getPositionX() const {return _x;}
		float getPositionY() const {return _y;}
		float getRadius() const {return _radius;}
		void update(float dx, float dy, float dt);
		void update(bool move);
	protected:
		float _x, _y;
		float _radius;
		float _vx, _vy;

};

#endif


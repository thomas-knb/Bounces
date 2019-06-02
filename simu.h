#ifndef SIMU_H_
#define SIMU_H_

#include "shape.h"
#include "ball.h"
#include "cube.h"


class Simu
{
	public:
		Simu();
		Simu(int type, float x, float y, float radius, float vx, float vy); // type = 1 -> Ball, type = 2 -> Cube
		Simu& operator+=(const Shape& shape);
		int getNbShapes() const {return _nbShapes;}
		Shape ** getShapes() const {return _shapes;}
	protected:
		int _nbShapes;
		Shape ** _shapes;

};

#endif


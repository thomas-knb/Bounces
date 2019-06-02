#include "wall.h"


void Wall::computeSpeed(Shape& shape)
{
	static const float dampingNorm = 0.85;
	static const float dampingDir = 0.95;
	
	float vx = shape.getSpeedX();
	float vy = shape.getSpeedY();
	float x  = shape.getPositionX();
	float y  = shape.getPositionY();
	float radius = shape.getRadius();
	float dx1 = (x - radius) - (_x + _w); // distance entre la gauche de la balle et la droite du mur (devrait être > 0)
	float dx2 = _x           - (x + radius); // distance entre la droite de la balle et la gauche du mur (devrait être > 0)
	float dy1 = (y - radius) - (_y + _h); // distance entre le haut de la balle et le bas du mur (devrait être > 0)
	float dy2 = _y           - (y + radius); // distance entre le bas de la balle et le haut du mur (devrait être > 0)
	if(dx1 > 0 && dx1 <= 5) { // collision avec le mur de gauche
		vx = -dampingNorm*vx;
		vy *= dampingDir;
	}
	if(dx2 > 0 && dx2 <= 5) { // collision avec le mur de droite
		vx = -dampingNorm*vx;
		vy *= dampingDir;
	}
	if((dy1 > 0 && dy1 <= 5)  &&  (x >= (_x - _w) && x <= (_x + _w))) { // collision avec le plafond
		vy = -dampingNorm*vy;
		vx *= dampingDir;
	}
	if((dy2 > 0  && dy2 <= 10)  &&  (x >= (_x - _w) && x <= (_x + _w))) { // collision avec le sol
		vy = -dampingNorm*vy;
		vx *= dampingDir;
	}
	
	shape.setSpeed(vx,vy);
}


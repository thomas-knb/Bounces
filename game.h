#ifndef _GAME_H
#define _GAME_H
#include "screen.h"
#include "shape.h"
#include "ball.h"
#include "cube.h"
#include "wall.h"


class Game
{
	public:
		Game():_screen(500,500), _play(false), _nbShapes(1){}
		Game(int nbShapes):_screen(500,500), _play(false), _nbShapes(nbShapes){}
//		~Game();
		bool play();
	private:
		Screen _screen;
		bool _play;
		int _nbShapes;
		Shape ** _shapes;
		Wall _walls[4];
	private:
		void initGame();
		void handleEvent (Screen& _s, bool & move);

};
#endif


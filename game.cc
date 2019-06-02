#include "game.h"


void Game::initGame()
{
	Cube cube1(350, 250, 15, 0, 0);
	_simu+=cube1;

	_walls[0] = Wall(0, 0, 500, 10);   // plafond
	_walls[1] = Wall(0, 490, 500, 10); // sol
	_walls[2] = Wall(0, 0, 10, 500);   // mur de gauche
	_walls[3] = Wall(490, 0, 10, 500); // mur de droite
}

void Game::handleEvent(Screen& _s, bool & move)
{
	sf::Event event;
	while (_screen.pollEvent(event)) {
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			_screen.close();
			_play = false;
		}
		if (event.type == sf::Event::KeyPressed)
			move = true;
		if (event.type == sf::Event::KeyReleased)
			move = false;
		if (!_play && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
			_play = true;
	}    
}

bool Game::play()
{
	uint16_t i,j;

	bool move = true;
	_play = false;
	initGame();

	while(_screen.isOpen()) {
		_screen.render();
		handleEvent(_screen, move);
		if(!_play)
			_screen.text(100, 250, "Press Space to start",0xFFFFFFFF);
		else {
			for (i=0; i<_simu.getNbShapes(); i++)
				_simu.getShapes()[i]->update(move);
			for (j = 0; j<4; j++) {
				_walls[j].draw(_screen);
				for (i=0; i<_simu.getNbShapes(); i++)
					_walls[j].computeSpeed(*_simu.getShapes()[i]);
			}
			for (i=0; i<_simu.getNbShapes(); i++)
				_simu.getShapes()[i]->draw(_screen);
		}      
	}
	return 0;
}


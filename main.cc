#include <iostream>
#include "game.h"


int main(int argc, char **argv)
{
	std::cerr << "To quit, type C-c in the terminal" << std::endl;
	Game g(2);
	g.play();
	return 0;
}


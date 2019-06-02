EXEC=bounce
SRC=$(wildcard *.cc)
OBJ=$(SRC:.cc=.o)
CC=g++ -std=c++11 -g
LDFLAGS=-lsfml-graphics  -lsfml-window -lsfml-system
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS)  -o $(EXEC)
%.o: %.cc
	$(CC) -Wall -c $< -o $@

.depend: $(SRC)
	g++ -std=c++11 -MM $(SRC) > .depend
-include .depend
clean:
	rm -f $(OBJ) $(EXEC)

re: clean $(EXEC)

screen.o: screen.cc screen.h
cube.o: cube.cc cube.h shape.h screen.h
game.o: game.cc game.h screen.h wall.h shape.h
main.o: main.cc game.h screen.h wall.h shape.h
ball.o: ball.cc ball.h shape.h screen.h
shape.o: shape.cc shape.h screen.h
wall.o: wall.cc wall.h screen.h shape.h

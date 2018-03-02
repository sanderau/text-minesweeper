#############################################################
# Author: Austin Sanders
# File: makefile
# Date: 2.15.18
# Description: This makes all my poorly written code into an exe
# Notes: none
#############################################################

CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

cell.o: cell.hpp cell.cpp
	g++ -c cell.cpp -g $(CFLAGS)

board.o: board.hpp board.cpp cell.o rngs.o
	g++ -c board.cpp -g $(CFLAGS)

game.o: game.hpp game.cpp board.o rngs.o
	g++ -c game.cpp -g $(CFLAGS)

#just type "make main" to compile the code
main: main.cpp game.o
	g++ -o runGame main.cpp -g cell.o board.o game.o $(CFLAGS)

#no functionality, this is just to see how many lines of code there are inside of this project
num: 
	wc ${SRC} ${HDR}

#type "make clean" to get rid of all files besides source code and makefile
clean:
	rm -f runGame *.o *.gcno *.gcda

/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#ifndef GAMEOFLIFE_H_INCLUDED
#define GAMEOFLIFE_H_INCLUDED

#include <iostream>

class GameOfLife {
	public:
		GameOfLife(int width);//constructor
		void playGame(int num, int speed); // speed in MILLISECONDS (ex 100)
		
	private:
		int WIDTH; // WIDTH x HEIGHT will be WIDTH^2
};
#endif
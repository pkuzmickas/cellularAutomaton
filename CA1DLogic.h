/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#ifndef CA1DLOGIC_H_INCLUDED
#define CA1DLOGIC_H_INCLUDED
#include <iostream>

using namespace std;

class CA1DLogic {
	public:
		CA1DLogic(int width, int generations); //constructor for the class that gives the const's a value
		void printRule(int value); //prints the output of the rule to the screen cell by cell or row by row
	private:
		int WIDTH, GENS; //to hold how wide the pattern can go and how many generations you have
		int Rule[8];
		void setRule(int value); //converts the decimal given into a binary array
		void printLine(int gen[]);
};
#endif
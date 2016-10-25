/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#ifndef CA_1D_LOGIC_H_INCLUDED
#define CA_1D_LOGIC_H_INCLUDED

using namespace std;

class CA1DLogic {
	public:
		CA1DLogic(int width, int generations); //constructor for the class that gives the const's a value
		void setRule(int value); //converts the decimal given into a binary array
		void printRule(); //prints the output of the rule to the screen cell by cell or row by row
	private:
		const int WIDTH, GENS; //to hold how wide the pattern can go and how many generations you have
		int parentGen[WIDTH]; //the array holding the generation
}
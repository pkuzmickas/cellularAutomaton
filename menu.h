/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream.h>

class Menu {
	public:
		void main();//initialises the program
		void printMenu(); //prints the menu to the screen
		void oneDCA(); //1 Dimensional cellular array
		void showcase();//goes through all the rules and prints them to the screen in a sort of slideshow
		void gameOfLife();//creates a 2D cellular array with the special rules of Conway's Game of Life
		void loadRecent();//loads a recent output from a txt file
		
	private:
		int generations;
		int width;
		 //if(!cin) {cout<<"Error message"} can use a while loop to help it along
		
}
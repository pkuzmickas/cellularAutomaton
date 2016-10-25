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
		main();
		printMenu();
		oneDCA(); //1 Dimensional cellular array
		showcase();
		gameOfLife();
		loadRecent();
		
	private:
		int generations;
		int width;
		 //if(!cin) {cout<<"Error message"} can use a while loop to help it along
		
}
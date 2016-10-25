/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/
#include <iostream>
#include "CA1DLogic.h"

using namespace std;


	CA1DLogic::CA1DLogic(int width, int generations) {
		WIDTH = width;
		GENS = generations;
	}

	void CA1DLogic::printLine(int gen[]) {
		for(int i=0; i<WIDTH; i++) {
			if(gen[i]==0) cout << "\u2588";
			else if(gen[i]==1) cout << "\u2591";
		}
		cout<<endl;
	}

	void CA1DLogic::printRule(int value) {
		int ParentGen[WIDTH]; //the array holding the generation
		setRule(value);
		for(int i=0; i<WIDTH; i++) ParentGen[i] = 0;
		ParentGen[WIDTH/2]=1;
		printLine(ParentGen);
		int currentLine[WIDTH];
		for(int j=0; j<GENS; j++) {
			for(int i=0; i<WIDTH; i++) {
				if(i==0) {
					if(ParentGen[i]==0 && ParentGen[i+1]==0 && ParentGen[WIDTH-1]==0) { // element 1
						currentLine[i]=Rule[0];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==1 && ParentGen[WIDTH-1]==0) { // element 1
						currentLine[i]=Rule[1];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==0 && ParentGen[WIDTH-1]==0) { // element 1
						currentLine[i]=Rule[2];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==1 && ParentGen[WIDTH-1]==0) { // element 1
						currentLine[i]=Rule[3];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==0 && ParentGen[WIDTH-1]==1) { // element 1
						currentLine[i]=Rule[4];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==1 && ParentGen[WIDTH-1]==1) { // element 1
						currentLine[i]=Rule[5];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==0 && ParentGen[WIDTH-1]==1) { // element 1
						currentLine[i]=Rule[6];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==1 && ParentGen[WIDTH-1]==1) { // element 1
						currentLine[i]=Rule[7];
					}
				}
				else if(i==WIDTH-1) {
					if(ParentGen[i]==0 && ParentGen[0]==0 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[0];
					}
					else if(ParentGen[i]==0 && ParentGen[0]==1 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[1];
					}
					else if(ParentGen[i]==1 && ParentGen[0]==0 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[2];
					}
					else if(ParentGen[i]==1 && ParentGen[0]==1 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[3];
					}
					else if(ParentGen[i]==0 && ParentGen[0]==0 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[4];
					}
					else if(ParentGen[i]==0 && ParentGen[0]==1 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[5];
					}
					else if(ParentGen[i]==1 &&ParentGen[0]==0 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[6];
					}
					else if(ParentGen[i]==1 && ParentGen[0]==1 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[7];
					}
				}
				else {
					if(ParentGen[i]==0 && ParentGen[i+1]==0 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[0];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==1 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[1];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==0 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[2];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==1 && ParentGen[i-1]==0) { // element 1
						currentLine[i]=Rule[3];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==0 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[4];
					}
					else if(ParentGen[i]==0 && ParentGen[i+1]==1 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[5];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==0 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[6];
					}
					else if(ParentGen[i]==1 && ParentGen[i+1]==1 && ParentGen[i-1]==1) { // element 1
						currentLine[i]=Rule[7];
					}
				}
			}
			printLine(currentLine);
			for(int i=0; i<WIDTH; i++) ParentGen[i]=currentLine[i];
		}
	}

	void CA1DLogic::setRule(int value) {
		for(int i=0; i<8; i++) {
			Rule[i] = value%2;
			value/=2;
		}
	}

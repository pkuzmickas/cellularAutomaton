/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/
#include <iostream>
#include <fstream>
#include "CA1DLogic.h"
#include <thread>
#include <chrono>
using namespace std;



CA1DLogic::CA1DLogic(int width, int generations) {
	WIDTH = width;
	GENS = generations;
}

void CA1DLogic::printLine(int gen[]) {
	for(int i=0; i<WIDTH; i++) {
		if(gen[i]==0) cout << "\u2588"; //prints out special characters, a white block and a black block
		else if(gen[i]==1) cout << "\u2591";
	}
	cout<<endl;
}

void CA1DLogic::printRule(int value) {
	int ParentGen[WIDTH]; //the array holding the generation
	setRule(value); //converts decimal value to binary
	ofstream file; //opens a file to write to
	file.open("saveFile.txt");
	file << "Rule: " << value << " ( ";
	for(int i=7; i>=0; i--) { // has to print from 7 to 0 because otherwise the binary number would look wrong when printed
		file << Rule[i] << " ";
	}
	file<<")"<<endl<<endl;
		
	for(int i=0; i<WIDTH; i++) ParentGen[i] = 0; //Clears the array with 0s
	ParentGen[WIDTH/2]=1; //adds one block in the middle of the line as the starting point
	printLine(ParentGen); //prints the generation
	for(int i=0; i<WIDTH; i++) { //writes the first line to file
		if(ParentGen[i]==0) file << "\u2588";
		if(ParentGen[i]==1) file << "\u2591";
	}
	file << endl;
	int currentLine[WIDTH];
	for(int j=0; j<GENS; j++) {
		for(int i=0; i<WIDTH; i++) {
			int index2 = i; //so we can iterate the neighbours index as well
			int index3 = i;
			if(i==0) {
				index3 = WIDTH;
			}
			else if(i==WIDTH-1) {
				index2 = -1;
			} //the 8 different rules and how they affect the next generation
			if(ParentGen[i]==0 && ParentGen[index2+1]==0 && ParentGen[index3-1]==0) { // element 1
				currentLine[i]=Rule[0]; //Parent is 000
			}
			else if(ParentGen[i]==0 && ParentGen[index2+1]==1 && ParentGen[index3-1]==0) { // element 1
				currentLine[i]=Rule[1]; //Parent is 010
			}
			else if(ParentGen[i]==1 && ParentGen[index2+1]==0 && ParentGen[index3-1]==0) { // element 1
				currentLine[i]=Rule[2]; //Parent is 100
			}
			else if(ParentGen[i]==1 && ParentGen[index2+1]==1 && ParentGen[index3-1]==0) { // element 1
				currentLine[i]=Rule[3]; //Parent is 110
			}
			else if(ParentGen[i]==0 && ParentGen[index2+1]==0 && ParentGen[index3-1]==1) { // element 1
				currentLine[i]=Rule[4]; //Parent is 011
			}
			else if(ParentGen[i]==0 && ParentGen[index2+1]==1 && ParentGen[index3-1]==1) { // element 1
				currentLine[i]=Rule[5]; //Parent is 011
			}
			else if(ParentGen[i]==1 && ParentGen[index2+1]==0 && ParentGen[index3-1]==1) { // element 1
				currentLine[i]=Rule[6]; //Parent is 101
			}
			else if(ParentGen[i]==1 && ParentGen[index2+1]==1 && ParentGen[index3-1]==1) { // element 1
				currentLine[i]=Rule[7]; //Parent is 111
			}
		}
		printLine(currentLine);
		for(int i=0; i<WIDTH; i++) {
			if(currentLine[i]==0) file << "\u2588";
			if(currentLine[i]==1) file << "\u2591";
			
		}
		file<<endl;
		for(int i=0; i<WIDTH; i++) ParentGen[i]=currentLine[i];
		this_thread::sleep_for(chrono::milliseconds(100)); //pauses the program after a line is printed
	}
	this_thread::sleep_for(chrono::seconds(2)); //pauses the program the automaton is printed fully
	file.close(); //closes the file we saved the output too
}

void CA1DLogic::setRule(int value) {
	for(int i=0; i<8; i++) {
		Rule[i] = value%2; //takes the modulus of the decimal number and stores it in an array
		value/=2;
	}
}

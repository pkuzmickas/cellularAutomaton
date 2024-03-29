/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/
#include "GameOfLife.h"
#include <thread>
#include <chrono>
using namespace std;

GameOfLife::GameOfLife(int width) {
	WIDTH = width;
}

void GameOfLife::playGame(int num, int speed) {
	int Board[WIDTH][WIDTH]; //creates the current board 
	int NewGen[WIDTH][WIDTH]; //and the next generation
	for(int i=0; i<WIDTH; i++) {
		for(int j=0; j<WIDTH; j++) {
			Board[i][j] = 0; //create a blank slate
		}
	}
	switch(num) { //the starting positions for each pattern
		case 0: // glider
			Board[WIDTH/2+1][WIDTH/2]=1;
			Board[WIDTH/2+1][WIDTH/2-1]=1;
			Board[WIDTH/2+1][WIDTH/2+1]=1;
			Board[WIDTH/2-1][WIDTH/2]=1;
			Board[WIDTH/2][WIDTH/2+1]=1;
		break;
		case 1: // small exploder
			Board[WIDTH/2+1][WIDTH/2]=1;
			Board[WIDTH/2][WIDTH/2-1]=1;
			Board[WIDTH/2][WIDTH/2+1]=1;
			Board[WIDTH/2-1][WIDTH/2+1]=1;
			Board[WIDTH/2-1][WIDTH/2]=1;
			Board[WIDTH/2-1][WIDTH/2-1]=1;
			Board[WIDTH/2-2][WIDTH/2]=1;
		break;
		case 2: // exploder
			Board[WIDTH/2+2][WIDTH/2]=1;
			Board[WIDTH/2-2][WIDTH/2]=1;
			Board[WIDTH/2][WIDTH/2+2]=1;
			Board[WIDTH/2][WIDTH/2-2]=1;
			Board[WIDTH/2-1][WIDTH/2-2]=1;
			Board[WIDTH/2-1][WIDTH/2+2]=1;
			Board[WIDTH/2-2][WIDTH/2+2]=1;
			Board[WIDTH/2-2][WIDTH/2-2]=1;
			Board[WIDTH/2+1][WIDTH/2-2]=1;
			Board[WIDTH/2+1][WIDTH/2+2]=1;
			Board[WIDTH/2+2][WIDTH/2+2]=1;
			Board[WIDTH/2+2][WIDTH/2-2]=1;
		break;
		case 3: // 10 cell row
			Board[WIDTH/2][WIDTH/2]=1;
			Board[WIDTH/2][WIDTH/2-1]=1;
			Board[WIDTH/2][WIDTH/2-2]=1;
			Board[WIDTH/2][WIDTH/2-3]=1;
			Board[WIDTH/2][WIDTH/2-4]=1;
			Board[WIDTH/2][WIDTH/2+1]=1;
			Board[WIDTH/2][WIDTH/2+2]=1;
			Board[WIDTH/2][WIDTH/2+3]=1;
			Board[WIDTH/2][WIDTH/2+4]=1;
			Board[WIDTH/2][WIDTH/2+5]=1;
		break;
		case 4: // lightweight spaceship
			Board[WIDTH/2+1][WIDTH/2+1]=1;
			Board[WIDTH/2][WIDTH/2+2]=1;
			Board[WIDTH/2-1][WIDTH/2+2]=1;
			Board[WIDTH/2-2][WIDTH/2+2]=1;
			Board[WIDTH/2-2][WIDTH/2+1]=1;
			Board[WIDTH/2-2][WIDTH/2]=1;
			Board[WIDTH/2-2][WIDTH/2-1]=1;
			Board[WIDTH/2-1][WIDTH/2-2]=1;
			Board[WIDTH/2+1][WIDTH/2-2]=1;
		break;
		case 5: // tumbler
			Board[WIDTH/2][WIDTH/2+1]=1;
			Board[WIDTH/2-1][WIDTH/2+1]=1;
			Board[WIDTH/2-2][WIDTH/2+1]=1;
			Board[WIDTH/2-3][WIDTH/2+1]=1;
			Board[WIDTH/2-3][WIDTH/2+2]=1;
			Board[WIDTH/2-2][WIDTH/2+2]=1;
			Board[WIDTH/2+1][WIDTH/2+1]=1;
			Board[WIDTH/2+2][WIDTH/2+2]=1;
			Board[WIDTH/2][WIDTH/2+3]=1;
			Board[WIDTH/2+1][WIDTH/2+3]=1;
			Board[WIDTH/2+2][WIDTH/2+3]=1;

			Board[WIDTH/2][WIDTH/2-1]=1;
			Board[WIDTH/2-1][WIDTH/2-1]=1;
			Board[WIDTH/2-2][WIDTH/2-1]=1;
			Board[WIDTH/2-3][WIDTH/2-1]=1;
			Board[WIDTH/2-3][WIDTH/2-2]=1;
			Board[WIDTH/2-2][WIDTH/2-2]=1;
			Board[WIDTH/2+1][WIDTH/2-1]=1;
			Board[WIDTH/2+2][WIDTH/2-2]=1;
			Board[WIDTH/2][WIDTH/2-3]=1;
			Board[WIDTH/2+1][WIDTH/2-3]=1;
			Board[WIDTH/2+2][WIDTH/2-3]=1;
		break;
		case 6: // gosper glider gun WIDTH MUST BE ATLEAST 40
			Board[WIDTH/2-2][WIDTH/2]=1;
			Board[WIDTH/2-3][WIDTH/2-1]=1;
			Board[WIDTH/2-3][WIDTH/2-2]=1;
			Board[WIDTH/2-2][WIDTH/2-2]=1;
			Board[WIDTH/2-1][WIDTH/2-2]=1;

			Board[WIDTH/2-4][WIDTH/2-8]=1;
			Board[WIDTH/2-5][WIDTH/2-8]=1;
			Board[WIDTH/2-5][WIDTH/2-9]=1;
			Board[WIDTH/2-4][WIDTH/2-10]=1;
			Board[WIDTH/2-3][WIDTH/2-10]=1;
			Board[WIDTH/2-3][WIDTH/2-9]=1;

			Board[WIDTH/2-4][WIDTH/2-17]=1;
			Board[WIDTH/2-5][WIDTH/2-17]=1;
			Board[WIDTH/2-5][WIDTH/2-18]=1;
			Board[WIDTH/2-4][WIDTH/2-18]=1;

			Board[WIDTH/2-6][WIDTH/2+6]=1;
			Board[WIDTH/2-7][WIDTH/2+6]=1;
			Board[WIDTH/2-7][WIDTH/2+5]=1;
			Board[WIDTH/2-6][WIDTH/2+4]=1;
			Board[WIDTH/2-5][WIDTH/2+4]=1;
			Board[WIDTH/2-5][WIDTH/2+5]=1;

			Board[WIDTH/2-6][WIDTH/2+16]=1;
			Board[WIDTH/2-7][WIDTH/2+16]=1;
			Board[WIDTH/2-7][WIDTH/2+17]=1;
			Board[WIDTH/2-6][WIDTH/2+17]=1;

			Board[WIDTH/2][WIDTH/2+17]=1;
			Board[WIDTH/2][WIDTH/2+18]=1;
			Board[WIDTH/2+1][WIDTH/2+17]=1;
			Board[WIDTH/2+2][WIDTH/2+17]=1;
			Board[WIDTH/2+1][WIDTH/2+19]=1;

			Board[WIDTH/2+5][WIDTH/2+6]=1;
			Board[WIDTH/2+5][WIDTH/2+7]=1;
			Board[WIDTH/2+5][WIDTH/2+8]=1;
			Board[WIDTH/2+6][WIDTH/2+6]=1;
			Board[WIDTH/2+7][WIDTH/2+7]=1;
		break;

	}
	for(int i=0; i<WIDTH; i++) {
		for(int j=0; j<WIDTH; j++) {
			NewGen[i][j] = Board[i][j];
		}
	}
	while(1) { //while keep on running, let the pattern keep on moving as some patterns don't stop
		cout << string( 100, '\n' );
		
		for(int i=0; i<WIDTH; i++) { //checks every square on the board for how many neighbours each square have
			for(int j=0; j<WIDTH; j++) {
				int counter = 0;
				int index1=i; //are the two edges
				int index2=j;
				if(i==0) index1=WIDTH; //checks how many neighbours it has including the wrapping
				if(i==WIDTH-1) index1=-1;
				if(j==0) index2=WIDTH;
				if(j==WIDTH-1) index2=-1;
				if(Board[index1-1][j]==1) counter++;
				if(Board[index1-1][index2+1]==1) counter++;
				if(Board[i][index2+1]==1) counter++;
				if(Board[index1+1][index2+1]==1) counter++;
				if(Board[index1+1][j]==1) counter++;
				if(Board[index1+1][index2-1]==1) counter++;
				if(Board[i][index2-1]==1) counter++;
				if(Board[index1-1][index2-1]==1) counter++;
				if(Board[i][j]==1) {
					if(counter < 2) NewGen[i][j]=0; //if they have less than 2 neighbours it dies
					else if(counter > 3) NewGen[i][j]=0; //if they have more than 3 neighbours it dies
				} else {
					if(counter==3) NewGen[i][j]=1; //it has 3 neighbours it lives (or is born)
				}
				if(Board[i][j]==0) cout << "\u2588";
				else if(Board[i][j]==1) cout << "\u2591";
			}
			cout<<endl;
		}
		
		for(int i=0; i<WIDTH; i++) { //updates the board
			for(int j=0; j<WIDTH; j++) {
				Board[i][j] = NewGen[i][j];
			}
		}
		cout<<"CTRL + C to stop"<<endl;
		this_thread::sleep_for(chrono::milliseconds(speed)); //makes the program pause before the next screen is printed, determines how fast the pattern moves

	}
}
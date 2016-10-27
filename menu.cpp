/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#include "menu.h"
#include "CA1DLogic.h"
#include "GameOfLife.h"


using namespace std;

Menu::Menu(){ //constructor for menu
	int width = 0;
	int generations =0;
}

void Menu::printMenu(){ //prints out the standard menu
	cout<<"======================================================"<<endl;
	cout<<"1. Create a single dimensional Cellular array"<<endl;
	cout<<"2. Load the most recent output"<<endl;
	cout<<"3. Showcase all the rules"<<endl;
	cout<<"4. Conway's Game of Life"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"Please enter an integer to choose the option you want"<<endl;
	cout<<"======================================================"<<endl;
}

bool Menu::findSize() //finds the width and number of generations of the automoman and returns if its valid or not
{ //width and generations are fields 
	cout<<"Please enter the Width of the Automaton"<<endl;
	cout<<"This width should be greater than or equal to 8"<<endl;
	cin>>width;
	if(!cin || width < 8) //checks to see if its valid or not
	{
		cout<<"That isn't a valid number! Please input a number greater than 8!"<<endl;
		return false; //The input isn't valid
	}
	else
	{
		cout<<"Your width is :"<<width<<endl;

		cout<<"======================================================"<<endl;
		cout<<"Please enter the number of generations the Automaton should span"<<endl;
		cin>>generations;

		if(!cin || generations <=0)
		{
			cout<<"That isn't a valid number! Please input a number greater than 0"<<endl;
			return false; //The input isn't valid
		}
		else
		{
			cout<<"The number of generations is :"<<generations<<endl;
			cout<<"======================================================"<<endl;
			return true;
		}
	}
}

void Menu::oneDCA(){
	if(findSize() == true)
	{
		int ruleNo;
		cout<<"Please enter the rule number, its between 0 and 255"<<endl;
		cin>>ruleNo;
		if(!cin || ruleNo<0 || ruleNo>255)
		{
			cout<<"That isn't a valid number! Please input a number between 0 and 255"<<endl;
		}
		else
		{
			CA1DLogic cad1dLogic1(width,generations); //creates an object of CA1DLogic
			cad1dLogic1.printRule(ruleNo); //Starts printing the rule
		}
	
	}

}

void Menu::showcase()
{
	if(findSize() == true)
	{
		CA1DLogic cad1dLogic1(width,generations);
		for(int i=0;i<256;i++) //starts printing out all the rules from 0 to 255
		{
			cout<<""<<endl;
			cout<<"Rule : "<<i<<endl;
			cout<<""<<endl;
			cad1dLogic1.printRule(i);

		}
	}
}

void Menu::loadRecent() //loads the most recent saved pattern into the terminal
{
	string line;
	ifstream saveFile ("saveFile.txt"); //opens up a stream for reading
	if(saveFile.is_open()) //if it did open correctly then
	{
		while(getline (saveFile,line)) //loop thrrough every line and print it until you get to a line with nothing in it
		{
			cout<<line<<endl;
		}
		saveFile.close(); //close the file
	}
	else
	{
		cout<<"The file is unable to open"<<endl;
	}

}

void Menu::gameOfLife()
{
	if(findSize() == true)
	{
		cout<<"Please enter the speed of the Game (its in milliseconds)"<<endl;
		int speed;
		cin>>speed;
		if(!cin)
		{
			cout<<"Sorry that isn't a number please choose again"<<endl;
		}
		else
		{
			cout<<"======================================================"<<endl;
			cout<<"Please choose what pattern you would like"<<endl;
			cout<<"======================================================"<<endl;
			cout<<"1. Glider"<<endl;
			cout<<"2. Small Exploder"<<endl;
			cout<<"3. Exploder"<<endl;
			cout<<"4. 10 Cell Row"<<endl;
			cout<<"5. Lightweight Spaceship"<<endl;
			cout<<"6. Tumbler"<<endl;
			cout<<"7. Gosper Glider Gun"<<endl;
			cout<<"8. Exit"<<endl;
			cout<<"======================================================"<<endl;
			cout<<"Please enter an integer to choose the option you want"<<endl;
			cout<<"======================================================"<<endl;

			int noOfGame = 1; //the string holding the user's answer
			while(noOfGame != 8)
			{
				cin>>noOfGame;
				if(!cin)
				{
					cout<<"Sorry that isn't a number please choose again"<<endl;
				}
				else
				{
					GameOfLife game(width); 
					switch(noOfGame)
					{
						case 1:
						game.playGame(noOfGame-1, speed); //the pattern they want to use and the speed of the game in milliseconds
						break;

						case 2:
						game.playGame(noOfGame-1, speed);
						break;

						case 3:
						game.playGame(noOfGame-1, speed);
						break;

						case 4:
						game.playGame(noOfGame-1, speed);
						break;

						case 5:
						game.playGame(noOfGame-1, speed);
						break;

						case 6:
						game.playGame(noOfGame-1, speed);
						break;

						case 7:
						game.playGame(noOfGame-1, speed);
						break;

						case 8: //The 
							cout<<"Are you sure you want to exit?"<<endl;
						break;

						default:
						cout<<"That isn't a valid option!"<<endl;
					}
				}
			}
		
		
		}
	}

}



int main(){
	Menu menu1;
	string choice = "1"; //the string holding the user's answer
	
	while(choice != "5")
	{
		menu1.printMenu();
		cin>>choice;
		
			switch(choice.at(0)) //gets the character at the start of the string
			{
				case '1':
				menu1.oneDCA();
				break;

				case '2':
				menu1.loadRecent();
				break;

				case '3':
				menu1.showcase();
				break;

				case '4':
				menu1.gameOfLife();
				break;

				case '5':
					cout<<"Are you sure you want to exit?"<<endl;
				break;

				default:
				cout<<"That isn't a valid option!"<<endl;
				break;
			}
		}

	return 0;
}
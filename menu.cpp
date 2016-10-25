/************************
 	James Strachan - 150008551
	Paulius Kuzmickas - 150015860
	AC21009 Assignment #2
	Cellular Automaton
*************************/

#include "menu.h"


using namespace std;

Menu::Menu(){ //constructor for menu
	int width = 0;
	int generations =0;
}

void Menu::printMenu(){
	cout<<"======================================================"<<endl;
	cout<<"1. Create a single dimensional Cellular array"<<endl;
	cout<<"2. Load the most recent output"<<endl;
	cout<<"3. Showcase all the rules"<<endl;
	cout<<"4. Conway's Game of Life"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"Please enter an integer to choose the option you want"<<endl;
	cout<<"======================================================"<<endl;
}

void Menu::oneDCA(){
	cout<<"======================================================"<<endl;
	cout<<"Please enter the Width of the Automaton"<<endl;
	cout<<"This width should be greater than or equal to 8"<<endl;
	cin>>width;
	if(!cin || width < 8) //checks to see if its valid or not
	{
		cout<<"That isn't a valid number! Please input a number greater than 8!"<<endl;
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
		}
		else
		{
			cout<<"The number of generations is :"<<generations<<endl;
			cout<<"======================================================"<<endl;
			int ruleNo;
			cout<<"Please enter the rule number, its between 0 and 255"<<endl;
			cin>>ruleNo;
			if(!cin || ruleNo<1 || ruleNo>255);
			{
				cout<<"That isn't a valid number! Please input a number between 0 and 255"<<endl;
			}
			else
			{
			CA1DLogic cad1dLogic1(width,generations);
			cad1dLogic1.printRule();
			}	
		}
	}

}


int main(){
	Menu menu1;
	int choice = 1; //the string holding the user's answer
	while(choice != 0)
	{
		menu1.printMenu();
		cin>>choice;
		if(!cin)
		{
			cout<<"Sorry that isn't a number please choose again"<<endl;
		}
		else
		{
			switch(choice)
			{
				case 1:
				menu1.oneDCA();
				break;

				case 2:

				break;

				case 3:

				break;

				case 4:

				break;

				case 0:

				break;

				default:
				cout<<"That isn't a valid option!"<<endl;
			}
		}
	}

	return 0;
}
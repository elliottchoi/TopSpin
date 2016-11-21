#include <iostream>
#include "CircularDoublyLinkedList.h"
#include "TopSpin.h"
#include <string>

using namespace std;

int main()
{
	int response; 
	int numberOfRandomMoves;
	int numberOfShifts;
	TopSpin game=TopSpin(20,4);
	cout << game;
	cout << "How many random moves do you want to use? " << endl;
	cin >> numberOfRandomMoves;
	for (int x = 0; x < numberOfRandomMoves; x++)
	{
		game.shiftLeft();
		game.spin();
	}
	cout << game;
	cout << "This is the state of your game. " << endl;
	bool loop = 1;
	int direction;
	while (loop)
	{
		cout << "Please choose from the following options enter your choice by entering the corresponding number : " << endl
			<< "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cin >> response; 
		if (response == 1)
		{
			cout << "What are the number of Shifts?" << endl;
			cin >> numberOfShifts;
			cout << "What direction shift? (Right=0, Left ==1)" << endl;
			cin >> direction;
			if (direction == 0)
			{
				for (int x = 0; x < numberOfShifts; x++)
				{
					game.shiftRight();
				}
			}
			else
			{
				for (int x = 0; x < numberOfShifts; x++)
				{
					game.shiftLeft();
				}
			}
			cout << game;
			cout << "This is the current state of your board" << endl;
		}
		else if (response == 2)
		{
			game.spin();
			cout << "This is the state of your board! " << endl;
			cout << game;
			if (game.isSolved())
			{
				loop = 0;
			}
		}
		else
		{
			loop = 0;
		}
	}
}

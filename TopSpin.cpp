#include "TopSpin.h"
#include <iostream>
using namespace std;

TopSpin::TopSpin(int size, int spinSize)
{
	//Checks params if they are within bounds
	if (size<1 || spinSize>size)
	{
		gameSize = 20;
		spinSize = 4;
	}
	//Adjust params to user inputted params
	else
	{
		gameSize = size;
		mechanismSpinSize = spinSize;
	}
	
	//Adding values to List
	for (int x = 1; x <= size; x++)
	{
		board.addItem(x);
	}
	//Setting up the begining spin node 
	mechanismStart = mechanismEnd=board.getHead;
	//Setting up the spin end node 
	for (int x = 0; x < spinSize; x++)
	{
		mechanismEnd = mechanismEnd->next;
	}
}
int TopSpin::getSize()
{
	return gameSize;
}
void TopSpin::shiftLeft(int numberOfShifts)
{
	//Shift the start of the mechnaism 
	for (int x = 0; x < numberOfShifts; x++)
	{
		mechanismStart = mechanismStart->next;
	}
	mechanismEnd = mechanismStart;
	//Establish the Mech location
	for (int x = 0; x < mechanismSpinSize; x++)
	{
		mechanismEnd = mechanismEnd->next;
	}
}
void TopSpin::shiftRight(int numberOfShifts)
{
	//Shift the start of the mechnaism 
	for (int x = 0; x < numberOfShifts; x++)
	{
		mechanismStart = mechanismStart->previous;
	}
	mechanismEnd = mechanismStart;
	//Establish the Mech location
	for (int x = 0; x < mechanismSpinSize; x++)
	{
		mechanismEnd = mechanismEnd->previous;
	}
}
void TopSpin::spin()
{
}
bool TopSpin::isSolved()
{

}

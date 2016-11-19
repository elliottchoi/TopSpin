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
	for (int x = 1; x <= 20; x++)
	{
		board.addItem(x);
	}
}
int TopSpin::getSize()
{
	return gameSize;
}

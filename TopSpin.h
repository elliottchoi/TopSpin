#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
using namespace std;

//Abstract Class
class TopSpinADT {
public:
	virtual void shiftLeft() = 0;
	virtual void shiftRight() = 0;
	virtual void spin() = 0;
	virtual bool isSolved() = 0;
};

class TopSpin:public TopSpinADT
{
private:
	//Node Class
	class Node {
	public:
		//Node Constructor 
		Node(int val, Node* nx = NULL, Node* prv = NULL) :Value(val), next(nx), previous(prv)
		{
			if (previous)
			{
				previous->next = this;
			}
			if (next)
			{
				next->previous = this;
			}
		}
		int Value;
		Node*next;
		Node*previous;
	};
public:
	//Top spin member variables
	int gameSize = 0;
	int mechanismSpinSize = 0;
	CircularDoublyLinkedList<int>board; 
	
	//Top Spin Functions
	TopSpin(int size, int spinSize);
	int getSize()const;
	//Overriding functions 
	virtual void shiftLeft();
	virtual void shiftRight();
	virtual void spin();
	virtual bool isSolved();
	//Operator Overloading
	friend ostream &operator<<(ostream &os, const TopSpin&s);
};



TopSpin::TopSpin(int size, int spinSize)
{
	//Checks params if they are within bounds
	if (size<1 || spinSize>size)
	{
		cout << "Invalid Value, Game Size must be larger than 1, and spinsize cannot exceed Game Size" << endl;
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
	for (int x = 1; x <= gameSize; x++)
	{
		board.addItem(x);
	}
}
int TopSpin::getSize()const
{
	return gameSize;
}
//Setting Shifts
void TopSpin::shiftLeft()
{
	board.move_head(1);
}
void TopSpin::shiftRight()
{
	board.move_head(0);
}
void TopSpin::spin()
{
	//Get two Iterators that will transverse the list 
	CircularDoublyLinkedList<int>::Iterator front(board.getHead());
	CircularDoublyLinkedList <int>::Iterator spinEnd(board.getHead());

	for (int x = 1; x < mechanismSpinSize; x++)
	{
		//Positions the end node to nth node of the spin mechanism 
		++spinEnd;
	}

	//Only need to transvere 1/2 of the list 
	for (int x = 0; x < (mechanismSpinSize / 2); x++)
	{
		//Set temp val
		int swapVal = front.getValue();
		//Switch two iterators
		front.setValue(spinEnd.getValue());
		spinEnd.setValue(swapVal);
		//Close the gap between the iterators 
		++front;
		--spinEnd;
	}
}
bool TopSpin::isSolved()
{
	//Get the front of the list
	CircularDoublyLinkedList<int>::Iterator begin(board.getHead());
	bool isFound = 0;

	//Finding the position of 1 in the LinkedList
	while (!isFound)
	{
		if (begin.getValue() == 1)
		{
			isFound = 1;
			//cout << "Found node 1" << endl;
		}
		else
		{
			++begin;
		}
	}

	//Now check for pos 2.....gameSize
	++begin;
	for (int check = 2; check <= gameSize; check++, ++begin)
	{
		if (check != begin.getValue())
		{
			for (int reverseCounter = gameSize; reverseCounter > 1; reverseCounter--, ++begin)
			{
				if (reverseCounter!=begin.getValue())
				{
					return 0;
				}
			}
		}
	}
	cout << "Congradulations! You win!" << endl;
	return 1;
}
ostream& operator << (ostream& os, const TopSpin& ts)
{
	CircularDoublyLinkedList<int>::Iterator start = (ts.board).begin();
	//Syntax creating box 
	cout << "|-";
	for (int x = 0; x < ts.mechanismSpinSize; x++)
		cout << "--";
	cout << "|" << endl;

	//Adds | for begin and end of spin mechnaism 
	for (int x = 0; x < ts.gameSize; x++, ++start)
	{
		if (x == 0 || x == ts.mechanismSpinSize)
			cout << "| ";
		os << start.getValue() << " "; //output a value that is stored in node
	}
	cout << endl;
	cout << "|-";
	for (int x = 0; x < ts.mechanismSpinSize; x++)
		cout << "--";
	cout << "|" << endl;
	return os;
}

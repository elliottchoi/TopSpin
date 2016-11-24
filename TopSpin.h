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
	void shiftLeft(int numberOfShifts);
	void shiftRight(int numberOfShifts);
	//Operator Overloading
	friend ostream &operator<<(ostream &os, const TopSpin&s);
};




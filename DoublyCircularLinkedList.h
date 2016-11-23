#include <iostream>
#pragma once
template <class T>

class CircularDoublyLinkedList
{
	private: 
	//Node Class with Next and Previous Pointer
	class Node{
	public:
		//Node Constructor 
		Node(T val, Node* nx = NULL, Node* prv = NULL) :Value(val), next(nx), previous(prv)
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
		T Value;
		Node*next;
		Node*previous;
	};

	//private member variables
	private:
		Node* m_head;
		Node* m_tail;
		int m_size; 

	public:
		//Construct empty Circular Doubly Linked List
		CircularDoublyLinkedList();
		//Destroy a Circular Doubly Linked List 
		~CircularDoublyLinkedList();
		//Add Item to Front of List
		void addItem(T val);
		//get the head of the linkedList
		Node*getHead()const { return m_head; }
		void move_head(bool directionShift);


		//Unused Functions but you apprently have to make them to get 100
		unsigned int size() const;  // return number of items in the list
		bool isEmpty() const; // true if list is empty, false otherwise
		void addHead(T item);  // adds item to front of list
		T removeHead();  // remove front node, and return the data T found in it;
						 // PRECONDITION: list must not be empty already
		T retrieveHead() const; // returns the data T in front node; 
								// PRECONDITION: list must not be empty already
		void addTail(T item); // add item to end of list
		T removeTail(); // remove last node, and return the data T found in it;
						// PRECONDITION: list must not be empty already
		T retrieveTail() const; // return data T in last node; 
								// PRECONDITION: list must not be empty already
		void add(unsigned int n, T item); // Add a new node containing an item in position n on the list
										  // PRECONDITION: n must be a valid list position (1<=n<=(size+1))
		T replace(unsigned int n, T item); // Replace the data stored in position n of the list with
										   // item, and return the replaced item; 
										   // PRECONDITION: n must be a valid list position (1<=n<=size)  
		T remove(unsigned int n); // Remove the node at position n from the list, and return the
								  // item it contained; PRECONDITION: n must be a valid list position (1<=n<=size)
		T retrieve(unsigned int n) const; // Return the item value from the node in position n; 
										  // PRECONDITION: n must be a valid list position (1<=n<=size)

		//Iterator Class
public:

	class Iterator {// iterators are used for efficient traversal of linked lists
	private:
		Node* m_ptr;    // an iterator hides a pointer to node
	public:
		Iterator(Node* ptr) { m_ptr = ptr; }
		void operator++ () { m_ptr = m_ptr->next; } // for forward traversing, e,g, Iterator i=begin(); ... ++i;
		void operator--() { m_ptr = m_ptr->previous; }
		bool operator != (const Iterator& b) { return m_ptr != b.m_ptr; }
		int operator *() { return m_ptr->Value; }
		T getValue() { return m_ptr->Value; }
		void setValue(int val) { m_ptr->Value = val; }
	};
	// linked list objects create forward-traversal iterators using the two functions below
	Iterator begin() const { return Iterator(m_head); }
	Iterator end() const { return Iterator(m_tail); }
};

//Construct Circular Doubly Linked List
template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList():
	m_head(NULL),
	m_tail(NULL),
	m_size(0)
	{}

//Destructor
template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList()
{
	Node *temp = m_head, *nextNode;
	//Iterates while there are still nodes left
	for (int x = 0; x > this->m_size; x++)
	{
		nextNode = temp->next;
		delete temp;
		temp = nextNode;
	}
}

//Adding item to tail
template <class T>
void CircularDoublyLinkedList<T>::addItem(T val)
{
	//Empty List, adding first node
	if (m_size == 0)
	{
		m_head = m_tail = new Node(val, NULL, NULL);
	}
	else
	{
		m_tail = new Node(val, m_head, m_tail);
	}
	m_size++;
}

//Allowing the shift of list
template <class T>
void CircularDoublyLinkedList<T>::move_head(bool shiftDirection)
{
	//Shifting Left
	if (shiftDirection)
	{
		m_head = m_head->next;
		m_tail = m_tail->next;
	}
	//Shifting Right
	else
	{
		m_head = m_head->previous;
		m_tail = m_tail->previous; 
	}
}

//Unused Functions

//Return Size
template <class T>
unsigned int CircularDoublyLinkedList<T>::size()const
{
	return m_size;
}

//Return if list is empty 
template <class T>
bool CircularDoublyLinkedList<T>::isEmpty()const
{
	if (m_size == 0)
	{
		return 0;
	}
	return 1; 
}

//Add head using add item since add item adds to the head 
template <class T>
void CircularDoublyLinkedList<T>::addHead(T item)
{
	addItem(T item);
}

//Remove the head item 
template <class T>
T CircularDoublyLinkedList<T>::removeHead()
{
	// PRECONDITION: list is not already empty
	assert((!isEmpty() && "LinkedList is Empty (in removeHead)"));
	Node * oldNode = m_head;
	T returnVal = m_head->Value;
	m_head = m_head->next;
	m_tail->next =m_head;
	m_head->previous = m_tail;
	if (m_head == nullptr) m_tail = nullptr;
	m_size--;
	delete oldNode;
	return returnVal;
}

template <class T>
T CircularDoublyLinkedList<T>::retrieveHead()
{
	// PRECONDITION: list is not already empty
	assert((!isEmpty() && "LinkedList is Empty (in retrieveHead)"));
	return m_head->Value;
}

template <class T>
void CircularDoublyLinkedList<T>::addTail(T val)
{
	if (isEmpty()) addHead(val);
	else
	{
		Node *temp = new Node(val);
		temp->previous = m_tail;
		temp->next = m_head;
		m_tail = temp;
		m_size++;
	}
}

template <class T>
void CircularDoublyLinkedList<T>::add(unsigned int n, T val)
{

}

template <class T>
T CircularDoublyLinkedList<T>::replace(unsigned int n, T val)
{

}

template <class T>
T CircularDoublyLinkedList<T>::remove(unsigned int n)
{

}

template <class T>
T CircularDoublyLinkedList::retrieve(unsigned int n) const
{

}

#include <iostream>
using namespace std;

#ifndef DLIST
#define DLIST

typedef int ElementType;

class List {
private:
	int mySize;  //current size of list
	int myCapacity;  //capacity of array
	ElementType* myArray;  //pointer to dynamic array

public:
	List(int maxSize = 1024);  //constructor
	~List(); //destructor
	List(const List& origList); //copy constructor
	const List& operator=(const List& rightHandSide);
	bool empty() const;
	void insert(ElementType item, int pos);
	void erase(int pos);
	void display(ostream& out) const;
};

ostream& operator<<(ostream& out, const List& aList);

#endif // !DLIST


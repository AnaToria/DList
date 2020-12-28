#include <iostream>
#include <cassert>
using namespace std;

#include "DList.h"


List::List(int maxSize)
	:mySize(0), myCapacity(maxSize)
{
	myArray = new(nothrow) ElementType[maxSize];
	assert(myArray != 0);
}

List::~List() {
	delete[] myArray;
}

List::List(const List& origList)
	:mySize(origList.mySize), myCapacity(origList.myCapacity)
{
	myArray == new(nothrow) ElementType[myCapacity];

	if (myArray != 0)      //check if memory available
		for (int i = 0; i < mySize; i++)
			myArray[i] = origList.myArray[i];
	else {
		cerr << "*** Inadequate memory to allocate storage for list ***\n";
		exit(1);
	}
}

const List& List::operator=(const List& rightHandSide) {
	//check that not self-assignment
	if (this != &rightHandSide){   
		if (myCapacity != rightHandSide.myCapacity) {
			delete[] myArray;
			myCapacity = rightHandSide.myCapacity;
			myArray = new(nothrow) ElementType[myCapacity];

			if (myArray == 0) {
				cerr << "*** Inadequate memory to allocate storage for list ***\n";
				exit(1);
			}
		}

		//Copy righHandSide's list element into this array
		mySize = rightHandSide.mySize;
		for (int i = 0; i < mySize; i++)
			myArray[i] = rightHandSide.myArray[i];
	}
	return *this;
}

bool List::empty() const {
	return mySize == 0;
}

ostream& operator<<(ostream& out, const List& aList) {
	aList.display(out);
	return out;
}

void List::display(ostream& out) const {
	for (int i = 0; i < mySize; i++)
		out << myArray[i] << " ";
}

void List::insert(ElementType item, int pos) {
	if (mySize == myCapacity) {
		cerr << "*** Illegal location to insert -- " << pos << ". List unchanged. ***\n";
		exit(1);
	}

	if (pos<0 || pos>mySize) {
		cerr << "*** Illegal location to insert -- " << pos << ". List unchanged. ***\n";
		return;
	}

	for (int i = mySize; i > pos; i--)
		myArray[i] = myArray[i - 1];

	myArray[pos] = item;
	mySize++;
}

void List::erase(int pos) {
	if (mySize == 0) {
		cerr << "*** List is empty ***\n";
		return;
	}

	if (pos < 0 || pos >= mySize) {
		cerr << "Illegal location to delete -- " << pos << ". List unchanged. ***\n";
		return;
	}

	for (int i = pos; i < mySize; i++)
		myArray[i] = myArray[i + 1];

	mySize--;
}
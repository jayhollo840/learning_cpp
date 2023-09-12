Classes are the C++ equivalent to C's structs, except you can have functions/methods within.

Member methods of a class can be access by:
- Public - Accessible to any place that the object is access to.
- Private - Only accessible inside the class.
- Protected (Default) - Accessible inside the class and sub-classes.

```C++
#include <iostream>
using namespace stdl;

class Point {
	int x, y; // Protected

	public: // Public defined
		Point (int x, int y); // Constructor
		Point (); // No arg constructor
		int getX() {return x;} // Define getters
		int getY() (return y;)
};

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::Point() {
	x = 0;
	y = 0;
}

int main (void) {
	// Dynamically allocate a Point
	Point *point = new Point(); // The same as malloc(sizeof(point), point)
	cout << "(" << point->getX() << ", " << point->getY() << ")\n";

	// When done with a heap variable, free it with delete.
	delete point; // The same as free(point)

	return 0;
}

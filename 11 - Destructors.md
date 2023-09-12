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

class Line {
	Point *point1;
	Point *point2;

	public:
		Line (int startX, int startY, int endX, int endY);
		float length;

		// This is a "destructor". It will be called when an object of class Line 
		// is deleted.
		~Line () {delete point1; delete point2}; // Tilde denotes a destructor
};

Line::Line(int startX, int startY, int endX, int endY) {
	point1 = new Point(startX, startY);
	point2 = new Point(endX, endY);
}

float Line::length() {
	float dx = (float)(point1->getX()) - (float)(point2->getX());
	float dy = (float)(point1->getY()) - (float)(point2->getY());
	float len = sqrtf(dx*dx + dy*dy);
	return len;
}

int main (void) {
	Line *line = new Line(5, 3, -4, 2);
	cout << "the length of the line is " << line->length() << "\n";

	// Call the destructor
	delete line;

	return 0;
}
```
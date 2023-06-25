#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
int main() {
	Square square("Square", 10, 10, 15);
	Square square2;

	Rectangle rec("Rectangle", 25, 10, 8, 17);
	Rectangle rec2;
	
	Shape* Mas1[4];
	Mas1[0] = new Square("Square", 10, 10, 15);
	Mas1[1] = new Rectangle("Rectangle", 25, 10, 8, 17);
	Mas1[2] = new Circle("Circle", 13, 9, 5);
	Mas1[3] = new Ellipse("Ellipse", 34, 10, 5,4);

	for (int ii = 0; ii < 4; ii++) {
		Mas1[ii]->Save("Test.txt");
	}

	Shape* Mas2[4];
	Mas2[0] = new Square;
	Mas2[1] = new Rectangle;
	Mas2[2] = new Circle;
	Mas2[3] = new Ellipse;

	for (int ii = 0; ii < 4; ii++) {
		Mas2[ii]->Load("Test.txt");
	}

	for (int ii = 0; ii < 4; ii++) {
		Mas2[ii]->Show();
	}

}
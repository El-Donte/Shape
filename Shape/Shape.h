#pragma once
#include <iostream>
class Shape
{
protected:
	char* type;
public:
	Shape() {
		type = new char[32];
		strcpy_s(type, 32, "none");
	}
	Shape(const char* _type) {
		type = new char[32];
		strcpy_s(type, 32, _type);
	}
	virtual void Show() = 0;
	virtual void Save(const char*) = 0;
	virtual void Load(const char*) = 0;
};


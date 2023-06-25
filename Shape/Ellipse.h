#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>
class Ellipse : public Shape {
	double x;
	double y;
	double a;
	double b;

public:
	Ellipse(const char* _type,double _x, double _y, double _a,double _b) :
		Shape(_type),
		x{ _x }, y{ _y }, b{ _b },a{_a}
	{}
	Ellipse() :Ellipse("none", 0, 0, 0,0)
	{}
	void Show() {
		std::cout << "-----" << type << "---- \n";
		std::cout << "coordinate: " << '(' << x << ',' << y << ')' << std::endl;
		std::cout << "sides of rectangle: " << '(' << a << ',' << b << ')' << std::endl;
		std::cout << std::endl;
	}
	void Save(const char* path) {
		std::ofstream fout;
		try
		{
			fout.open(path, std::ios_base::app | std::ios_base::out);
			if (!fout.is_open()) {
				throw std::invalid_argument("Error: can`t open file");
			}
			else {
				fout << type << '\n';
				fout << x << '\n';
				fout << y << '\n';
				fout << a << '\n';
				fout << b << '\n';
				fout << '\n';
			}
			fout.close();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	void Load(const char* path) {
		std::ifstream fin;
		try
		{
			fin.open(path, std::ios_base::in);
			if (!fin.is_open()) {
				throw std::invalid_argument("Error: can`t open file");
			}
			else {
				while (!fin.eof()) {
					fin.getline(type, 32);
					if (strcmp(type, "Ellipse") == 0) {
						fin >> x;
						fin >> y;
						fin >> a;
						fin >> b;
						break;
					}
				}

			}
			fin.close();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
};
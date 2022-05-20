#pragma once
#include <iostream>

class Building {
private:
	size_t height;
	double area;
	char* address;

	void copyFrom(const Building& other);
	void free();

public:
	Building();
	Building(const Building& other);
	Building& operator=(const Building& other);
	~Building();

	Building(size_t height, double area, const char* address);
};


#include "Building.h"
#pragma warning(disable:4996)

void Building::copyFrom(const Building& other) {
	height = other.height;
	area = other.area;
	size_t len = strlen(other.address);
	address = new char[len + 1];
	strcpy(address, other.address);
}

void Building::free() {
	delete[] address;
}

Building::Building() {
	height = 0;
	area = 0;
	address = new char[16];
	strcpy(address, "Invalid Address");
}

Building::Building(const Building& other) {
	copyFrom(other);
}

Building& Building::operator=(const Building& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Building::~Building() {
	free();
}

Building::Building(size_t height, double area, const char* address) {
	this->height = height;
	this->area = area;
	size_t len = strlen(address);
	this->address = new char[len + 1];
	strcpy(this->address, address);
}
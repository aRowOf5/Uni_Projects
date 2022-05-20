#include "House.h"

size_t House::houseCount = 1;

void House::copyFrom(const House& other) {
	floors = other.floors;
	people = other.people;
	houseNumber = houseCount;
	size_t len = strlen(other.ownerName);
	ownerName = new char[len + 1];
	strcpy(ownerName, other.ownerName);
}

void House::free() {
	delete[] ownerName;
	houseCount--;
}

House::House() : Building() {
	floors = 1;
	people = 1;
	houseNumber = houseCount;
	houseCount++;
	ownerName = new char[6];
	strcpy(ownerName, "Peter");
}

House::House(const House& other) : Building(other) {
	copyFrom(other);
	houseCount++;
}

House& House::operator=(const House& other) {
	if (this != &other) {
		Building::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

House::~House() {
	free();
}

House::House(size_t floors, size_t people, const char* ownerName, size_t height, size_t area, const char* address) 
	: Building(height, area, address) {
	this->floors = floors;
	this->people = people;
	this->houseNumber = houseCount;
	size_t len = strlen(ownerName);
	this->ownerName = new char[len + 1];
	houseCount++;
}

std::ostream& operator<<(std::ostream& os, const House& home) {
	Building temp(home);
	os << temp;//predifinirai operatora v building
	os << "Number of Floors: " << home.floors << std::endl;
	os << "Number of People: " << home.people << std::endl;
	os << "Number of House: " << home.houseNumber << std::endl;
	os << "Name of Owner: " << home.ownerName << std::endl;

}
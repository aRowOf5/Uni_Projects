#pragma once
#include "Building.h"
class House : public Building {
private:
	size_t floors;
	size_t people;
	size_t houseNumber;
	static size_t houseCount;
	char* ownerName;

	void copyFrom(const House& other);
	void free();

public:
	House();
	House(const House& other);
	House& operator=(const House& other);
	~House();

	House(size_t floors, size_t people, const char* ownerName, size_t height, size_t area, const char* address);

	friend std::ostream& operator<<(std::ostream& os, const House& home);
	friend std::istream& operator>>(std::istream& is, House& home);
};


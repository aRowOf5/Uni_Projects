#pragma once
#include "Patients.h"

class Doctors {
private:
	char* name;
	Patients* list;
	double avrgVisits;
	size_t currPatients;

	void copyDoctors(const Doctors& other);
	void freeDoctors();

public:
	Doctors();
	Doctors(const Doctors& other);
	Doctors& operator=(const Doctors& other);
	~Doctors();

	void copyDoctors(const Doctors& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);

	}

	void freeDoctors() {
		delete[] name;
	}
};
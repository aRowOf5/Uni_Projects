#include <iostream>
#include "Doctors.h"

Patients::Patients() {
	Patients::name = nullptr;
	dateOfBirth = Date();
	visitsCount = 0;

}

Patients::Patients(const Patients& other) {
	copyPatients(other);
}

Patients& Patients::operator=(const Patients& other) {
	if (this != &other) {
		freePatients();
		copyPatients(other);
	}
	return *this;
}

Patients::~Patients() {
	freePatients();
}

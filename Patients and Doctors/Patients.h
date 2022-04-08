#pragma once

struct Date {
	int day, month, year;

	Date() {
		day = 1, month = 1, year = 1900;
	}
};

class Patients {
private:
	char* name;
	Date dateOfBirth;
	int visitsCount;
	static size_t patientNumber;

	void copyPatients(const Patients& other);
	void freePatients();

public:
	Patients();
	Patients(const Patients& other);
	Patients& operator=(const Patients& other);
	~Patients();

	void copyPatients(const Patients& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);

	}

	void freePatients() {
		delete[] name;
	}
};
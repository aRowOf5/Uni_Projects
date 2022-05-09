#include "Wallet.h"
#pragma warning (disable:4996)

void Wallet::copyFrom(const Wallet& other) {
	size_t len = strlen(other.firstName);
	firstName = new char[len + 1];
	strcpy(firstName,other.firstName);

	len = strlen(other.lastName);
	lastName = new char[len + 1];
	strcpy(lastName, other.lastName);

	balance = other.balance;
}

void Wallet::free() {
	delete[] firstName;
	delete[] lastName;
}

Wallet::Wallet() {
	firstName = new char[6];
	lastName = new char[7];
	
	strcpy(firstName, "Petur");
	strcpy(lastName, "Ivanov");

	balance = Money(0, 0);
}

Wallet::Wallet(const char* firstName, const char* lastName, const Money& balance) {
	size_t len = strlen(firstName);
	this->firstName = new char[len + 1];
	strcpy(this->firstName, firstName);

	len = strlen(lastName);
	this->lastName = new char[len + 1];
	strcpy(this->lastName, lastName);

	this->balance = balance;
}

Wallet::Wallet(const Wallet& other) {
	copyFrom(other);
}

Wallet& Wallet::operator=(const Wallet& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Wallet::~Wallet() {
	free();
}

void Wallet::withdrawal(const Money& resource) {
	balance -= resource;
}

void Wallet::deposit(const Money& resource) {
	balance += resource;
}

std::ostream& operator<<(std::ostream& os, const Wallet& person) {
	return os << person.firstName << " " << person.lastName << " has " << person.balance;
}

std::istream& operator>>(std::istream& is, Wallet& person) {
	char buff[1024];
	is.getline(buff, 1024, ' ');
	strcpy(person.firstName, buff);

	is.getline(buff, 1024);
	strcpy(person.lastName, buff);

	is >> person.balance;
	return is;
}
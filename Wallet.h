#pragma once
#include "Money.h"

class Wallet {
private:
	Money balance;
	char* firstName;
	char* lastName;

	void copyFrom(const Wallet& other);
	void free();

public:
	Wallet();
	Wallet(const char* firstName, const char* lastName, const Money& balance);
	Wallet(const Wallet& other);
	Wallet& operator=(const Wallet& other);
	~Wallet();

	void withdrawal(const Money& amount);
	void deposit(const Money& amount);

	friend std::ostream& operator<<(std::ostream& os, const Wallet& resource);
	friend std::istream& operator>>(std::istream& is, Wallet& resource);
};


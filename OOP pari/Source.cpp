#include "Wallet.h"

int main() {
	Money balance(123, 45);
	Wallet person("Elon", "Musk", balance);


	person.withdrawal(Money(45,21));
	person.deposit(Money(7, 67));

	std::cout << person;
}
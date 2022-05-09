#pragma once
#include <iostream>

class Money {
private:
	size_t lev;
	size_t stotinka;

public:
	Money();
	Money(size_t leva, size_t stotinkas);
	Money& operator=(const Money& resource);

	Money& operator+=(const Money& resource); // money = money + newMoney
	Money& operator++(); //prefix
	Money operator++(int temp); //postfix
	friend Money operator+(const Money& resourceLeft, const Money& resourceRight);

	Money& operator-=(const Money& resource); //money = money - newMoney
	Money& operator--(); //prefix
	Money operator--(int temp); //postfix
	friend Money operator-(const Money& resourceLeft, const Money& resourceRight);

	friend std::ostream& operator<<(std::ostream& os, const Money& resource);
	friend std::istream& operator>>(std::istream& is, Money& resource);

	bool operator>(const Money& comparer)const; //neshto > drugo neshto
	bool operator>=(const Money& comparer)const; //neshto >= drugo neshto
	bool operator<(const Money& comparer)const; //neshto < drugo neshto
	bool operator<=(const Money& comparer)const; //neshto <= drugo neshto
	bool operator==(const Money& comparer)const; //neshto == drugo neshto
	bool operator!=(const Money& comparer)const; //neshto != drugo neshto
};



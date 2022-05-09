#pragma once

class Money
{
private:
	size_t lev;
	size_t stotinka;

public:
	Money();
	Money(size_t leva, size_t stotinkas);

	Money& operator+=(const Money& resource); // money = money + newMoney
	friend Money operator+(const Money& resourceLeft, const Money& resourceRight);

	Money& operator-=(const Money& resource); //money = money - newMoney
	friend Money operator-(const Money& resourceLeft, const Money& resourceRight);

	friend std::ostream operator<<(std::ostream& os, const Money& resource);
	friend std::istream operator>>(std::istream& is, Money& resource);
	bool operator>(const Money& resourceRight)const; //neshto > neshto
};


bool operator>=(const Money& resourceLeft, const Money& resourceRight);
bool operator<(const Money& resourceLeft, const Money& resourceRight);
bool operator<=(const Money& resourceLeft, const Money& resourceRight);

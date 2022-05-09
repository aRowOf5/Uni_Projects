#include "Money.h"

Money::Money() {
	lev = 0;
	stotinka = 0;
}

Money::Money(size_t leva, size_t stotinka) {
	this->lev = leva;
	this->stotinka = stotinka;
}

Money& Money::operator=(const Money& resource) {
	this->lev = resource.lev;
	this->stotinka = resource.stotinka;

	return *this;
}

Money& Money::operator+=(const Money& resource) {
	this->lev = this->lev + resource.lev;
	this->stotinka = this->stotinka + resource.stotinka;

	return *this;
}

Money& Money::operator++() {
	this->lev += 1;
	this->stotinka += 1;

	return *this;
}

Money Money::operator++(int temp) {
	Money tempRes = *this;

	++(*this);

	return tempRes;
}

Money operator+(const Money& resourceLeft, const Money& resourceRight) {
	Money newResource = resourceLeft;
	newResource += resourceRight;

	return newResource;
}

Money& Money::operator-=(const Money& resource) {
	if (this->lev - resource.lev >= 0) {
		this->lev = this->lev - resource.lev;
	}
	
	if (this->stotinka - resource.stotinka >= 0) {
		this->stotinka = this->stotinka - resource.stotinka;
	}

	return *this;
}

Money& Money::operator--() {
	if (this->lev - 1 >= 0) {
		this->lev -= 1;
	}

	if (this->stotinka - 1 >= 0) {
		this->stotinka -= 1;
	}

	return *this;
}

Money Money::operator--(int temp) {
	Money tempRes = *this;

	--(*this); //this->operator--();

	return tempRes;
}

Money operator-(const Money& resourceLeft, const Money& resourceRight) {
	Money newResource = resourceLeft;
	newResource -= resourceRight;

	return newResource;
}

std::ostream& operator<<(std::ostream& os, const Money& resource) {
	return os << "Balance: " << resource.lev << "." << resource.stotinka;
}

std::istream& operator>>(std::istream& is, Money& resource) {
	return is >> resource.lev >> resource.stotinka;
}

bool Money::operator>(const Money& comparer)const {
	if (this->lev > comparer.lev) {
		return true;
	}
	else if (this->lev == comparer.lev && this->stotinka > comparer.stotinka) {
		return true;
	}
	else {
		return false;
	}
}

bool Money::operator>=(const Money& comparer)const { 
	if (this->lev < comparer.lev) {
		return false;
	}
	else if (this->lev == comparer.lev && this->stotinka < comparer.stotinka) {
		return false;
	}
	else {
		return true;
	}
}

bool Money::operator<(const Money& comparer)const {
	if (this->lev < comparer.lev) {
		return true;
	}
	else if (this->lev == comparer.lev && this->stotinka < comparer.stotinka) {
		return true;
	}
	else {
		return false;
	}
}

bool Money::operator<=(const Money& comparer)const {
	if (this->lev > comparer.lev) {
		return false;
	}
	else if (this->lev == comparer.lev && this->stotinka > comparer.stotinka) {
		return false;
	}
	else {
		return true;
	}
}

bool Money::operator==(const Money& comparer)const {
	if (this->lev == comparer.lev) {
		if (this->stotinka == comparer.stotinka) {
			return true;
		}
	}
}

bool Money::operator!=(const Money& comparer)const {
	if (this->lev != comparer.lev) {
		if (this->stotinka != comparer.stotinka) {
			return true;
		}
	}
}
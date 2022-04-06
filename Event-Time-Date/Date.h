#pragma once

enum dayOfWeek {sunday, monday, tuesday, wednesday, thursday, friday, saturday};

int days[] = { 31, 28, 31, 30, 31, 30,
			   31, 31, 30, 31, 30, 31 };

class Date {
private:
	int day, month, year, daysOfMonth, dayOfWeek, dayCount;
	const int firstDate, firstDayOfWeek, firstYear;

public:
	Date() : firstDate(1), firstDayOfWeek(saturday), firstYear(1900) {
		day = 1, month = 1, year = 1900, daysOfMonth = 31, dayOfWeek = saturday, dayCount = 0;
	}
	void getNewDate(int day, int month, int year);
	void getDayOfTheWeek();
	void tomorrowDate();
	void getRightDate();
	void printDate();
	bool isLeapYear();
	int dayOfYear();
};

bool Date::isLeapYear() {
	if (this->year % 4 == 0) {
		if (this->year % 100 == 0) { return (this->year % 400 == 0); }
		return true;
	}
	return false;
}

void Date::getRightDate() {
	switch (this->month) {
	case 1: 
		this->daysOfMonth = 31;
		break;
	case 2:
		if (isLeapYear()) { this->daysOfMonth = 29; break; }
		this->daysOfMonth = 28;
		break;
	case 3:
		this->daysOfMonth = 31;
		break;
	case 4:
		this->daysOfMonth = 30;
		break;
	case 5:
		this->daysOfMonth = 31;
		break;
	case 6:
		this->daysOfMonth = 30;
		break;
	case 7:
		this->daysOfMonth = 31;
		break;
	case 8:
		this->daysOfMonth = 31;
		break;
	case 9:
		this->daysOfMonth = 30;
		break;
	case 10:
		this->daysOfMonth = 31;
		break;
	case 11:
		this->daysOfMonth = 30;
		break;
	case 12:
		this->daysOfMonth = 31;
		break;
	default:
		break;
	}
}

void Date::getNewDate(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;

	if (this->day > daysOfMonth) {
		this->month = this->month + this->day / daysOfMonth;
		this->day = this->day % this->daysOfMonth;
	}

	if (this->month > 12) {
		this->year = this->year + this->month / 12;
		this->month = this->month % 12;
	}

	if (this->year == 1916 && this->month == 4) { //смяна на календара
		if (this->day >= 1 && this->day <= 13) {
			this->day = this->day + 13;
		}
	}
}

void Date::tomorrowDate() {
	this->day++;
	if (this->day > daysOfMonth) {
		this->month++;
		this->day = this->day % daysOfMonth;
	}
	if (this->month > 12) {
		this->year++;
		this->month = this->month % 12;
	}
}

int Date::dayOfYear() {
	int tempYear = this->year;
	int tempMonth = this->month;
	dayCount = this->day;

	if (tempMonth > 2 && tempYear % 4 == 0
		&& (tempYear % 100 != 0 || tempYear % 400 == 0)) {
		++dayCount;
	}

	while (tempMonth-- > 0) {
		dayCount = dayCount + days[tempMonth - 1];
	}
	return dayCount;
}

void Date::getDayOfTheWeek() {
	dayOfWeek = ((this->year - firstYear) * 365 + (this->year - firstYear) / 4 + dayOfYear()) % 7;
}

void Date::printDate() {
	switch (dayOfWeek) { //switch case за ден от седмицата
	case sunday:
		std::cout << "Sunday, ";
		break;
	case monday:
		std::cout << "Monday, ";
		break;
	case tuesday:
		std::cout << "Tuesday, ";
		break;
	case wednesday:
		std::cout << "Wednesday, ";
		break;
	case thursday:
		std::cout << "Thursday, ";
		break;
	case friday:
		std::cout << "Friday, ";
		break;
	case saturday:
		std::cout << "Saturday, ";
		break;
	default:
		std::cout << "Error day of the week!";
		break;
	}

	switch (month) { //switch case за дата
	case 1:
		std::cout << "January " << day << ", " << year << std::endl;
		break;
	case 2:
		std::cout << "February " << day << ", " << year << std::endl;
		break;
	case 3:
		std::cout << "March " << day << ", " << year << std::endl;
		break;
	case 4:
		std::cout << "April " << day << ", " << year << std::endl;
		break;
	case 5:
		std::cout << "May " << day << ", " << year << std::endl;
		break;
	case 6:
		std::cout << "June " << day << ", " << year << std::endl;
		break;
	case 7:
		std::cout << "July " << day << ", " << year << std::endl;
		break;
	case 8:
		std::cout << "August " << day << ", " << year << std::endl;
		break;
	case 9:
		std::cout << "September " << day << ", " << year << std::endl;
		break;
	case 10:
		std::cout << "October " << day << ", " << year << std::endl;
		break;
	case 11:
		std::cout << "November " << day << ", " << year << std::endl;
		break;
	case 12:
		std::cout << "December " << day << ", " << year << std::endl;
		break;
	default:
		std::cout << "Error month!";
		break;
	}
	
}
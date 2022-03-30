#include <iostream>

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() {
        hours = 0, minutes = 0, seconds = 0;
    }
    int compare(int hours, int minutes, int seconds);
    void getToMidnight() const;
    bool isDinnerTime();
    bool isPartyTime();
    void print(bool is12HoursClock);
    void getNewTime(int hours, int minutes, int seconds);
};

void Time::getNewTime(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

int Time::compare(int hours, int minutes, int seconds) {
    if (hours < this->hours) {
        if (minutes < this->minutes) {
            if (seconds < this->seconds) {
                Time::getNewTime(hours, minutes, seconds);
                return 1;
            }
            else if(seconds > this->seconds) {
                Time::getNewTime(hours, minutes, seconds);
                return -1;
            }
        }
        else if (minutes > this->minutes) {
            Time::getNewTime(hours, minutes, seconds);
            return -1;
        }
    }
    else if (hours > this->hours) {
        Time::getNewTime(hours, minutes, seconds);
        return -1;
    }
    Time::getNewTime(hours, minutes, seconds);
    return 0;
}

void Time::getToMidnight() const{
    int midNightH = 23 - hours, midNightM = 59 - minutes, midNightS = 60 - seconds;

    if (midNightH < 10) { std::cout << "Time until midnight: " << "0" << midNightH << ":"; }
    else { std::cout << "Time until midnight: " << midNightH << ":"; }

    if (midNightM < 10) { std::cout << "0" << midNightM << ":"; }
    else { std::cout << midNightM << ":"; }

    if (midNightS < 10) { std::cout << "0" << midNightS << std::endl; }
    else { std::cout << midNightS << std::endl; }
    //std::cout << "Time until midnight: " << midNightH << ":" << midNightM << ":" << midNightS << std::endl;
}

bool Time::isDinnerTime() {
    if (hours >= 20 && hours <= 22) {
        if ((hours == 20 && minutes >= 30) || (hours == 22 && minutes == 0)) {
            return true;
        }
        return true;
    }
    return false;
}

bool Time::isPartyTime() {
    if (hours == 23 || (hours >= 0 && hours <= 6)) {
        if ((hours == 23 || hours == 6) && minutes == 0) {
            return true;
        }
        return true;
    }
    return false;
}

void Time::print(bool is12HoursClock) {
    is12HoursClock = false;
    int tempAns = 0;
    std::cout << "How many hours does your clock have?";
    std::cin >> tempAns;
    if (tempAns == 12) {
        is12HoursClock = true;
    }
    else if(tempAns != 24) {
        std::cout << "This clock doesn't exist!" << std::endl;
        return;
    }

    if (is12HoursClock) {
        if (hours - 12 < 0) {
            if (hours < 10) { std::cout << "The time is " << "0" << hours << ":"; }
            else { std::cout << "The time is " << hours << ":"; }

            if (minutes < 10) { std::cout << "0" << minutes << ":"; }
            else { std::cout << minutes << ":"; }

            if (seconds < 10) { std::cout << "0" << seconds << "AM." << std::endl; }
            else { std::cout << seconds << std::endl; }
        }
        else {
            if (hours - 12< 10) { std::cout << "The time is " << "0" << hours << ":"; }
            else { std::cout << "The time is " << hours << ":"; }

            if (minutes < 10) { std::cout << "0" << minutes << ":"; }
            else { std::cout << minutes << ":"; }

            if (seconds < 10) { std::cout << "0" << seconds << "PM." << std::endl; }
            else { std::cout << seconds << std::endl; }
        }
    }
    else {
        if (hours < 10) { std::cout << "The time is " << "0" << hours << ":"; }
        else { std::cout << "The time is " << hours << ":"; }

        if (minutes < 10) { std::cout << "0" << minutes << ":"; }
        else { std::cout << minutes << ":"; }

        if (seconds < 10) { std::cout << "0" << seconds << std::endl; }
        else { std::cout << seconds << std::endl; }
    }
}


int main() {
    return 0;
}

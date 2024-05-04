#ifndef TIME_H
#define TIME_H
#include <iomanip>
#include <iostream>
#include <limits>

class Time {
    private:
        int _hour;
        int _minute;
        int _second;
        int compare(const Time& time);
        void rationalize();
    public:
        Time(int hour, int minute, int second);
        Time() : _hour(0), _minute(0), _second(0) {}
        int compare(const Time& time) const;
        Time operator+(const Time& time) const;
        Time& operator++(); // Pre-increment
        Time operator++(int); // Post-increment
        bool operator==(const Time& time) const;
        bool operator!=(const Time& time) const;
        bool operator<(const Time& time) const;
        bool operator>(const Time& time) const;
        bool operator<=(const Time& time) const;
        bool operator>=(const Time& time) const;
        friend std::ostream& operator<<(std::ostream& ost, const Time& time);
        friend std::istream& operator>>(std::istream& ist, Time& time);
};

#endif // TIME_H

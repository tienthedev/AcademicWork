#include "Time.h"

Time::Time(int hour, int minute, int second) : _hour{hour}, _minute{minute}, _second{second} {
    rationalize();
}
int Time::compare(const Time& time) const {
    if (_hour < time._hour) return -1;
    if (_hour > time._hour) return 1;
    if (_minute < time._minute) return -1;
    if (_minute > time._minute) return 1;
    if (_second < time._second) return -1;
    if (_second > time._second) return 1;
    return 0;
}
void Time::rationalize() {
    int totalSeconds = _hour * 3600 + _minute * 60 + _second;
    totalSeconds = (totalSeconds >= 0) ? totalSeconds : 0;
    _hour = (totalSeconds / 3600) % 24;
    _minute = (totalSeconds % 3600) / 60;
    _second = totalSeconds % 60;
}
Time Time::operator+(const Time& time) const {
    Time result{_hour + time._hour, _minute + time._minute, _second + time._second};
    result.rationalize();
    return result;
}
Time& Time::operator++() {
    _second++;
    rationalize();
    return *this;
}
Time Time::operator++(int) {
    Time result = *this;
    ++(*this); 
    return result;
}
bool Time::operator==(const Time& time) const {
    return compare(time) == 0;
}
bool Time::operator!=(const Time& time) const {
    return compare(time) != 0;
}
bool Time::operator<(const Time& time) const {
    return compare(time) < 0;
}
bool Time::operator>(const Time& time) const {
    return compare(time) > 0;
}
bool Time::operator<=(const Time& time) const {
    return compare(time) <= 0;
}
bool Time::operator>=(const Time& time) const {
    return compare(time) >= 0;
}
std::ostream& operator<<(std::ostream& ost, const Time& time) {
    ost << std::setfill('0') << std::setw(2) << time._hour << ":"
        << std::setfill('0') << std::setw(2) << time._minute << ":"
        << std::setfill('0') << std::setw(2) << time._second;
    return ost;
}
std::istream& operator>>(std::istream& ist, Time& time) {
    char separator;
    if (ist >> time._hour >> separator >> time._minute >> separator >> time._second) {
        time.rationalize();
    } else {
        ist.setstate(std::ios::failbit);
    }
    return ist;
}


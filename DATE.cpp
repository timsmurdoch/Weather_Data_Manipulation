#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(const unsigned Sday, const unsigned Smonth, const unsigned Syear)
{
    day = Sday;
    month = Smonth;
    year = Syear;
}

void Date::setDay(const unsigned Sday)
{
    day = Sday;
}

void Date::setMonth(const unsigned Smonth)
{
    month = Smonth;
}

void Date::setYear(const unsigned Syear)
{
    year = Syear;
}

unsigned Date::getDay() const
{
    return day;
}

unsigned Date::getMonth() const
{
    return month;
}

unsigned Date::getYear() const
{
    return year;
}

bool Date::operator == (const Date &D) const
{
    if(D.getDay() == day && D.getMonth() == month && D.getYear() == year)
        return true;
    else
        return false;
}

bool Date::operator < (const Date & D) const
{
    if(D.getYear() > year)
        return true;
    else if(D.getYear() < year)
        return false;
    else if(D.getMonth() > month)
        return true;
    else if(D.getMonth() < month)
        return false;
    else if(D.getDay() > day)
        return true;
    else if(D.getDay() < day)
        return false;
    else
        return false;
}

bool Date::operator > (const Date & D) const
{
    if(D.getYear() < year)
        return true;
    else if(D.getYear() > year)
        return false;
    else if(D.getMonth() < month)
        return true;
    else if(D.getMonth() > month)
        return false;
    else if(D.getDay() < day)
        return true;
    else if(D.getDay() > day)
        return false;
    else
        return false;
}

/*
istream & operator >>( istream & input, Date & D )
{
    string tempDay;
    string tempMonth;
    string tempYear;

    getline(input, tempDay, ',');
    getline(input, tempMonth, ',');
    getline(input, tempYear, ',');

    D.setDay(stoi(tempDay));
    D.setMonth(stoi(tempMonth));
    D.setYear(stoi(tempYear));

    return input;
}
ostream & operator <<( ostream & os, const Date & D )
{
    os << "  Date: " << D.getDay() << " / " << D.getMonth() << " / " << D.getYear() << '\n';

  return os;
}
*/

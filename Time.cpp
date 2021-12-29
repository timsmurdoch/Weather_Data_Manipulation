#include "Time.h"

Time::Time()
{
    hours = 0;
    minutes = 0;
}

Time::Time(const unsigned tHours, const unsigned tMinutes)
{
    hours = tHours;
    minutes = tMinutes;
}

void Time::setHour(const unsigned tHour)
{
    hours = tHour;
}

void Time::setMinutes(const unsigned tMinutes)
{
    minutes = tMinutes;
}

unsigned Time::getHour() const
{
    return hours;
}

unsigned Time::getMinutes() const
{
    return minutes;
}

bool Time::operator == (const Time &D) const
{
    if(D.getHour() == hours && D.getMinutes() == minutes)
        return true;
    else
        return false;
}

bool Time::operator < (const Time & D) const
{
    if(D.getHour() > hours)
        return true;
    else if(D.getHour() < hours)
        return false;
    else if(D.getMinutes() > minutes)
        return true;
    else if(D.getMinutes() < minutes)
        return false;
    else
        return false;
}

bool Time::operator > (const Time & D) const
{
    if(D.getHour() < hours)
        return true;
    else if(D.getHour() > hours)
        return false;
    else if(D.getMinutes() < minutes)
        return true;
    else if(D.getMinutes() > minutes)
        return false;
    else
        return false;
}

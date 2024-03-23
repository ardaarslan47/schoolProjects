#include "classes.h"

void employee::setStartingTime(myTime sTime, unsigned int day)
{
    if (day <= 30)
    {
        startingTime[day - 1] = sTime;
    }
}

void employee::setExitTime(myTime eTime, unsigned int day)
{
    if (day <= 30)
    {
        exitTime[day - 1] = eTime;
    }
}

myTime employee::getStartingTime(unsigned int day) const
{
    return startingTime[day - 1];
}

myTime employee::getExitTime(unsigned int day) const
{
    return exitTime[day - 1];
}
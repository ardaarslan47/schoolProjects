#include <cstring>

struct myTime
{
    int hour;
    int minute;
    int second;

    myTime()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    myTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
};

class employee
{
private:
    myTime *exitTime;
    myTime *startingTime;

public:
    char ID[11];
    employee(char id[11]);
    ~employee();

    void setStartingTime(myTime sTime, unsigned int day);
    void setExitTime(myTime eTime, unsigned int day);

    myTime getStartingTime(unsigned int day) const;
    myTime getExitTime(unsigned int day) const;
};

employee::employee(char id[11])
{
    std::strcpy(ID, id);

    exitTime = new myTime[30];
    startingTime = new myTime[30];

    for (int i = 0; i < 30; i++)
    {
        exitTime[i] = myTime();
        startingTime[i] = myTime();
    }
}

employee::~employee()
{
    delete[] exitTime;
    delete[] startingTime;
}
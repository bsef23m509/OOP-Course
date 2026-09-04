#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time()
    {
        this->setHours(0);
        this->setMinutes(0);
        this->setSeconds(0);
    }

    Time(int h, int m, int s)
    {
        this->setHours(h);
        this->setMinutes(m);
        this->setSeconds(s);
    }

    int getHours()
    {
        return hours;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getSeconds()
    {
        return seconds;
    }

    void setHours(int hours)
    {
        if (hours >= 0 && hours <= 23)
            this->hours = hours;
    }

    void setMinutes(int minutes)
    {
        if (minutes >= 0 && minutes <= 60)
            this->minutes = minutes;
    }

    void setSeconds(int seconds)
    {
        if (seconds >= 0 && seconds <= 60)
            this->seconds = seconds;
    }

    void setTime()
    {
        this->setHours(0);
        this->setMinutes(0);
        this->setSeconds(0);
    }

    void incHours(int hours)
    {
        int h = (this->hours + hours) % 24;

        // cout << h << endl;

        if (this->hours + hours > 23)
            this->setHours(h);
        else
            this->setHours(this->hours + hours);
    }

    void incMinutes(int minutes)
    {
        int m = minutes % 60;
        int h = (this->minutes + m) / 60;

        // cout << m << " " << h << endl;

        if (this->minutes + m > 60)
            this->setMinutes((this->minutes + m) % 60);
        else
            this->setMinutes(this->minutes + m);

        this->incHours(h);
    }

    void incSeconds(int seconds)
    {
        int s = seconds % 60;
        int m = ((seconds) / 60) + 1;
        int h = (this->minutes + m) / 60;

        // cout << s << " " << m << " " << h << endl;

        if (this->seconds + s > 60)
            this->setSeconds((this->seconds + s) % 60);
        else
            this->setSeconds(this->seconds + s);

        this->incMinutes(m);
        this->incHours(h);
    }

    void printTwentyFourHourFormat()
    {
        cout << hours << ":" << minutes % 60 << ":" << seconds % 60 << endl;
    }

    void printTwelveHourFormat()
    {
        if (hours == 0 || hours == 12)
        {
            cout << 12 << ":" << minutes % 60 << ":" << seconds % 60 << " AM" << endl;
        }

        else if (hours < 12)
        {
            cout << hours << ":" << minutes % 60 << ":" << seconds % 60 << " AM" << endl;
        }
        else
            cout << hours % 12 << ":" << minutes % 60 << ":" << seconds % 60 << " PM" << endl;
    }
};

int main()
{
    Time t;

    t = Time();

    int h, m, s;

    do
    {
        cout << "Enter Hours (Greater then -1 and less then 24): ";
        cin >> h;
    } while (h < 0 || h > 23);

    cout << endl;

    do
    {
        cout << "Enter Minutes (Greater then -1 and less then 61): ";
        cin >> m;
    } while (m < 0 || m > 60);

    cout << endl;

    do
    {
        cout << "Enter Seconds (Greater then -1 and less then 61): ";
        cin >> s;
    } while (s < 0 || s > 60);

    t.setHours(h);
    t.setMinutes(m);
    t.setSeconds(s);

    cout << "-----------------------------" << endl;
    cout << "Time: " << endl;
    t.printTwelveHourFormat();
    t.printTwentyFourHourFormat();

    cout << "After incrimenting 70 seconds: " << endl;
    t.incSeconds(1);
    t.printTwelveHourFormat();
    t.printTwentyFourHourFormat();

    cout << "After incrimenting 6 minutes: " << endl;
    t.incMinutes(1);
    t.printTwelveHourFormat();
    t.printTwentyFourHourFormat();

    cout << "After incrimenting 10 hours: " << endl;
    t.incHours(1);
    t.printTwelveHourFormat();
    t.printTwentyFourHourFormat();

    return 0;
}
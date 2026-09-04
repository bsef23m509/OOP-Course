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
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    Time(int hours, int minutes, int seconds)
    {
        this->setTime(hours, minutes, seconds);
    }

    void setHours(int hours)
    {
        if (hours <= 23 && hours >= 0)
            this->hours = hours;
        else
            this->hours = 0;
    }
    void setMinutes(int minutes)
    {
        if (minutes <= 60 && minutes >= 0)
            this->minutes = minutes;
        else
            this->minutes = 0;
    }
    void setSeconds(int seconds)
    {
        if (seconds <= 60 && seconds >= 0)
            this->seconds = seconds;
        else
            this->hours = 0;
    }
    void setTime(int hours, int minutes, int seconds)
    {
        this->setHours(hours);
        this->setMinutes(minutes);
        this->setSeconds(seconds);
    }

    int getHours()
    {
        return this->hours;
    }
    int getMinutes()
    {
        return this->minutes;
    }
    int getSeconds()
    {
        return this->seconds;
    }

    void printTwentyFourHourFormat()
    {
        if (this->hours < 10)
            cout << 0 << this->hours << ":";
        else
            cout << this->hours << ":";

        if (this->minutes < 10)
            cout << 0 << this->minutes << ":";
        else
            cout << this->minutes << ":";

        if (this->seconds < 10)
            cout << 0 << this->seconds;
        else
            cout << this->seconds;

        cout << endl;
    }

    void incHours(int hours)
    {
        int h = (this->hours + hours) % 24;

        if (this->hours + hours > 23)
            this->setHours(h);
        else
            this->setHours(this->hours + hours);
    }

    void incMinutes(int minutes)
    {
        int m = minutes % 60;
        int h = (this->minutes + m) / 60;

        if (this->minutes + m >= 60)
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

        if (this->seconds + s >= 60)
            this->setSeconds((this->seconds + s) % 60);
        else
            this->setSeconds(this->seconds + s);

        this->incMinutes(m);
        this->incHours(h);
    }

    bool operator==(Time &other)
    {
        if (this->hours == other.hours &&
            this->minutes == other.minutes &&
            this->seconds == other.seconds)
            return true;
        else
            return false;
    }

    bool operator!=(Time &other)
    {
        if (this->hours == other.hours &&
            this->minutes == other.minutes &&
            this->seconds == other.seconds)
            return false;
        else
            return true;
    }

    bool operator>(Time &other)
    {
        if (this->seconds > other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->minutes > other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->hours > other.hours)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(Time &other)
    {
        if (this->seconds < other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->minutes < other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->hours < other.hours)
        {
            return true;
        }
        else
            return false;
    }

    bool operator>=(Time &other)
    {
        if (this->seconds >= other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->minutes >= other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->hours >= other.hours)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(Time &other)
    {
        if (this->seconds <= other.seconds && this->minutes == other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->minutes <= other.minutes && this->hours == other.hours)
        {
            return true;
        }
        else if (this->hours <= other.hours)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Time operator+(Time &other)
    {
        Time ans;

        ans.setSeconds((this->seconds + other.seconds) % 60);
        if ((this->seconds + other.seconds) >= 60)
        {
            ans.incMinutes(1);
        }

        if ((this->minutes + other.minutes + ans.minutes) >= 60)
        {
            ans.incHours(1);
        }
        ans.setMinutes((this->minutes + other.minutes + ans.minutes) % 60);

        ans.setHours((this->hours + other.hours + ans.hours) % 24);

        return ans;
    }

    Time operator-(Time &other)
    {
        Time ans;

        if (this->hours - other.hours < 0)
        {
            cout << "Not Possible. Hours greater of second object" << endl;
            return ans;
        }
        else
        {
            ans.setHours(this->hours - other.hours);
        }

        if ((this->minutes - other.minutes) < 0)
        {
            ans.setHours(ans.getHours() - 1);
            ans.setMinutes((this->minutes - other.minutes) + 60);
        }
        else
        {
            ans.setMinutes((this->minutes - other.minutes));
        }

        if ((this->seconds - other.seconds) < 0)
        {
            ans.setMinutes(ans.getMinutes() - 1);
            ans.setSeconds((this->seconds - other.seconds + 60));
        }
        else
        {
            ans.setSeconds((this->seconds - other.seconds));
        }
        return ans;
    }
};

int main()
{

    Time t1(22, 29, 35), t2(0, 29, 35);

    Time t3 = t1 + t2;
    t3.printTwentyFourHourFormat();

    Time t4 = t3 - t2;
    t4.printTwentyFourHourFormat();

    return 0;
}
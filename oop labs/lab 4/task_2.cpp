#include <iostream>
using namespace std;

class Date
{
private:
    int date;
    int month;
    int year;

    string giveMonth(int month)
    {
        if (month == 1)
            return "January";
        else if (month == 2)
            return "February";
        else if (month == 3)
            return "March";
        else if (month == 4)
            return "April";
        else if (month == 5)
            return "May";
        else if (month == 6)
            return "June";
        else if (month == 7)
            return "July";
        else if (month == 8)
            return "August";
        else if (month == 9)
            return "September";
        else if (month == 10)
            return "October";
        else if (month == 11)
            return "November";
        else
            return "December";
    }

public:
    int getDate()
    {
        return date;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    void setDate(int date)
    {
        if (date >= 1 && date <= 31)
            this->date = date;
    }

    void setMonth(int month)
    {
        if (month >= 1 && month <= 12)
            this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    void printDateFormat1()
    {
        cout << date << "/" << month << "/" << year << endl;
    }

    void printDateFormat2()
    {
        cout << giveMonth(month) << " " << date << ", " << year << endl;
    }

    void printDateFormat3()
    {
        cout << date << " " << giveMonth(month) << " " << year << endl;
    }
};

int main()
{
    Date d;

    int date, month, year;

    do
    {
        cout << "Enter Date (Greater then 0 and less then or equal to 31): ";
        cin >> date;
    } while (date < 1 || date > 31);
    cout << endl;

    do
    {
        cout << "Enter Month (Greater then 0 and less then or equal to 12): ";
        cin >> month;
    } while (month < 1 || month > 12);
    cout << endl;

    cout << "Enter Year: ";
    cin >> year;
    cout << endl;

    d.setDate(date);
    d.setMonth(month);
    d.setYear(year);

    d.setDate(100);
    d.setMonth(-1);

    d.printDateFormat1();
    d.printDateFormat2();
    d.printDateFormat3();

    return 0;
}
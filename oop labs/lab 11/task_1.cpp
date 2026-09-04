#include <iostream>
using namespace std;

class PhoneCall
{
private:
    string callerNo;
    int duration;
    float rateCharged;

public:
    PhoneCall()
    {
        this->callerNo = "";
        this->duration = 0;
        this->rateCharged = 0.0;
    }

    PhoneCall(string callerNo, int duration, float rateCharged)
    {
        this->callerNo = callerNo;
        this->duration = duration;
        this->rateCharged = rateCharged;
    }

    string getCallerNo()
    {
        return this->callerNo;
    }
    void setCallerNo(string callerNo)
    {
        this->callerNo = callerNo;
    }

    int getDuration()
    {
        return this->duration;
    }
    void setDuration(int duration)
    {
        this->duration = duration;
    }

    float getRateCharged()
    {
        return this->rateCharged;
    }
    void setRateCharged(float rateCharged)
    {
        this->rateCharged = rateCharged;
    }

    friend ostream &operator<<(ostream &out, const PhoneCall obj)
    {
        out << "Caller No: " << obj.callerNo << endl;
        out << "Duration: " << obj.duration << " minutes" << endl;
        out << "Rate Charged: " << obj.rateCharged << " / minutes" << endl;

        return out;
    }

    friend istream &operator>>(istream &in, PhoneCall &obj)
    {

        string callerNo;
        int dur;
        float rc;

        cout << "Enter Caller No: ";
        in >> callerNo;
        cout << "Enter Duration: ";
        in >> dur;
        cout << "Enter Rate Charged: ";
        in >> rc;

        obj.setCallerNo(callerNo);
        obj.setDuration(dur);
        obj.setRateCharged(rc);

        return in;
    }

    bool operator==(PhoneCall &other)
    {
        return this->callerNo == other.callerNo;
    }

    bool operator>(PhoneCall &other)
    {
        return this->duration > other.duration;
    }

    int operator+(PhoneCall &other)
    {
        return this->duration + other.duration;
    }

    operator int()
    {
        return this->duration;
    }

    operator double()
    {
        return this->rateCharged;
    }
};

int main()
{

    PhoneCall p1, p2("03335967989", 1, 1.45);
    cin >> p1;
    cout << (p1 == p2) << endl;
    cout << (p1 > p2) << endl;
    cout << (p1 + p2) << endl;

    int num = p1;
    double db = p1;

    cout << num << " " << db << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Measurement
{
private:
    int feet;
    float inches;
    static int objCount;

public:
    Measurement()
    {
        this->feet = 0;
        this->inches = 0.0;
        this->objCount++;

        cout << "Object Count of this obj: " << objCount << endl;
    }

    Measurement(int feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
        this->objCount++;
        cout << "Object Count of this obj: " << objCount << endl;
    }

    ~Measurement()
    {
        this->objCount--;
    }

    void print()
    {
        cout << "Feet: " << this->feet << endl;
        cout << "Inches: " << this->inches << endl;
    }

    bool operator==(Measurement &other)
    {
        if (this->feet == other.feet && this->inches == other.inches)
            return true;
        else
            return false;
    }

    bool operator!=(Measurement &other)
    {
        if (this->feet == other.feet && this->inches == other.inches)
            return false;
        else
            return true;
    }

    bool operator>(Measurement &other)
    {
        if (this->inches > other.inches && this->feet == other.feet)
            return true;
        else if (this->feet > other.feet)
            return true;
        else
            return false;
    }

    bool operator>=(Measurement &other)
    {
        if (this->inches >= other.inches && this->feet == other.feet)
            return true;
        else if (this->feet >= other.feet)
            return true;
        else
            return false;
    }

    bool operator<(Measurement &other)
    {
        if (this->inches < other.inches && this->feet == other.feet)
            return true;
        else if (this->feet < other.feet)
            return true;
        else
            return false;
    }

    bool operator<=(Measurement &other)
    {
        if (this->inches <= other.inches && this->feet == other.feet)
            return true;
        else if (this->feet <= other.feet)
            return true;
        else
            return false;
    }

    Measurement operator+(Measurement &other)
    {
        Measurement ans;
        int f;

        ans.feet = this->feet + other.feet;
        if (this->inches + other.inches <= 12.0)
            ans.inches = this->inches + other.inches;
        else
        {
            f = (this->inches + other.inches) / 12.0;
            ans.inches = this->inches + other.inches;
            ans.inches -= (f * 12.0);
            ans.feet += f;
        }

        return ans;
    }

    Measurement operator-(Measurement &other)
    {
        Measurement ans;
        float t_f, o_f, total;

        t_f = this->feet * 12 + this->inches;
        o_f = other.feet * 12 + other.inches;
        total = t_f - o_f;

        // if (t_f < o_f)
        // {
        //     cout << "Not Possible" << endl;
        //     return ans;
        // }
        // else
        // {
        ans.feet = total / 12;
        while (total > 12.0)
        {
            total -= 12.0;
        }
        ans.inches = total;
        // }

        return ans;
    }

    Measurement operator*(int k)
    {
        Measurement ans;
        float total;

        total = (this->feet * 12 + this->inches) * k;

        ans.feet = total / 12;
        while (total > 12.0)
        {
            total -= 12.0;
        }
        ans.inches = total;

        return ans;
    }

    Measurement operator/(int k)
    {
        Measurement ans;
        float total;

        total = (this->feet * 12 + this->inches) / k;

        ans.feet = total / 12;
        while (total > 12.0)
        {
            total -= 12.0;
        }
        ans.inches = total;

        return ans;
    }
};

int Measurement::objCount = 0;

int main()
{

    Measurement m1(2, 3.0), m2(1, 2.0);

    Measurement m3 = m1 + m2;
    Measurement m4 = m3 - m2;

    m3.print();
    m4.print();

    Measurement m5 = m1 * 10;
    m5.print();
    Measurement m6 = m5 / 10;
    m6.print();

    return 0;
}
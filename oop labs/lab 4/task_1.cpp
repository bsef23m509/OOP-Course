#include <iostream>
using namespace std;

class Rational
{
private:
    int denominator;
    int numerator;

    int hcf(int num1, int num2)
    {
        while (num1 > 0)
        {
            if (num1 > num2)
                num1 = num1 - num2;
            else if (num2 > num1)
                num2 = num2 - num1;
            else
                break;
        }
        return num1;
    }

public:
    Rational()
    {
        denominator = 1;
        numerator = 1;
    }
    Rational(int denominator, int numerator)
    {
        this->denominator = denominator;
        this->numerator = numerator;
    }

    int getDenominator()
    {
        return denominator;
    }

    int getNumerator()
    {
        return numerator;
    }

    void setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    void setNumerator(int numerator)
    {
        this->numerator = numerator;
    }

    void printRational()
    {
        cout << numerator << " / " << denominator << endl;
    };

    Rational reduceRational()
    {

        Rational ans = Rational();

        int hcf = this->hcf(denominator, numerator);
        ans.setDenominator(denominator / hcf);
        ans.setNumerator(numerator / hcf);

        return ans;
    }
};

int main()
{
    Rational r1, r2;

    r1 = Rational();
    r1.printRational();

    r2 = Rational(2, 3);
    r2.printRational();

    r1.setDenominator(20);
    r1.setNumerator(40);

    r1.printRational();
    r2.printRational();

    Rational r3 = r2.reduceRational();
    r3.printRational();

    return 0;
}
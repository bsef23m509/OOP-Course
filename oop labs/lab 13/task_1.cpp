#include <iostream>
using namespace std;

class Employee
{

protected:
    string firstName;
    string lastName;
    int socialSecurityNum;
    float earning;

public:
    Employee()
    {
        this->firstName = "";
        this->lastName = "";
        this->socialSecurityNum = 0;
    }

    Employee(string firstName, string lastName, int socialSecurityNum)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->socialSecurityNum = socialSecurityNum;
    }

    Employee(Employee &other)
    {
        this->firstName = other.firstName;
        this->lastName = other.lastName;
        this->socialSecurityNum = other.socialSecurityNum;
    }

    virtual void display() = 0;

    virtual void setEarning() = 0;
};

class SalariedEmployee : public Employee
{

private:
    float weeklySalary;

public:
    SalariedEmployee() : Employee()
    {
        this->weeklySalary = 0;
    }

    SalariedEmployee(string firstName, string lastName, int socialSecurityNum, float weeklySalary)
        : Employee(firstName, lastName, socialSecurityNum)
    {
        this->weeklySalary = weeklySalary;
    }

    SalariedEmployee(SalariedEmployee &other) : Employee(other)
    {
        this->weeklySalary = other.weeklySalary;
    }

    float getWeeklySalary() { return this->weeklySalary; }
    void setWeeklySalary(float weeklySalary) { this->weeklySalary = weeklySalary; }

    void setEarning()
    {
        this->earning = this->weeklySalary;
    }

    void display()
    {
        cout << "Salaried Employee: " << this->firstName << " " << this->lastName << endl;
        cout << "social security number: " << this->socialSecurityNum << endl;
        cout << "Weekly Salary: " << this->weeklySalary << endl;
        cout << "Earning: " << this->earning << endl;
    }
};

class HourlyEmployee : public Employee
{

private:
    float wage;
    int hours;

public:
    HourlyEmployee() : Employee()
    {
        this->wage = 0;
        this->hours = 0;
    }

    HourlyEmployee(string firstName, string lastName, int socialSecurityNum, float wage, int hours)
        : Employee(firstName, lastName, socialSecurityNum)
    {
        this->wage = wage;
        this->hours = hours;
    }

    HourlyEmployee(HourlyEmployee &other) : Employee(other)
    {
        this->wage = other.wage;
        this->hours = other.hours;
    }

    float getWage() { return this->wage; }
    void setWage(int wage) { this->wage = wage; }

    int getHours() { return this->hours; }
    void setHours(int hours) { this->hours = hours; }

    void setEarning()
    {
        if (this->hours <= 40)
            this->earning = this->wage * this->hours;
        else
            this->earning = (40 * this->wage) + ((hours - 40) * (this->wage * 1.5));
    }

    void display()
    {
        cout << "Hourly Employee: " << this->firstName << " " << this->lastName << endl;
        cout << "social security number: " << this->socialSecurityNum << endl;
        cout << "Hourly Wage: " << this->getWage() << "; " << "Hours Worked: " << this->getHours() << endl;
        cout << "Earning: " << this->earning << endl;
    }
};

class CommissionEmployee : public Employee
{

protected:
    float commissionRate;
    float grossSales;

public:
    CommissionEmployee() : Employee()
    {
        this->commissionRate = 0;
        this->grossSales = 0;
    }

    CommissionEmployee(string firstName, string lastName, int socialSecurityNum, float commissionRate, float grossSales)
        : Employee(firstName, lastName, socialSecurityNum)
    {
        this->commissionRate = commissionRate;
        this->grossSales = grossSales;
    }

    CommissionEmployee(CommissionEmployee &other) : Employee(other)
    {
        this->commissionRate = other.commissionRate;
        this->grossSales = other.grossSales;
    }

    float getCommissionRate() { return this->commissionRate; }
    void setCommissionRate(float commissionRate) { this->commissionRate = commissionRate; }

    float getGrossSales() { return this->grossSales; }
    void setGrossSales(float grossSales) { this->grossSales = grossSales; }

    void setEarning()
    {
        this->earning = this->commissionRate * this->grossSales;
    }

    void display()
    {
        cout << "Commission Employee: " << this->firstName << " " << this->lastName << endl;
        cout << "social security number: " << this->socialSecurityNum << endl;
        cout << "Gross Sales: " << this->grossSales << endl;
        cout << "Commission Rate: " << this->commissionRate << endl;
        cout << "Earning: " << this->earning << endl;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    float baseSalary;

public:
    BasePlusCommissionEmployee() : CommissionEmployee()
    {
        this->baseSalary = 0;
    }

    BasePlusCommissionEmployee(string firstName, string lastName, int socialSecurityNum, float commissionRate, float grossSales, float baseSalary)
        : CommissionEmployee(firstName, lastName, socialSecurityNum, commissionRate, grossSales)
    {
        this->baseSalary = baseSalary;
    }

    BasePlusCommissionEmployee(BasePlusCommissionEmployee &other) : CommissionEmployee(other)
    {
        this->baseSalary = other.baseSalary;
    }

    float getBaseSalary() { return this->baseSalary; }
    void setBaseSalary(float baseSalary) { this->baseSalary = baseSalary; }

    void setEarning()
    {
        this->earning = (this->commissionRate * this->grossSales) + this->baseSalary;
    }

    void display()
    {
        cout << "Base Salaried Commission Employee: " << this->firstName << " " << this->lastName << endl;
        cout << "social security number: " << this->socialSecurityNum << endl;
        cout << "Gross Sales: " << this->grossSales << endl;
        cout << "Commission Rate: " << this->commissionRate << endl;
        cout << "Base Salary: " << this->baseSalary << endl;
        cout << "Earning: " << this->earning << endl;
    }
};

int main()
{

    Employee *employees[10];

    employees[0] = new SalariedEmployee("one", "salaried", 1, 50.0);
    employees[1] = new SalariedEmployee("two", "salaried", 2, 50.0);

    employees[2] = new HourlyEmployee("one", "hourly", 3, 20.0, 10);
    employees[3] = new HourlyEmployee("two", "hourly", 4, 20.0, 50);

    employees[4] = new CommissionEmployee("one", "commission", 5, 20.0, 100.0);
    employees[5] = new CommissionEmployee("two", "commission", 6, 10.0, 300.0);

    employees[6] = new BasePlusCommissionEmployee("one", "baseCommission", 7, 20.0, 100.0, 20.0);
    employees[7] = new BasePlusCommissionEmployee("two", "baseCommission", 8, 10.0, 300.0, 20.0);

    employees[8] = new SalariedEmployee("three", "salaried", 9, 30.0);
    employees[9] = new BasePlusCommissionEmployee("three", "baseCommission", 10, 5.0, 700.0, 20.0);

    for (int i = 0; i < 10; i++)
    {
        employees[i]->setEarning();
        employees[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete employees[i];
    }

    return 0;
}
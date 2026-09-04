#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string name;
    double salary;

public:
    Employee()
    {
        this->setEmployeeID(0);
        this->setName("");
        this->setSalary(0.0);
    }

    Employee(int employeeID, string name, double salary)
    {
        this->setEmployeeID(employeeID);
        this->setName(name);
        this->setSalary(salary);
    }

    Employee(Employee &other)
    {
        this->setEmployeeID(other.employeeID);
        this->setName(other.name);
        this->setSalary(other.salary);
    }

    ~Employee() {}

    void setEmployeeID(int employeeID) { this->employeeID = employeeID; }
    void setName(string name) { this->name = name; }
    void setSalary(double salary) { this->salary = salary; }

    int getEmployeeID() { return this->employeeID; }
    string getName() { return this->name; }
    double getSalary() { return this->salary; }

    virtual void displayEmployeeInfo() {}
};

class Manager : public Employee
{
public:
    Manager()
    {
        this->setEmployeeID(0);
        this->setName("");
        this->setSalary(0.0);
    }

    Manager(int employeeID, string name, double salary)
    {
        this->setEmployeeID(employeeID);
        this->setName(name);
        this->setSalary(salary);
    }

    Manager(Manager &other)
    {
        this->setEmployeeID(other.getEmployeeID());
        this->setName(other.getName());
        this->setSalary(other.getSalary());
    }

    void displayEmployeeInfo()
    {
        cout << "Manager Information: " << endl;
        cout << "ID: " << this->getEmployeeID() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Salary: " << this->getSalary() << endl;
    }
};

class Developer : public Employee
{
public:
    Developer()
    {
        this->setEmployeeID(0);
        this->setName("");
        this->setSalary(0.0);
    }

    Developer(int employeeID, string name, double salary)
    {
        this->setEmployeeID(employeeID);
        this->setName(name);
        this->setSalary(salary);
    }

    Developer(Developer &other)
    {
        this->setEmployeeID(other.getEmployeeID());
        this->setName(other.getName());
        this->setSalary(other.getSalary());
    }

    void displayEmployeeInfo()
    {
        cout << "Developer Information: " << endl;
        cout << "ID: " << this->getEmployeeID() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Salary: " << this->getSalary() << endl;
    }
};

class Intern : public Employee
{
public:
    Intern()
    {
        this->setEmployeeID(0);
        this->setName("");
        this->setSalary(0.0);
    }

    Intern(int employeeID, string name, double salary)
    {
        this->setEmployeeID(employeeID);
        this->setName(name);
        this->setSalary(salary);
    }

    Intern(Intern &other)
    {
        this->setEmployeeID(other.getEmployeeID());
        this->setName(other.getName());
        this->setSalary(other.getSalary());
    }

    void displayEmployeeInfo()
    {
        cout << "Intern Information: " << endl;
        cout << "ID: " << this->getEmployeeID() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Salary: " << this->getSalary() << endl;
    }
};

int main()
{
    Employee *e1 = new Manager(1, "Adil", 1.1);
    Employee *e2 = new Developer(2, "Abdullah", 1.1);
    Employee *e3 = new Intern(3, "Ali", 1.1);

    e1->displayEmployeeInfo();
    cout << "------------------" << endl;
    e2->displayEmployeeInfo();
    cout << "------------------" << endl;
    e3->displayEmployeeInfo();

    delete e1;
    delete e2;
    delete e3;

    return 0;
}
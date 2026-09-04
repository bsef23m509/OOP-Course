#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    int employeeId;

public:
    Employee()
    {
        this->name = "";
        this->employeeId = 0;
    }

    Employee(string name, int employeeId)
    {
        this->name = name;
        this->employeeId = employeeId;
    }

    virtual void display() = 0;
};

class Manager : public Employee
{
protected:
    int teamSize;

public:
    Manager()
    {
        this->teamSize = 0;
    }

    Manager(string name, int employeeId, int teamSize) : Employee(name, employeeId)
    {
        this->teamSize = teamSize;
    }

    void display()
    {
        cout << "Manager Information: " << endl;
        cout << "Name: " << this->name << endl;
        cout << "Id: " << this->employeeId << endl;
        cout << "TeamSize: " << this->teamSize << endl;
    }
};

class Developer : public Employee
{
protected:
    string programmingLanguage;

public:
    Developer()
    {
        this->programmingLanguage = "";
    }

    Developer(string name, int employeeId, string programmingLanguage) : Employee(name, employeeId)
    {
        this->programmingLanguage = programmingLanguage;
    }

    void display()
    {
        cout << "Developer Information: " << endl;
        cout << "Name: " << this->name << endl;
        cout << "Id: " << this->employeeId << endl;
        cout << "Programming Language: " << this->programmingLanguage << endl;
    }
};

class TeamLead : public Developer, public Manager
{
public:
    TeamLead() {}

    TeamLead(string name, int employeeId, int teamSize, string programmingLanguage)
        : Developer(name, employeeId, programmingLanguage),
          Manager(name, employeeId, teamSize) {}

    void display()
    {
        cout << "TeamLead Information: " << endl;
        cout << "Name: " << this->Developer::name << endl;
        cout << "Id: " << this->Developer::employeeId << endl;
        cout << "Programming Language: " << this->programmingLanguage << endl;
        cout << "TeamSize: " << this->teamSize << endl;
    }
};

int main()
{
    TeamLead e4("Adil", 1, 4, "TS");
    e4.display();

    return 0;
}
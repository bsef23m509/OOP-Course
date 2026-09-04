#include <iostream>
using namespace std;
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Department.h"
#include "../header/Department.h"

// constructors

Department::Department()
{
    this->ID = 0;
    this->name = CharString();

    this->employeeCount = 0;

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        this->employees[i] = NULL;
}

Department::Department(int ID, CharString name)
{
    this->ID = ID;
    this->name.copyFrom(name);

    this->employeeCount = 0;

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        this->employees[i] = NULL;
}

// member functions

void Department::diisplayDepartmentInfo()
{
    cout << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Name: " << this->getName().getCstr() << endl;
    cout << "No. of employees: " << this->getEmployeeCount() << endl;
    // cout << endl;
}

void Department::displayAllEmployee()
{
    if (this->getEmployeeCount() == 0)
    {
        cout << "No employees in the department" << endl;
    }
    else
    {
        cout << "No. of employees: " << this->getEmployeeCount() << endl;

        for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        {
            if (this->employees[i] != NULL)
            {
                this->employees[i]->displayEmployeeInfo();
            }
        }
    }
}

bool Department::addEmployee(Employee *employee)
{
    if (!employee || this->employeeCount >= this->MAX_EMPLOYEES)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] == NULL)
        {
            this->employees[i] = employee;
            this->employees[i]->setAssignedToDept(true);
            this->employees[i]->setDept(this);
            this->employeeCount++;
            return true;
        }
    }
    return false;
}

bool Department::removeEmployee(int employeeID)
{
    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] != NULL)
        {
            if (this->employees[i]->getID() == employeeID)
            {
                this->employees[i]->setAssignedToDept(false);
                this->employees[i]->setDept(NULL);
                this->employees[i] = NULL;
                this->employeeCount--;
                return true;
            }
        }
    }
    return false;
}

// getters

int Department::getID() const
{
    return this->ID;
}

int Department::getEmployeeCount() const
{
    return this->employeeCount;
}

CharString Department::getName()
{
    CharString ans;
    ans.copyFrom(this->name);
    return ans;
}
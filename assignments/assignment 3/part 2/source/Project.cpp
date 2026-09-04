#include <iostream>
using namespace std;
#include "../header/Project.h"
#include "../header/Employee.h"

// constructors

Project::Project()
{
    this->ID = 0;
    this->projectDescription = CharString();
    this->employeeCount = 0;

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        this->employees[i] = NULL;
}

Project::Project(int ID, CharString description)
{
    this->ID = ID;
    this->projectDescription.copyFrom(description);
    this->employeeCount = 0;

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        this->employees[i] = NULL;
}

// getters

int Project::getID() const
{
    return this->ID;
}

int Project::getEmployeeCount() const
{
    return this->employeeCount;
}

CharString Project::getProjectDescription()
{
    CharString ans;
    ans.copyFrom(this->projectDescription);
    return ans;
}

// member functions

void Project::incrementEmployeeCount()
{
    this->employeeCount++;
}

void Project::decrementEmployeeCount()
{
    this->employeeCount--;
}

void Project::diisplayProjectInfo()
{
    cout << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Description: " << this->getProjectDescription().getCstr() << endl;
    cout << "No of employees: " << this->getEmployeeCount() << endl;
    // cout << endl;
}

void Project::displayAllEmployees()
{
    if (this->getEmployeeCount() == 0)
    {
        cout << "No employees working on this project" << endl;
    }
    else
    {
        cout << "No. of employees working on this project: " << this->getEmployeeCount() << endl;

        for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        {
            if (this->employees[i] != NULL)
            {
                this->employees[i]->displayEmployeeInfo();
            }
        }
    }
}

bool Project::assignToEmployee(Employee *employee)
{
    if (this->getEmployeeCount() >= MAX_EMPLOYEES || !employee)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] == NULL)
        {
            this->employees[i] = employee;
            this->employeeCount++;
            return true;
        }
    }

    return false;
}

bool Project::unAssignEmployee(int employeeID)
{
    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] != NULL)
        {
            if (this->employees[i]->getID() == employeeID)
            {
                this->employees[i] = NULL;
                this->employeeCount--;
                return true;
            }
        }
    }
    return false;
}
#include <iostream>
using namespace std;
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Employee.h"
#include "../header/Project.h"
#include "../header/Department.h"

// constructors

Employee::Employee()
{
    this->ID = 0;
    this->name = CharString();
    this->setSalary(1.0);

    this->permanentAddress = Address();

    this->projectCount = 0;

    this->department = NULL;
    this->setAssignedToDept(false);

    for (int i = 0; i < this->MAX_PROJECTS; i++)
        this->projects[i] = NULL;
}

Employee::Employee(int ID, CharString name, float salary, Address permanentAddr)
{
    this->ID = ID;
    this->name.copyFrom(name);
    this->setSalary(salary);

    this->permanentAddress.setHouseNo(permanentAddr.getHouseNo());
    this->permanentAddress.setStreetNo(permanentAddr.getStreetNo());
    this->permanentAddress.setBlock(permanentAddr.getBlock());
    this->permanentAddress.setCity(permanentAddr.getCity());

    this->projectCount = 0;

    this->department = NULL;
    this->setAssignedToDept(false);

    for (int i = 0; i < this->MAX_PROJECTS; i++)
        this->projects[i] = NULL;
}

// member functions

void Employee::displayEmployeeInfo()
{
    cout << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Name: " << this->getName().getCstr() << endl;
    cout << "Salary: " << this->getSalary() << endl;
    cout << "No. of projects working on: " << this->getProjectCount() << endl;

    if (this->getDept() != NULL)
    {
        cout << "Department info" << endl;
        this->getDept()->diisplayDepartmentInfo();
    }
    else
        cout << "Currently in no department" << endl;

    this->getPermanentAddress().diisplayAddress();
    // cout << endl;
}

void Employee::displayAllProjects()
{
    if (this->getProjectCount() == 0)
    {
        cout << "Working on no projects" << endl;
    }
    else
    {
        cout << "No. of projects working on: " << this->getProjectCount() << endl;

        for (int i = 0; i < this->MAX_PROJECTS; i++)
        {
            if (this->projects[i] != NULL)
            {
                this->projects[i]->diisplayProjectInfo();
            }
        }
    }
}

bool Employee::addProject(Project *project)
{

    if (this->getProjectCount() >= this->MAX_PROJECTS || !project)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_PROJECTS; i++)
    {
        if (this->projects[i] == NULL)
        {
            bool success = project->assignToEmployee(this);
            if (!success)
            {
                return false;
            }
            this->projects[i] = project;
            this->projectCount++;
            return true;
        }
    }

    return false;
}

bool Employee::removeProject(int projectID)
{
    for (int i = 0; i < this->MAX_PROJECTS; i++)
    {
        if (this->projects[i] != NULL)
        {
            if (this->projects[i]->getID() == projectID)
            {
                bool success = this->projects[i]->unAssignEmployee(this->getID());
                if (!success)
                {
                    return false;
                }
                this->projects[i] = NULL;
                this->projectCount--;
                return true;
            }
        }
    }
    return false;
}

// setters

void Employee::setAssignedToDept(bool value)
{
    this->assignedToDept = value;
}

void Employee::setDept(Department *dept)
{
    this->department = dept;
}

void Employee::setSalary(float salary)
{
    if (salary > 0)
        this->salary = salary;
}

float Employee::getSalary() const
{
    return this->salary;
}

// getters

int Employee::getID() const
{
    return this->ID;
}

int Employee::getProjectCount() const
{
    return this->projectCount;
}

CharString Employee::getName()
{
    CharString ans;
    ans.copyFrom(this->name);
    return ans;
}

bool Employee::getAssignedToDept() const
{
    return this->assignedToDept;
}

Address Employee::getPermanentAddress()
{
    Address addr;
    addr.setHouseNo(this->permanentAddress.getHouseNo());
    addr.setStreetNo(this->permanentAddress.getStreetNo());
    addr.setBlock(this->permanentAddress.getBlock());
    addr.setCity(this->permanentAddress.getCity());
    return addr;
}

Department *Employee::getDept() const
{
    return this->department;
}

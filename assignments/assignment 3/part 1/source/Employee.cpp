#include <iostream>
using namespace std;
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Employee.h"


Employee::Employee(int houseNo, CharString name, Address permanentAddr) {}
void Employee::diisplayEmployeeInfo() {}
void Employee::displayAllProject() {}
bool Employee::addProject(Project *project) {}
bool Employee::removeProject(int projectID) {}

void Employee::setAssignedToDept(bool value)
{
    this->assignedToDept = value;
}

int Employee::getID()
{
    return this->ID;
}

int Employee::getProjectCount()
{
    return this->projectCount;
}

CharString Employee::getName()
{
    return this->name;
}

bool Employee::getAssignedToDept()
{
    return this->assignedToDept;
}


Address Employee::getPermanentAddress()
{
    return this->permanentAddress;
}
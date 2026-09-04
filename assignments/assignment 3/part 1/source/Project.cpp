#include <iostream>
using namespace std;
#include "../header/Project.h"

Project::Project(int ID, CharString description)
{
    this->ID = ID;
    this->projectDescription.copyFrom(description);
    this->employeeCount = 0;
}

int Project::getID()
{
    return this->ID;
}

int Project::getEmployeeCount()
{
    return this->employeeCount;
}

CharString Project::getProjectDescription()
{
    return this->projectDescription;
}

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
    cout << "Project Information" << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Description: " << *(this->getProjectDescription().getCstr()) << endl;
    cout << "No of employees: " << this->getEmployeeCount() << endl;
    cout << endl;
}
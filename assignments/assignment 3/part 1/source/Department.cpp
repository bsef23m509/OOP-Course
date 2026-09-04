#include <iostream>
using namespace std;
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Department.h"
#include "../header/Department.h"


Department::Department(int ID, CharString name) {}
void Department::diisplayDepartmentInfo() {}
void Department::displayAllEmployee() {}
bool Department::addEmployee(Employee *employee) {}
bool Department::removeEmployee(int employeeID) {}

int Department::getID()
{
    return this->ID;
}

int Department::getEmployeeCount()
{
    return this->employeeCount;
}

CharString Department::getName()
{
    return this->name;
}
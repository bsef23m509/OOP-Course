#pragma once
#include "./CharString.h"
#include "./Address.h"
#include "./Project.h"
#include "./Employee.h"

class Department
{
private:
    int ID;
    CharString name;
    Employee *employees[3];
    int employeeCount;

public:

    Department(int ID, CharString name);
    void diisplayDepartmentInfo();
    void displayAllEmployee();
    bool addEmployee(Employee *employee);
    bool removeEmployee(int employeeID);

    int getID();
    int getEmployeeCount();
    CharString getName();
};

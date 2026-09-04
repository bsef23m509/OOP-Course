#pragma once
#include "./CharString.h"
#include "./Address.h"
#include "./Project.h"
#include "./Employee.h"

class Employee;

class Department
{
private:
    static const int MAX_EMPLOYEES = 20;

    int ID;
    CharString name;
    Employee *employees[MAX_EMPLOYEES];
    int employeeCount;

public:
    // constructors

    Department();
    Department(int ID, CharString name);

    // member functions

    void diisplayDepartmentInfo();
    void displayAllEmployee();
    bool addEmployee(Employee *employee);
    bool removeEmployee(int employeeID);

    // getters

    int getID() const;
    int getEmployeeCount() const;
    CharString getName();
};

#pragma once
#include "./CharString.h"
#include "./Employee.h"

class Employee;

class Project
{
private:
    static const int MAX_EMPLOYEES = 10;

    int ID;
    int employeeCount;
    Employee *employees[MAX_EMPLOYEES];
    CharString projectDescription;

public:
    // constructors

    Project();
    Project(int ID, CharString description);

    // member functions

    void diisplayProjectInfo();
    void displayAllEmployees();

    void incrementEmployeeCount();
    void decrementEmployeeCount();

    bool assignToEmployee(Employee *newEmployee);
    bool unAssignEmployee(int employeeID);

    // getters
    
    int getID() const;
    int getEmployeeCount() const;
    CharString getProjectDescription();
};

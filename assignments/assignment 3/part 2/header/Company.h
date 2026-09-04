#pragma once
#include "./Project.h"
#include "./Employee.h"
#include "./Department.h"

class Company
{
private:
    static const int MAX_EMPLOYEES = 300;
    static const int MAX_PROJECTS = 50;
    static const int MAX_DEPARTMENTS = 20;

    int employeeCount;
    Employee *employees[MAX_EMPLOYEES];
    int deptCount;
    Department *departments[MAX_DEPARTMENTS];
    int projectCount;
    Project *projects[MAX_PROJECTS];

public:
    // constructors and destructors

    Company();
    ~Company();

    // member functions

    bool AddEmployee(Employee *employee);
    bool AddDepartment(Department *dept);
    bool AddProject(Project *project);

    void displayProjects();
    void displayEmployees();
    void displayDepartments();

    Employee *findEmployee(int empID);
    Department *findDepartment(int deptID);
    Project *findProject(int prjID);

    bool AssignProjectToEmployee(int empID, int prjID);
    bool AssignEmployeeToDepartment(int deptID, int empID);

    bool removeProjectFromEmployee(int empID, int prjID);
    bool removeEmployeeFromDepartment(int deptID, int empID);

    void displayAllProjectsOfEmployee(int empID);
    void displayAllEmployeesOfDept(int deptID);
    void displayAllEmployeesOnProj(int prjID);

    // getters

    int getProjectCount() const;
    int getEmployeeCount() const;
    int getDepartmentCount() const;
};
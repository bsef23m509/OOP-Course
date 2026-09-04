#pragma once
#include "./CharString.h"
#include "./Address.h"
#include "./Project.h"

class Project;
class Department;

class Employee
{
private:
    static const int MAX_PROJECTS = 3;

    int ID;
    CharString name;
    float salary;
    Address permanentAddress;
    bool assignedToDept;
    Department *department;
    Project *projects[MAX_PROJECTS];
    int projectCount;

public:
    // constructors

    Employee();
    Employee(int ID, CharString name, float salary, Address permanentAddr);

    // member functions

    void displayEmployeeInfo();
    void displayAllProjects();

    bool addProject(Project *project);
    bool removeProject(int projectID);

    // setters

    void setAssignedToDept(bool value);
    void setDept(Department *dept);
    void setSalary(float salary);

    // getters

    float getSalary() const;
    int getID() const;
    int getProjectCount() const;
    bool getAssignedToDept() const;
    CharString getName();
    Address getPermanentAddress();
    Department *getDept() const;
};

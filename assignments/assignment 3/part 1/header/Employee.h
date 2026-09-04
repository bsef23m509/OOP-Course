#pragma once
#include "./CharString.h"
#include "./Address.h"
#include "./Project.h"

class Employee
{
private:
    int ID;
    CharString name;
    Address permanentAddress;
    bool assignedToDept;
    Project *projests[3];
    int projectCount;

public:
    Employee(int houseNo, CharString name, Address permanentAddr);
    
    void diisplayEmployeeInfo();
    void displayAllProject();
    bool addProject(Project *project);
    bool removeProject(int projectID);
    void setAssignedToDept(bool value);

    int getID();
    int getProjectCount();
    bool getAssignedToDept();
    CharString getName();
    Address getPermanentAddress();
};

#pragma once
#include "./CharString.h"

class Project
{
private:
    int ID;
    int employeeCount;
    CharString projectDescription;

public:
    Project(int ID, CharString description);
    void diisplayProjectInfo();

    void incrementEmployeeCount();
    void decrementEmployeeCount();

    int getID();
    int getEmployeeCount();
    CharString getProjectDescription();
};

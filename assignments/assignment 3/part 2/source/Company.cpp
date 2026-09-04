#include <iostream>
using namespace std;
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Employee.h"
#include "../header/Project.h"
#include "../header/Department.h"
#include "../header/Company.h"

// constructors and destructors

Company::Company()
{
    this->projectCount = 0;
    this->employeeCount = 0;
    this->deptCount = 0;

    for (int i = 0; i < this->MAX_PROJECTS; i++)
        this->projects[i] = NULL;

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        this->employees[i] = NULL;

    for (int i = 0; i < this->MAX_DEPARTMENTS; i++)
        this->departments[i] = NULL;
}

Company::~Company()
{
    for (int i = 0; i < this->MAX_DEPARTMENTS; i++)
    {
        delete this->departments[i];
    }
    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        delete this->employees[i];
    }
    for (int i = 0; i < this->MAX_PROJECTS; i++)
    {
        delete this->projects[i];
    }
}

// member functions

bool Company::AddEmployee(Employee *employee)
{

    if (!employee || this->employeeCount >= this->MAX_EMPLOYEES)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] == NULL)
        {
            this->employees[i] = employee;
            this->employeeCount++;

            return true;
        }
    }
    return false;
}

bool Company::AddDepartment(Department *dept)
{

    if (!departments || this->deptCount >= this->MAX_DEPARTMENTS)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_DEPARTMENTS; i++)
    {
        if (this->departments[i] == NULL)
        {
            this->departments[i] = dept;
            this->deptCount++;
            return true;
        }
    }
    return false;
}

bool Company::AddProject(Project *project)
{

    if (!project || this->projectCount >= this->MAX_PROJECTS)
    {
        return false;
    }

    for (int i = 0; i < this->MAX_PROJECTS; i++)
    {
        if (this->projects[i] == NULL)
        {
            this->projects[i] = project;
            this->projectCount++;
            return true;
        }
    }
    return false;
}

void Company::displayProjects()
{
    if (this->getProjectCount() == 0)
    {
        cout << "No projects" << endl;
    }
    else
    {
        cout << "No. of projects are: " << this->getProjectCount() << endl;

        for (int i = 0; i < this->MAX_PROJECTS; i++)
        {
            if (this->projects[i] != NULL)
            {
                cout << projects[i] << " " << i << endl;
                this->projects[i]->diisplayProjectInfo();
            }
        }
    }
}

void Company::displayEmployees()
{

    if (this->getEmployeeCount() == 0)
    {
        cout << "No Employees" << endl;
    }
    else
    {
        cout << "No. of employees are: " << this->getEmployeeCount() << endl;

        for (int i = 0; i < this->MAX_EMPLOYEES; i++)
        {
            if (this->employees[i] != NULL)
            {
                this->employees[i]->displayEmployeeInfo();
            }
        }
    }
}

void Company::displayDepartments()
{
    if (this->getDepartmentCount() == 0)
    {
        cout << "No Departments" << endl;
    }
    else
    {
        cout << "No. of departments are: " << this->getDepartmentCount() << endl;

        for (int i = 0; i < this->MAX_DEPARTMENTS; i++)
        {
            if (this->departments[i] != NULL)
            {
                this->departments[i]->diisplayDepartmentInfo();
            }
        }
    }
}

void Company::displayAllProjectsOfEmployee(int empID)
{
    Employee *employee = this->findEmployee(empID);

    if (employee != NULL)
        employee->displayAllProjects();
    else
        cout << "Employee Not Found" << endl;
}

void Company::displayAllEmployeesOfDept(int deptID)
{
    Department *department = this->findDepartment(deptID);

    if (department != NULL)
        department->displayAllEmployee();
    else
        cout << "Department Not Found" << endl;
}

void Company::displayAllEmployeesOnProj(int prjID)
{
    Project *project = this->findProject(prjID);

    if (project != NULL)
        project->displayAllEmployees();
    else
        cout << "Project Not Found" << endl;
}

Employee *Company::findEmployee(int empID)
{
    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (this->employees[i] != NULL && this->employees[i]->getID() == empID)
            return this->employees[i];
    }
    return NULL;
}

Department *Company::findDepartment(int deptID)
{
    for (int i = 0; i < MAX_DEPARTMENTS; i++)
    {
        if (this->departments[i] != NULL && this->departments[i]->getID() == deptID)
            return this->departments[i];
    }
    return NULL;
}

Project *Company::findProject(int prjID)
{
    for (int i = 0; i < MAX_PROJECTS; i++)
    {
        if (this->projects[i] != NULL && this->projects[i]->getID() == prjID)
            return this->projects[i];
    }
    return NULL;
}

bool Company::AssignProjectToEmployee(int empID, int prjID)
{
    Employee *employee = findEmployee(empID);
    Project *project = findProject(prjID);

    if (!employee || !project)
        return false;

    return employee->addProject(project);
}

bool Company::AssignEmployeeToDepartment(int deptID, int empID)
{
    Department *department = findDepartment(deptID);
    Employee *employee = findEmployee(empID);

    if (!department || !employee)
        return false;

    return department->addEmployee(employee);
}

bool Company::removeProjectFromEmployee(int empID, int prjID)
{
    Employee *employee = findEmployee(empID);

    if (!employee)
        return false;

    return employee->removeProject(prjID);
}

bool Company::removeEmployeeFromDepartment(int deptID, int empID)
{
    Department *department = findDepartment(deptID);
    if (!department)
        return false;

    return department->removeEmployee(empID);
}

// getters

int Company::getProjectCount() const
{
    return this->projectCount;
}

int Company::getEmployeeCount() const
{
    return this->employeeCount;
}

int Company::getDepartmentCount() const
{
    return this->deptCount;
}
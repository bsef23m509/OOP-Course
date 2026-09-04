#include <iostream>
#include "../header/CharString.h"
#include "../header/Address.h"
#include "../header/Project.h"
#include "../header/Employee.h"
#include "../header/Department.h"
#include "../header/Company.h"
using namespace std;

int main()
{
    Company company;

    int choice = 0;

    int id, employeeID, projectID, deptID;
    int newEmployeeID = 1, newProjectID = 1, newDeptID = 1;

    char inputString[100];

    float employeeSalary;
    int employeeHouse, employeeStreet;
    char employeeBlock;

    do
    {
        cout << "\n\tMain Menu" << endl;

        cout << "\t1. Add Employee" << endl;
        cout << "\t2. Display All Employees" << endl;
        cout << "\t3. Search for an Employee" << endl;

        cout << "\t4. Add Project" << endl;
        cout << "\t5. Display All Projects" << endl;
        cout << "\t6. Search for an Project" << endl;

        cout << "\t7. Add Department" << endl;
        cout << "\t8. Display All Departments" << endl;
        cout << "\t9. Search for an Department" << endl;

        cout << "\t10. Assign Project to Employee" << endl;
        cout << "\t11. Assign Employee to Department" << endl;

        cout << "\t12. Remove Project from Employee" << endl;
        cout << "\t13. Remove Employee from Department" << endl;

        cout << "\t14. Display All Projects of Employee" << endl;
        cout << "\t15. Display All Employees of Department" << endl;
        cout << "\t16. Display All Employees on Project" << endl;

        cout << "\t17. Quit" << endl;

        cout << endl;
        cout << "Enter your choice: ";

        do
        {
            cin >> choice;
        } while (choice < 1 || choice > 17);

        if (choice == 1) // Add employee
        {

            cout << "Enter Name: ";
            cin >> inputString;

            CharString name = CharString(inputString);

            cout << "Enter Salary: ";
            cin >> employeeSalary;

            cout << "Enter House No.: ";
            cin >> employeeHouse;

            cout << "Enter Street No.: ";
            cin >> employeeStreet;

            cout << "Enter Block: ";
            cin >> employeeBlock;

            cout << "Enter City: ";
            cin >> inputString;

            CharString city = CharString(inputString);

            bool success = company.AddEmployee(
                new Employee(
                    newEmployeeID++,
                    CharString(name),
                    employeeSalary,
                    Address(employeeHouse, employeeBlock, employeeStreet, city)));

            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully Added." << endl;
        }
        else if (choice == 2) // Display employees
        {
            company.displayEmployees();
        }
        else if (choice == 3) // Search employee
        {
            cout << "Enter ID: ";
            cin >> id;
            Employee *employee = company.findEmployee(id);

            if (employee != NULL)
                employee->displayEmployeeInfo();
            else
                cout << "No such employee." << endl;
        }
        else if (choice == 4) // Add project
        {

            cout << "Enter Project Description: ";
            cin >> inputString;

            CharString des = CharString(inputString);

            bool success = company.AddProject(new Project(newProjectID++, CharString(des)));
            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully Adeed." << endl;
        }
        else if (choice == 5) // Display projects
        {
            company.displayProjects();
        }
        else if (choice == 6) // Search project
        {
            cout << "Enter ID: ";
            cin >> id;
            Project *project = company.findProject(id);

            if (project != NULL)
                project->diisplayProjectInfo();
            else
                cout << "No such project." << endl;
        }
        else if (choice == 7) // Add department
        {

            cout << "Enter Department Name: ";
            cin >> inputString;

            CharString name = CharString(inputString);

            bool success = company.AddDepartment(new Department(newDeptID++, CharString(name)));
            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully Added." << endl;
        }
        else if (choice == 8) // Display departments
        {
            company.displayDepartments();
        }
        else if (choice == 9) // Search department
        {
            cout << "Enter ID: ";
            cin >> id;
            Department *department = company.findDepartment(id);

            if (department != NULL)
                department->diisplayDepartmentInfo();
            else
                cout << "No such department." << endl;
        }
        else if (choice == 10) // Assign Project to Employee
        {
            cout << "Enter employee ID: ";
            cin >> employeeID;
            cout << "Enter project ID: ";
            cin >> projectID;

            bool success = company.AssignProjectToEmployee(employeeID, projectID);

            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully assigned." << endl;
        }
        else if (choice == 11) // Assign Employee to Department
        {
            cout << "Enter employee ID: ";
            cin >> employeeID;
            cout << "Enter department ID: ";
            cin >> deptID;

            bool success = company.AssignEmployeeToDepartment(deptID, employeeID);

            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully assigned." << endl;
        }
        else if (choice == 12) // Remove Project from Employee
        {
            cout << "Enter employee ID: ";
            cin >> employeeID;
            cout << "Enter project ID: ";
            cin >> projectID;

            bool success = company.removeProjectFromEmployee(employeeID, projectID);

            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully removed." << endl;
        }
        else if (choice == 13) // Remove Employee from Department
        {
            cout << "Enter employee ID: ";
            cin >> employeeID;
            cout << "Enter department ID: ";
            cin >> deptID;

            bool success = company.removeEmployeeFromDepartment(deptID, employeeID);

            if (!success)
                cout << "Failed" << endl;
            else
                cout << "Successfully removed." << endl;
        }
        else if (choice == 14) // Display All Projects of Employee
        {
            cout << "Enter ID: ";
            cin >> id;
            Employee *employee = company.findEmployee(id);

            if (employee != NULL)
                employee->displayAllProjects();
            else
                cout << "No such employee." << endl;
        }
        else if (choice == 15) // Display All Employees of Department
        {
            cout << "Enter ID: ";
            cin >> id;
            Department *department = company.findDepartment(id);

            if (department != NULL)
                department->displayAllEmployee();
            else
                cout << "No such Department." << endl;
        }
        else if (choice == 16) // Display All Employees on Project
        {
            cout << "Enter ID: ";
            cin >> id;
            Project *project = company.findProject(id);

            if (project != NULL)
                project->displayAllEmployees();
            else
                cout << "No such project." << endl;
        }
        else // Quit
        {
            cout << "Goed Bye!!!" << endl;
            break;
        }

    } while (true);

    return 0;
}
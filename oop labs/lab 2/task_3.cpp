#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    char Name[100];
    int rollNo;
    Date Date_of_birth;
    int No_of_Courses;
    int *Marks_of_courses;
    float CGPA;
};

void inputStudentData(Student &stu)
{
    cout << "Enter Name: ";
    cin >> stu.Name;
    cout << "Enter Roll no.: ";
    cin >> stu.rollNo;

    cout << "Enter Date of birth: " << endl;
    do
    {
        cout << "Enter Day of birth: ";
        cin >> stu.Date_of_birth.day;
    } while (stu.Date_of_birth.day > 31);
    do
    {
        cout << "Enter Month of birth: ";
        cin >> stu.Date_of_birth.month;
    } while (stu.Date_of_birth.month > 12);
    do
    {
        cout << "Enter Year of birth: ";
        cin >> stu.Date_of_birth.year;
    } while (stu.Date_of_birth.year < 0);

    cout << "Enter Number of courses: ";
    cin >> stu.No_of_Courses;

    stu.Marks_of_courses = new int[stu.No_of_Courses];

    cout << "Enter Marks of each course: " << endl;
    ;

    for (int i = 0; i < stu.No_of_Courses; i++)
    {
        do
        {
            cout << "Enter Marks of course " << i + 1 << " : ";
            cin >> stu.Marks_of_courses[i];
        } while (stu.Marks_of_courses[i] > 100 || stu.Marks_of_courses[i] < 0);
    }

    do
    {
        cout << "Enter CGPA (between 0.0 and 4.0): ";
        cin >> stu.CGPA;
    } while (stu.CGPA > 4.0 || stu.CGPA < 0);
}

void displayDate(Date date)
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
}

void displayStudentData(Student stu)
{

    int passed = 0;

    cout << "----------------" << endl;
    cout << "Student's Name: " << stu.Name << endl;
    cout << "Student's Roll number: " << stu.rollNo << endl;
    cout << "Student's Date of Birth: ";
    displayDate(stu.Date_of_birth);

    cout << "Student's No. of courses: " << stu.No_of_Courses << endl;
    cout << "Student's Marks of courses: " << endl;

    for (int i = 0; i < stu.No_of_Courses; i++)
    {
        cout << "Marks of course " << i + 1 << ": " << stu.Marks_of_courses[i] << endl;
        ;
    }

    cout << "Student's CGPA: " << stu.CGPA << endl;

    if (stu.CGPA < 2.5)
    {
        cout << "Student is dropped." << endl;
    }
    else
    {
        cout << "Student's failed courses are: ";

        for (int i = 0; i < stu.No_of_Courses; i++)
        {
            if (stu.Marks_of_courses[i] < 50)
                cout << i + 1 << " ";
            else
                passed++;
        }

        if (passed == stu.No_of_Courses)
            cout << "None";

        cout << endl;
    }

    cout << "----------------" << endl;
    cout << endl;
}

int main()
{
    Student student1, student2, student3;

    inputStudentData(student1);
    displayStudentData(student1);

    inputStudentData(student2);
    displayStudentData(student2);

    inputStudentData(student3);
    displayStudentData(student3);

    delete[] student1.Marks_of_courses;
    delete[] student2.Marks_of_courses;
    delete[] student3.Marks_of_courses;

    return 0;
}
#include <iostream>
using namespace std;

class Teacher
{
private:
    string name;
    int extentionNumber;

public:
    Teacher()
    {
        this->name = "";
        this->extentionNumber = 0;
        cout << "Teacher CTOR" << endl;
    }

    Teacher(string name, int extentionNumber)
    {
        this->name = name;
        this->extentionNumber = extentionNumber;
        cout << "Teacher CTOR" << endl;
    }

    Teacher(Teacher &otherTeacher)
    {
        this->name = otherTeacher.getName();
        this->extentionNumber = otherTeacher.getExtentionNumber();
    }

    void operator=(Teacher &otherTeacher)
    {
        this->name = otherTeacher.getName();
        this->extentionNumber = otherTeacher.getExtentionNumber();
        cout << "Teacher Assignment OPTR" << endl;
    }

    ~Teacher()
    {
        cout << "Teacher DTOR" << endl;
    }

    string getName() const
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getExtentionNumber() const
    {
        return this->extentionNumber;
    }

    void setExtentionNumber(int extentionNumber)
    {
        this->extentionNumber = extentionNumber;
    }

    void display() const
    {
        cout << "Teacher Details:" << endl;
        cout << "Teacher Name: " << this->getName() << endl;
        cout << "Teacher Office Extention Number: " << this->getExtentionNumber() << endl;
        cout << endl;
    }
};

class ClassRoom
{
private:
    int roomNumber;
    int capacity;

public:
    ClassRoom()
    {
        this->roomNumber = 0;
        this->capacity = 0;
        cout << "ClassRoom CTOR" << endl;
    }

    ClassRoom(int roomNumber, int capacity)
    {
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        cout << "ClassRoom CTOR" << endl;
    }

    ClassRoom(ClassRoom &otherClassRoom)
    {
        this->roomNumber = otherClassRoom.getRoomNumber();
        this->capacity = otherClassRoom.getCapacity();
    }

    void operator=(ClassRoom &otherClassRoom)
    {
        this->roomNumber = otherClassRoom.getRoomNumber();
        this->capacity = otherClassRoom.getCapacity();
        cout << "ClassRoom Assignment OPTR" << endl;
    }

    ~ClassRoom()
    {
        cout << "ClassRoom DTOR" << endl;
    }

    int getRoomNumber() const
    {
        return this->roomNumber;
    }

    void setRoomNumber(int roomNumber)
    {
        this->roomNumber = roomNumber;
    }

    int getCapacity() const
    {
        return this->capacity;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }

    void display() const
    {
        cout << "ClassRoom Details:" << endl;
        cout << "ClassRoom Room Number: " << this->getRoomNumber() << endl;
        cout << "ClassRoom Capacity: " << this->getCapacity() << endl;
        cout << endl;
    }
};

class Course
{
private:
    string title;
    int code;
    Teacher teacher;
    ClassRoom *classRoomPtr;

public:
    Course()
    {
        this->title = "";
        this->code = 0;
        this->classRoomPtr = NULL;
        cout << "Course CTOR" << endl;
    }

    Course(string title, int code, string teacherName, int teacherExtensionNumber, ClassRoom *classRoom)
    {
        this->title = title;
        this->code = code;
        this->teacher.setName(teacherName);
        this->teacher.setExtentionNumber(teacherExtensionNumber);
        this->allocateClassRoom(classRoom);
        cout << "Course CTOR" << endl;
    }

    Course &operator=(Course &newCourse)
    {
        this->title = newCourse.getTitle();
        this->code = newCourse.getCode();
        this->teacher.setName(newCourse.getTeacher().getName());
        this->teacher.setExtentionNumber(newCourse.getTeacher().getExtentionNumber());
        this->allocateClassRoom(newCourse.getClassRoomPtr());
        cout << "Course Assignment OPTR" << endl;
        return *(this);
    }

    Course(Course &newCourse)
    {
        this->title = newCourse.getTitle();
        this->code = newCourse.getCode();
        this->teacher.setName(newCourse.getTeacher().getName());
        this->teacher.setExtentionNumber(newCourse.getTeacher().getExtentionNumber());
        this->allocateClassRoom(newCourse.getClassRoomPtr());
        cout << "Course Copy CTOR" << endl;
    }

    ~Course()
    {
        cout << "Course DTOR" << endl;
    }

    string getTitle() const
    {
        return this->title;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    int getCode() const
    {
        return this->code;
    }

    void setCode(int code)
    {
        this->code = code;
    }

    Teacher getTeacher()
    {
        return this->teacher;
    }

    ClassRoom *getClassRoomPtr() const
    {
        return this->classRoomPtr;
    }

    void changeTeacher(Teacher newTeacher)
    {
        this->teacher = newTeacher;
    }

    void allocateClassRoom(ClassRoom *newClassRoom)
    {
        if (newClassRoom != NULL)
            this->classRoomPtr = newClassRoom;
    }

    void display() const
    {
        cout << "Course Details:" << endl;
        cout << "Course Title: " << this->getTitle() << endl;
        cout << "Course Code: " << this->getCode() << endl;
        cout << endl;
        this->teacher.display();
        if (this->classRoomPtr != NULL)
            this->classRoomPtr->display();
        cout << "--------------------------------" << endl;
    }
};

int main()
{
    Teacher t1 = Teacher("Abdullah", 28);
    Teacher t2 = Teacher("Ahmad", 34);
    Teacher t3 = Teacher("Ali", 46);

    ClassRoom cr1 = ClassRoom(201, 54);
    ClassRoom cr2 = ClassRoom(130, 52);
    ClassRoom cr3 = ClassRoom(176, 49);

    Course c1 = Course("OOP", 221, t1.getName(), t1.getExtentionNumber(), &cr1);
    Course c2 = Course("PF", 189, t2.getName(), t2.getExtentionNumber(), &cr2);

    cout << endl
         << "Before change: " << endl
         << endl;
    c1.display();
    c2.display();

    c1.allocateClassRoom(&cr3);

    c2.changeTeacher(t3);

    cout << endl
         << "After change: " << endl
         << endl;
    c1.display();
    c2.display();

    return 0;
}
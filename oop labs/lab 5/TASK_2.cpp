#include <iostream>
using namespace std;

class MyClass
{
private:
    static int count;
    const int id;

public:
    MyClass() : id(0)
    {
        count++;
    }

    MyClass(int givenId) : id(givenId)
    {
        count++;
    }

    MyClass(const MyClass &givenClass) : id(givenClass.id)
    {
        // count++;
    }

    ~MyClass()
    {
        // count--;
        cout << "DCON called" << endl;
    }

    static int getCount()
    {
        return count;
    }
};

int MyClass::count = 0;

int main()
{
    cout << "MyClass objects count: " << MyClass::getCount() << endl;

    MyClass class1;
    // cout << "MyClass objects count: " << class1.getCount() << endl;
    MyClass class2 = MyClass(9);
    // cout << "MyClass objects count: " << class2.getCount() << endl;
    MyClass class3(class2);
    cout << "MyClass objects count: " << class3.getCount() << endl;

    const MyClass class4;
    class4.getCount();
    cout << "MyClass objects count: " << class3.getCount() << endl;

    return 0;
}
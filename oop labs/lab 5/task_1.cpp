#include <iostream>
using namespace std;

class MyList
{
private:
    int list[1000];
    int noOfElement;
    const int LENGTH = 1000;

public:
    MyList() 
    {
        this->noOfElement = 0;
    };

    MyList(const MyList &otherlist)
    {
        this->noOfElement = otherlist.noOfElement;
        for (int i = 0; i < this->noOfElement; i++)
        {
            this->list[i] = otherlist.list[i];
        }
    };

    bool isEmptyList() const
    {
        if (this->noOfElement == 0)
            return true;
        return false;
    };

    bool isFullList() const
    {
        if (this->noOfElement == (LENGTH))
            return true;
        return false;
    };

    int search(int searchItem) const
    {
        for (int i = 0; i < this->noOfElement; i++)
            if (this->list[i] == searchItem)
                return i;
        return -1;
    };

    void insert(int newElement)
    {
        if (!(this->isFullList()))
        {
            this->list[noOfElement] = newElement;
            noOfElement++;
        }
        else
        {
            cout << "List full" << endl;
        }
    };

    void remove(int removeElement)
    {
        if (!(this->isEmptyList()))
        {

            int elemPostion = this->search(removeElement);
            if (elemPostion != -1)
            {
                for (int i = elemPostion + 1; i < noOfElement; i++)
                    this->list[i - 1] = this->list[i];
                noOfElement--;
            }
        }
        else
        {
            cout << "List Empty" << endl;
        }
    };

    void printList() const
    {
        for (int i = 0; i < noOfElement; i++)
        {
            cout << "Item " << i + 1 << ": " << this->list[i] << endl;
        }
    };
};

int main()
{
    MyList list1;

    list1.remove(8);

    list1.insert(2);
    list1.insert(8);
    list1.insert(7);

    cout << "list1: " << endl;
    list1.printList();

    list1.remove(8);

    cout << "list1: " << endl;
    list1.printList();

    MyList list2 = list1;

    cout << "list2: " << endl;
    list2.printList();

    cout << "list2: " << endl;
    // for (int i = 0; i < 998; i++)
    //     list2.insert(i);

    list2.printList();

    return 0;
}
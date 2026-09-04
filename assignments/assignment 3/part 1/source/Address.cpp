#include <iostream>
using namespace std;
#include "../header/Address.h"

Address::Address(int houseNo, char block, int streetNo, CharString city)
{
    this->houseNo = houseNo;
    this->block = block;
    this->streetNo = streetNo;
    this->city.copyFrom(city);
}

Address::Address()
{
}

Address::Address(Address &other)
{
}

void Address::diisplayAddress()
{
    cout << endl;
    cout << "Address Information" << endl;
    cout << "House Number: " << houseNo << endl;
    cout << "Block Letter: " << block << endl;
    cout << "Street Number: " << streetNo << endl;
    cout << "City: " << *(city.getCstr()) << endl;
    cout << endl;
}
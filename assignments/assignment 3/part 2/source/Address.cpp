#include <iostream>
using namespace std;
#include "../header/Address.h"

// constructors

Address::Address(int houseNo, char block, int streetNo, CharString city)
{
    this->houseNo = houseNo;
    this->block = block;
    this->streetNo = streetNo;

    this->city.copyFrom(city);
}

Address::Address()
{
    this->houseNo = 0;
    this->block = ' ';
    this->streetNo = 0;
    this->city = CharString();
}

Address::Address(Address &other)
{
    this->houseNo = other.getHouseNo();
    this->block = other.getBlock();
    this->streetNo = other.getStreetNo();
    this->city.copyFrom(other.getCity());
}

// member functions

void Address::diisplayAddress()
{
    cout << endl;
    cout << "Address Information" << endl;
    cout << "House Number: " << houseNo << endl;
    cout << "Block Letter: " << block << endl;
    cout << "Street Number: " << streetNo << endl;
    cout << "City: " << city.getCstr() << endl;
    // cout << endl;
}

// getters

int Address::getHouseNo() const
{
    return this->houseNo;
}

int Address::getStreetNo() const
{
    return this->streetNo;
}

char Address::getBlock() const
{
    return this->block;
}

CharString Address::getCity()
{
    CharString ans;
    ans.copyFrom(this->city);
    return ans;
}

// setters

void Address::setHouseNo(int houseNo)
{
    this->houseNo = houseNo;
}

void Address::setStreetNo(int streetNo)
{
    this->streetNo = streetNo;
}

void Address::setBlock(char block)
{
    this->block = block;
}

void Address::setCity(CharString city)
{
    this->city.copyFrom(city);
}

#pragma once
#include "./CharString.h"

class Address
{
private:
    int houseNo;
    char block;
    int streetNo;
    CharString city;

public:
    // constructors

    Address(int houseNo, char block, int streetNo, CharString city);
    Address();
    Address(Address &other);

    // member functions

    void diisplayAddress();

    // getters

    int getHouseNo() const;
    int getStreetNo() const;
    char getBlock() const;
    CharString getCity();

    // setters

    void setHouseNo(int houseNo);
    void setStreetNo(int streetNo);
    void setBlock(char block);
    void setCity(CharString city);
};

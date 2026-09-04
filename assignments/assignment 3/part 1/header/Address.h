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
    Address(int houseNo, char block, int streetNo, CharString city);
    Address();
    Address(Address &other);
    void diisplayAddress();
};

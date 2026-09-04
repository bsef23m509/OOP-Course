#include <iostream>
using namespace std;
#include "../header/CharString.h"

CharString::CharString()
{
    this->cstr = NULL;
    this->size = 0;
}

CharString::~CharString()
{
    if (this->cstr != NULL)
        delete[] this->cstr;
}

CharString::CharString(CharString &other)
{
    this->copyFrom(other);
}

int CharString::getSize()
{
    return this->size;
}

char *CharString::getCstr()
{
    return this->cstr;
}

int CharString::calculateSize(const char *str)
{
}

void CharString::copyFrom(const char *str)
{
}

void CharString::copyFrom(CharString str)
{
}

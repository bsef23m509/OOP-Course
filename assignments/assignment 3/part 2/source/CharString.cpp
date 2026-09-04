#include <iostream>
using namespace std;
#include "../header/CharString.h"

// constructors and destructors

CharString::CharString()
{
    this->cstr = NULL;
    this->size = 0;
}

CharString::CharString(const char *str)
{
    this->copyFrom(str);
}

CharString::CharString(CharString &other)
{
    int new_length = other.getSize();
    char *other_string = other.getCstr();

    if (other_string == NULL)
    {
        this->setSize(0);
        this->setCstr(NULL);
        return;
    }

    char *new_string = new char[new_length];

    for (int i = 0; i < new_length - 1; i++)
    {
        new_string[i] = other_string[i];
    }
    new_string[new_length - 1] = '\0';

    this->setCstr(new_string);
    this->setSize(new_length);
}

CharString::~CharString()
{
    if (this->cstr != NULL)
        delete[] this->cstr;
}

// getters

int CharString::getSize() const
{
    return this->size;
}

char *CharString::getCstr() const
{
    return this->cstr;
}

// setters

void CharString::setSize(int size)
{
    this->size = size;
}

void CharString::setCstr(char *ptr)
{
    if (ptr != NULL)
        this->cstr = ptr;
}

// member functions

void CharString::copyFrom(const char *str)
{
    int new_length = this->calculateSize(str);
    char *new_string = new char[new_length];

    for (int i = 0; i < new_length - 1; i++)
    {
        new_string[i] = str[i];
    }
    new_string[new_length - 1] = '\0';

    this->setCstr(new_string);
    this->setSize(new_length);
}

void CharString::copyFrom(CharString str)
{
    delete[] this->getCstr();

    char *str_string = str.getCstr();
    int new_length = str.getSize();

    if (str_string == NULL)
    {
        this->setSize(0);
        this->setCstr(NULL);
        return;
    }

    char *new_string = new char[new_length];

    for (int i = 0; i < new_length - 1; i++)
    {
        new_string[i] = str_string[i];
    }
    new_string[new_length - 1] = '\0';
    this->setCstr(new_string);
    this->setSize(new_length);
}

// static functions

int CharString::calculateSize(const char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        size++;
    }
    size++;
    return size;
}
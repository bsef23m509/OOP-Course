#pragma once

class CharString
{
private:
    char *cstr;
    int size;

public:
    // static functions

    static int calculateSize(const char *str);

    // constructors and destructors

    CharString();
    CharString(const char *str);
    CharString(CharString &other);
    ~CharString();

    // member functions

    void copyFrom(const char *str);
    void copyFrom(CharString str);

    // getters

    int getSize() const;
    char *getCstr() const;

    // setters

    void setSize(int size);
    void setCstr(char *ptr);
};

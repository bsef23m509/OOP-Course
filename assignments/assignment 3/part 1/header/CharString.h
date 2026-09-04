#pragma once

class CharString
{
private:
    char *cstr;
    int size;

public:
    static int calculateSize(const char *str);

    CharString();
    CharString(CharString& other);
    ~CharString();
    void copyFrom(const char *str);
    void copyFrom(CharString str);

    int getSize();
    char* getCstr();
};

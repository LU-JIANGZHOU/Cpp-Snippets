#ifndef MYCLASS_H
#define MYCLASS_H

class myClass
{
private:
    /* data */
     int* data;

public:
    myClass(const int size);
    ~myClass();
    void doSth();
};

#endif

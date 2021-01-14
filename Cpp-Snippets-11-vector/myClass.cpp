#include "myClass.h"
#include <iostream>

using namespace std;

myClass::myClass(string s): name(s)
{
    cout<<"constructor:"<<name<<"\n";
}

myClass::myClass(const myClass & c): name(c.name){
    cout<<"Copy constructor:"<<name<<"\n";
};

myClass& myClass::operator=(const myClass & c){
    name=c.getName();
    cout<<"Copy assigning:"<<name<<"\n";
    return *this;
};

myClass::~myClass(void){
    cout<<"destructor:"<<name<<"\n";
};

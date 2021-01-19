#include<iostream>
#include "myClass.h"
using namespace std;

myClass::myClass(const int size)
{
    cout<<"allocate memory for data"<<"\n";
    data = new int[size];
}

myClass::~myClass()
{
    cout<<"release memory"<<"\n";
    delete[] data;
}

void myClass::doSth(){
    
};

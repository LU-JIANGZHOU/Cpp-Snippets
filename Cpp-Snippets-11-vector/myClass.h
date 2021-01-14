#ifndef MYCLASS_H
#define MYCLASS_H
#include<string>
using namespace std;

class myClass
{
private:
    string name;

public:
    myClass(string s);
    myClass(const myClass & c);
    myClass& operator = (const myClass & c);
    ~myClass(void);
    string getName() const { return name;};
};

#endif // MYCLASS_H

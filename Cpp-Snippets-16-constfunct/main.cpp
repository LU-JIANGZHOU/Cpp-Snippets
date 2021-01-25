#include <iostream>
using namespace std;

class student
{
private:
     int age;
     string name;

public:
     student();
     ~student();

     //const parameters
     void setAge(const int &a)
     {
          age = a;
          //a++; //expression must be a modifiable lvalue
     }
     /*      void setAge(const int a) //past by value, the const is not very useful since the a is a copy and should not changed during operation
     {
          age = a;
          //a++; //expression must be a modifiable lvalue
     } */
     /*      void setAge(int a) //past by value, the same as previous one
     {
          age = a;
          //a++; //expression must be a modifiable lvalue
     } */

     //const return value
     const string &getName();

     //const function
     void showName() const;
     void showName();
};

student::student()
{
     age = 12;
     name = "hello";
}

student::~student()
{
}

const string &student::getName()
{
     return name;
}

/* const string student::getName() //return by value, useless
{
     return name;
} */

void student::showName() const
{
     cout << "const" << name << "\n";
}

void student::showName()
{
     cout << "non const" << name << "\n";
}

int main()
{
     int i = 15;
     student s1;
     s1.setAge(i);

     cout << "i is" << i << "\n";

     const string &name = s1.getName();
     cout << name << "\n";

     s1.showName();
     const student s2;
     s2.showName();

     return EXIT_SUCCESS;
}

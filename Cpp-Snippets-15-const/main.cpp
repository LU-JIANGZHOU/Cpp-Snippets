#include <iostream>
using namespace std;

int main()
{
     const int i = 0;
     //i = 1; //expression must be a modifiable lvalue
     const_cast<int &> (i)=1;

     const int *p=&i; //i is const but pointer p is not const
     //*p=2;//expression must be a modifiable lvalue
     p++;//ok

     int j; 
     int * const p1=&j; //p1 is const but the value point to is not a const

     const int * const p2=&i; //both p and i are const

     int const * p3 =&i; //i is const
     const int * p4 = & i; //i is const

     static_cast<const int &> (j);

     return EXIT_SUCCESS;
}

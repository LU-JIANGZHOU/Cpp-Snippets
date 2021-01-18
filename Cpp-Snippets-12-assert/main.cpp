#include <iostream>
#include <vector>
#include <stdexcept>
// uncomment to disable assert()
//#define NDEBUG //before the assert include
#include <cassert>

double printDivision(int x, int y)
{
     assert(y != 0);

     return static_cast<double>(x) / y;
}

using namespace std;

int main()
{

     printDivision(2, 0);
     //cout<<"reach here"<<"\n";
     return EXIT_SUCCESS;
}

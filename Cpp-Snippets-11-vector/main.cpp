#include <iostream>
#include <vector>
#include <stdexcept>
// uncomment to disable assert()
#define NDEBUG //before the assert include
#include <cassert>
#include "myClass.h"

using namespace std;

int main()
{
    cout << "hello vector 11"
         << "\n";

    vector<int> num{0, 1, 2, 3}; //C++ 11 and 14 need to add "<int>"
    //vector num{0,1,2,3}; //C++ 17 and 20, auto deduct the data type

    num.push_back(4);

    int i = num[1];
    assert(i == 1);
    cout << "Expression valid...Execution continues.\n";
    assert(i == 5);
    cout << "Asset disabled...execution continuous with invalid expression\n";

    num[0] = 3;
    for (auto i : num)
    {
        cout << i << "\n";
    }

    cout << "Create a new object for my class_____________________"
         << "\n";
    myClass fC("first");
    { //for scope //c++17
        vector<myClass> vCs;
        cout << "Start push my class to a vector_____________________"
             << "\n";
        vCs.push_back(fC);
        cout << "end of the first push operation_____________________"
             << "\n";
        cout << "Create and push second my class objects to a vector__"
             << "\n";
        vCs.push_back(myClass("second"));
        cout << "end of the second push operation_____________________"
             << "\n";
        cout << "Create and push third my class objects to a vector__"
             << "\n";
        vCs.push_back(myClass("third"));
        cout << "end of the third push operation_____________________"
             << "\n";
    }

    return EXIT_SUCCESS;
}

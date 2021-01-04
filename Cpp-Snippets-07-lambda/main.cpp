#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  cout << "to test lambda functions" << endl;

  ///1) basic lambda
  {
    auto c = [](int a, float b) -> float {
      return a + 1 / b;
    }(1, 5.0);
    cout << "Example1: " << c << endl
         << endl; //output:1.2
  }

  ///2) lambda basic function
  {
    auto f2 = [](int a, float b) -> float {
      return a + 1 / b;
    };
    auto c = f2(1, 5.0);
    cout << "Example2: " << c << endl
         << endl; //output:1.2
  }
  ///3) nested basic lambda
  {
    float c = [](int a) -> float {
      return [a](float b) -> float {
        return a + 1 / b;
      }(5.0);
    }(1);
    cout << "Example3: " << c << endl
         << endl; //output:1.2
  }

  ///4) nested lambda function
  {
    auto f = [](int a) -> auto
    {
      return [a](float b) -> auto
      {
        return a + 1 / b;
      };
    };
    auto c = f(1)(5.0);
    cout << "Example4: " << c << endl
         << endl; //output:1.2
  }

  ///5) lambda mutable
  {
    auto a = 10;
    /*   auto f = [a](){
    return a++; //expression must be a modifiable lvalue
    };
    */
    auto f5 = [a]() mutable -> int {
        return ++a; 
    };
    cout << "Example5: " << a << endl; //output:10
    auto c = f5();
    cout << "Example5: " << c << endl; //output:11
    cout << "Example5: " << a << endl
         << endl; //output:10
  }

  ///6) lambda capture by value
  {
    auto a = 10;
    auto f6 = [a]() mutable -> int {
      return ++a;
    };
    a += 2;
    cout << "Example6: " << a << endl; //output 12
    auto c = f6();                     //get the at the capture position
    cout << "Example6: " << c << endl; // output 11
    cout << "Example6: " << a << endl
         << endl; //output 12
  }

  ///7) lambda capture by reference
  {
    auto a = 10;
    auto f7 = [&a]() mutable -> int {
      return ++a;
    };
    a += 2;
    cout << "Example7: " << a << endl; //output 12
    auto c = f7();                     //get the at the capture position
    cout << "Example7: " << c << endl; // output 13
    cout << "Example7: " << a << endl
         << endl; //output 13
  }

  ///8) lambda capture multiple variables
  {
    auto a = 10;
    auto b = 20;
    auto f8 = [a, b]() -> int {
      return a + b;
    };
    auto c = f8();
    cout << "Example8: " << c << endl
         << endl; //output 30
  }

  ///9) lambda capture all variables by value
  {
    auto a = 10;
    auto b = 20;
    auto f9 = [=]() -> int {
      return a + b;
    };
    auto c = f9();
    cout << "Example9: " << c << endl
         << endl; //output 30
  }

  ///10) lambda capture multiple variable by reference
  {
    auto a = 10;
    auto b = 20;
    [&](){
      b = a + b;
    }();
    cout << "Example10: " << b << endl
         << endl; //output 30
  }

  ///11) lambda capture multiple mixed
  {
    auto a = 10;
    auto b = 20;
    auto c = 15;
    auto f11 = [a, b, &c]() -> int {
      return c += a + b;
    };
    c = f11();
    cout << "Example11: " << c << endl
         << endl; //output 45
  }

  ///12) lambda work together with for_each
  {
    vector<int> vec{2, 3, 4, 5, 6};
    cout << "Example12: ";
    for_each(vec.begin(), vec.end(), [](int v) { cout << v << " "; }); //output:2 3 4 5 6
    cout << endl;
    for_each(vec.begin(), vec.end(), [](int &v) { v++; });
    cout << "Example12: ";
    for_each(vec.begin(), vec.end(), [](int v) { cout << v << " "; }); //output:3 4 5 6 7
    cout << endl;
  }

  return EXIT_SUCCESS;
};

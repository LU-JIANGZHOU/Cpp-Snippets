#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
  int i;
  const int j = 1;
  const int &m = i;
  int &&n = 2;
  int a[5];
  int *p;

  decltype(i) var1; // int
  cout << "typeid variable 1 = " << typeid(var1).name() << endl;

  decltype(1.8) var2; // doublr
  cout << "typeid variable 2 = " << typeid(var2).name() << endl;

  decltype(2 + 3) var3; // int(+ operator returns an rvalue)
  cout << "typeid variable 3 = " << typeid(var3).name() << endl;

  decltype(1.6f) var4; // float
  cout << "typeid variable 4 = " << typeid(var4).name() << endl;

  decltype((i)) var5 = i; // int&
  cout << "typeid variable 5 = " << typeid(var5).name() << endl;

  decltype(j) var6 = 1; // const int
  cout << "typeid variable 6 = " << typeid(var6).name() << endl;

  return EXIT_SUCCESS;
};
#include <iostream>
#include <memory>
using namespace std;

struct myBase
{
  myBase() { cout << "  myBase::myBase()\n"; }
  ~myBase() { cout << "  myBase::~myBase()\n"; }
};

struct myDerived : public myBase
{
  myDerived() { cout << "  myDerived::myDerived()\n"; }
  ~myDerived() { cout << "  myDerived::~myDerived()\n"; }
};
int main()
{
  {
    unique_ptr<myBase> uniquePtr = make_unique<myDerived>();
  }//sth is wrong here, can not use unique pointer.

  return EXIT_SUCCESS;
};

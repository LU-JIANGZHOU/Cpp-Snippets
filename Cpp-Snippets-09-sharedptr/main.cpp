#include <iostream>
#include <memory>
using namespace std;

struct myBase
{
    myBase() {  cout << "  myBase::myBase()\n"; }
     ~myBase() {  cout << "  myBase::~myBase()\n"; }
};
 
struct myDerived: public myBase
{
    myDerived() {  cout << "  myDerived::myDerived()\n"; }
    ~myDerived() {  cout << "  myDerived::~myDerived()\n"; }
};
int main()
{
  shared_ptr<myBase> sharedPtr =  make_shared<myDerived>();

  return EXIT_SUCCESS;
};

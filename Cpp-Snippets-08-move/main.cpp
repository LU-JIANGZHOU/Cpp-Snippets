#include <iostream>
#include <string>
#include "myString.h"

std::string myConcat(std::string &, std::string &);
std::string myConcat(std::string &, std::string &&);
std::string myAppend(std::string &);

int main()
{
  std::cout << "to demo move semantics" << std::endl;
  //std::string & str01="Hello"; //error a reference of type "std::string &" (not const-qualified) cannot be initialized with a value of type "const char [6]"
  std::string &&str02 = "Hello"; // rvalue it is ok
  std::cout << str02.c_str() << std::endl;

  std::string stra = std::string("Hello");
  std::string strb = std::string("world");
  std::cout << stra.c_str() << strb.c_str() << std::endl;

  moveSwap(stra, strb);
  std::cout << stra.c_str() << strb.c_str() << std::endl;

  myConcat(stra, strb);
  std::cout << stra.c_str() << strb.c_str() << std::endl;

   myConcat(stra, "world");
  std::cout << stra.c_str() << strb.c_str() << std::endl;

  return EXIT_SUCCESS;
};

std::string myConcat(std::string &a, std::string &b)
{
  return a.append(b);
};

std::string myConcat(std::string &a, std::string &&b)
{
  if ((b.capacity() - b.size()) >= a.size())
  {
    b.insert(0, a);
    a.swap(b);
    return a;
  };
  return a.append(b);
};

std::string myAppend(std::string &a)
{
  //std::string str("world");
  return myConcat(a, std::move("world"));
};

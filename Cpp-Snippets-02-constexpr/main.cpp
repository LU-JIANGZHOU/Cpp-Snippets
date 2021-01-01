#include <iostream>
using namespace std;

#define LEN 10
int len_foo()
{
  int i = 2;
  return i;
}

constexpr int len_foo_constexpr()
{
  return 5;
}

constexpr int len_foo_constexpr(const int n)
{
  if (n < -1)
    return -1;
  else if (n > 1)
    return 1;
  else
    return 0;
}

int main()
{
  char arr01[10];  // ok
  char arr02[LEN]; // ok

  int len = 10;
  char arr03[len]; // run time allocate

  const int len_2 = len + 1;
  constexpr int len_2_constexpr = 1 + 2 + 3;
  char arr04[len_2]; //ok for GCC 9.x
  arr04[0] = 'h';
  arr04[1] = 'e';
  char arr05[len_2_constexpr]; //compile time allocated

  char arr06[len_foo() + 5];           //
  char arr07[len_foo_constexpr() + 1]; //

  return EXIT_SUCCESS;
};
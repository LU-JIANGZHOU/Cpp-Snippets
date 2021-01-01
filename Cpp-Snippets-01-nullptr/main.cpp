#include <iostream>
using namespace std;

// function with an integer
int Funct(int m)
{
  cout << "Funct(int)"
       << "integer function is called" << endl;
  return m;
};

// Overloaded Function with a char pointer
void Funct(char *c)
{
  cout << "Funct(char *)"
       << "pointer function is called" << endl;
};

int main()
{
  // Ideally, it should have called Funct(char *),
  // but it causes compiler error.
  Funct(1); //ok
  char myWord[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  Funct(myWord); //ok
  //Funct(NULL);//compile error, Funct(NULL) is a ambiguous GCC
  Funct(nullptr); //ok

  return EXIT_SUCCESS;
};
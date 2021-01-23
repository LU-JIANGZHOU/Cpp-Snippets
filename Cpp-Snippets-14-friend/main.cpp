#include <iostream>
using namespace std;

class B;

class A
{
     friend void fun_a();
     friend B;

protected:
     int a;

private:
     int b;

public:
     int c;
};

void fun_a(void)
{
     A m_a;
     m_a.a = 10;
     m_a.b = 20;
     m_a.c = 30;
}

class B
{
public:
     void printVal()
     {
          A ma;
          cout << ma.a << ma.b << ma.c << "\n";
     }
};

int main()
{

     fun_a();
     B mb;
     mb.printVal();

     return EXIT_SUCCESS;
}

#include <iostream>

class base
{
private:
  /* data */
public:
  int i;
  int j;
  base();
  base(int);
  virtual int MyAdd() final;
  ~base();
};

base::base()
{
  i = 1;
}

base::base(int k)
{
  j = k;
}

int base::MyAdd()
{
  return i + j;
}

base::~base()
{
}

class SubClassA final : public base
{
private:
  /* data */
public:
  SubClassA();
  SubClassA(int);
  //virtual int MyAdd() override; //cannot override 'final' function "base::MyAdd" (declared at line 26)
  ~SubClassA();
};

SubClassA::SubClassA()
{
  i=1;
};
SubClassA::SubClassA(int k)
{
  j=k;
};

SubClassA::~SubClassA()
{
}

/* class SubClassB : SubClassA //a 'final' class type cannot be used as a base class
{
private:
public:
  SubClassB();
  SubClassB();
};
SubClassB::SubClassB()
{
}
SubClassB ::SubClassB()
{
} */

int main()
{
  SubClassA a(5);
  std::cout<<a.i<<a.j<<a.MyAdd()<<std::endl;
  return EXIT_SUCCESS;
};

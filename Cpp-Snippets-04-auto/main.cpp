#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;
template <typename T, typename U>
auto add(T x, U y)
{
  return x + y;
}

int main()
{
  auto i = 8;              //type integer
  auto j = 5.8;            //type double
  auto arr = new auto(10); //tupe int *
  cout << "typeid i= " << typeid(i).name() << endl;
  cout << "typeid j = " << typeid(j).name() << endl;
  cout << "typeid arr = " << typeid(arr).name() << endl;

  int arr1[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    std::cout << arr1[i] << std::endl;
  for (int i = 0; i < sizeof(arr1); i++)
    std::cout << arr1[i] << std::endl;

  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;

  std::vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++)
    std::cout << (*it) << std::endl;

  std::list<std::string> lst;
  lst.push_back("Hello");
  lst.push_back("Modern");
  lst.push_back("C");
  lst.push_back("plus");
  lst.push_back("!");

  for (std::list<std::string>::iterator it1 = lst.begin(); it1 != lst.end(); it1++)
    std::cout << it1->c_str() << std::endl;

  for (auto it2 = lst.begin(); it2 != lst.end(); it2++)
    std::cout << it2->c_str() << std::endl;

  auto sum = add<double, int>(1.5, 2);
  std::cout << "sum: " << sum << typeid(sum).name() << std::endl;

  std::vector<int> vec = {1, 2, 3, 4};
  for (auto element : vec)
  {
    std::cout << element << "  ";
  }
  std::cout << std::endl;

  return EXIT_SUCCESS;
};

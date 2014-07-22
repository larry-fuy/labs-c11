#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

double f1(char, int a, float)
{ return a; }

int f4(int b)
{ return b; }

double f4(double b)
{ return b; }

void f7(ostream &os, int val)
{ os << val << endl; }

int main()
{
  using namespace std::placeholders;
  auto f2 = bind(f1, _3, _1, _2);
  double x2 = f2(42, 7.0, '6');
  cout << typeid(x2).name() << "    " << x2 << endl;

  auto f3 = bind(f1, '6', _1, 7.0);
  auto x3 = f3(9);
  cout << typeid(x3).name() << "    " << x3 << endl;

  //auto f5 = bind(f4, _1);  // No good
  auto f6 = bind((int(*)(int))f4, _1);
  int x6 = f6(13);
  cout << typeid(x6).name() << "    " << x6 << endl;

  //auto f8 = bind(f7, cout, _1);  // No good
  auto f8 = bind(f7, ref(cout), _1);
  f8(42);

}

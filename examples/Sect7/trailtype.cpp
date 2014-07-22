#include <iostream>
#include <typeinfo>
using namespace std;

template <class A, class B>
auto fun(A a, B b) -> decltype(a+b)
{
  return a + b;
}

int main()
{

  int x1 = 2;
  long y1 = 3L;
  auto z1 = fun(x1, y1);
  cout << typeid(z1).name() << ' ' << z1 << endl;

  float x2 = 2.1;
  long long y2 = 3LL;
  auto z2 = fun(x2, y2);
  cout << typeid(z2).name() << ' ' << z2 << endl;

  int x3 = 2;
  double y3 = 3.2;
  auto z3 = fun(x3, y3);
  cout << typeid(z3).name() << ' ' << z3 << endl;

  char x4 = 2;
  short y4 = 3;
  auto z4 = fun(x4, y4);
  cout << typeid(z4).name() << ' ' << z4 << endl;

}


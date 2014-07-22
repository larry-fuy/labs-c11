#include <iostream>
#include <typeinfo>
#include <functional>
using namespace std;

double f1(char, int a, float)
{ return a; }

class f3
{
public:
  int operator()(int b) { return b; }
};

class M
{
public:
  double f5(double b) { return b; }
};

int main()
{
  using namespace std::placeholders;
  //function<double (char, int, float)> f2 = bind(f1, _3, _1, _2);
  function<decltype(f1)> f2 = bind(f1, _3, _1, _2);
  cout << typeid(f2).name() << endl;
  double x2 = f2(42, 7.0, '6');
  cout << typeid(x2).name() << "    " << x2 << endl;

  function<int (int)> f4;
  f4 = f3();
  int x4 = f4(7);
  cout << typeid(x4).name() << "    " << x4 << endl;

  function<double (M*, double)> f6;
  f6 = &M::f5;
  M m1;
  auto x6 = f6(&m1, 13);
  cout << typeid(x6).name() << "    " << x6 << endl;

  function<double (double)> f7 = bind(f6, &m1, _1);
  auto x7 = f7(77);
  cout << typeid(x7).name() << "    " << x7 << endl;
  

}

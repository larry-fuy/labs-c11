#include <iostream>
#include <typeinfo>
using namespace std;

template <class A, class B>
struct X
{
  A a;
  B b;
};

template <class B>
using Y = X<int, B>;

using Z = X<float, char>;

int main()
{

  X<long, short> x = { 3, 2 };
  cout << typeid(x.a).name() << ' ' << x.a << endl;
  cout << typeid(x.b).name() << ' ' << x.b << endl;

  Y<float> y = { 4, 5.2 };
  cout << typeid(y.a).name() << ' ' << y.a << endl;
  cout << typeid(y.b).name() << ' ' << y.b << endl;

  Z z = { 5.2, 'a' };
  cout << typeid(z.a).name() << ' ' << z.a << endl;
  cout << typeid(z.b).name() << ' ' << z.b << endl;

}


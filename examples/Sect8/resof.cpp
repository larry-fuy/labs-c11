#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

// The straight class, return type same as argument type
struct straight
{
  int    operator()(int a) const { return a; }
  double operator()(double a) const { return a; }
};

// The crossed class, return type different from argument type
struct crossed
{
  double operator()(int a) const { return double(a); }
  int    operator()(double a) const { return int(a); }
};

// The first connect class
template<class A>
class Connect1
{
public:
  template<class B> B operator()(B a) const
  {
    return fob(a);
  }
private:
  A fob;
};

// The second connect class
template<class A>
class Connect2
{
public:
  template<class B> typename result_of<A(B)>::type operator()(B a) const
  {
    return fob(a);
  }
private:
  A fob;
};

int main()
{
  int x = 3;
  float y = 5.5f;
  Connect1<straight> c1s;
  auto w1s = c1s(x);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(w1s).name() << " w1s = " << w1s << endl;

  x = 3;
  y = 5.5f;
  auto z1s = c1s(y);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(z1s).name() << " z1s = " << z1s << endl;

  x = 3;
  y = 5.5f;
  Connect1<crossed> c1c;
  auto w1c = c1c(x);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(w1c).name() << " w1c = " << w1c << endl;

  x = 3;
  y = 5.5f;
  auto z1c = c1c(y);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(z1c).name() << " z1c = " << z1c << endl;

  x = 3;
  y = 5.5f;
  Connect2<straight> c2s;
  auto w2s = c2s(x);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(w2s).name() << " w2s = " << w2s << endl;

  x = 3;
  y = 5.5f;
  auto z2s = c2s(y);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(z2s).name() << " z2s = " << z2s << endl;

  x = 3;
  y = 5.5f;
  Connect2<crossed> c2c;
  auto w2c = c2c(x);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(w2c).name() << " w2c = " << w2c << endl;

  x = 3;
  y = 5.5f;
  auto z2c = c2c(y);
  cout << "y = " << y << ", x = " << x << endl;
  cout << typeid(z2c).name() << " z2c = " << z2c << endl;

}

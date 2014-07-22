#include <iostream>
#include <typeinfo>
#include <type_traits>
using namespace std;

// First way of operating
template <bool C>
struct Converter
{
  template<class A, class B> int cvt( A& a, B&b )
  { cout << "T1" << endl; a = (b); return 1; }
};

// Second way of operating
template <>
struct Converter<true>
{
  template<class A, class B> int cvt( A& a, B&b )
  { cout << "T2" << endl; a = float(b); return 2; }
};

// Instantiating 'convert' will automatically pick the correct way
template<class A, class B>
int convert (A& a, B& b)
{
 // Use the second way only if A is integer and B is a float
 return Converter<is_integral<A>::value && is_floating_point<B>::value>().cvt(a,b);
}

int main()
{
  int x = 3;
  float y = 5.5f;
  int w;
  float z;
  w = convert(y, x);
  cout << "y = " << y << ", x = " << x << endl;
  x = 4;
  y = 5.5f;
  z = convert(x, y);
  cout << "y = " << y << ", x = " << x << endl;
  cout << "w = " << w << ", z = " << z << endl;
}

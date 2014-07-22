#include <iostream>
#include <typeinfo>
#include <tuple>
using namespace std;

int main()
{

  tuple<int, char, float> a { 3, '2', 1.0 };
  cout << typeid(a).name() << endl;

  auto b = make_tuple(string("One"), 2, 3.4);
  cout << typeid(b).name() << endl;
  cout << "size of b is " << tuple_size<decltype(b)>::value << endl;
  tuple_element<0, decltype(b)>::type x = get<0>(b);
  cout << typeid(x).name() << ' ' << x << endl;
  tuple_element<1, decltype(b)>::type y = get<1>(b);
  cout << typeid(y).name() << ' ' << y << endl;
  tuple_element<2, decltype(b)>::type z = get<2>(b);
  cout << typeid(z).name() << ' ' << z << endl;

}


#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;

initializer_list<int> fun(initializer_list<int> a)
{
  const int* p = a.begin();
  cout << "a = " << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
  cout << "p = " << p[0]*p[0] << ' ' << p[1]*p[1] << ' ' << p[2]*p[2] << endl;
  auto b  { p[0]*p[0], p[1]*p[1], p[2]*p[2] } ;
  for ( auto i : b ) cout << i << endl;
  return b;
}

auto d = { 8, 9, 10 };

initializer_list<int> e { 2, 4, 6 };
initializer_list<int> f = { 1, 3, 5 };
initializer_list<int> g(e);
initializer_list<int> h = f;
initializer_list<int> q;

int main()
{
  cout << typeid(d).name() << endl;

  q = d;
  q = e;

  for ( auto i : q ) cout << i << endl;

  q = fun( { 1, 2, 3 } );
  cout << typeid(q).name() << endl;
  for ( auto i : q ) cout << i << endl;

}

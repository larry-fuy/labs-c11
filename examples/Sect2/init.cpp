#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <string>
using namespace std;

class A
{
  int a = 7;  // not yet implemented 4.6.3; available in 4.7.2
  int b = 3;
public:
  void display() { cout << a << ' ' << b << endl; }
};

vector<int> c = { 1, 2, 3 };

auto d = { 8, 9, 10 };

struct icf 
{
  int a;
  char b;
  float c;
}tt1 = { 2, 'b', 2.2 };
//auto tt2 = { 2, 'b', 2.2 };  // no good
//auto tt2{ 2, 'b', 2.2 };   // no good
icf tt2{ 2, 'b', 2.2 }; 
//initializer_list<icf> tt3 = { 2, 'b', 2.2 };  // no good
initializer_list<icf> tt3 = { {2, 'b', 2.2} };
struct IntStr 
{
  int a;
  string b;
}is1 = { 2, "ab" };
IntStr is2 { 2, "ab" };
IntStr is3 ( { 2, "ab" } );
//IntStr is4 ( 2, "ab" );  // no good

auto j(42L);

int k = 3.0;
//int l = { 3.0 };  // Not allowed

decltype(0+0.0f) f1(int a, float b)
{
  return a + b;
}

template<class T1, class T2>
decltype((T1)0+(T2)0) f2(T1 a, T2 b)
{
  return a + b;
}

template<class T1, class T2>
auto f3(T1 a, T2 b) -> decltype(a+b)
{
  return a + b;
}

pair<int, char> fun( initializer_list<char> a )
{
  for ( auto i : a ) cout << i << endl;
  return { 1.1, 'c' };
}


int main()
{
  A x;
  x.display();

  auto *p = new A();
  cout << typeid(p).name() << endl;

  auto o = new A;
  cout << typeid(o).name() << endl;

  cout << typeid(j).name() << endl;

  for ( auto i : c ) cout << i << endl;

  cout << typeid(d).name() << endl;

  auto i = find(d.begin(), d.end(), 9);
  cout << typeid(i).name() << endl;
  cout << i << endl;

  cout << "is1 = " << is1.a << ", " << is1.b << endl;
  cout << "is2 = " << is2.a << ", " << is2.b << endl;
  cout << "is3 = " << is3.a << ", " << is3.b << endl;

  int m = 3;
  float n = 4.0f;
  auto q1 = f1(m,n);
  cout << typeid(q1).name() << endl;
  cout << q1 << endl;
  auto q2 = f2(m,n);
  cout << typeid(q2).name() << endl;
  cout << q2 << endl;
  auto q3 = f3(m,n);
  cout << typeid(q3).name() << endl;
  cout << q3 << endl;

  auto g = fun( { '3', 33, 'a' } );
  cout << g.first << ' ' << g.second << endl;
  cout << typeid(g).name() << endl;
  cout << typeid(g.first).name() << endl;
  cout << typeid(g.second).name() << endl;

  auto v = new vector<int> { 1, 2, 3 };
  cout << typeid(v).name() << endl;
  for ( auto i : *v ) cout << i << endl;

}

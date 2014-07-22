#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
using namespace std;

template <class A> void foo( A const& a) {}
enum X { x };
enum { y };

void f(vector<int>& v)
{
  struct lt {
    bool operator() (const int& a, const int& b) { return (a < b); }
    };
  sort(v.begin(), v.end(), lt());
};

int main()
{

  foo(x);
  foo(y);
  enum Z { z };
  foo(z);

  vector<int> v = { 3, 7, 2, 1, 8, 6 };
  f(v);
  for ( int i : v ) cout << i << " ";
  cout << endl;

}


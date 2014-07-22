#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

  auto l = { 1, 2, 3 };
  cout << typeid(l).name() << endl;

  auto b = l.begin();
  cout << typeid(b).name() << endl;

  for ( auto i : l ) cout << i << ' ';
  cout << endl;

  auto f = find(l.begin(), l.end(), 3);
  cout << "f = " << *f << endl;

}

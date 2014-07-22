#include <iostream>
#include <typeinfo>
#include <atomic>
using namespace std;


int main()
{
  //atomic<int> a = 1;  // cannot initialize this way
  atomic<int> a(1);     // this is OK
  atomic<int> b;
  atomic_int c;

  b.store(2);
  c = 3;

  cout << typeid(a).name() << endl;
  cout << a << endl;

  cout << typeid(b).name() << endl;
  cout << b << endl;

  cout << typeid(c).name() << endl;
  cout << c << endl;

  a++;
  cout << a << endl;
  
  b--;
  cout << b << endl;
  
  a += 4;
  cout << a << endl;
  
  b |= 4;
  cout << b << endl;
  
}

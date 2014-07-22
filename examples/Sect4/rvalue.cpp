#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;

int main()
{
  int&& x = 42;     // OK
//  int&& y = x;      // NG x is an lvalue
//  int&& z;          // NG not initialized
  int&& z = 0;
  z = x;

  cout << typeid(z).name() << endl;
  cout << z << endl;
  cout << "z at "<< &z << " x at " << &x << endl;
  x = 24;
  cout << "z is "<< z << " x is " << x << endl;

  int& a = x;       // OK x in an lvalue
//  int& b = 3;       // NG 3 is an rvalue
  int&& c = z/2+3;  // OK
  cout << "a is "<< a << " c is " << c << endl;

  int&& d = move(x);
  cout << d << endl;

  cout << "x = " << x << ", z = " << z << endl;
  swap(x, z);
  cout << "x = " << x << ", z = " << z << endl;

  int m = 6;
  int n = 7;
  cout << "m = " << m << ", n = " << n << endl;
  swap(m, n);
  cout << "m = " << m << ", n = " << n << endl;

  string p = "six";
  string q = "seven";
  cout << "p = " << p << ", q = " << q << endl;
  swap(p, q);
  cout << "p = " << p << ", q = " << q << endl;
}

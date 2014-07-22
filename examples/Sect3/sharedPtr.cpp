#include <iostream>
#include <typeinfo>
#include <fstream>
#include <memory>
using namespace std;

int main()
{
  shared_ptr<int> p (new int(42));
  //shared_ptr<int> q = new int(42);  // not valid, cannot convert int*
  int* a = new int(42);
  shared_ptr<int> q(a);
  shared_ptr<int> r;

  cout << typeid(p).name() << endl;
  cout << typeid(q).name() << endl;
  cout << typeid(r).name() << endl;

  //r = a;                            // also not valid
  r = q;
  cout << typeid(r).name() << endl;

}

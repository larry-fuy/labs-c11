#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> v = { -2, 1, -4, 3, 5 };

int main()
{
  //using namespace std::placeholders;
  sort(v.begin(), v.end());
  for (int i : v) 
    cout << i << " ";
  cout << endl;
  
  sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b);});
  for (int i : v) 
    cout << i << " ";
  cout << endl;

  auto f = [] { return 42; };
  cout << f() << endl;
  cout << typeid(f).name() << endl;
  
  int x = 7;
  auto l1 = [&] { return x; };
  
  x = 13;
  auto l2 = [=] { return x; };

  x = 2;
  auto l3 = [x] { return x; };

  x = 42;
  auto l4 = [x] { return x; };

  cout << l1() << endl;
  cout << typeid(l1).name() << endl;
  cout << l2() << endl;
  cout << typeid(l2).name() << endl;
  cout << l3() << endl;
  cout << typeid(l3).name() << endl;
  cout << l4() << endl;
  cout << typeid(l4).name() << endl;
  
  //auto l5 = [x] { ++x; return x; };  // error, x is read-only
  auto l5 = [x] () mutable{ ++x; return x; };
  cout << l5() << endl;
  cout << typeid(l5).name() << endl;

  auto l6 = [] (int x) { return x%2 ? true : false; };
  cout << l6(3) << endl;
  cout << l6(4) << endl;
  cout << typeid(l6).name() << endl;

  auto l7 = [] (int x) { if (x%2) return true; return false; }; // error
  cout << l7(3) << endl;
  cout << l7(4) << endl;
  cout << typeid(l7).name() << endl;

  auto l8 = [] (int x) -> bool { if (x%2) return true; return false; };
  cout << l8(3) << endl;
  cout << l8(4) << endl;
  cout << typeid(l8).name() << endl;

  auto x6 = l6(5);
  auto x7 = l7(6);
  auto x8 = l8(7);
  cout << typeid(x6).name() << x6 <<endl;
  cout << typeid(x7).name() << x7 <<endl;
  cout << typeid(x8).name() << x8 <<endl;
}

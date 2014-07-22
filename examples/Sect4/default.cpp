#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <map>
using namespace std;

map<string,string>m;

string a[] = { "Good", "Morning" };
//const char* b[] = { "Good", "Morning" };
char* b[] = { "Good", "Morning" };
vector<string> c = { "Good", "Morning" };

class A
{
  vector<int> v;
public:
  A(initializer_list<int> n) {
    //for(auto i : n) v.push_back(i);
    for(auto i=n.begin(); i !=n.end(); ++i) v.push_back(*i);
  }
  void display() {
    for(auto i : v)
       cout << i << endl;
   }
  A(A&& c) = default;
  A& operator=(const A& x) = default;
  A& operator=(A&& x) = default;
};


int main()
{
  A x({ 1, 2, 3 });
  x.display();

  A y = { 1, 2, 3 };
  y.display();

  A z = A({ 1, 2, 3 });
  z.display();

  A w{ 1, 2, 3 };
  w.display();

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;

  m["a"] = "b";
  cout << m["a"] << endl;

}

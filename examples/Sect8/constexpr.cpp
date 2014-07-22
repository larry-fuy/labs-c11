#include <iostream>
#include <typeinfo>
using namespace std;

constexpr int fun(int a) { return a+1; }

struct Point {
  int x, y;
  constexpr Point(int xx, int yy) : x(xx), y(yy) { }
};

int main()
{
  static int i = 7;
  static const int j = 3;
  const int* p = &i;
  const constexpr int* p1 = &j;
  constexpr int* q = &i;
  constexpr int c = fun(j);
  constexpr int d = fun(*p1);

   cout << typeid(p).name() << endl;
   cout << typeid(q).name() << endl;
   cout << *p << endl;
   cout << *q << endl;

   constexpr Point a(0,0);
   constexpr int x = a.x;

   //constexpr Point b(i,j);
   Point e(i,j);

}

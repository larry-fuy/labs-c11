#include <iostream>
#include <typeinfo>
#include "demangle.cpp"
using namespace std;


class Date
{
  int y_, m_, d_;
public:
  Date(int y, int m, int d) :y_(y), m_(m), d_(d) {}
  string display() const
  {
    char fmtd[12];
    sprintf(fmtd, "%02d/%02d/%02d", y_-2000, m_+1, d_);
    string rv(fmtd);
    return move(rv);
  }
};

Date operator "" _dt (const char* c, size_t s)
{
  int y,m,d;
  sscanf(c, "%d/%d/%d", &y, &m, &d);
  Date rv(y+2000, m-1, d);
  return rv;
}


int main()
{
  Date a(2013,0,4);
  cout << "a = " << a.display() << endl;
  cout << typeid(a).name() << endl;

  Date b = "12/10/9"_dt;
  cout << "b = " << b.display() << endl;
  cout << typeid(b).name() << endl;

//  Not yet implemented
//  auto s = "HI"s;
//  cout << "s = " << s << endl;
//  cout << typeid(s).name() << endl;

  auto i = 1.2i;
  cout << "i = " << i << endl;
  cout << typeid(i).name() << endl;

  cout << demangle(typeid(i).name()) << endl;
}

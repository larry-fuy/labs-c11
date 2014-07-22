#include <iostream>
#include <typeinfo>
#include <fstream>
using namespace std;


string a =  "Maiden";
string b =  "Fraulein";
string c = R"ab(a\b)ab";

int main()
{
  cout << "a = " << a << endl;
  cout << typeid(a).name() << endl;
  cout << "b = " << b << endl;
  unsigned char uma = 228;
  cout << "uma = " << uma << endl;
  cout << typeid(b).name() << endl;
  b[2] = uma;
  cout << "b = " << b << endl;
  cout << typeid(b).name() << endl;
  cout << "c = " << c << endl;
  cout << typeid(c).name() << endl;

  wchar_t ca = 228;
  wcout << ca << endl;
  cout << typeid(ca).name() << endl;
  cout << sizeof ca << endl;

}

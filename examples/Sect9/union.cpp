#include <iostream>
#include <typeinfo>
#include <string>
#include <stdlib.h>
using namespace std;

// The Complicated Union Class
class u11disc {
private:
  enum { num, str } typ; // discriminate
  union {
    int     m1;
    string  m3;
  };
public:
  u11disc () { typ = num; }
  ~u11disc () { if (typ==str) m3.~string(); }   // destroy the string 
  u11disc& operator=(const u11disc& u);
  u11disc& operator=(int u);
  u11disc& operator=(string u);
  string show();
};

inline u11disc& u11disc::operator=(const u11disc& u)
{
  if (typ==str && u.typ==str) {
    m3 = u.m3;  // usual string assignment;
    return *this;
  }
  if (typ==str) m3.~string();   // destroy the old string
  switch (u.typ) {
  case num: m1 = u.m1; break;     // normal copy
  case str: new(&m3) string(u.m3); break;  // placement new
  }
  typ = u.typ;
  return *this;
}

inline u11disc& u11disc::operator=(int u)
{
  if (typ==str) m3.~string();   // destroy the old string
  m1 = u;
  typ = num;
  return *this;
}

inline u11disc& u11disc::operator=(string u)
{
  if (typ==str) {
    m3 = u;  // usual string assignment;
    return *this;
  }
  new(&m3) string(u); // placement new
  typ = str;
  return *this;
}

inline string u11disc::show()
{
  string temp;
  switch (typ) {
  case num: temp = "int ";
            temp += to_string(m1);
            break;
  case str: temp = "str ";
            temp += m3;
            break;
  }
  return temp;
}


int main()
{
  u11disc myunion;
  myunion = 3;
  cout << myunion.show() << endl;

  myunion = "Hello";
  cout << myunion.show() << endl;
}

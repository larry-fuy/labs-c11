/* 
  Exercise 1 of Section 8
  print a string with escape charaters, e.g.  123\a456\rabc\tdef\nmno'pqr\"stu\vwx
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string x1 = "123\a456\rabc\tdef\nmno'pqr\"stu\vwx";
  string x2 = "123\\a456\\rabc\\tdef\\nmno'pqr\\\"stu\\vwx";
  string x3 = R"(123\a456\rabc\tdef\nmno'pqr\"stu\vwx)";
  
  cout << "------ x1 ------" << endl;
  cout << x1 << endl;
  cout << "------ x2 ------" << endl;
  cout << x2 << endl;
  cout << "------ x3 ------" << endl;
  cout << x3 << endl;

}

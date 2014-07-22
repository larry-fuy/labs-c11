
#include <iostream>
#include <iomanip>
using namespace std;


class myok
{
  int m;
public:
  myok() = default;
  myok(int i) { m = i; display(); }
  void set(int i) { m = i; }
  void display() { cout << "m = " << m << endl; }
};

class mypriv2: public myok
{
public:
  void set(int i) = delete;
};

struct mypriv3: myok
{
  mypriv3() { cout << "mypriv3 is OK" << endl; display(); }
};

int main()
{
  myok a;    //This is OK
  myok b(4);
  mypriv2 c;   //This is OK also
  mypriv3 d;   //This is OK, the default for struct is public
  b.display();
  a.set(3);
  a.display();
  //c.set(2);  //Fails, as it should
  return 0;
}

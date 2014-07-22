#include <iostream>
#include <typeinfo>
#include <fstream>
#include <memory>
using namespace std;

class connection
{
  ifstream fl_;
public:
  void open(const char* filename)
  {
    fl_.open(filename, ios::in);
    cout << "Opened file" << endl;
  }
  void close()
  {
    fl_.close();
    cout << "Closed file" << endl;
  }
};


void end_connection(connection* c) { c->close(); }

int main()
{
  connection c;

  c.open("uniquePtr.cpp");
  unique_ptr<connection, decltype(end_connection)*> p (&c, end_connection);

  cout << typeid(p).name() << endl;

}

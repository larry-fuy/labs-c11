#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
void print_comma_separated_list(T value)
{
    cout << value << endl;
}

template<typename First,typename ... Rest>
void print_comma_separated_list(First first,Rest ... rest)
{
    cout << first << ", ";
    print_comma_separated_list(rest...);
}


int main()
{
  int a = 3;
  const char* b = "hi";
  long long c = 42;
  string d = "bye";
  double e = 1.1;
  bool f = false;
  short g = 7;
  float h = 2.2;

  print_comma_separated_list(a, b, c);
  print_comma_separated_list(b, g, e, f, a);
  print_comma_separated_list(h, d);
}

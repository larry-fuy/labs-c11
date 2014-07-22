#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;


template<class T>
T get(vector<T> a, int i) noexcept
{
  return a.at(i);
}
int main()
{
  try {
  vector<int> x = { 0, 1, 4, 9, 16, 25 };
  cout << get(x, 3) << endl;
  cout << get(x, 6) << endl;
  } catch (...) { cout << "exception" << endl; }
}

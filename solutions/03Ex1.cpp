#include <iostream>
#include <chrono>
using namespace std;

int main()
{
  chrono::system_clock::time_point current = chrono::system_clock::now();
  auto prev = current - chrono::hours(100000);
  time_t rt_prev = chrono::system_clock::to_time_t(prev);
  cout << "One hundred thousand hours ago it was " << ctime(&rt_prev) << endl;
}

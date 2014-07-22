#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
auto d = hours(100000);
auto current = system_clock::now();
auto t = current - d;
auto t_time_t = system_clock::to_time_t(t);
cout << ctime(&t_time_t) << endl;
}

#include <iostream>
#include <chrono>
#include <random>
#include <functional>
using namespace std;

default_random_engine re;
uniform_int_distribution<int> dist(1, 100);
auto myrand = bind(dist, re);

vector<int> bars(100);

int main()
{
  using namespace std::chrono;
  steady_clock::time_point start = steady_clock::now();
  for(int i=0; i<4000; ++i) ++bars[myrand()]; // generate

  for(int i=0; i<bars.size(); ++i) {
    cout << i << '\t';
    for(int j=0; j<bars[i]; ++j) cout << "*";
    cout << '\n';
  }
  steady_clock::time_point stop = steady_clock::now();
  auto elapsed = duration_cast<microseconds>(stop - start);
  cout << "Elapsed time " << elapsed.count() << " microseconds." << endl;
}

#include <iostream>
#include <random>
#include <functional>
using namespace std;

// From Stroustrup's FAQ

default_random_engine re;
//normal_distribution<int> nd(31 /* mean */, 8 /* sigma */);  //per FAQ
normal_distribution<double> nd(20 /* mean */, 4 /* sigma */);  //per compiler
auto norm = bind(nd, re);

vector<int> mm(40);

int main()
{
  for(int i=0; i<1200; ++i) {
    int r = round(norm()); // generate
    if (r < 0) continue;
    if (r >= mm.size()) continue;
    ++mm[r];
  }

  for(int i=0; i<mm.size(); ++i) {
    cout << i << '\t';
    for(int j=0; j<mm[i]; ++j) cout << "*";
    cout << '\n';
  }
}

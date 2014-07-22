#include <iostream>
#include <random>
#include <functional>
using namespace std;

// From Stroustrup's FAQ

default_random_engine re;
//normal_distribution<int> nd(31 /* mean */, 8 /* sigma */);  //per FAQ
normal_distribution<double> nd(31 /* mean */, 8 /* sigma */);  //per compiler
auto norm = bind(nd, re);

vector<int> mm(64);

int main()
{
  for(int i=0; i<1200; ++i) ++mm[round(norm())]; // generate

  for(int i=0; i<mm.size(); ++i) {
    cout << i << '\t';
    for(int j=0; j<mm[i]; ++j) cout << "*";
    cout << '\n';
  }
}

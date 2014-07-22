#include <iostream>
#include <random>
#include <functional>
#include <unistd.h>
using namespace std;

default_random_engine re;
ranlux24 rl;
mt19937 mt;

normal_distribution<double> nd(20, 4);
uniform_int_distribution<int> ud(0,39);
binomial_distribution<int> bd(80,0.25);
geometric_distribution<int> gd(0.1);
poisson_distribution<int> pd(20);

vector<int> mm(40);

template<typename F, typename D>
void makeit(F re, D nd) {
  auto norm = bind(nd, re);
  for(int i=0; i<1200000; ++i) {
    int r = round(norm()); // generate
    if (r < 0) continue;
    if (r >= mm.size()) continue;
    ++mm[r];
  }
}

void printit() {
  for(int i=0; i<mm.size(); ++i) {
    cout << i << '\t';
    for(int j=0; j<mm[i]/1000; ++j) cout << "*";
    cout << '\n';
    mm[i] = 0;
  }
}

int main()
{
  makeit(mt, ud);
  printit();
  sleep(1);

  makeit(mt, nd);
  printit();
  sleep(1);

  makeit(mt, bd);
  printit();
  sleep(1);

  makeit(mt, gd);
  printit();
  sleep(1);

  makeit(mt, pd);
  printit();
}

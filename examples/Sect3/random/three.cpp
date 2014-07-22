#include <iostream>
#include <random>
#include <functional>
#include <unistd.h>
using namespace std;

default_random_engine re;
normal_distribution<double> nd(20, 4);
auto norm = bind(nd, re);

ranlux24 e2;
auto norm2 = bind(nd, e2);

mt19937 e3;
auto norm3 = bind(nd, e3);

vector<int> mm(40);

template<typename F>
void makeit(F rand) {
  for(int i=0; i<1200; ++i) {
    int r = round(rand()); // generate
    if (r < 0) continue;
    if (r >= mm.size()) continue;
    ++mm[r];
  }
}

void printit() {
  for(int i=0; i<mm.size(); ++i) {
    cout << i << '\t';
    for(int j=0; j<mm[i]; ++j) cout << "*";
    cout << '\n';
    mm[i] = 0;
  }
}

int main()
{
  makeit(norm);
  printit();
  sleep(3);

  makeit(norm2);
  printit();
  sleep(3);

  makeit(norm3);
  printit();
  sleep(3);
}

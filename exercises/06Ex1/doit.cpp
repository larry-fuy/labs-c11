#include <iostream>
#include <thread>
#include <random>
#include <functional>
#include <chrono>
#include <mutex>
#include <atomic>
#include "doit.h"
using namespace std;
using namespace std::chrono;
namespace {
  mutex x;
  default_random_engine re{static_cast<long unsigned int>(time(0))};
  uniform_int_distribution<int> dist(0, 30);
  auto myrand = bind(dist, re);
  atomic<int> total_calls(0);
  int state = 0;
  int count = 0;
}

Doit::Doit(void) {}

Doit::~Doit(){}

int Doit::getthreads()
{
  if (state != 0) {
   cout << "getthreads may only be called once at the beginning" << endl;
   exit(1);
  }
  state = 1;
  int randnum = myrand();
  //cout << randnum << endl;
  // call again, for some odd reason, I always got the same value first time
  randnum = myrand();
  //cout << randnum << endl;
  numthrs_ = randnum % 5 + 1;
  return numthrs_;
}

void Doit::done()
{
  if (state != 1 or total_calls < numthrs_ or total_calls != count) {
    cout << "Program failed" << endl;
    cout << "Expected " << total_calls << " got " << count << endl;
  }
  else
    cout << "Program complete, " << total_calls << " calls made." << endl;
}

milliseconds Doit::getduration()
{
  int n = myrand();
  chrono::milliseconds dur(n*10);
  total_calls++;
  return dur;
}

int Doit::incrcount()
{
  int holdcount = count;
  milliseconds msec(10);
  this_thread::sleep_for(msec);
  count = holdcount + 1;
  return count;
}

mutex* Doit::getlock()
{
  return &lock_;
}

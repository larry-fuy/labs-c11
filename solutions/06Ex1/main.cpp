
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "doit.h"
using namespace std;

void mythrd(Doit &mydoitobj, int idx)
{
  using namespace std::chrono;
  int calls = 0;
  milliseconds mywaittime;
  mutex* mylock = mydoitobj.getlock();
  do {
    mywaittime = mydoitobj.getduration();
    calls++;
    mylock->lock();
    mydoitobj.incrcount();
    mylock->unlock();
    this_thread::sleep_for(mywaittime);
  } while (mywaittime != milliseconds::zero());
  cout << "Thread " << idx+1 << " made " << calls << " calls, exiting." << endl;
}

int main()
{
  Doit doit;
  int numthreads = doit.getthreads();
  cout << "Starting " << numthreads << " threads." << endl;
  vector<thread> thds;
  for (int i=0; i<numthreads; i++)
    thds.emplace_back(thread(mythrd, ref(doit), i));
  for (int i=0; i<numthreads; i++)
    thds[i].join();
  doit.done();
}

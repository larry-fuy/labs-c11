
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#include "doit.h"
using namespace std;
using std::chrono::steady_clock;

// the thread function
void thread_comp(Doit& di, int ind) {
   chrono::milliseconds dur;
   while ( (dur = di.getduration()) == steady_clock::duration::zero());
   auto m = di.getlock();
   m->lock();
//      this_thread::sleep_for(steady_clock::duration::zero());
   this_thread::sleep_for(dur);
   di.incrcount();
   m->unlock();
}

int main()
{

   Doit di;
   int num_th = di.getthreads();
   cout << num_th << endl;
   vector<thread> threads;
   for (int i = 0; i < num_th; ++i) {
      threads.push_back(thread(thread_comp, ref(di), i));
   }

   for (auto& t : threads) {
      t.join();
   }

   di.done();
}

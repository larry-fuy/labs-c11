#ifndef DOIT_H
#define DOIT_H
#include <chrono>
#include <mutex>

class Doit
{
public:
  Doit(void);
  ~Doit();
  int getthreads();
  void done();
  std::chrono::milliseconds getduration();
  int incrcount();
  std::mutex* getlock();
private:
  int numthrs_;
  std::mutex lock_;
};
#endif

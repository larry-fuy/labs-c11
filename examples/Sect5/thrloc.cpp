#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// define a thread local storage variable
thread_local double tss_result = 1.0;

void compute_factorial ( long number )
{
  for (long i = 1; i <= number; i++ ) {
    tss_result *= i;
    }
}

void print_factorial( long number )
{
  cout << number << "! is " << tss_result << endl;
}

void factorial(long number) 
{
  double result = 1.0;
  for (long i = 1; i <= number; i++ ) {
    result *= i;
    }

  compute_factorial(number);

  chrono::seconds duration(number/10);
  this_thread::sleep_for(duration);
  cout << number << "! is " << result << endl;

  print_factorial(number);
}

int main(int argc, char** argv) 
{
  thread t1(factorial, 10L);
  thread t2(factorial, 20L);
  thread t3(factorial, 30L);

  // must wait for all threads to complete before exiting
  t1.join();
  t2.join();
  t3.join();
  return 0;
}

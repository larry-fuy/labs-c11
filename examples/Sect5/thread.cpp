#include <iostream>
#include <thread>
using namespace std;

void mythread(int a, char b, float c)
{
  cout << "Thread " << a << b << c << endl;
}

int main()
{
  cout << "Main" << endl;
  thread thr(mythread, 3, 'b', 1.0);
  thr.join();
}


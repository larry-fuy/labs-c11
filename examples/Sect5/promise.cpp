#include <future> 
#include <iostream> 
#include <string> 
using namespace std;

const char * thrfun(const char* msg) 
{
  if (msg=="exception")
    throw std::string(msg);
   else
     return msg; 
} 

int main() 
{ 
  packaged_task<const char*(const char*)> packtask(thrfun);
  auto fut = packtask.get_future();
  packtask("all's well");
  cout << "got " << fut.get() << endl;
  //cout << typeid(fut).name() << " got " << fut.get() << endl;
  packtask.reset();
  auto fut2 = packtask.get_future();
  packtask("play it again, Sam");
  cout << "got " << fut2.get() << endl;
  //cout << typeid(fut2).name() << " got " << fut2.get() << endl;
  
} 

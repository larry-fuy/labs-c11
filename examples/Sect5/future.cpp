#include <future> 
#include <iostream> 
#include <string> 

const char * thrfun(const char* msg) 
{
  if (msg=="exception")
    throw std::string(msg);
  else
    return msg;
} 

int main() 
{ 
  std::future<const char *> a = std::async(thrfun, "message");
  std::future<const char *> b = std::async(thrfun, "exception"); 
  try 
  {
    std::cout << a.get() << std::endl;  
    std::cout << b.get() << std::endl;
  }
  catch (std::string& s) 
  {
    std::cout << "Caught: " << s << std::endl;
  } 
} 


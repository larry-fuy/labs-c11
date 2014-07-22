
#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>

using namespace std;

exception_ptr fun2()
{
  return make_exception_ptr(runtime_error("Here it is"));
}

void fun1()
{
  auto exptr = fun2();
  rethrow_exception(exptr);
}

int main()
{
  try
  {
    fun1();
    cout << "Oops, didn't get exception" << endl;
  }
  catch (runtime_error ex)
  {
    cout << "OK: " << ex.what() << endl;
  }
}



#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

// fun2
exception_ptr fun2() {
   exception_ptr ep;
   try{
      string().at(1);
   } catch (...) {
      ep = current_exception();
   }
   return ep;
};


// fun1
void fun1() {
//   try{
      auto ep = fun2();     
   if (ep) rethrow_exception(ep);
//   } catch (const exception& e) {
//      cout << "Caught exception in fun1" << e.what() << endl;
//   }
}
      

int main()
{
   try{
      fun1();
   } catch (const exception& e) {
      cout << "Caught exception in main " << e.what() << endl;
   }
}

